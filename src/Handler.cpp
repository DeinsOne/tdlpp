
#include <tdlpp/base/Handler.hpp>

std::shared_ptr<tdlpp::base::TdlppHandler> tdlpp::base::TdlppHandler::create(const std::shared_ptr<auth::IAuth>& auth_) {
    auto handler = std::make_shared<tdlpp::base::TdlppHandler>(auth_);
    handler->this_ = handler;
    handler->auth_->SetHandler(handler);
    return handler;
}

tdlpp::base::TdlppHandler::TdlppHandler(const std::shared_ptr<auth::IAuth>& auth__) : auth_(auth__) {
    TDLPP_LOG_VERBOSE("tdlpp::base::TdlppHandler::constructor");
    updatesHandler = UpdateCallbacksHandler::create();
    binding = BindingHandler::create();
    if (this_)
        auth_->SetHandler(this_);

    SetCallback<td::td_api::updateAuthorizationState>(true, [&](td::td_api::updateAuthorizationState state) {
        auth_->OnAuthStateUpdate(std::move(state));
    });
}

void tdlpp::base::TdlppHandler::Handle(const std::uint64_t& requestId, tdlpp::UniqueObjectPtr<td::td_api::Object> object) {
    TDLPP_LOG_DEBUG("tdlpp::base::TdlppHandler::Handle %s rid:%ld", TDLPP_TD_ID_NAME(object->get_id()), requestId);

    std::shared_ptr<td::td_api::Object> objectPtr(std::move(object).release());

    if (requestId == 0) {
        updatesHandler->Handle(objectPtr);
    }

    binding->Handle(requestId, objectPtr);
}



