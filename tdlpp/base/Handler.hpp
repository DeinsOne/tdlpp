
#ifndef tdlpp_Handler
#define tdlpp_Handler

#include <tdlpp/auth/IAuth.hpp>
#include <tdlpp/router/Router.hpp>

#include <tdlpp/base/ResponsePromise.hpp>
#include <tdlpp/base/UpdateCalbacksHandler.hpp>

#include <functional>
#include <thread>
#include <queue>

#include <unordered_set>

namespace tdlpp { namespace poll {
    class LongPoll;
} // namespace poll
} // namespace tdlpp

namespace tdlpp { namespace base {

    // Controles processing of incoming responses
    class TdlppHandler : public TdlppBase {
        friend poll::LongPoll;
    public:
        /**
         * @brief A factory method
         * 
         * @return std::shared_ptr<TdlppHandler> New instance of 'TdlppHandler'
         */
        static std::shared_ptr<TdlppHandler> create(const std::shared_ptr<auth::IAuth>& auth_);

    public:
        TdlppHandler(const std::shared_ptr<auth::IAuth>& auth__);

        ~TdlppHandler();

        /**
         * @brief Set a callback for a specific td update
         * 
         * @tparam TdUpdate Inherited from td::td_api::Update
         * @param func Callback function
         * @param overwrite Controles erasing all other update callbacks
         * @return std::shared_ptr<TdlppHandler> Pointer to this. Provides chaining
         */
        template<typename TdUpdate>
        std::shared_ptr<TdlppHandler> SetCallback(const bool& overwrite, const std::function<void(TdUpdate&)>& func) noexcept {
            TDLPP_LOG_DEBUG("%s", TDLPP_TD_ID_NAME(TdUpdate::ID));
            if (overwrite) updatesHandler->RemoveCallbacks<TdUpdate>();
            updatesHandler->Listen<TdUpdate>(func);
            return this_;
        }


        /**
         * @brief Execute td function synchronously and return the response
         * 
         * @tparam TdFunction Inherited from td::td_api::Function
         * @tparam TArgs Variadic arguments for td function constructor
         * @return std::shared_ptr<td::td_api::Object> Plain telegram response object
         */
        template<typename TdFunction, typename... TArgs>
        std::shared_ptr<td::td_api::Object> ExecuteSync(TArgs... args) noexcept {
            const auto rid = router_->ReserveId();
            TDLPP_LOG_DEBUG("rid:%ld %s", rid, TDLPP_TD_ID_NAME(TdFunction::ID));

            auto promise = ResponsePromise<TdFunction>::create(rid);
            responsePromises.insert({rid, promise});

            router_->Send(td::td_api::make_object<TdFunction>(std::move(args)...), rid);
            return promise->GetResponse();
        }


        /**
         * @brief Execute td function synchronously and return the response
         * 
         * @tparam TdFunction Inherited from td::td_api::Function
         * @tparam TdResult Inherited from td::td_api::Object, represents type to convert response
         * @tparam TArgs Variadic arguments for td function constructor
         * @return std::shared_ptr<TdResult> Converted response object. If plain object is not convertable
         * to TdResult will throw invalid_argument exception
         */
        template<typename TdFunction, typename TdResult, typename... TArgs>
        std::shared_ptr<TdResult> ExecuteSync(TArgs... args) {
            auto plainObjectPtr = ExecuteSync<TdFunction>(std::move(args)...);
            return tdlpp::cast_object<TdResult>(plainObjectPtr);
        }


        /**
         * @private
         * @brief Execute td function asynchronously
         * 
         * @tparam TdFunction Inherited from td::td_api::Function
         * @param function Td function object pointer
         * @param handler Callback function to be called on response
         */
        template<typename TdFunction>
        std::shared_ptr<tdlpp::base::IResponsePromise> ExecuteAsync(UniqueObjectPtr<TdFunction> function, const std::function<void(SharedObjectPtr<td::td_api::Object>)>& handler) noexcept {
            const auto rid = router_->ReserveId();

            TDLPP_LOG_DEBUG("rid:%ld %s", rid, TDLPP_TD_ID_NAME(TdFunction::ID));
            auto promise = ResponsePromise<TdFunction>::create(rid, handler);
            responsePromises.insert({rid, promise});

            router_->Send(std::move(function), rid);
            return promise;
        }

    private:
        std::shared_ptr<TdlppHandler> this_;
        std::shared_ptr<auth::IAuth> auth_;

        std::shared_ptr<router::Router> router_;
        std::shared_ptr<UpdateCallbacksHandler> updatesHandler;
        // std::shared_ptr<BindingHandler> binding;

        std::thread worker;


        // Updates queue in correct order
        std::queue<std::pair<std::uint64_t,SharedObjectPtr<td::td_api::Object>>> updatesQueue;
        std::condition_variable updatesQueueNotifier;
        std::mutex updatesQueueMtx;

        // Promises waiting to be resolved
        std::unordered_map<std::uint64_t,SharedObjectPtr<IResponsePromise>> responsePromises;



        bool destroy;
        std::condition_variable destroyLock;

        /**
         * @brief Pushes object to processing queue
         * 
         * @param requestId Respons's request id 
         * @param object Response object
         */
        void PushToQueue(const std::uint64_t& requestId, UniqueObjectPtr<td::td_api::Object> object) noexcept;

        /**
         * @brief Handle incoming response
         * 
         * @param requestId Response's request id 
         * @param object Response object
         */
        void Handle(const std::uint64_t& requestId, SharedObjectPtr<td::td_api::Object> object);

        void SetRouter(const std::shared_ptr<router::Router>& router__) noexcept { router_ = router__; }

    };

} // namespace base
} // namespace tdlpp

#endif // tdlpp_Handler
