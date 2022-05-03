
#include <tdlpp/auth/DefaultAuth.hpp>
#include <tdlpp/base/Handler.hpp>
#include <td/tl/TlObject.h>

#include <tdlpp/log/utils.hpp>

std::shared_ptr<tdlpp::auth::DefaultAuth> tdlpp::auth::DefaultAuth::create() {
    return std::make_shared<tdlpp::auth::DefaultAuth>();
}

tdlpp::auth::DefaultAuth::DefaultAuth() : authorized(false), authQueryId(0) {
    TDLPP_LOG_VERBOSE("tdlpp::auth::DefaultAuth::constructor");
}

void tdlpp::auth::DefaultAuth::WaitAuthorized() {
    TDLPP_LOG_INFO("tdlpp::auth::DefaultAuth::WaitAuthorized lock");
    std::mutex _mtx;
    std::unique_lock<std::mutex> lock(_mtx);
    authLock.wait(lock, [&] { return authorized.load() || retries >= TDLPP_MAX_AUTH_RETRIES; });
    TDLPP_LOG_DEBUG("tdlpp::auth::DefaultAuth::WaitAuthorized unlock");
}

void tdlpp::auth::DefaultAuth::handleUpdate() {
    authQueryId++;
    TDLPP_LOG_DEBUG("tdlpp::auth::DefaultAuth::OnAuthStateUpdate %s", TDLPP_TD_ID_NAME(authState->get_id()));

    td::td_api::downcast_call(*authState, overloaded(
        [this](td::td_api::authorizationStateWaitTdlibParameters& object) {
            OnAuthStateWaitParametres();
        },
        [this](td::td_api::authorizationStateWaitEncryptionKey& object) {
            OnAuthStateWaitEncryptionKey();
        },
        [this](td::td_api::authorizationStateWaitPhoneNumber& object) {
            OnAuthStateWaitPhoneNumber();
        },
        [this](td::td_api::authorizationStateWaitCode& object) {
            OnAuthStateWaitCode();
        },
        [this](td::td_api::authorizationStateWaitRegistration& object) {
            OnAuthStateRegistration();
        },
        [this](td::td_api::authorizationStateWaitPassword& object) {
            OnAuthStateWaitPassword();
        },
        [this](td::td_api::authorizationStateReady& object) {
            OnAuthorized();
        },
        [this](td::td_api::authorizationStateLoggingOut& object) {
            OnLogOut();
        },
        [this](td::td_api::authorizationStateClosed& object) {
            OnAuthStateClosed();
        },
        [this](auto&) {}
    ));
}

void tdlpp::auth::DefaultAuth::OnAuthStateUpdate(td::td_api::updateAuthorizationState&& update) {
    authState = SharedObjectPtr<td::td_api::AuthorizationState>(std::move(update.authorization_state_).release());

    handleUpdate();
}

void tdlpp::auth::DefaultAuth::OnAuthorized() {
    TDLPP_LOG_INFO("tdlpp::auth::DefaultAuth::OnAuthorized");
    authorized = true;
    authLock.notify_all();
}

void tdlpp::auth::DefaultAuth::OnLogOut() {
    TDLPP_LOG_ERROR("tdlpp::auth::DefaultAuth::OnLogOut");
    authorized = false;
    authLock.notify_all();
}

void tdlpp::auth::DefaultAuth::OnAuthStateClosed() {
    TDLPP_LOG_ERROR("tdlpp::auth::DefaultAuth::OnAuthStateClosed");
    authorized = false;
    authLock.notify_all();
}

void tdlpp::auth::DefaultAuth::OnAuthStateWaitCode() {
    TDLPP_LOG_INFO("tdlpp::auth::DefaultAuth::OnAuthStateWaitCode");

    std::cout << "  Enter authentication code: " << std::flush;
    std::string code;
    std::cin >> code;

    handler_->ExecuteAsync(td::td_api::make_object<td::td_api::checkAuthenticationCode>(code),
        [this](SharedObjectPtr<td::td_api::Object> object) {
            td::td_api::downcast_call(*object, overloaded(
                [this](td::td_api::error& err) {
                    TDLPP_LOG_ERROR("tdlpp::auth::DefaultAuth::OnAuthStateWaitCode %s", err.message_.c_str());
                    retry = true;
                    ++retries;
                },
                [this](td::td_api::ok&) {
                    retries = 0;
                },
                [this](auto&) {}
            ));
        }
    );
}

void tdlpp::auth::DefaultAuth::OnAuthStateRegistration() {
    TDLPP_LOG_INFO("tdlpp::auth::DefaultAuth::OnAuthStateRegistration");

    std::string first_name;
    std::string last_name;
    std::cout << "  Enter your first name: " << std::flush;
    std::cin >> first_name;
    std::cout << "  Enter your last name: " << std::flush;
    std::cin >> last_name;

    handler_->ExecuteAsync(td::td_api::make_object<td::td_api::registerUser>(first_name, last_name),
        [this](SharedObjectPtr<td::td_api::Object> object) {
            td::td_api::downcast_call(*object, overloaded(
                [this](td::td_api::error& err) {
                    TDLPP_LOG_ERROR("tdlpp::auth::DefaultAuth::OnAuthStateWaitCode %s", err.message_.c_str());
                    retry = true;
                    ++retries;
                },
                [this](td::td_api::ok&) {
                    retries = 0;
                },
                [](auto&) {}
            ));
        }
    );
}

void tdlpp::auth::DefaultAuth::OnAuthStateWaitPassword() {
    TDLPP_LOG_INFO("tdlpp::auth::DefaultAuth::OnAuthStateWaitPassword");

    std::string password = utils::getpass("  Enter authentication password: ");

    handler_->ExecuteAsync(td::td_api::make_object<td::td_api::checkAuthenticationPassword>(password),
        [this](SharedObjectPtr<td::td_api::Object> object) {
            td::td_api::downcast_call(*object, overloaded(
                [this](td::td_api::error& err) {
                    TDLPP_LOG_ERROR("tdlpp::auth::DefaultAuth::OnAuthStateWaitPassword %s", err.message_.c_str());
                    retry = true;
                    ++retries;
                },
                [this](td::td_api::ok&) {
                    retries = 0;
                },
                [](auto&) {}
            ));
        }
    );
}

void tdlpp::auth::DefaultAuth::OnAuthStateWaitPhoneNumber() {
    TDLPP_LOG_INFO("tdlpp::auth::DefaultAuth::OnAuthStateWaitPhoneNumber");

    std::cout << "  Enter phone number: " << std::flush;
    std::string phone_number;
    std::getline(std::cin, phone_number);


    handler_->ExecuteAsync(td::td_api::make_object<td::td_api::setAuthenticationPhoneNumber>(phone_number, nullptr),
        [this](SharedObjectPtr<td::td_api::Object> object) {
            td::td_api::downcast_call(*object, overloaded(
                [this](td::td_api::error& err) {
                    TDLPP_LOG_ERROR("tdlpp::auth::DefaultAuth::OnAuthStateWaitPhoneNumber %s", err.message_.c_str());
                    retry = true;
                    ++retries;
                },
                [this](td::td_api::ok&) {
                    retries = 0;
                },
                [](auto&) {}
            ));
        }
    );
}

void tdlpp::auth::DefaultAuth::OnAuthStateWaitEncryptionKey() {
    TDLPP_LOG_DEBUG("tdlpp::auth::DefaultAuth::OnAuthStateWaitEncryptionKey");

    handler_->ExecuteAsync(td::td_api::make_object<td::td_api::checkDatabaseEncryptionKey>(""),
        [this](SharedObjectPtr<td::td_api::Object> object) {
            td::td_api::downcast_call(*object, overloaded(
                [this](td::td_api::error& err) {
                    TDLPP_LOG_ERROR("tdlpp::auth::DefaultAuth::OnAuthStateWaitEncryptionKey %s", err.message_.c_str());
                    retry = true;
                    ++retries;
                },
                [this](td::td_api::ok&) {
                    retries = 0;
                },
                [](auto&) {}
            ));
        }
    );
}

void tdlpp::auth::DefaultAuth::OnAuthStateWaitParametres() {
    TDLPP_LOG_DEBUG("tdlpp::auth::DefaultAuth::OnAuthStateWaitParametres");

    std::string apiId = utils::getpass("  Enter api id: ");
    std::string apiHash = utils::getpass("  Enter api hash: ");

    auto parameters = td::td_api::make_object<td::td_api::tdlibParameters>();
    parameters->database_directory_ = "tdlib";
    parameters->use_message_database_ = true;
    parameters->use_secret_chats_ = false;
    parameters->api_id_ = std::stoi(apiId);
    parameters->api_hash_ = apiHash;
    parameters->system_language_code_ = "en";
    parameters->device_model_ = "desktop";
    parameters->application_version_ = "0.1";
    parameters->enable_storage_optimizer_ = true;

    handler_->ExecuteAsync(td::td_api::make_object<td::td_api::setTdlibParameters>(std::move(parameters)),
        [this](SharedObjectPtr<td::td_api::Object> object) {
            td::td_api::downcast_call(*object, overloaded(
                [this](td::td_api::error& err) {
                    TDLPP_LOG_ERROR("tdlpp::auth::DefaultAuth::OnAuthStateWaitParametres %s", err.message_.c_str());
                    retry = true;
                    ++retries;
                },
                [this](td::td_api::ok&) {
                    retries = 0;
                },
                [](auto&) {}
            ));
        }
    );
}


void tdlpp::auth::DefaultAuth::SetHandler(const std::shared_ptr<tdlpp::base::TdlppHandler>& handler) {
    TDLPP_LOG_VERBOSE("tdlpp::auth::DefaultAuth::SetHandler");
    handler_ = handler;
}

bool tdlpp::auth::DefaultAuth::HandleRetry() {
    if (retry.load()) {
        handleUpdate();
        retry = false;
        authLock.notify_all();
        return true;
    }

    return false;
}
