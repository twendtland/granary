
#pragma once

#include <type_traits>

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


    template<typename T>
    constexpr bool has_type(){
        return false;
    }

    template<typename T, typename U, typename ... Us>
    constexpr bool has_type(){
        if (std::is_same<T, U>::value){
            return true;
        }
        else {
            return has_type<T, Us...>();
        }
    }


    // check if one tuple contains types not in the other
    template<typename Tuple>
    constexpr bool has_all_types(std::tuple<>){
        return true;
    }

    template<typename Tuple, typename T>
    constexpr bool has_all_types(std::tuple<T>){
        return HasType<T, Tuple>::value;
    }

    template<typename Tuple, typename T, typename ... Ts>
    constexpr bool has_all_types(std::tuple<T, Ts...>){
        return HasType<T, Tuple>::value && has_all_types<Tuple>(std::tuple<Ts...>{});
    }
}
}
