
#ifndef tdlpp_BindingHandler
#define tdlpp_BindingHandler

#include <tdlpp/core.hpp>
#include <tdlpp/base/ResponsePromise.hpp>
#include <unordered_map>

namespace tdlpp { namespace base {

    class BindingHandler : public TdlppBase {
    public:
        static std::shared_ptr<BindingHandler> create() {
            return std::make_shared<tdlpp::base::BindingHandler>();
        }

    public:
        void Handler(const std::uint64_t& requestId, const SharedObjectPtr<td::td_api::Object>& object) {
            TDLPP_LOG_DEBUG("tdlpp::base::BindingHandler::Handler %s rid: %ld", TDLPP_TD_ID_NAME(object->get_id()), requestId);
            std::lock_guard<std::mutex> _lock(promisesLock);

            auto promise = promises.find(requestId);
            if (promise != promises.end()) {
                promise->second->SetResponse(object);
                promises.erase(promise);
                return;
            }
        }

        template<typename TdFunction>
        void Listen(const std::shared_ptr<ResponsePromise<TdFunction>>& promise) {
            TDLPP_LOG_DEBUG("tdlpp::base::BindingHandler::Listen %s rid: %ld", TDLPP_TD_ID_NAME(TdFunction::ID), promise->GetRID());
            std::lock_guard<std::mutex> _lock(promisesLock);
            promises[promise->GetRID()] = promise;
        }

    private:
        // Promises contains ordered map of request ids and appropriate promises to them: std::unordered_map<rid; promise> 
        std::unordered_map<std::uint64_t, SharedObjectPtr<IResponsePromise>> promises;
        std::mutex promisesLock;
    };

} // namespace base
} // namespace tdlpp


#endif // tdlpp_BindingHandler
