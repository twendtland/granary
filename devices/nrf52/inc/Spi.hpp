
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
#include "nrf52_spi.hpp"

namespace granary {

    struct SpiMode {
        std::uint32_t value;
    };
    struct SpiFrequency {
        nrf52::Spi::FrequencyType value;
    };

    template<typename Instance, typename ... Pins>
    class Spi {
        static constexpr auto  PinConfig = makeGpioConfig();
        public:
            template<typename Config>
            static constexpr void init(const Config& c);
    };

    template<typename ... Values>
    static constexpr auto makeSpiConfig(Values ... values){
        constexpr auto defaults = std::make_tuple(SpiMode{56}, SpiFrequency{nrf52::Spi::FrequencyType::K125});
        return makeConfig(std::tuple<Values...>{values...}, defaults);
    }
}

// -----------------------------------------------------------------------------

template<typename Instance, typename ... Pins>
template<typename Config>
constexpr void granary::Spi<Instance, Pins...>::init(const Config& c){
    auto mode = c.template get<SpiMode>();
    *((uint32_t*)0x20003000) = (uint32_t)mode.value; // dummy usage
    PinWrapper<Pins...>::init(PinConfig);
}
