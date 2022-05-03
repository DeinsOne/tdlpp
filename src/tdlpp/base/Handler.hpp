
#ifndef tdlpp_Handler
#define tdlpp_Handler

#include <tdlpp/auth/IAuth.hpp>
#include <tdlpp/base/UpdateCalbacksHandler.hpp>
#include <tdlpp/router/Router.h>
#include <tdlpp/base/BindongHandler.hpp>
#include <functional>

namespace tdlpp { namespace poll {
    class LongPoll;
    class PollManager;
} // namespace poll
} // namespace tdlpp

namespace tdlpp { namespace base {

    class TdlppHandler : public TdlppBase {
        friend poll::PollManager;
        friend poll::LongPoll;
    public:
        static std::shared_ptr<TdlppHandler> create(const std::shared_ptr<auth::IAuth>& auth_) {
            auto handler = std::make_shared<tdlpp::base::TdlppHandler>(auth_);
            handler->this_ = handler;
            handler->auth_->SetHandler(handler);
            return handler;
        }

    public:
        TdlppHandler(const std::shared_ptr<auth::IAuth>& auth__) : auth_(auth__) {
            TDLPP_LOG_VERBOSE("tdlpp::base::TdlppHandler::constructor");
            updatesHandler = UpdateCallbacksHandler::create();
            binding = BindingHandler::create();
            if (this_)
                auth_->SetHandler(this_);

            updatesHandler->Listen<td::td_api::updateAuthorizationState>([&](td::td_api::updateAuthorizationState state) {
                auth_->OnAuthorizationStateUpdate(std::move(state));
            }, true);
        }

        template<typename TdUpdate>
        std::shared_ptr<TdlppHandler> SetCallback(const std::function<void(TdUpdate)>& func, const bool& overwrite = false) {
            TDLPP_LOG_DEBUG("tdlpp::base::TdlppHandler::SetCallback %s", TDLPP_TD_ID_NAME(TdUpdate::ID));
            updatesHandler->Listen<TdUpdate>(func, overwrite);
            return this_;
        }

        /**
         * @tparam TFunction derived from td::td_api::Function
         */
        template<typename TdFunction>
        std::shared_ptr<IResponsePromise> Execute(UniqueObjectPtr<TdFunction> function) {
            TDLPP_LOG_DEBUG("tdlpp::base::TdlppHandler::Execute %s rid: %ld", TDLPP_TD_ID_NAME(TdFunction::ID), router_->GetLastRequestId() + 1);
            auto rid = router_->Send(std::move(function));
            auto promise = ResponsePromise<TdFunction>::create(rid);
            binding->Listen(promise);
            return promise;
        }

        /**
         * @tparam TFunction derived from td::td_api::Function
         */
        template<typename TdFunction>
        void CallAsync(UniqueObjectPtr<TdFunction> function, const std::function<void(SharedObjectPtr<td::td_api::Object>)>& handler = {} ) {
            TDLPP_LOG_DEBUG("tdlpp::base::TdlppHandler::CallAsync %s rid: %ld", TDLPP_TD_ID_NAME(TdFunction::ID), router_->GetLastRequestId() + 1);
            auto rid = router_->Send(std::move(function));
            binding->Listen(ResponsePromise<TdFunction>::create(rid, handler));
        }

        void Handle(const std::uint64_t& requestId, UniqueObjectPtr<td::td_api::Object> object) {
            TDLPP_LOG_DEBUG("tdlpp::base::TdlppHandler::Handle %s rid: %ld", TDLPP_TD_ID_NAME(object->get_id()), requestId);

            std::shared_ptr<td::td_api::Object> objectPtr(std::move(object).release());

            if (requestId == 0) {
                updatesHandler->Handle(objectPtr);
            }

            binding->Handler(requestId, objectPtr);
        }

    private:
        std::shared_ptr<TdlppHandler> this_;
        std::shared_ptr<auth::IAuth> auth_;

        std::shared_ptr<router::Router> router_;
        std::shared_ptr<UpdateCallbacksHandler> updatesHandler;
        std::shared_ptr<BindingHandler> binding;

        void SetRouter(const std::shared_ptr<router::Router>& router__) {
            router_ = router__;
        }

    };

} // namespace base
} // namespace tdlpp

#endif // tdlpp_Handler
