
#ifndef tdlpp_UpdateCallbacksHandler
#define tdlpp_UpdateCallbacksHandler

#include <tdlpp/core.hpp>
#include <memory>

#include <functional>

#include <unordered_map>
#include <vector>

namespace tdlpp { namespace base {

    class UpdateCallbacksHandler : public TdlppBase {
    public:
        static std::shared_ptr<UpdateCallbacksHandler> create() {
            auto handler = std::make_shared<tdlpp::base::UpdateCallbacksHandler>();
            handler->this_ = handler;
            return handler;
        }

    public:
        UpdateCallbacksHandler() {
            TDLPP_LOG_VERBOSE("tdlpp::router::UpdateCallbacksHandler::constructor");
        }

        template<typename TdUpdate>
        std::shared_ptr<UpdateCallbacksHandler> Listen(const std::function<void(TdUpdate)>& func, const bool& overwrite = false) {
            if (overwrite) RemoveCallbacks<TdUpdate>();

            TDLPP_LOG_DEBUG("tdlpp::base::UpdateCallbacksHandler::Listen %s overwrite:%d", TDLPP_TD_ID_NAME(TdUpdate::ID), overwrite);
            callbacks[TdUpdate::ID].emplace_back(new std::function<void(TdUpdate)>(func));
            return this_;
        }


        template<typename TdUpdate>
        void Handle(const SharedObjectPtr<TdUpdate>& objectPtr) {
            TDLPP_LOG_DEBUG("tdlpp::base::UpdateCallbacksHandler::Handle %s", TDLPP_TD_ID_NAME(objectPtr->get_id()));

            auto current = callbacks.find(objectPtr->get_id());

            if (current != callbacks.end()) {
                td::td_api::downcast_call(*objectPtr, overloaded([&](auto& casted) {
                    for (int i = 0; i < current->second.size(); i++) {
                        auto callback = reinterpret_cast<std::function<void(decltype(casted))>*>(current->second.at(i));
                        if (callback) {
                            TDLPP_LOG_DEBUG("tdlpp::base::UpdateCallbacksHandler::Handle callback[%d]", i);
                            callback->operator()(casted);
                        }
                    }
                }));
            }
        }


        template<typename TdUpdate>
        void RemoveCallbacks() {
            TDLPP_LOG_DEBUG("tdlpp::base::UpdateCallbacksHandler::RemoveCallbacks %s", TDLPP_TD_ID_NAME(TdUpdate::ID));
            callbacks.erase(TdUpdate::ID);
        }

    private:
        std::shared_ptr<UpdateCallbacksHandler> this_;
        std::unordered_map<std::int32_t,std::vector<void*>> callbacks;
    };

} // namespace base
} // namespace tdlpp

#endif // tdlpp_UpdateCallbacksHandler
