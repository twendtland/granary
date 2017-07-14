
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

namespace granary {

    template<typename ... Values>
    constexpr auto makeGpioConfig(Values ... values){
        std::tuple<int, float> defaults;
        return makeConfig(std::tuple<Values...>{values...}, defaults);
    }

    template<typename Port, std::uint32_t Pin, bool Inverted = false>
    class Gpio {
        public:
            void init();
            void set();
            void clear();
    };
}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
void granary::Gpio<Port, Pin, Inverted>::init(){

}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
void granary::Gpio<Port, Pin, Inverted>::set(){

}

// -----------------------------------------------------------------------------

template<typename Port, std::uint32_t Pin, bool Inverted>
void granary::Gpio<Port, Pin, Inverted>::clear(){

}

// -----------------------------------------------------------------------------
