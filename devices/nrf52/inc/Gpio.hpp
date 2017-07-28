
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

#include <cstdint>
#include "nrf52_gpio.hpp"
#include "Config.hpp"
#include "GpioTypes.hpp"

namespace granary {

    template<typename Port, std::uint32_t Pin, bool Inverted = false>
    class Gpio {
        public:
            template<typename Conf>
            static void init(const Conf config);
            static void deInit();

            static constexpr void set();
            static constexpr void clear();
            static constexpr void toggle();
    };

    template<typename ... Values>
    constexpr auto makeGpioConfig(Values ... values){
        std::tuple<GpioType, GpioPullType> defaults {GpioType::Output, GpioPullType::NoPull};
        return makeConfig(std::tuple<Values...>{values...}, defaults);
    }
}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
template<typename Conf>
void granary::Gpio<Port, Pin, Inverted>::init(const Conf config){
     auto type = config.template get<GpioType>();
     if (type == GpioType::Output){
         Port::template Pin_Cnf<Pin>::Dir::set();
         Port::template Pin_Cnf<Pin>::Input::set();
         Port::template Pin_Cnf<Pin>::Drive::write(static_cast<std::uint8_t>(GpioDriveType::S0S1));
         Port::template Pin_Cnf<Pin>::Sense::write(std::uint8_t{0});
     }
     auto pulltype = config.template get<GpioPullType>();
     Port::template Pin_Cnf<Pin>::Pull::write(static_cast<std::uint8_t>(pulltype));
     clear();
}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
constexpr void granary::Gpio<Port, Pin, Inverted>::set(){
    if (Inverted == false){
        Port::Outset::Pins::write(std::uint32_t{1<<Pin});
    }
    else {
        Port::Outclr::Pins::write(std::uint32_t{1<<Pin});
    }
}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
constexpr void granary::Gpio<Port, Pin, Inverted>::clear(){
    if (Inverted == false){
        Port::Outclr::Pins::write(std::uint32_t{1<<Pin});
    }
    else {
        Port::Outset::Pins::write(std::uint32_t{1<<Pin});
    }
}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
constexpr void granary::Gpio<Port, Pin, Inverted>::toggle(){
    if (Port::Outset::Pins::read() & (1<<Pin)){
        set();
    }
    else {
        clear();
    }
}
