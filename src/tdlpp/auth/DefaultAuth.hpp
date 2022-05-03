
#ifndef tdlpp_DefaultAuth
#define tdlpp_DefaultAuth

#include <tdlpp/auth/IAuth.hpp>
#include <mutex>
#include <atomic>
#include <condition_variable>

namespace tdlpp { namespace auth {

    class DefaultAuth : public IAuth, public TdlppBase {
    public:
        static std::shared_ptr<DefaultAuth> create() {
            return std::make_shared<tdlpp::auth::DefaultAuth>();
        }

    public:
        DefaultAuth() : authorized(false), authQueryId(0) {
            TDLPP_LOG_VERBOSE("tdlpp::auth::DefaultAuth::constructor");
        }

        virtual bool IsAuthorized() override { return authorized.load(); }

        virtual void WaitAuthorized() override {
            TDLPP_LOG_INFO("tdlpp::auth::DefaultAuth::WaitAuthorized lock");
            std::mutex _mtx;
            std::unique_lock<std::mutex> lock(_mtx);
            authLock.wait(lock, [&] { return authorized.load(); });
            TDLPP_LOG_DEBUG("tdlpp::auth::DefaultAuth::WaitAuthorized unlock");
        }

    private:
        virtual void OnAuthorized() override;
        virtual void OnLogOut() override;
        virtual void OnAuthorizationStateUpdate(td::td_api::updateAuthorizationState&&) override;

        virtual void OnAuthStateClosed() override;
        virtual void OnAuthStateRegistration() override;
        virtual void OnAuthStateWaitCode() override;
        virtual void OnAuthStateWaitPassword() override;
        virtual void OnAuthStateWaitPhoneNumber() override;
        virtual void OnAuthStateWaitEncryptionKey() override;
        virtual void OnAuthStateWaitParametres() override;

        virtual void SetHandler(const std::shared_ptr<base::TdlppHandler>& handler) override {
            TDLPP_LOG_VERBOSE("tdlpp::auth::DefaultAuth::SetHandler");
            handler_ = handler;
        }


        void handleUpdate();
        // std::function<void(SharedObjectPtr<td::td_api::Object>)> create_authentication_query_handler() {
        //     return [this, id = authQueryId](SharedObjectPtr<td::td_api::Object> object) {
        //         if (id == authQueryId) {
        //             check_authentication_error(std::move(object));
        //         }
        //     };
        // }

        // void check_authentication_error(SharedObjectPtr<td::td_api::Object> object) {
        //     if (object->get_id() == td::td_api::error::ID) {
        //         // auto error = td::move_tl_object_as<td::td_api::error>(object);
        //         // CRITICAL("Error: {}", to_string(error).c_str());
        //         // OnAuthorizationStateUpdate( dynamic_cast<td::td_api::updateAuthorizationState&>(authState.get() ) );
        //         // td::td_api::make_object<td::td_api::updateAuthorizationState>(authState.get());
        //     }
        // }

    private:
        std::uint64_t authQueryId{0};
        std::atomic<bool> authorized;
        SharedObjectPtr<td::td_api::AuthorizationState> authState;
        std::condition_variable authLock;

        std::shared_ptr<base::TdlppHandler> handler_;
    };

} // namespace auth
} // namespace tdlpp

#endif // tdlpp_DefaultAuth
