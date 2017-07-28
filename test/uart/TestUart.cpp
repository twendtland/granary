
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

static constexpr auto LedConfig = granary::makeGpioConfig();
using LedGreen = granary::Gpio<nrf52::P0, 3>;

//using device = nrf52;

using TxPin = granary::Gpio<nrf52::P0, 16>;
using RxPin = granary::Gpio<nrf52::P0, 17>;
using Uart0 = granary::Uart<nrf52::Uart0, TxPin, RxPin>; // dummy
//static constexpr auto SpiConfig = granary::makeSpiConfig(granary::SpiFrequency{nrf52::Spi::FrequencyType::K125});

using test = std::tuple<int>;

int main(int argc, char** argv){

    return 0;
}
