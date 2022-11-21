
#include <tdlpp/poll/LongPoll.hpp>

std::shared_ptr<tdlpp::poll::LongPoll> tdlpp::poll::LongPoll::create(const std::shared_ptr<tdlpp::base::TdlppHandler>& handler) {
  auto poll = std::make_shared<tdlpp::poll::LongPoll>(handler);
  poll->this_ = poll;
  return poll;
}

tdlpp::poll::LongPoll::LongPoll(const std::shared_ptr<tdlpp::base::TdlppHandler>& handler) : handler_(handler), running(true), destroy(false) {
  TDLPP_LOG_VERBOSE("constructor");
  router_ = tdlpp::router::Router::create();
  handler_->SetRouter(router_);
}

tdlpp::poll::LongPoll::~LongPoll() {
  TDLPP_LOG_VERBOSE("distructor");
  running = false, destroy = true;

  std::mutex _mtx;
  std::unique_lock<std::mutex> lock(_mtx);
  destroyLock.wait(lock, [&]()
                   { return !destroy; });
  TDLPP_LOG_VERBOSE("distructor lock release");
}


void tdlpp::poll::LongPoll::Resume() {
  TDLPP_LOG_INFO("resume");
  running = true;
}

void tdlpp::poll::LongPoll::Pause() {
  TDLPP_LOG_INFO("pause");
  running = false;
}


void tdlpp::poll::LongPoll::ExecuteSync() {
  // Infinite loop for receiving telegram updates. Ends once distructor is called
  while (!destroy) {
    if (running) {
      // Check retries count inside the loop. This is oly applicable to auth update. Will drop
      // a poll once retries are exceed, otherwise will try to use the same action on last update
      if (handler_->auth_->HandleRetry()) {
        if (handler_->auth_->GetRetriesCount() >= TDLPP_MAX_AUTH_RETRIES) {
          TDLPP_LOG_FATAL("poll is paused because you have exceeded limit of authentication retries(%d)", TDLPP_MAX_AUTH_RETRIES);
          this->destroy = true;
          this->Pause();
          continue;
        }
      }

      // Handles state before authentication
      else if (!handler_->auth_->IsAuthorized()) {
        handlingResponse(router_->Receive(100));
      }

      // Handles updates on authorized state. Will deal with multiple updates at one time, or if
      //there is no more will cause poll to wait timeout before processing new updates
      else {
        while (running) {
          auto response = router_->Receive(0);
          if (response.object) handlingResponse(std::move(response));
          else break;
        }
      }
    }

    // Implicit loop timeout
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

void tdlpp::poll::LongPoll::ExecuteAsync() {
  this->asyncPollWorker = std::thread([this]() {
    TDLPP_LOG_INFO("run polling thread");
    ExecuteSync();

    destroy = false;
    destroyLock.notify_all();
  });

  this->asyncPollWorker.detach();
}

void tdlpp::poll::LongPoll::handlingResponse(td::ClientManager::Response response) {
  if (!response.object) return;
  TDLPP_LOG_DEBUG(" ");
  handler_->PushToQueue(response.request_id, std::move(response.object));
}

