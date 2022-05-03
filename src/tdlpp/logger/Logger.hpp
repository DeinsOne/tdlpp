
#ifndef tdlpp_Logger
#define tdlpp_Logger

#include <memory>
#include <tdlpp/logger/IdNameBinding.hpp>

#if defined(TDLPP_ENABLE_OBJECT_LOGGING) || defined(TDLPP_ENABLE_FILE_LOGGING) || defined(TDLPP_ENABLE_CONSOLE_LOGGING)
    #define __TDLPP_LOGGING_ENABLE
#endif

#if defined(__TDLPP_LOGGING_ENABLE)
    #include <tdlpp/logger/plog/Log.h>
    #include <tdlpp/logger/plog/Init.h>

    #include <tdlpp/logger/plog/Appenders/ColorConsoleAppender.h>
    #include <tdlpp/logger/plog/Appenders/RollingFileAppender.h>

    #include <plog/Record.h>
    #include <plog/Util.h>
    #include <iomanip>
#endif

#if defined(__TDLPP_LOGGING_ENABLE)
namespace tdlpp { namespace log {

    template<bool useUtcTime>
    class LogFormatterImpl {
    public:

        static plog::util::nstring header() {
            // return PLOG_NSTR("Header\n");
            return plog::util::nstring();
        }

        static plog::util::nstring format(const plog::Record& record) {
            tm t;
            useUtcTime ? plog::util::gmtime_s(&t, &record.getTime().time) : plog::util::localtime_s(&t, &record.getTime().time);

            plog::util::nostringstream column1;
            column1 << PLOG_NSTR("[") << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_hour << PLOG_NSTR(":") << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_min << PLOG_NSTR(":") << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_sec << PLOG_NSTR(".") << std::setfill(PLOG_NSTR('0')) << std::setw(3) << static_cast<int>(record.getTime().millitm) << PLOG_NSTR("] ");
            column1 << PLOG_NSTR("[") << std::left << severityToString(record.getSeverity()) << PLOG_NSTR("] ");
            column1 << PLOG_NSTR("tid:") << record.getTid();

            plog::util::nostringstream raw;
            raw << std::setw(33) << std::left << std::setfill(PLOG_NSTR(' ')) << PLOG_NSTR(column1.str()) << PLOG_NSTR(" | ");
            raw << record.getMessage() << PLOG_NSTR("\n");

            return raw.str();
        }
    };

    class LogFormatter : public LogFormatterImpl<false> {};
    class LogFormatterUtcTime : public LogFormatterImpl<true> {};


    class Logger {
    public:
        static Logger* Get() {
            static Logger* this_ = new Logger();
            return this_;
        }

        template<typename... TArgs>
        void AddLog(const plog::Severity& level, TArgs... args) {
            PLOG_(0, level).printf(args...);
            PLOG_(1, level).printf(args...);
        }

        template<typename... TArgs>
        void AddObjectLog(TArgs... args) {
            PLOG_(2, plog::Severity::verbose).printf(args...);
        }

    private:
        Logger() {
            #ifdef TDLPP_ENABLE_CONSOLE_LOGGING
                consoleAppender = std::make_shared<plog::ColorConsoleAppender<LogFormatter>>();
                plog::init<0>((plog::Severity)TDLPP_CONSOLE_LOGGING_LEVEL, consoleAppender.get());
            #endif

            #ifdef TDLPP_ENABLE_FILE_LOGGING
                rollingFileAppender = std::make_shared<plog::RollingFileAppender<LogFormatter>>("tdlpp.log", TDLPP_FILE_LOGGING_MAX_FILE_SIZE, TDLPP_FILE_LOGGING_MAX_FILES);
                plog::init<1>((plog::Severity)TDLPP_FILE_LOGGING_LEVEL, rollingFileAppender.get());
                // plog::get<0>()->addAppender(rollingFileAppender.get());
            #endif

            #ifdef TDLPP_ENABLE_OBJECT_LOGGING
                objectFileAppender = std::make_shared<plog::RollingFileAppender<LogFormatter>>("objects.log", TDLPP_OBJECT_LOGGING_MAX_FILE_SIZE, TDLPP_OBJECT_LOGGING_MAX_FILES);
                plog::init<2>((plog::Severity)plog::Severity::verbose, objectFileAppender.get());
            #endif
        }

        #ifdef TDLPP_ENABLE_CONSOLE_LOGGING
            std::shared_ptr<plog::ConsoleAppender<LogFormatter>> consoleAppender;
        #endif

        #ifdef TDLPP_ENABLE_FILE_LOGGING
            std::shared_ptr<plog::RollingFileAppender<LogFormatter>> rollingFileAppender;
        #endif

        #ifdef TDLPP_ENABLE_OBJECT_LOGGING
            std::shared_ptr<plog::RollingFileAppender<LogFormatter>> objectFileAppender;
        #endif
    };

} // namespace log
} // namespace tdlpp
#endif // __TDLPP_LOGGING_ENABLE

#define TDLPP_TD_ID_NAME(x)             tdlpp::log::__IdNameBinding(x).c_str()


#if !defined(__TDLPP_LOGGING_ENABLE)
    #define TDLPP_LOG_VERBOSE(...)
    #define TDLPP_LOG_DEBUG(...)
    #define TDLPP_LOG_INFO(...)
    #define TDLPP_LOG_WARNING(...)
    #define TDLPP_LOG_ERROR(...)
    #define TDLPP_LOG_FATAL(...)
    #define TDLPP_LOG_NONE(...)

    #define TDLPP_OBJECT_LOG(...)
#else
    #define TDLPP_LOG_VERBOSE(...)      tdlpp::log::Logger::Get()->AddLog(plog::verbose, __VA_ARGS__)
    #define TDLPP_LOG_DEBUG(...)        tdlpp::log::Logger::Get()->AddLog(plog::debug, __VA_ARGS__)
    #define TDLPP_LOG_INFO(...)         tdlpp::log::Logger::Get()->AddLog(plog::info, __VA_ARGS__)
    #define TDLPP_LOG_WARNING(...)      tdlpp::log::Logger::Get()->AddLog(plog::warning, __VA_ARGS__)
    #define TDLPP_LOG_ERROR(...)        tdlpp::log::Logger::Get()->AddLog(plog::error, __VA_ARGS__)
    #define TDLPP_LOG_FATAL(...)        tdlpp::log::Logger::Get()->AddLog(plog::fatal, __VA_ARGS__)
    #define TDLPP_LOG_NONE(...)         tdlpp::log::Logger::Get()->AddLog(plog::none, __VA_ARGS__)

    #define TDLPP_OBJECT_LOG(...)       tdlpp::log::Logger::Get()->AddObjectLog(__VA_ARGS__)
#endif // __TDLPP_LOGGING_ENABLE



#endif // tdlpp_Logger
