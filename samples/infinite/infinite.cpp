
#include <tdlpp/tdlpp.hpp>
#include <tdlpp/auth/DefaultAuth.hpp>

int main(int argc, char** argv) {

  // Authentication object
  auto auth = tdlpp::auth::DefaultAuth::create(
    -1,             // api id
    "",             // api hash
    "sample-shared-tdlib"  // downloading dir
  );

  auto handler = tdlpp::base::TdlppHandler::create();
  auto longPoll = tdlpp::poll::LongPoll::create(auth, handler);


  handler->SetCallback<td::td_api::updateNewMessage>(false, [&](td::td_api::updateNewMessage& update) {
    bool isUser = true;
    std::uint64_t senderId = -1;
    std::string title = "UNKNOWN";

    // Determine who is a sender
    td::td_api::downcast_call(*update.message_->sender_id_, tdlpp::overloaded(
      [&](td::td_api::messageSenderUser& sender) {
        isUser = true;
        senderId = sender.user_id_;
      },
      [&](auto&) {}
    ));

    // Get username
    try {
      if (isUser && senderId) {
        auto userPointer = handler->ExecuteSync<td::td_api::getUser>(senderId);
        auto user = tdlpp::cast_object<td::td_api::user>(userPointer);
        if (user->usernames_ && user->usernames_->active_usernames_.size()) title = user->usernames_->active_usernames_.at(0);
        printf("  User new message '%s': mid %ld\n", title.c_str(), update.message_->id_);
      }
    } catch (std::exception& error) {
      TDLPP_LOG_ERROR("Cannot acces sender details: %s", error.what());
    }

  });

  handler->SetCallback<td::td_api::updateUserStatus>(false, [&](td::td_api::updateUserStatus& update) {
    auto user = handler->ExecuteSync<td::td_api::getUser, td::td_api::user>(update.user_id_);
    std::string username = "UNKNOWN";

    if (user->usernames_ && user->usernames_->active_usernames_.size())
      username = user->usernames_->active_usernames_.at(0);


    if (!update.status_) return;

    td::td_api::downcast_call(*update.status_, tdlpp::overloaded(
      [&](td::td_api::userStatusOnline& status) {
        printf("  User went online '%s'\n", username.c_str());
      },
      [&](td::td_api::userStatusOffline& status) {
        printf("  User went offline '%s'\n", username.c_str());
      },
      [&](auto& status) {}
    ));
  });


  longPoll->ExecuteSync();

  return 0;
}
