
// Copyright 2017 Thomas Wendtland
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

#include "Config.hpp"
#include "Callback.hpp"

#include "nrf52_nfct.hpp"
#include "nrf52_uicr.hpp"

namespace granary {

    template<typename ... Values>
    constexpr auto makeNfcConfig(Values ... values){
        constexpr nrf52::Nfct::FramedelaymodeType delaymode = nrf52::Nfct::FramedelaymodeType::Window;
        constexpr auto defaults = std::make_tuple(nrf52::Nfct::BitframesddType{nrf52::Nfct::BitframesddType::Sdd00000}, delaymode);
        return makeConfig(values..., defaults);
    }

    template<typename Instance>
    class Nfc {
        using IrqHandler = Callback<void>;
        public:
            template<typename Config>
            static void init(const Config config, const IrqHandler handler);

            static void start();
            static void stop();

            static void handleIrq();

        private:
            static IrqHandler callback;
    };
}

// -----------------------------------------------------------------------------

template<typename Instance>
typename granary::Nfc<Instance>::IrqHandler granary::Nfc<Instance>::callback;

// -----------------------------------------------------------------------------

template<typename Instance>
template<typename Config>
void granary::Nfc<Instance>::init(const Config config, const IrqHandler handler){
    nrf52::Uicr0::Nfcpins::Protect::set();

    Instance::Inten::Ready::set();
    Instance::Inten::Fielddetected::set();
    Instance::Inten::Error::set();

    const auto delaymode = getParam<nrf52::Nfct::FramedelaymodeType>(config);
    Instance::Framedelaymode::Value::write(delaymode);

    NVIC_EnableIRQ(static_cast<IRQn_Type>(Instance::Interrupt));

    Instance::Tasks_Activate::Value::set();
    callback = handler;
}

// -----------------------------------------------------------------------------

template<typename Instance>
void granary::Nfc<Instance>::start(){

}

// -----------------------------------------------------------------------------

template<typename Instance>
void granary::Nfc<Instance>::stop(){

}

// -----------------------------------------------------------------------------

template<typename Instance>
void granary::Nfc<Instance>::handleIrq(){
    if (Instance::Events_Ready::Value::read() == true){
        callback();
    }
}
