
#pragma once

#include "nrf52_uart.hpp"
#include "Pins.hpp"

namespace granary {

    template<typename ... Values>
    static constexpr auto makeUartConfig(Values ... values){
        constexpr auto defaults = std::make_tuple(nrf52::Uart::BaudrateType::Baud9600);
        return makeConfig(std::make_tuple(values...), defaults);
    }

    template<typename Instance, typename TxPin, typename RxPin, typename CtsPin = Pin::NotConnected, typename RtsPin = Pin::NotConnected>
    class Uart {
        static constexpr auto TxPinConfig = makeGpioConfig();
        static constexpr auto RxPinConfig = makeGpioConfig(GpioType::Input);
    public:
        template<typename Config>
        static constexpr void init(Config config);
        static constexpr void deInit();
    };

}

// -----------------------------------------------------------------------------

template<typename Instance, typename TxPin, typename RxPin, typename CtsPin, typename RtsPin>
template<typename Config>
constexpr void granary::Uart<Instance, TxPin, RxPin, CtsPin, RtsPin>::init(Config config){
    TxPin::init(TxPinConfig);
    RxPin::init(RxPinConfig);
    CtsPin::init(TxPinConfig);
    RtsPin::init(TxPinConfig);
}
