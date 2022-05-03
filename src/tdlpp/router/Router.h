
#ifndef tdlpp_Router
#define tdlpp_Router

#include <tdlpp/core.hpp>
#include <mutex>

namespace tdlpp { namespace router {

    class Router : public TdlppBase {
    public:
        static std::shared_ptr<Router> create() {
            return std::make_shared<tdlpp::router::Router>();
        }

    public:
        Router() : requestId(0) {
            TDLPP_LOG_VERBOSE("tdlpp::router::Router::constructor");
            td::ClientManager::execute(td::td_api::make_object<td::td_api::setLogVerbosityLevel>(1));
            clientManager = std::make_shared<td::ClientManager>();
            clientId = clientManager->create_client_id();
            Send(td::td_api::make_object<td::td_api::getOption>("version"));
        }

        td::ClientManager::Response Receive(const double& secondsTimeout = 0) {
            auto reponse = clientManager->receive(secondsTimeout);

            if (reponse.object) {
                td::td_api::downcast_call(*reponse.object, overloaded([&](auto& casted) {
                    TDLPP_LOG_DEBUG("tdlpp::router::Router::Receive %s rid: %ld", TDLPP_TD_ID_NAME(casted.get_id()), reponse.request_id);
                    TDLPP_OBJECT_LOG("Receive %ld %s", reponse.request_id, td::td_api::to_string(casted).c_str());
                }));
            }

            return reponse;
        }

        td::ClientManager::RequestId Send(UniqueObjectPtr<td::td_api::Function> function) {
            std::lock_guard<std::mutex> lock(writingLock);
            auto rid = _getRequestId();

            if (function) {
                td::td_api::downcast_call(*function, overloaded([&](auto& casted) {
                    TDLPP_LOG_DEBUG("tdlpp::router::Router::Send %s rid: %ld", TDLPP_TD_ID_NAME(casted.get_id()), rid);
                    TDLPP_OBJECT_LOG("Send %ld %s", rid, td::td_api::to_string(casted).c_str());
                }));
            }

            clientManager->send(clientId, rid, std::move(function));
            return rid;
        }

        td::ClientManager::RequestId GetLastRequestId() const { return requestId; }

    private:
        std::shared_ptr<td::ClientManager> clientManager;
        td::ClientManager::ClientId clientId{0};
        td::ClientManager::RequestId requestId{0};

        std::mutex writingLock;

        td::ClientManager::RequestId _getRequestId() { return ++requestId; }
    };

} // namespace router
} // namespace tdlpp

#endif // tdlpp_Router
