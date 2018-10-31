
// Copyright 2018 Thomas Wendtland
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

namespace nrf52 {

    template<typename Port, std::uint32_t Pin, bool Inverted = false>
    class Gpio {
        public:
            static constexpr std::uint32_t PinNumber = Pin;

            template<typename Conf>
            static constexpr void init(const Conf config);
            static void deInit();

            static constexpr void set();
            static constexpr auto& on = set;
            static constexpr void clear();
            static constexpr void toggle();
        private:
            // this allows for a smaller code footprint
            template<typename Conf>
            static constexpr void generic_init(const Conf config, const std::uint32_t pin);
    };

    template<typename ... Values>
    constexpr auto makeGpioConfig(Values ... values) {
        auto defaults  = std::make_tuple(nrf52::hardware::gpio::ModeType::Output, nrf52::hardware::gpio::PullType::Disabled,
                                         nrf52::hardware::gpio::DriveType::SS01, nrf52::hardware::gpio::SenseType::Disabled);
        return granary::makeConfig(defaults, values...);
    }
}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
template<typename Conf>
constexpr void nrf52::Gpio<Port, Pin, Inverted>::init(const Conf config) {
    auto type = config.template get<nrf52::hardware::gpio::ModeType>();
    if (type == nrf52::hardware::gpio::ModeType::Output) {
        Port::template Pin_Cnfs<Pin>::Dir::write(true);
        Port::template Pin_Cnfs<Pin>::Input::write(true); // disconnect
        Port::template Pin_Cnfs<Pin>::Sense::write(nrf52::hardware::gpio::SenseType::Disabled);
    }
    else if (type==nrf52::hardware::gpio::ModeType::Input) {
        Port::template Pin_Cnfs<Pin>::Dir::write(false);
        Port::template Pin_Cnfs<Pin>::Input::write(false); // connect
    }
    auto drive = config.template get<nrf52::hardware::gpio::DriveType>();
    Port::template Pin_Cnfs<Pin>::Drive::write(drive);
    auto pulltype = config.template get<nrf52::hardware::gpio::PullType>();
    Port::template Pin_Cnfs<Pin>::Pull::write(pulltype);
    clear();
}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
constexpr void nrf52::Gpio<Port, Pin, Inverted>::set() {
    if (Inverted == false) {
        Port::Outset::template Pin<Pin>::set();
    }
    else {
        Port::Outclr::template Pin<Pin>::set();
    }
}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
constexpr void nrf52::Gpio<Port, Pin, Inverted>::clear() {
    if (Inverted == false) {
        Port::Outclr::template Pin<Pin>::set();
    }
    else {
        Port::Outset::template Pin<Pin>::set();
    }
}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
constexpr void nrf52::Gpio<Port, Pin, Inverted>::toggle() {
    if (Port::Outset::template Pin<Pin>::read() & (1<<Pin)) {
        set();
    }
    else {
        clear();
    }
}
