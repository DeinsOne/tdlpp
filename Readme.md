# **Tdlpp**

Tdlpp is an async c++ wrapper to interact with Telegram's API tdlib, is used by [Spy-X-telegram](https://github.com/DeinsOne/Spy-X-telegram.git).


## Basic usage

Tdlpp provides interface to be executed in sync or async modes, here is an example:

```c++
// Authentication object handles td::td_api::AuthorizationStateUpdate updates.
// Using DefaultAuth you can specify credentials at compile time, or pass
// default values to set credentials at runtime from console. You should 
// create new class inherited from tdlpp::auth::IAuth to override default behavior
auto auth = tdlpp::auth::DefaultAuth::create(API_CREDENTIALS);

// Handler object is responsible for executing update callbacks. Using instance of
// the object you can run tdlib functions synchronously or asynchronously. All the
// callbacks are executed in different from poll thread
auto handler = tdlpp::base::TdlppHandler::create();

// Longpoll is responsible for td api i/o operations. Receives and sends data in
// different from executor thread and forwards it to handler for further processing
auto poll = tdlpp::poll::LongPoll::create(auth, handler);


/* Define update callbacks here(actually you can do it anywhere, even on poll runtime) */

// Set callback processing all new message updates, overwriting all previous callbacks
handler->SetCallback<td::td_api::updateNewMessage>(true, [&](td::td_api::updateNewMessage& update) {
  ...
});

// Finally run polling. There is two api methods for that, sync and async respectively.
// Sync polling will block executor thread while async will create new separated thread
// and will not affect executor thread flow. You should call only one of the methods
poll->ExecuteSync();
poll->ExecuteAsync();
```

To have a deep dive refer to section [advanced](##Advanced).


## Demos

There are some samples along with repository, you should check [samples](./samples/) directory or pick from the list
  - [Infinite loop](./samples/infinite/)
  - [Get top chats](./samples/top-chats/)
  - [Get me](./samples/get-me/)


## Building && Install

The library is relying on Cmake build system, so you can include the library into existing one with `add_subdirectory` function. Please notice, tdlpp requires following dependencies to be installed or included by your project:

  - [tdlib](https://github.com/tdlib/td) and its dependencies, refer to [instructions](https://tdlib.github.io/td/build.html)
  - [plog](https://github.com/SergiusTheBest/plog) use default cmake install steps

Install plog:
```sh
git clone https://github.com/SergiusTheBest/plog.git
cd plog
mkdir build && cd build
cmake -DPLOG_BUILD_SAMPLES=OFF -DPLOG_INSTALL=ON -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --target install
```

Build tdlpp
```sh
git clone https://github.com/DeinsOne/tdlpp.git
cd tdlpp
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

For building library there is some options for cmake
|                  Name                 |                   Value                   |        Description       |
|---------------------------------------|-------------------------------------------|--------------------------|
| TDLPP_BUILD_SAMPLES                   | boolean `(default: true)`                 | Whether to compile demos |
| TDLPP_MAX_AUTH_RETRIES                | integer `(default: 5)`                    | Auth retries count |
| TDLPP_ENABLE_CONSOLE_LOGGING          | boolean `(default: false)`                | Whether to use runtime console logging |
| TDLPP_CONSOLE_LOGGING_LEVEL           | integer `(default: 3)`                    | Console logging level, see below |
| TDLPP_ENABLE_FILE_LOGGING             | boolean `(default: false)`                | Whether to use runtime file logging |
| TDLPP_FILE_LOGGING_LEVEL              | integer `(default: 3)`                    | File logging level, see below |
| TDLPP_FILE_LOGGING_MAX_FILE_SIZE      | integer `(default: 1024 * 1024 * 32)`     | File log size in bytes |
| TDLPP_FILE_LOGGING_MAX_FILES          | integer `(default: 1)`                    | Count of log files |
| TDLPP_ENABLE_OBJECT_LOGGING           | boolean `(default: false)`                | Whether to same updates into log file at runtime |
| TDLPP_OBJECT_LOGGING_MAX_FILE_SIZE    | integer `(default: 1024 * 1024 * 16)`     | Objects file log size in bytes |
| TDLPP_OBJECT_LOGGING_MAX_FILES        | integer `(default: 1)`                    | Count of update log files |

### Log level

| Log level | Value |
|-----------|-------|
| NONE      | 0     |
| FATAL     | 1     |
| ERROR     | 2     |
| WARN      | 3     |
| INFO      | 4     |
| DEBUG     | 5     |
| VERBOSE   | 6     |


## Advanced

This section covers in all the details underlying concepts of tdlpp...

### Concurrency

