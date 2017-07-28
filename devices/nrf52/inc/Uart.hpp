
#pragma once

#include "nrf52_uart.hpp"

namespace granary {

    static constexpr auto makeUartConfig(){
        constexpr auto defaults = std::make_tuple(nrf52::Uart::BaudrateType::Baud9600);
    }

    template<typename Instance, typename TxPin, typename RxPin, typename CtsPin = void, typename RtsPin = void>
    class Uart {
        static constexpr auto TxPinConfig = makeGpioConfig();
        static constexpr auto RxPinConfig = makeGpioConfig(GpioType::Input);

        template<typename Config>
        static constexpr void init(Config config);
    };
}

// -----------------------------------------------------------------------------

template<typename Instance, typename TxPin, typename RxPin, typename CtsPin, typename RtsPin>
template<typename Config>
constexpr void granary::Uart<Instance, TxPin, RxPin, CtsPin, RtsPin>::init(Config config){
    TxPin::init(TxPinConfig);
    RxPin::init(RxPinConfig);
    if (std::is_same<CtsPin, void>::value == false){

    }
    if (std::is_same<RtsPin, void>::value == false){

    }
}
