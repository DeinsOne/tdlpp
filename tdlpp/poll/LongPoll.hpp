
#ifndef tdlpp_LongPoll
#define tdlpp_LongPoll

#include <tdlpp/core.hpp>
#include <tdlpp/router/Router.hpp>
#include <tdlpp/base/Handler.hpp>

namespace tdlpp { namespace poll {

    // Class executing poll, performing program's flow 
    class LongPoll : public TdlppBase {
    public:
        /**
         * @brief A factory method
         * 
         * @return std::shared_ptr<LongPoll> New instance of 'LongPoll'
         */
        static std::shared_ptr<LongPoll> create(const std::shared_ptr<auth::IAuth>& auth, const std::shared_ptr<base::TdlppHandler>& handler);

    public:
        LongPoll(const std::shared_ptr<auth::IAuth>& auth, const std::shared_ptr<base::TdlppHandler>& handler);
        ~LongPoll();

        /**
         * @brief A factory method that executes polling thread
         */
        void ExecuteAsync();

        /**
         * @brief A method to execute polling in parent thread, will block the thread
        */
        void ExecuteSync();

    public:
        void Resume();
        void Pause();
        bool IsRunning() { return running; }

    private:
        std::shared_ptr<poll::LongPoll> this_;
        std::shared_ptr<router::Router> router_;
        std::shared_ptr<base::TdlppHandler> handler_;
        std::shared_ptr<auth::IAuth> auth_;

        bool running;
        bool destroy;
        std::thread asyncPollWorker;
        std::condition_variable destroyLock;

        /**
         * @brief A callback function that is called when a response is received
         * 
         * @param response Response to handle
         */
        void handlingResponse(td::ClientManager::Response response);
    };

} // namespace poll
} // namespace tdlpp

#endif // tdlpp_LongPoll
