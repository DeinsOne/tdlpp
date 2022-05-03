
#ifndef tdlpp_LongPoll
#define tdlpp_LongPoll

#include <tdlpp/core.hpp>
#include <tdlpp/router/Router.h>
#include <tdlpp/base/Handler.hpp>

namespace tdlpp { namespace poll {

    class PollManager;

    class LongPoll : public TdlppBase {
        friend poll::PollManager;
    public:
        static std::shared_ptr<LongPoll> create(const std::shared_ptr<base::TdlppHandler>& handler) {
            auto poll = std::make_shared<LongPoll>(handler);
            poll->this_ = poll;
            return poll;
        }

    public:
        LongPoll(const std::shared_ptr<base::TdlppHandler>& handler) : handler_(handler) {
            TDLPP_LOG_VERBOSE("tdlpp::poll::LongPoll::constructor");
            router_ = tdlpp::router::Router::create();
            handler_->SetRouter(router_);
        }

        std::shared_ptr<poll::PollManager> ExecuteAsync();

    private:
        std::shared_ptr<poll::LongPoll> this_;
        std::shared_ptr<router::Router> router_;
        std::shared_ptr<base::TdlppHandler> handler_;
    };

} // namespace poll
} // namespace tdlpp

#endif // tdlpp_LongPoll
