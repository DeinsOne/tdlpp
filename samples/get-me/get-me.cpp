
#include <tdlpp/tdlpp.hpp>
#include <tdlpp/auth/DefaultAuth.hpp>

int main(int argc, char** argv) {

    auto auth = tdlpp::auth::DefaultAuth::create(
        -1,             // api id
        "",             // api hash
        "sample-shared-tdlib"  // downloading dir
    );

    auto handler = tdlpp::base::TdlppHandler::create();
    auto longPoll = tdlpp::poll::LongPoll::create(auth, handler);
    longPoll->ExecuteAsync();


    if (!auth->IsAuthorized()) {
        auth->WaitAuthorized();

        if (auth->GetRetriesCount() >= TDLPP_MAX_AUTH_RETRIES) {
            return 1;
        }
    }


    // Get telegram user link prefix
    auto tMeLinkPromise = handler->ExecuteSync<td::td_api::getOption>("t_me_url");
    std::string tMeLink = tdlpp::cast_object<td::td_api::optionValueString>(tMeLinkPromise)->value_;


    // Get info about me
    auto mePromise = handler->ExecuteSync<td::td_api::getMe>();
    auto me = tdlpp::cast_object<td::td_api::user>(mePromise);

    auto profilePhoto = std::move(me->profile_photo_);
    tMeLink += me->usernames_->active_usernames_.at(0);

    printf("\n  My username: %s\n", me->usernames_->active_usernames_.at(0).c_str());
    printf("  Link: %s\n", tMeLink.c_str());


    // Download profile photo and print path to it. Photo will be downloaded every time program executed
    // To prevent it enable use_message_database_ in td::td_api::tdlibParameters when send params to tdlib
    auto photoPromise = handler->ExecuteSync<td::td_api::downloadFile>(profilePhoto->big_->id_, 1, 0, 0, true);
    auto photo = tdlpp::cast_object<td::td_api::file>(photoPromise);

    printf("  Profile photo: %s\n\n", photo->local_->path_.c_str());


    return 0;
}