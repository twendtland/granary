
// Copyright 2017 Thomas Wendtland
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

#include "Gpio.hpp"
#include "Uart.hpp"

namespace device = nrf52;

static constexpr auto LedConfig = granary::makeGpioConfig();
using LedGreen = granary::Gpio<device::P0, 3>;

using TxPin = granary::Gpio<device::P0, 16>;
using RxPin = granary::Gpio<device::P0, 17>;
using Uart0 = granary::Uart<device::Uart0, TxPin, RxPin, granary::Pin::NotConnected, granary::Pin::NotConnected>;
static constexpr auto UartConfig = granary::makeUartConfig();

// -----------------------------------------------------------------------------

int main(int argc, char** argv){
    Uart0::init(UartConfig);
    return 0;
}
