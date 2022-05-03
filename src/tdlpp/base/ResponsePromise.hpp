
#ifndef tdlpp_ResponsePromise
#define tdlpp_ResponsePromise

#include <tdlpp/core.hpp>
#include <condition_variable>
#include <functional>

namespace tdlpp { namespace base {

    class BindingHandler;

    class IResponsePromise {
        friend BindingHandler;
    public:
        virtual std::uint64_t GetRID() = 0;
        virtual std::int32_t getTdTypeId() = 0;

        virtual std::shared_ptr<td::td_api::Object> GetResponse() = 0;

    private:
        virtual void SetResponse(SharedObjectPtr<td::td_api::Object> response_) = 0;

    };



    template<typename TdFunction>
    class ResponsePromise : public IResponsePromise {
    public:
        static std::shared_ptr<ResponsePromise> create(const std::uint64_t& rid) {
            return std::make_shared<tdlpp::base::ResponsePromise<TdFunction>>(rid);
        }
        static std::shared_ptr<ResponsePromise> create(const std::uint64_t& rid, const std::function<void(SharedObjectPtr<td::td_api::Object>)>& callback) {
            return std::make_shared<tdlpp::base::ResponsePromise<TdFunction>>(rid, callback);
        }

    public:
        ResponsePromise(const std::uint64_t& requestId) : rid(requestId) {
            TDLPP_LOG_VERBOSE("tdlpp::router::ResponsePromise::constructor");
        }
        ResponsePromise(const std::uint64_t& requestId, const std::function<void(SharedObjectPtr<td::td_api::Object>)>& callback_)
            : rid(requestId), callback(callback_) 
        {
            TDLPP_LOG_VERBOSE("tdlpp::router::ResponsePromise::constructor");
        }

        virtual std::uint64_t GetRID() override { return rid; };

        virtual std::int32_t getTdTypeId() override { return TdFunction::ID; };

        virtual std::shared_ptr<td::td_api::Object> GetResponse() override {
            // TDLPP_LOG_DEBUG("tdlpp::base::ResponsePromise::GetResponse rid: %ld", rid);
            if (response) return response;
            TDLPP_LOG_DEBUG("tdlpp::base::ResponsePromise::GetResponse rid: %ld lock, wait response", rid);
            std::mutex _mtx;
            std::unique_lock<std::mutex> ulock(_mtx);
            lock.wait(ulock, [&] { return response != nullptr; });
            TDLPP_LOG_DEBUG("tdlpp::base::ResponsePromise::GetResponse rid: %ld unlock", rid);
            return response;
        }

    private:
        virtual void SetResponse(SharedObjectPtr<td::td_api::Object> response_) override {
            TDLPP_LOG_DEBUG("tdlpp::base::ResponsePromise::GetResponse %s rid: %ld", TDLPP_TD_ID_NAME(response_->get_id()), rid);
            response = response_;
            if (callback) {
                TDLPP_LOG_DEBUG("tdlpp::base::ResponsePromise::GetResponse %s trigger callback rid: %ld", TDLPP_TD_ID_NAME(response_->get_id()), rid);
                callback(response);
            }
            lock.notify_all();
        }

    private:
        std::uint64_t rid;
        std::shared_ptr<td::td_api::Object> response;

        std::function<void(SharedObjectPtr<td::td_api::Object>)> callback;
        std::condition_variable lock;
    };


} // namespace base
} // namespace tdlpp

#endif // tdlpp_ResponsePromise
