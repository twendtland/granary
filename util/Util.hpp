
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

    template<typename Param, typename T, typename ... Ts>
    constexpr void for_each_impl(Param p, T t, Ts ... ts){
        for_each_impl(p, ts...);
    }

    template<typename Param, typename T>
    constexpr void for_each(Param p, T t){
        constexpr size_t size = std::tuple_size<T>::value;
        using i = std::make_index_sequence<size>;
        //T::init(p);
        for_each_impl(p, std::get<i>(t));
    }
}
}
