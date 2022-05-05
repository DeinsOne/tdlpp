
#include <tdlpp/tdlpp.hpp>
#include <tdlpp/auth/DefaultAuth.hpp>

int main(int argc, char** argv) {

    auto auth = tdlpp::auth::DefaultAuth::create(
        -1,             // api id
        "",             // api hash
        "sample-shared-tdlib"  // downloading dir
    );

    auto handler = tdlpp::base::TdlppHandler::create(auth);
    auto longPoll = tdlpp::poll::LongPoll::create(handler);
    auto controller = longPoll->ExecuteAsync();

    
    if (!auth->IsAuthorized()) {
        auth->WaitAuthorized();

        if (auth->GetRetriesCount() >= TDLPP_MAX_AUTH_RETRIES) {
            return 1;
        }
    }


    std::string tMeLink;
    tdlpp::UniqueObjectPtr<td::td_api::profilePhoto> profilePhoto;

    // Get telegram user link prefix
    auto tMeLinkPromise = handler->Execute<td::td_api::getOption>("t_me_url");

    td::td_api::downcast_call(*tMeLinkPromise->GetResponse(), tdlpp::overloaded(
        [&](td::td_api::optionValueString& option) {
            tMeLink = option.value_;
        },
        [](auto&) {}
    ));

    // Execute commands synchronously in functional flow
    auto mePromise = handler->Execute<td::td_api::getMe>();

    td::td_api::downcast_call(*mePromise->GetResponse(), tdlpp::overloaded(
        [&](td::td_api::user& me) {
            tMeLink += me.username_;

            printf("\n  My username: %s\n", me.username_.c_str());
            printf("  Link: %s\n", tMeLink.c_str());

            profilePhoto = std::move(me.profile_photo_);
        },
        [](td::td_api::error& err) {
            TDLPP_LOG_FATAL("getMe error: %s", err.message_.c_str());
            return 1;
        },
        [](auto& unknown) {
            TDLPP_LOG_FATAL("getMe returned: %s", TDLPP_TD_ID_NAME(unknown.get_id()));
            return 1;
        }
    ));

    // Download profile photo and print path to it. Photo will be downloaded every time program executed
    // To prevent it enable use_message_database_ in td::td_api::tdlibParameters when send params to tdlib
    auto photoPromise = handler->Execute<td::td_api::downloadFile>(profilePhoto->big_->id_, 1, 0, 0, true);

    td::td_api::downcast_call(*photoPromise->GetResponse(), tdlpp::overloaded(
        [](td::td_api::file& photo) {
            printf("  Profile photo: %s\n\n", photo.local_->path_.c_str());
        },
        [](auto&) {}
    ));


    return 0;
}