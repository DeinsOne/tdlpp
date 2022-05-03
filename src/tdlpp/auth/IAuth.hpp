
#ifndef tdlpp_IAuth
#define tdlpp_IAuth

#include <tdlpp/core.hpp>

namespace tdlpp { namespace base {
    class TdlppHandler;
} // namespace base
} // namespace tdlpp

namespace tdlpp { namespace auth {

    class IAuth {
    public:
        virtual bool IsAuthorized() = 0;
        virtual void WaitAuthorized() = 0;

    private:
        virtual void OnAuthorized() = 0;
        virtual void OnLogOut() = 0;
        virtual void OnAuthorizationStateUpdate(td::td_api::updateAuthorizationState&&) = 0;

        virtual void OnAuthStateClosed() = 0;
        virtual void OnAuthStateWaitCode() = 0;
        virtual void OnAuthStateRegistration() = 0;
        virtual void OnAuthStateWaitPassword() = 0;
        virtual void OnAuthStateWaitPhoneNumber() = 0;
        virtual void OnAuthStateWaitEncryptionKey() = 0;
        virtual void OnAuthStateWaitParametres() = 0;

    private:
        friend base::TdlppHandler;
        virtual void SetHandler(const std::shared_ptr<base::TdlppHandler>& handler) = 0;

    };

} // namespace auth
} // namespace tdlpp

#endif // tdlpp_IAuth
