
#ifndef tdlpp_ResponsePromise
#define tdlpp_ResponsePromise

#include <tdlpp/core.hpp>
#include <condition_variable>
#include <functional>

namespace tdlpp { namespace base {

    /**
     * @brief Interface class to provide thread blocking waiting for response
    */
    class IResponsePromise {
    public:
        // Get request id
        virtual std::uint64_t GetRID() = 0;

        // Get id of td function
        virtual std::int32_t getTdTypeId() = 0;

        // Waiting for response to be set. Locks executing thread
        virtual std::shared_ptr<td::td_api::Object> GetResponse() = 0;

        // Set promise response. Will call callback in executing thread
        virtual void SetResponse(SharedObjectPtr<td::td_api::Object> response_) = 0;

        // Invoke promise callback in executor thread
        virtual void InvokeCallback() = 0;
    };


    template<typename TdFunction>
    class ResponsePromise : public IResponsePromise {
    public:
        /**
         * @brief A factory method
         * 
         * @param rid Request id of thrown request associated with this promise
         * 
         * @return std::shared_ptr<BindingHandler> New instance of 'BindingHandler'
         */
        static std::shared_ptr<ResponsePromise> create(const std::uint64_t& rid) {
            return std::make_shared<tdlpp::base::ResponsePromise<TdFunction>>(rid);
        }

        /**
         * @brief A factory method
         * 
         * @param rid Request id of thrown request associated with this promise
         * @param callback Calback to be called on response handling
         * 
         * @return std::shared_ptr<BindingHandler> New instance of 'BindingHandler'
         */
        static std::shared_ptr<ResponsePromise> create(const std::uint64_t& rid, const std::function<void(SharedObjectPtr<td::td_api::Object>)>& callback) {
            return std::make_shared<tdlpp::base::ResponsePromise<TdFunction>>(rid, callback);
        }

    public:
        ResponsePromise(const std::uint64_t& requestId) : rid(requestId) {
            TDLPP_LOG_VERBOSE("constructor");
            TDLPP_LOG_VERBOSE("constructor");
        }
        ResponsePromise(const std::uint64_t& requestId, const std::function<void(SharedObjectPtr<td::td_api::Object>)>& callback_)
            : rid(requestId), callback(callback_) 
        {
            TDLPP_LOG_VERBOSE("constructor");
            TDLPP_LOG_VERBOSE("constructor");
        }

        virtual std::uint64_t GetRID() override { return rid; };
        virtual std::int32_t getTdTypeId() override { return TdFunction::ID; };

        virtual std::shared_ptr<td::td_api::Object> GetResponse() override {
            if (response) return response;
            TDLPP_LOG_DEBUG("rid:%ld lock, wait response", rid);
            TDLPP_LOG_DEBUG("rid:%ld lock, wait response", rid);
            std::mutex _mtx;
            std::unique_lock<std::mutex> ulock(_mtx);
            lock.wait(ulock, [&] { return response != nullptr; });
            TDLPP_LOG_DEBUG("rid:%ld unlock", rid);
            TDLPP_LOG_DEBUG("rid:%ld unlock", rid);
            return response;
        }

        virtual void SetResponse(SharedObjectPtr<td::td_api::Object> response_) override {
            TDLPP_LOG_DEBUG("rid:%ld %s", rid, TDLPP_TD_ID_NAME(response_->get_id()));
            TDLPP_LOG_DEBUG("rid:%ld %s", rid, TDLPP_TD_ID_NAME(response_->get_id()));
            response = response_;
            lock.notify_all();
        }

        virtual void InvokeCallback() override {
            if (callback) {
                TDLPP_LOG_DEBUG("%s trigger callback rid:%ld", TDLPP_TD_ID_NAME(response->get_id()), rid);
                callback(response);
            }
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
