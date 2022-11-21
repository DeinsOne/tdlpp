#include <tdlpp/router/Router.hpp>

std::shared_ptr<tdlpp::router::Router> tdlpp::router::Router::create() {
  return std::make_shared<tdlpp::router::Router>();
}

tdlpp::router::Router::Router() : requestId(0) {
  TDLPP_LOG_VERBOSE("constructor");
  td::ClientManager::execute(td::td_api::make_object<td::td_api::setLogVerbosityLevel>(1));
  clientManager = std::make_shared<td::ClientManager>();
  clientId = clientManager->create_client_id();
  Send(td::td_api::make_object<td::td_api::getOption>("version"));
}

td::ClientManager::Response tdlpp::router::Router::Receive(const double& secondsTimeout) noexcept {
  auto reponse = clientManager->receive(secondsTimeout);

  if (reponse.object) {
    td::td_api::downcast_call(*reponse.object, overloaded([&](auto& casted) {
      TDLPP_LOG_DEBUG("Receive rid:%ld %s", reponse.request_id, TDLPP_TD_ID_NAME(casted.get_id()));
      TDLPP_OBJECT_LOG("Receive %ld %s", reponse.request_id, td::td_api::to_string(casted).c_str());
    }));
  }

  return reponse;
}

td::ClientManager::RequestId tdlpp::router::Router::Send(UniqueObjectPtr<td::td_api::Function> function, const td::ClientManager::RequestId& rid) noexcept {
  std::lock_guard<std::mutex> lock(writingLock);
  const std::uint64_t requestId = (rid < 0 ? _getRequestId() : rid);

  td::td_api::downcast_call(*function, overloaded([&](auto& casted) {
    TDLPP_LOG_DEBUG("Send rid:%ld %s", requestId, TDLPP_TD_ID_NAME(casted.get_id()));
    TDLPP_OBJECT_LOG("Send %ld %s", requestId, td::td_api::to_string(casted).c_str());
  }));

  clientManager->send(clientId, requestId, std::move(function));
  return requestId;
}

