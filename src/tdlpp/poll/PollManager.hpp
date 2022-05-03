
#ifndef tdlpp_PollManager
#define tdlpp_PollManager

#include <tdlpp/poll/LongPoll.hpp>

#include <condition_variable>
#include <atomic>
#include <thread>

namespace tdlpp { namespace poll {

    class PollManager : public TdlppBase {
    public:
        static std::shared_ptr<PollManager> create(const std::shared_ptr<LongPoll>& poll) {
            return std::make_shared<PollManager>(poll);
        }

    public:
        PollManager(const std::shared_ptr<LongPoll>& longPoll) : poll(longPoll), active(true), destroy(false) {
            TDLPP_LOG_VERBOSE("tdlpp::poll::PollManager::constructor");
            auto func = [&]() {
                while (!destroy.load()) {
                    if (IsActive()) {
                        if (!poll->handler_->auth_->IsAuthorized()) {
                            processResponse(longPoll->router_->Receive(10));
                        }
                        else {
                            while (true) {
                                auto response = longPoll->router_->Receive(0);
                                if (response.object) processResponse(std::move(response));
                                else break;
                            }
                        }
                    }

                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }

                printf("tdlpp::PollManager exit the loop\n");
                destroy = false;
                destroyLock.notify_all();
            };

            worker = std::thread(func);
            worker.detach();
        }

        ~PollManager() {
            TDLPP_LOG_VERBOSE("tdlpp::poll::PollManager::distructor");
            active = false, destroy = true;

            std::mutex _mtx;
            std::unique_lock<std::mutex> lock(_mtx);
            destroyLock.wait(lock, [&]() { return !destroy.load(); } );
            TDLPP_LOG_VERBOSE("tdlpp::poll::PollManager::distructor lock release");
        }

        void Resume() { active = true; }
        void Pause() { active = false; }
        bool IsActive() { return active.load(); }

    private:
        std::atomic<bool> active;
        std::thread worker;

        std::atomic<bool> destroy;
        std::condition_variable destroyLock;

        std::shared_ptr<LongPoll> poll;


        void processResponse(td::ClientManager::Response response) {
            if (!response.object) return;

            TDLPP_LOG_DEBUG("tdlpp::poll::PollManager::processResponse");
            poll->handler_->Handle(response.request_id, std::move(response.object));
        }
    };


    std::shared_ptr<PollManager> LongPoll::ExecuteAsync() {
        TDLPP_LOG_INFO("tdlpp::poll::LongPoll::ExecuteAsync run polling thread");
        return PollManager::create(this_);
    }

} // namespace base
} // namespace tdlpp

#endif // tdlpp_PollManager
