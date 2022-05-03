
#ifndef tdlpp_Core_hpp
#define tdlpp_Core_hpp

#include <td/telegram/td_api.h>
#include <td/telegram/td_api.hpp>
#include <td/telegram/Client.h>

#include <tdlpp/logger/Logger.hpp>
#include <memory>

namespace tdlpp {

    template<typename T>
    using UniqueObjectPtr = td::td_api::object_ptr<T>;

    template<typename T>
    using SharedObjectPtr = std::shared_ptr<T>;


    struct TdlppBase { };

    // overloaded
    namespace detail {
        template <class... Fs>
        struct overload;

        template <class F>
        struct overload<F> : public F {
            explicit overload(F f) : F(f) {}
        };

        template <class F, class... Fs>
        struct overload<F, Fs...> : public overload<F>, public overload<Fs...> {
            overload(F f, Fs... fs) : overload<F>(f), overload<Fs...>(fs...) {
            }
            using overload<F>::operator();
            using overload<Fs...>::operator();
        };

    } // namespace detail

    template <class... F>
    auto overloaded(F... f) {
        return detail::overload<F...>(f...);
    }

} // namespace tdlpp

#endif // tdlpp_Core_hpp
