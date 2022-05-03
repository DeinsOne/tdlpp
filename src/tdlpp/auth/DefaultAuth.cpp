
#include <tdlpp/auth/DefaultAuth.hpp>
#include <tdlpp/base/Handler.hpp>
#include <td/tl/TlObject.h>

#include <tdlpp/utils.hpp>

void tdlpp::auth::DefaultAuth::handleUpdate() {
    authQueryId++;
    TDLPP_LOG_DEBUG("tdlpp::auth::DefaultAuth::OnAuthorizationStateUpdate %s", TDLPP_TD_ID_NAME(authState->get_id()));

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

void tdlpp::auth::DefaultAuth::OnAuthorizationStateUpdate(td::td_api::updateAuthorizationState&& update) {
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

    std::cout << "Enter authentication code: " << std::flush;
    std::string code;
    std::cin >> code;

    handler_->CallAsync(td::td_api::make_object<td::td_api::checkAuthenticationCode>(code),
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
    std::cout << "Enter your first name: " << std::flush;
    std::cin >> first_name;
    std::cout << "Enter your last name: " << std::flush;
    std::cin >> last_name;

    handler_->CallAsync(td::td_api::make_object<td::td_api::registerUser>(first_name, last_name),
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

    std::string password = utils::getpass("Enter authentication password: ");

    handler_->CallAsync(td::td_api::make_object<td::td_api::checkAuthenticationPassword>(password),
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

    std::cout << "Enter phone number: " << std::flush;
    std::string phone_number;
    std::getline(std::cin, phone_number);


    handler_->CallAsync(td::td_api::make_object<td::td_api::setAuthenticationPhoneNumber>(phone_number, nullptr),
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

    handler_->CallAsync(td::td_api::make_object<td::td_api::checkDatabaseEncryptionKey>(""),
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

    auto parameters = td::td_api::make_object<td::td_api::tdlibParameters>();
    // parameters->database_directory_ = json_env["td_database_directory"].asString();
    parameters->database_directory_ = "tdlib";
    parameters->use_message_database_ = true;
    parameters->use_secret_chats_ = false;
    // parameters->api_id_ = json_env["td_api_id"].asUInt64();
    parameters->api_id_ = 2617703;
    // parameters->api_hash_ = json_env["td_api_hash"].asString();
    parameters->api_hash_ = "c8973b1a4470891012064aba2698512b";
    parameters->system_language_code_ = "en";
    parameters->device_model_ = "desktop";
    // parameters->application_version_ = json_env["td_application_version"].asString();
    parameters->application_version_ = "0.1";
    parameters->enable_storage_optimizer_ = true;

    // processor->send_query(td_api::make_object<td_api::setTdlibParameters>(std::move(parameters)),
        // auth->create_authentication_query_handler()
    // );

    handler_->CallAsync(td::td_api::make_object<td::td_api::setTdlibParameters>(std::move(parameters)),
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


