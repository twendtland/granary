
#pragma once

#include <cstdint>
#include <tuple>

namespace granary {
    using HandlerFunction = void(*)();

    struct InterruptHandler {
        constexpr InterruptHandler(std::uint32_t pos, HandlerFunction func) : position{pos}, function{func}{}
        std::uint32_t position;
        HandlerFunction function;
    };

    void DefaultHandler(){
        for(;;){}
    }

    template<std::uint32_t P>
    constexpr auto elemForPos(){
        return DefaultHandler;
    }

    template<std::uint32_t P, typename T, typename ... Ts>
    constexpr auto elemForPos(T t, Ts ... ts){
        if (t.position == P){
            return t.function;
        }
        return elemForPos<P>(ts...);
    }

    template<std::uint32_t Size>
    struct VectorTable {
        static constexpr auto Index = Size;
        template<typename ... Ts>
        static constexpr auto make(Ts ... ts){
            return std::tuple_cat(std::make_tuple(elemForPos<Index-1>(ts...)), VectorTable<Index-1>::make(ts...));
        }
    };

    template<>
    struct VectorTable<1> {
        template<typename ... Ts>
        static constexpr auto make(Ts ... ts){
            return std::make_tuple(elemForPos<0>(ts...));
        }
    };

    template<std::uint32_t Size, typename T, typename ... Ts>
    constexpr auto makeVectorTable(T stacktop, Ts ... ts){
        static_assert(sizeof...(Ts)<=Size, "VectorTable: too many elements for given size");
        return std::tuple_cat(VectorTable<Size>::make(ts...), std::make_tuple(stacktop));
    }
}
