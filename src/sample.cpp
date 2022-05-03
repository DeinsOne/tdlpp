#include <cstdio>
#include <algorithm>

#include <tdlpp/tdlpp.hpp>
#include <tdlpp/auth/DefaultAuth.hpp>

int main(int argc, char** argv) {
    auto auth = tdlpp::auth::DefaultAuth::create();
    auto handler = tdlpp::base::TdlppHandler::create(auth);

    handler->SetCallback<td::td_api::updateNewChat>([](td::td_api::updateNewChat) { });
    handler->SetCallback<td::td_api::updateChatTitle>([](td::td_api::updateChatTitle) { });

    auto poll = tdlpp::poll::LongPoll::create(handler);
    auto manager = poll->ExecuteAsync();

    if (!auth->IsAuthorized())
        auth->WaitAuthorized();


    std::string deletedMessagesChatTitle = "Deleted Messages";

    // Get id of deleted messages chat

    std::int32_t parsedChatsCount = 0;
    std::int32_t totalChatsCount = 1;
    std::int64_t deletedMessagesChatId = 0;
    bool chatFound = false;

    // auto a = "[02:49:42.593] [VERB] tid:535352";

    while (parsedChatsCount < totalChatsCount && !chatFound) {
        auto chatsPromise = handler->Execute(td::td_api::make_object<td::td_api::getChats>(
            td::td_api::make_object<td::td_api::chatListMain>(), 1000
        ));

        if (chatsPromise->GetResponse()->get_id() != td::td_api::error::ID) {
            totalChatsCount = static_cast<td::td_api::chats&>(*chatsPromise->GetResponse()).total_count_;
            // parsedChatsCount += static_cast<td::td_api::chats&>(*chatsPromise->GetResponse()).chat_ids_.size();

            printf("  chatsPromise parse %d chats\n", static_cast<td::td_api::chats&>(*chatsPromise->GetResponse()).chat_ids_.size());
            for (auto chatId : static_cast<td::td_api::chats&>(*chatsPromise->GetResponse()).chat_ids_) {
                parsedChatsCount++;

                // auto chatPromise = handler->Execute(td::td_api::make_object<td::td_api::getChat>((std::int64_t)chatId));

                // if (chatPromise->GetResponse()->get_id() != td::td_api::error::ID) {
                //     if (static_cast<td::td_api::chat&>(*chatsPromise->GetResponse()).title_ == deletedMessagesChatTitle) {
                //         printf("  Deleted messages chat found\n");
                //         deletedMessagesChatId = static_cast<td::td_api::chat&>(*chatsPromise->GetResponse()).id_;
                //         chatFound = true;
                //         break;
                //     }
                // }
            }

            continue;
        }

        printf("  ERROR: chatsPromise response type %d\n", chatsPromise->GetResponse()->get_id());
    }

    printf("Chats count %d/%d\n", parsedChatsCount, totalChatsCount);


    // Create new group for deleted messages if not found

    // auto groupCreatePromise = handler->Execute(td::td_api::make_object<td::td_api::createNewSupergroupChat>(
    //     deletedMessagesChatTitle, false,
    //     "Chat containing deleted messages from all users. Contains expiered media and messages from secret chats",
    //     td::td_api::make_object<td::td_api::chatLocation>(), false
    // ));

    // if (groupCreatePromise->GetResponse()->get_id() != td::td_api::error::ID) {
    //     printf("  Chat 'Deleted Messages' created %d\n", static_cast<td::td_api::chat&>(*groupCreatePromise->GetResponse()).id_);
    // }
    // else {
    //     printf("  ERROR: cannot create group\n");
    // }

    // std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    return 0;
}
