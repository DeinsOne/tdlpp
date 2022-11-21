
#include <tdlpp/base/Handler.hpp>

std::shared_ptr<tdlpp::base::TdlppHandler> tdlpp::base::TdlppHandler::create(const std::shared_ptr<auth::IAuth>& auth_) {
    auto handler = std::make_shared<tdlpp::base::TdlppHandler>(auth_);
    handler->this_ = handler;
    handler->auth_->SetHandler(handler);
    return handler;
}

tdlpp::base::TdlppHandler::TdlppHandler(const std::shared_ptr<auth::IAuth>& auth__) : auth_(auth__), destroy(false) {
    TDLPP_LOG_VERBOSE("tdlpp::base::TdlppHandler::constructor");
    updatesHandler = UpdateCallbacksHandler::create();
    // binding = BindingHandler::create();

    SetCallback<td::td_api::updateAuthorizationState>(true, [&](td::td_api::updateAuthorizationState& state) {
        auth_->OnAuthStateUpdate(std::move(state));
    });

    auto func = [&]() {
        TDLPP_LOG_DEBUG("Create worker thread %d", std::this_thread::get_id());
        while (!destroy) {
            updatesQueueMtx.lock();

            if (updatesQueue.size()) {
                auto object = updatesQueue.front();
                updatesQueue.pop();
                updatesQueueMtx.unlock();
                Handle(object.first, object.second);
            }
            else {
                updatesQueueMtx.unlock();
                std::mutex mtx;
                std::unique_lock<std::mutex> unique(mtx);
                updatesQueueNotifier.wait(unique);
            }
        }

        destroy = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        TDLPP_LOG_DEBUG("Destroy worker thread %d", std::this_thread::get_id());
        destroyLock.notify_all();
    };

    worker = std::thread(func);
    worker.detach();
}

tdlpp::base::TdlppHandler::~TdlppHandler() {
    destroy = true;
    updatesQueueNotifier.notify_all();

    std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);
    destroyLock.wait(lock, [&]() { return !destroy; });
}


void tdlpp::base::TdlppHandler::Handle(const std::uint64_t& requestId, SharedObjectPtr<td::td_api::Object> object) {
    TDLPP_LOG_DEBUG("rid:%ld %s", requestId, TDLPP_TD_ID_NAME(object->get_id()));

    if (requestId == 0) updatesHandler->Handle(object);

    else {
        auto iter = responsePromises.find(requestId);
        if (iter == responsePromises.end()) return;

        auto promise = iter->second;
        if (!promise->GetResponse()) promise->SetResponse(object);
        promise->InvokeCallback();

        responsePromises.erase(iter);
    }
}

void tdlpp::base::TdlppHandler::PushToQueue(const std::uint64_t& requestId, UniqueObjectPtr<td::td_api::Object> object) noexcept {
    TDLPP_LOG_DEBUG("rid:%ld %s", requestId, TDLPP_TD_ID_NAME(object->get_id()));
    std::shared_ptr<td::td_api::Object> objectPtr(std::move(object).release());

    updatesQueueMtx.lock();
    updatesQueue.push(std::pair<std::uint64_t,SharedObjectPtr<td::td_api::Object>>(requestId, objectPtr));
    updatesQueueMtx.unlock();
    updatesQueueNotifier.notify_all();


    // Store response only if it was declared required by any executor
    if (requestId > 0) {
        auto iter = responsePromises.find(requestId);
        if (iter == responsePromises.end()) return;

        iter->second->SetResponse(objectPtr);
    }
}
