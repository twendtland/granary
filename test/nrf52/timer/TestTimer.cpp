
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

#include "nrf52.h"

#include "nrf52840_gpio.hpp"
#include "nrf52840_timer.hpp"
#include "Gpio.hpp"
#include "Timer.hpp"
#include "Units.hpp"
#include "VectorTable.hpp"
#include "Initialization.hpp"

namespace device = nrf52840;

static constexpr std::uint32_t StackTop = 0x20003000;

using Led1 = nrf52::Gpio<device::P0, 13, true>;
using Led2 = nrf52::Gpio<device::P0, 14, true>;
static constexpr auto LedConfig = nrf52::makeGpioConfig(nrf52::GpioPullType::NoPull);

using PeriodicTimer = nrf52::Timer<device::Timer0>;
static constexpr auto PeriodTimerConfig = nrf52::makeTimerConfig();

using namespace granary::unit;

using BlinkLed = Led2;

// -----------------------------------------------------------------------------

void handleTimeout(const std::uint8_t channel){
    BlinkLed::toggle();
}

// -----------------------------------------------------------------------------

void defaultHandler(){
}

// -----------------------------------------------------------------------------

int main(){
    PeriodicTimer::init(PeriodTimerConfig, handleTimeout);
    PeriodicTimer::start(500_ms);

    BlinkLed::init(LedConfig);
    BlinkLed::set();

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
constexpr auto isr = granary::makeVectorTable<48>(StackTop, granary::makeVector(Reset_IRQn, handleReset), granary::makeVector(TIMER0_IRQn, PeriodicTimer::handleIrq));

// -----------------------------------------------------------------------------
