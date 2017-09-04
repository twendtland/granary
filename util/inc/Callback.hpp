
#pragma once

namespace granary {

    template<typename ReturnType, typename ... Args>
    struct Callback {
        using Signature = ReturnType(*)(Args...);
        constexpr Callback() : function {nullptr}{}
        constexpr Callback(const Callback& rhs) : function {rhs.function}{}
        constexpr Callback(Signature f) : function {f}{}

        constexpr Callback operator= (const Callback& rhs){
            function = rhs.function;
            return *this;
        }

        constexpr void operator()(Args ... args){
            if (function){
                function(args...);
            }
        }

        Signature function;
    };
}
