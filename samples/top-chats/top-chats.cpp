
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
    longPoll->ExecuteAsync();

    
    if (!auth->IsAuthorized()) {
        auth->WaitAuthorized();

        if (auth->GetRetriesCount() >= TDLPP_MAX_AUTH_RETRIES) {
            return 1;
        }
    }


    std::vector<td::td_api::int53> chatIds;

    // Get top 5 chats
    auto chatsPromise = handler->ExecuteSync<td::td_api::getChats>(td::td_api::make_object<td::td_api::chatListMain>(), 5);

    td::td_api::downcast_call(*chatsPromise, tdlpp::overloaded(
        [&](td::td_api::chats& chats) {
            chatIds = chats.chat_ids_;
        },
        [](auto&) {}
    ));

    printf("\n  Top 5 chats are:\n");


    // Print chat titles
    for (int i = 0; i < chatIds.size(); i++) {
        auto chatPromise = handler->ExecuteSync<td::td_api::getChat>(chatIds[i]);

        td::td_api::downcast_call(*chatPromise, tdlpp::overloaded(
            [&](td::td_api::chat& chat) {
                printf("    %s\n", chat.title_.c_str());
            },
            [](auto&) {}
        ));
    }

    printf("\n");

    return 0;
}