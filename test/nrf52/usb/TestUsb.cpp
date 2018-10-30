
// Copyright 2018 Thomas Wendtland
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "nrf52840.h"

#include "nrf52840_gpio.hpp"
#include "nrf52840_usbd.hpp"

#include "Pins.hpp"
#include "Gpio.hpp"
#include "UsbDevice.hpp"
#include "Units.hpp"
#include "VectorTable.hpp"
#include "Initialization.hpp"

namespace device = nrf52840;
using namespace granary::unit;

static constexpr std::uint32_t StackTop = 0x20003000;

using Led1 = nrf52::Gpio<device::P0, 13, true>;
using Led2 = nrf52::Gpio<device::P0, 14, true>;
static constexpr auto LedConfig = nrf52::makeGpioConfig(nrf52::GpioPullType::NoPull);

using TestDevice = nrf52::UsbDevice;

using BlinkLed = Led2;

constexpr std::uint16_t VendorId = 0xFF45;
// constexpr Usb::DeviceDescriptor::Length<
//
// __attribute__((used))
// constexpr auto f = Usb::makeDeviceDescriptor(Usb::makeField(1, 0xEE), Usb::makeFieldLong(3, VendorId));

// constexpr auto one = Usb::makeFieldT(std:uint8_t{2});

// Usb::makeDeviceDescriptor(;

// -----------------------------------------------------------------------------

void usbHandler(const std::uint8_t i) {
    // BlinkLed::set();
}

// -----------------------------------------------------------------------------

void defaultHandler() {
}

// -----------------------------------------------------------------------------

int main(){
    BlinkLed::init(LedConfig);
    BlinkLed::set();
    // TestDevice::init(43, usbHandler);

    for(;;);
}

// -----------------------------------------------------------------------------

void handleReset(){
    granary::DataSection::init();
    granary::BssSection::init();
    main();
}

// -----------------------------------------------------------------------------

__attribute__((section(".isr_vector"), used))
constexpr auto isr = granary::makeVectorTable<60>(StackTop, granary::makeVector(Reset_IRQn, handleReset));//, granary::makeVector(USBD_IRQn, TestDevice::handleIrq));

// -----------------------------------------------------------------------------
