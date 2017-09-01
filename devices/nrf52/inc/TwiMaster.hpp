
#pragma once

#include "Gpio.hpp"
#include "Pins.hpp"
#include "nrf52_twi.hpp"

namespace granary {

    template<typename ... Values>
    constexpr auto makeTwiConfig(Values ... values){
        constexpr auto defaults = std::make_tuple(nrf52::Twi::FrequencyType::K400);
        return makeConfig(std::make_tuple(values...), defaults);
    }

    template<typename Instance, typename SclPin, typename SdaPin>
    class TwiMaster {
        public:
            static constexpr auto PinConfig = makeGpioConfig(GpioType::Input, GpioDrive::S0D1, GpioPullType::PullUp);
            template<typename Config>
            static constexpr void init(Config config);
            static constexpr void deInit();
    };
}

// -----------------------------------------------------------------------------

template<typename Instance, typename SclPin, typename SdaPin>
template<typename Config>
constexpr void granary::TwiMaster<Instance, SclPin, SdaPin>::init(Config config){
    SclPin::init(PinConfig);
    SdaPin::init(PinConfig);

    auto freq = config.template get<nrf52::Twi::FrequencyType>();
    Instance::Frequency::Value::write(freq);

    Instance::Pselscl::Value::write(SclPin::Number);
    Instance::Pselsda::Value::write(SdaPin::Number);
}
