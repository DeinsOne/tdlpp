
#ifndef tdlpp_DefaultAuth
#define tdlpp_DefaultAuth

#include <tdlpp/auth/IAuth.hpp>
#include <condition_variable>
#include <mutex>
#include <atomic>

namespace tdlpp { namespace auth {

    class DefaultAuth : public IAuth, public TdlppBase {
    public:
        /**
         * @brief A factory method
         * 
         * @return std::shared_ptr<DefaultAuth> New instance of 'DefaultAuth'
         */
        static std::shared_ptr<DefaultAuth> create();
        /**
         * @brief A factory method
         * @details You can generate api on https://my.telegram.org
         * 
         * @param apiId_ Api id
         * @param apiHash_ Api hash
         * 
         * @return std::shared_ptr<DefaultAuth> New instance of 'DefaultAuth'
         */
        static std::shared_ptr<DefaultAuth> create(const std::int32_t& apiId_, const std::string& apiHash_);

    public:
        DefaultAuth();
        DefaultAuth(const std::int32_t& apiId_, const std::string& apiHash_);

        // Check if the instance is authorized or not
        virtual bool IsAuthorized() override { return authorized.load(); }
        // Wait for the authorization to complete, or for the maximum number of retries to be exceeded
        virtual void WaitAuthorized();

        // Returns count of consecutive retries
        virtual std::uint32_t GetRetriesCount() override { return retries; }

    private:
        virtual void OnAuthorized() override;
        virtual void OnLogOut() override;

        virtual void OnAuthStateClosed() override;
        virtual void OnAuthStateRegistration() override;
        virtual void OnAuthStateWaitCode() override;
        virtual void OnAuthStateWaitPassword() override;
        virtual void OnAuthStateWaitPhoneNumber() override;
        virtual void OnAuthStateWaitEncryptionKey() override;
        virtual void OnAuthStateWaitParametres() override;

        virtual void OnAuthStateUpdate(td::td_api::updateAuthorizationState&&) override;

    private:
        virtual void SetHandler(const std::shared_ptr<base::TdlppHandler>& handler);

        virtual bool HandleRetry() override;
        void handleUpdate();

    private:
        std::uint64_t authQueryId{0};
        std::atomic<bool> authorized{false};

        std::int32_t apiId{-1};
        std::string apiHash;

        std::atomic<bool> retry{false};
        std::uint32_t retries{0};

        SharedObjectPtr<td::td_api::AuthorizationState> authState;
        std::condition_variable authLock;

        std::shared_ptr<base::TdlppHandler> handler_;
    };

} // namespace auth
} // namespace tdlpp

#endif // tdlpp_DefaultAuth
