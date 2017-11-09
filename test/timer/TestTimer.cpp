
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
#include "Timer.hpp"
#include "VectorTable.hpp"
#include "Initialization.hpp"
#include "nrf52.h"

namespace device = nrf52;

using Led1 = granary::Gpio<device::P0, 17, true>;
using Led2 = granary::Gpio<device::P0, 18, true>;

static constexpr auto LedConfig = makeGpioConfig(granary::GpioPullType::NoPull);

using PeriodicTimer = granary::Timer<nrf52::Timer0>;
static constexpr auto PeriodTimerConfig = granary::makeTimerConfig();


uint32_t data = 0x55AA;
uint32_t g = 45;

// -----------------------------------------------------------------------------

void handleTimeout(const std::uint8_t channel){

}

// -----------------------------------------------------------------------------

void defaultHandler(){

}

// -----------------------------------------------------------------------------

int main(){
    PeriodicTimer::init(PeriodTimerConfig, handleTimeout);
    volatile int i  = data +1 + g;
    Led1::init(LedConfig);
    Led1::set();

    for(;;);
}

// -----------------------------------------------------------------------------

void handleReset(){
    //granary::DataSection::init();
    granary::BssSection::init();
    main();
}

// -----------------------------------------------------------------------------

__attribute__((section(".isr_vector"), used))
constexpr auto isr = granary::makeVectorTable<48>(0x20003000, granary::makeVector(Reset_IRQn, handleReset), granary::makeVector(TIMER0_IRQn, PeriodicTimer::handleIrq));

// -----------------------------------------------------------------------------
