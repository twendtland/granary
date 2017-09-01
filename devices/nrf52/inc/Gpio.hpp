
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
            static constexpr std::uint32_t Number = Pin;

            template<typename Conf>
            static constexpr void init(const Conf config);
            static void deInit();

            template<typename Conf>
            static void test(const Conf config);

            static constexpr void set();
            static constexpr void clear();
            static constexpr void toggle();
        private:
            // this allows for smaller code footprint
            template<typename Conf>
            static constexpr void generic_init(const Conf config, const std::uint32_t pin);
    };

    template<typename ... Values>
    constexpr auto makeGpioConfig(Values ... values){
        auto defaults  = std::make_tuple(GpioType::Output, GpioPullType::NoPull, GpioDrive::S0S1, GpioSensing::Disabled);
        return makeConfig(std::tuple<Values...>{values...}, defaults);
    }
}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
template<typename Conf>
constexpr void granary::Gpio<Port, Pin, Inverted>::init(const Conf config){
    //generic_init(config, Pin);
    auto type = config.template get<GpioType>();
    if (type == GpioType::Output){
        Port::template Pin_Cnf<Pin>::Dir::write(true);
        Port::template Pin_Cnf<Pin>::Input::write(true); // disconnect
        Port::template Pin_Cnf<Pin>::Sense::write(std::uint8_t{0});
    }
    else if (type==GpioType::Input){
        Port::template Pin_Cnf<Pin>::Dir::write(false);
        Port::template Pin_Cnf<Pin>::Input::write(false); // connect
    }
    auto drive = config.template get<GpioDrive>();
    using FieldType = uint8_t;
    Port::template Pin_Cnf<Pin>::Drive::write(static_cast<FieldType>(drive));
    auto sense = config.template get<GpioSensing>();
    Port::template Pin_Cnf<Pin>::Drive::write(static_cast<FieldType>(sense));
    auto pulltype = config.template get<GpioPullType>();
    Port::template Pin_Cnf<Pin>::Drive::write(static_cast<FieldType>(pulltype));
}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
template<typename Conf>
constexpr void granary::Gpio<Port, Pin, Inverted>::generic_init(const Conf config, const uint32_t pin){
     auto type = config.template get<GpioType>();
     if (type == GpioType::Output){
         Port::Pin_Cnf_Test::Dir::write(true, pin);
         Port::Pin_Cnf_Test::Input::write(true, pin); // disconnect
         Port::Pin_Cnf_Test::Sense::write(std::uint8_t{0}, pin);
     }
     else if (type==GpioType::Input){
          Port::Pin_Cnf_Test::Dir::write(false, pin);
          Port::Pin_Cnf_Test::Input::write(false, pin); // connect
     }
     auto drive = config.template get<GpioDrive>();
     using FieldType = uint8_t;
     Port::Pin_Cnf_Test::Drive::write(static_cast<FieldType>(drive), pin);
     auto sense = config.template get<GpioSensing>();
     Port::Pin_Cnf_Test::Drive::write(static_cast<FieldType>(sense), pin);
     auto pulltype = config.template get<GpioPullType>();
     Port::Pin_Cnf_Test::Drive::write(static_cast<FieldType>(pulltype), pin);
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
