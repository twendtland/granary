
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

#include "nrf52.h"

#include "nrf52840_gpio.hpp"

#include "Gpio.hpp"
#include "Nfc.hpp"
#include "Units.hpp"
#include "VectorTable.hpp"
#include "Initialization.hpp"
#include "Timer.hpp"

namespace device = nrf52;

using Led1 = nrf52::Gpio<nrf52840::P0, 17, true>;
using Led2 = nrf52::Gpio<nrf52840::P0, 18, true>;
using Led3 = nrf52::Gpio<nrf52840::P0, 19, true>;
using Led4 = nrf52::Gpio<nrf52840::P0, 20, true>;
static constexpr auto LedConfig = nrf52::makeGpioConfig(nrf52::GpioPullType::NoPull);

using NfcTag = nrf52::NfcTag<nrf52::Nfc0>;
static constexpr auto NfcConfig = nrf52::makeNfcConfig();

// -----------------------------------------------------------------------------

void handleNfcEvent(const nrf52::NfcEvent event){
    if (event == nrf52::NfcEvent::RxFrameEnd){
        Led1::toggle();
    }
    if (event == nrf52::NfcEvent::TxEnded){
        Led2::toggle();
    }
    if (event == nrf52::NfcEvent::Selected){
        Led3::toggle();
    }
}

// -----------------------------------------------------------------------------

void defaultHandler(){
}

// -----------------------------------------------------------------------------

int main(){
    Led1::init(LedConfig);
    Led2::init(LedConfig);
    Led3::init(LedConfig);
    Led4::init(LedConfig);

    NfcTag::init(NfcConfig, handleNfcEvent);
    NfcTag::start();

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
constexpr auto isr = granary::makeVectorTable<48>(0x20003000, granary::makeVector(Reset_IRQn, handleReset), granary::makeVector(NFCT_IRQn, NfcTag::handleIrq));

// -----------------------------------------------------------------------------
