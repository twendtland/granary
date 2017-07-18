
#pragma once

#include "Config.hpp"
#include "nrf52_spi.hpp"

namespace granary {

    struct SpiMode {
        std::uint32_t value;
    };
    struct SpiFrequency {
        std::uint32_t value;
    };

    template<typename Instance, typename ... Pins>
    class Spi {
        public:
            template<typename Config>
            static constexpr void init(const Config& c);
    };

    template<typename ... Values>
    static constexpr auto makeSpiConfig(Values ... values){
        constexpr auto defaults = std::make_tuple(SpiMode{0}, SpiFrequency{1000});
        return makeConfig(std::tuple<Values...>{values...}, defaults);
    }
}

// -----------------------------------------------------------------------------

template<typename Instance, typename ... Pins>
template<typename Config>
constexpr void granary::Spi<Instance, Pins...>::init(const Config& c){
    auto mode = c.template get<SpiMode>();
    *((uint32_t*)0x20003000) = (uint32_t)mode.value;
    // use mode
}
