
#pragma once

namespace granary {
namespace Util {

    template <typename T, typename Tuple>
    struct HasType;

    template <typename T>
    struct HasType<T, std::tuple<>> : std::false_type {};

    template <typename T, typename U, typename... Ts>
    struct HasType<T, std::tuple<U, Ts...>> : HasType<T, std::tuple<Ts...>> {};

    template <typename T, typename... Ts>
    struct HasType<T, std::tuple<T, Ts...>> : std::true_type {};

    template<typename Param, typename T>
    constexpr void for_each_impl(Param p, T t){

    }
}
}
