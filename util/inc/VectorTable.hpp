
#pragma once

#include <cstdint>
#include <tuple>

/*
    TODO:
*/

// to be implemented in application
void defaultHandler();

namespace granary {
    using HandlerFunction = void(*)();

    constexpr std::int32_t ResetVectorOffset = 15;

    namespace detail {
        struct InterruptVector{
            constexpr InterruptVector(std::int32_t n, HandlerFunction func) : number{n + ResetVectorOffset}, function{func}{}
            std::int32_t number;
            HandlerFunction function;
        };

        template<std::uint32_t N>
        constexpr auto elemForPos() {
            return defaultHandler;
        }

        template<std::uint32_t N, typename T, typename ... Ts>
        constexpr auto elemForPos(T t, Ts ... ts) {
            if (t.number == N) {
                return t.function;
            }
            return elemForPos<N>(ts...);
        }

        template<std::uint32_t Size>
        struct VectorTable {
            static constexpr auto Index = Size-1;
            template<typename ... Ts>
            static constexpr auto make(Ts ... ts) {
                return std::make_tuple(std::make_tuple(elemForPos<Index>(ts...)), VectorTable<Index>::make(ts...));
            }
        };

        template<>
        struct VectorTable<1> {
            template<typename ... Ts>
            static constexpr auto make(Ts ... ts) {
                return std::make_tuple(elemForPos<0>(ts...));
            }
        };
    }

    template<typename T>
    auto constexpr makeVector(T t, HandlerFunction func) {
        return detail::InterruptVector{t,func};
    }

    template<std::uint32_t Size, typename T, typename ... Ts>
    constexpr auto makeVectorTable(T stacktop, Ts ... ts) {
        static_assert(sizeof...(Ts)<=Size, "VectorTable: too many elements for given size");
        return std::tuple_cat(detail::VectorTable<Size-1>::make(ts...), std::make_tuple(stacktop));
    }

}
