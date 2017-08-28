
#pragma once

#include "Gpio.hpp"
#include "Pins.hpp"

namespace granary {

    template<typename ... Values>
    constexpr auto makeTwiConfig(Values ... values){
        constexpr auto defaults = std::make_tuple();
        return makeConfig(std::make_tuple(values...), defaults);
    }

    template<typename Instance, typename SclPin, typename SdaPin>
    class Twi {
        public:
            static constexpr auto PinConfig = makeGpioConfig();
            template<typename Config>
            static constexpr void init(Config config);
            static constexpr void deInit();
    };
}

// -----------------------------------------------------------------------------

template<typename Instance, typename SclPin, typename SdaPin>
template<typename Config>
constexpr void granary::Twi<Instance, SclPin, SdaPin>::init(Config config){
    SclPin::init(PinConfig);
    SdaPin::init(PinConfig);
}
