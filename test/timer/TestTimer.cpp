
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
#include "nrf52.h"

namespace device = nrf52;

using PeriodicTimer = granary::Timer<nrf52::Timer0>;
static constexpr auto PeriodTimerConfig = granary::makeTimerConfig();

extern "C" {
    void __libc_init_array();
}

int main();

// -----------------------------------------------------------------------------

void handleTimeout(const std::uint8_t channel){

}

// -----------------------------------------------------------------------------

void defaultHandler(){

}

// -----------------------------------------------------------------------------

void handleReset(){
    __libc_init_array();
    main();
}

// -----------------------------------------------------------------------------

__attribute__((section(".isr_vector"), used))
constexpr auto isr = granary::makeVectorTable<48>(0x20003000, granary::makeVector(Reset_IRQn, handleReset), granary::makeVector(TIMER0_IRQn, PeriodicTimer::handleIrq));

// -----------------------------------------------------------------------------

int main(){
    PeriodicTimer::init(PeriodTimerConfig, handleTimeout);
    for(;;);
}
