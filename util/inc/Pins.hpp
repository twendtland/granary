
#pragma once

#include <tuple>
#include "Gpio.hpp"

namespace granary {
    template<typename Pin, typename ... Pins>
    class PinWrapper {
        public:
            template<typename Config>
            static constexpr void init(Config config){
                init_each(config, std::tuple<Pin, Pins...>{});
            }

        private:
            template<typename Config>
            static constexpr void init_each(Config conf, std::tuple<>){
            }

            template<typename Config, typename P, typename ... Ps>
            static constexpr void init_each(Config conf, std::tuple<P, Ps...>){
                P::init(conf);
                init_each(conf, std::tuple<Ps...>{});
            }
    };
}
