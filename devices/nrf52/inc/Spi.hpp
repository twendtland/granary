
#pragma once

#include "Config.hpp"
#include "Pins.hpp"
#include "nrf52_spi.hpp"

namespace granary {

    struct SpiMode {
        std::uint32_t value;
    };
    struct SpiFrequency {
        nrf52::Spi::FrequencyType value;
    };

    template<typename Instance, typename ... Pins>
    class Spi {
        static constexpr auto  PinConfig = makeGpioConfig();
        public:
            template<typename Config>
            static constexpr void init(const Config& c);
    };

    template<typename ... Values>
    static constexpr auto makeSpiConfig(Values ... values){
        constexpr auto defaults = std::make_tuple(SpiMode{56}, SpiFrequency{nrf52::Spi::FrequencyType::K125});
        return makeConfig(std::tuple<Values...>{values...}, defaults);
    }
}

// -----------------------------------------------------------------------------

template<typename Instance, typename ... Pins>
template<typename Config>
constexpr void granary::Spi<Instance, Pins...>::init(const Config& c){
    auto mode = c.template get<SpiMode>();
    *((uint32_t*)0x20003000) = (uint32_t)mode.value; // dummy usage
    PinWrapper<Pins...>::init(PinConfig);
}
