
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

#include "devices/nrf52/inc/Gpio.hpp"
#include "devices/nrf52/inc/Spi.hpp"

static constexpr auto LedConfig = granary::makeGpioConfig();
using LedGreen = granary::Gpio<nrf52::P0, 3>;

using Spi1 = granary::Spi<nrf52::Spi0>; // dummy
static constexpr auto SpiConfig = granary::makeSpiConfig();

int main(int argc, char** argv){

    // constexpr auto test = GpioConfig.get<GpioType>();
    // *((uint32_t*)0x20003000) = (uint32_t)test;

    Spi1::init(SpiConfig);
    // LedGreen::init(LedConfig);
    // LedGreen::set();
    // LedGreen::clear();
    return 0;
}
