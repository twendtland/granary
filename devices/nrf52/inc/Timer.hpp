
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
#include "Pins.hpp"
#include "Callback.hpp"
#include "nrf52_timer.hpp"
#include "nrf52.h"

namespace granary {

    // timer clock divided by 2^prescaler, choose value accordingly
    template<typename ... Values>
    static constexpr auto makeTimerConfig(Values ... values){
        constexpr auto defaults = std::make_tuple(nrf52::Timer::ModeType::Timer, nrf52::Timer::BitmodeType::Bit16, std::uint8_t{1});
        return makeConfig(std::tuple<Values...>{values...}, defaults);
    }

    using IrqHandler = void(*)(const std::uint8_t channel);

    template<typename Instance>
    class Timer {
        static constexpr std::uint32_t BaseFrqeuency = 16000000;
        public:
            template<typename Config>
            static constexpr void init(const Config config, const IrqHandler handler);

            static void start(const std::uint32_t ms);
            static void stop();
            static void reset();

            static void handleIrq();

        private:
            static IrqHandler callback;

            static Callback<void, std::uint8_t> callback2;
    };
}

// -----------------------------------------------------------------------------

template<typename Instance>
granary::IrqHandler granary::Timer<Instance>::callback = nullptr;

// -----------------------------------------------------------------------------

template<typename Instance>
granary::Callback<void, std::uint8_t> granary::Timer<Instance>::callback2;

// -----------------------------------------------------------------------------

template<typename Instance>
template<typename Config>
constexpr void granary::Timer<Instance>::init(const Config config, const IrqHandler handler){
    auto mode = config.template get<nrf52::Timer::ModeType>();
    Instance::Mode::Value::write(mode);

    auto bitmode = config.template get<nrf52::Timer::BitmodeType>();
    Instance::Bitmode::Value::write(bitmode);

    auto prescaler = config.template get<std::uint8_t>();
    Instance::Prescaler::Value::write(prescaler);

    NVIC_EnableIRQ(TIMER0_IRQn);

    callback2 = handler;
}

// -----------------------------------------------------------------------------

template<typename Instance>
void granary::Timer<Instance>::start(const std::uint32_t ms){
    std::uint32_t prescaler = Instance::Prescaler::Value::read();
    std::uint32_t ticks = (BaseFrqeuency / 1000 * ms) >> prescaler;
    Instance::Cc::Value::write(ticks, 0);
    Instance::Intenset::Compare::write(std::uint8_t{1}); // @todo: used channel
    Instance::Tasks_Start::write(std::uint32_t{1});
}

// -----------------------------------------------------------------------------

template<typename Instance>
void granary::Timer<Instance>::stop(){
    Instance::Tasks_Stop::write(std::uint32_t{1});
    Instance::Intenclr::Compare::write(std::uint8_t{1});
}

// -----------------------------------------------------------------------------

template<typename Instance>
void granary::Timer<Instance>::reset(){
    stop();
    Instance::Tasks_Clear::write(std::uint32_t{1});
}


// -----------------------------------------------------------------------------

template<typename Instance>
void granary::Timer<Instance>::handleIrq(){
    //callback(1);
}
