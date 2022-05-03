
#include <tdlpp/poll/LongPoll.hpp>
#include <tdlpp/poll/PollManager.hpp>

std::shared_ptr<tdlpp::poll::LongPoll> tdlpp::poll::LongPoll::create(const std::shared_ptr<tdlpp::base::TdlppHandler>& handler) {
    auto poll = std::make_shared<tdlpp::poll::LongPoll>(handler);
    poll->this_ = poll;
    return poll;
}

tdlpp::poll::LongPoll::LongPoll(const std::shared_ptr<tdlpp::base::TdlppHandler>& handler) : handler_(handler) {
    TDLPP_LOG_VERBOSE("tdlpp::poll::LongPoll::constructor");
    router_ = tdlpp::router::Router::create();
    handler_->SetRouter(router_);
}

std::shared_ptr<tdlpp::poll::PollManager> tdlpp::poll::LongPoll::ExecuteAsync() {
    TDLPP_LOG_INFO("tdlpp::poll::LongPoll::ExecuteAsync run polling thread");
    return tdlpp::poll::PollManager::create(this_);
}


std::shared_ptr<tdlpp::poll::PollManager> tdlpp::poll::PollManager::create(const std::shared_ptr<tdlpp::poll::LongPoll>& poll) {
    return std::make_shared<tdlpp::poll::PollManager>(poll);
}

tdlpp::poll::PollManager::PollManager(const std::shared_ptr<tdlpp::poll::LongPoll>& longPoll) : poll(longPoll), active(true), destroy(false) {
    TDLPP_LOG_VERBOSE("tdlpp::poll::PollManager::constructor");
    auto func = [&]() {
        while (!destroy.load()) {
            if (IsActive()) {
                if (poll->handler_->auth_->HandleRetry()) {
                    if (poll->handler_->auth_->GetRetriesCount() >= TDLPP_MAX_AUTH_RETRIES) {
                        this->Pause();
                        TDLPP_LOG_FATAL("tdlpp::poll::PollManager poll is paused because you have passed limit of authentication retries(%d)", TDLPP_MAX_AUTH_RETRIES);
                    }
                }
                else if (!poll->handler_->auth_->IsAuthorized()) {
                    handlingResponse(longPoll->router_->Receive(10));
                }
                else {
                    while (true) {
                        auto response = longPoll->router_->Receive(0);
                        if (response.object) handlingResponse(std::move(response));
                        else break;
                    }
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        printf("tdlpp::PollManager exit the loop\n");
        destroy = false;
        destroyLock.notify_all();
    };

    worker = std::thread(func);
    worker.detach();
}

tdlpp::poll::PollManager::~PollManager() {
    TDLPP_LOG_VERBOSE("tdlpp::poll::PollManager::distructor");
    active = false, destroy = true;

    std::mutex _mtx;
    std::unique_lock<std::mutex> lock(_mtx);
    destroyLock.wait(lock, [&]() { return !destroy.load(); } );
    TDLPP_LOG_VERBOSE("tdlpp::poll::PollManager::distructor lock release");
}

void tdlpp::poll::PollManager::Resume() {
    TDLPP_LOG_INFO("tdlpp::poll::PollManager::Resume");
    active = true;
}

void tdlpp::poll::PollManager::Pause() {
    TDLPP_LOG_INFO("tdlpp::poll::PollManager::Pause");
    active = false;
}

void tdlpp::poll::PollManager::handlingResponse(td::ClientManager::Response response) {
    if (!response.object) return;
    TDLPP_LOG_DEBUG("tdlpp::poll::PollManager::handlingResponse");
    poll->handler_->Handle(response.request_id, std::move(response.object));
}
