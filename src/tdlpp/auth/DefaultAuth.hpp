
#ifndef tdlpp_DefaultAuth
#define tdlpp_DefaultAuth

#include <tdlpp/auth/IAuth.hpp>
#include <condition_variable>
#include <mutex>
#include <atomic>

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
            authLock.wait(lock, [&] { return authorized.load() || retries >= TDLPP_MAX_AUTH_RETRIES; });
            TDLPP_LOG_DEBUG("tdlpp::auth::DefaultAuth::WaitAuthorized unlock");
        }

        virtual bool HandleRetry() override {
            if (retry.load()) {
                handleUpdate();
                retry = false;
                authLock.notify_all();
                return true;
            }

            return false;
        }

        virtual std::uint32_t GetRetriesCount() override {
            return retries;
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

    private:
        std::uint64_t authQueryId{0};
        std::atomic<bool> authorized{false};
        
        std::atomic<bool> retry{false};
        std::uint32_t retries{0};

        SharedObjectPtr<td::td_api::AuthorizationState> authState;
        std::condition_variable authLock;

        std::shared_ptr<base::TdlppHandler> handler_;
    };

} // namespace auth
} // namespace tdlpp

#endif // tdlpp_DefaultAuth
