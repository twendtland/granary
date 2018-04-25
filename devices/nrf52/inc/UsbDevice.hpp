
// Copyright 2018 Thomas Wendtland
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with \the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "Usb.hpp"
#include "Callback.hpp"
#include "Clock.hpp"

#include "nrf52_power.hpp"
#include "nrf52840_usbd.hpp"

namespace nrf52 {

    class UsbDevice {
        public:
            using IrqHandler = granary::Callback<void, const std::uint8_t>;

            template<typename Config>
            static constexpr void init(const Config config, const IrqHandler handler);

            static void deInit();

            static void handleIrq();

        private:
            static void handleReset();
            static void handleSetup();

            static IrqHandler callback;
    };
}

// -----------------------------------------------------------------------------

typename nrf52::UsbDevice::IrqHandler nrf52::UsbDevice::callback;

// -----------------------------------------------------------------------------

template<typename Config>
constexpr void nrf52::UsbDevice::init(const Config config, const IrqHandler handler) {
    while (Power::Events_Usbdetected::Value::read() == false) {
    }
    Usbd::Enable::Value::set();
    Clock::startHighSpeedOscillator();

    // wait for this event before handling others
    Usbd::Inten::Usbevent::set();

    callback = handler;
    NVIC_EnableIRQ(static_cast<IRQn_Type>(Usbd::Interrupt));
}

// -----------------------------------------------------------------------------

void nrf52::UsbDevice::handleIrq() {
    if (Usbd::Events_Usbevent::Value::read() == true){
        if (Usbd::Eventcause::Ready::read() == true &&
            Power::Events_Usbpwrrdy::Value::read() == true) { // @todo: check clock ready?
            Usbd::Eventcause::Ready::clear();
            Usbd::Inten::Usbevent::clear();
            Usbd::Inten::Usbreset::set();
            Usbd::Usbpullup::Connect::set();
        }
    }
    if (Usbd::Events_Usbreset::Value::read() == true) {
        handleReset();
    }
    else if (Usbd::Events_Ep0Setup::Value::read() == true) {
        handleSetup();
    }

}

// -----------------------------------------------------------------------------

void nrf52::UsbDevice::handleReset() {
    Usbd::Events_Usbreset::Value::clear();
    Usbd::Inten::Ep0Setup::set();
}

// -----------------------------------------------------------------------------

void nrf52::UsbDevice::handleSetup() {
    Usbd::Inten::Ep0Setup::clear();
    std::uint32_t t = 0x20003000;
    Usbd::EndpointsIn::Ptr::write(t, 2);
    callback(0);
}
