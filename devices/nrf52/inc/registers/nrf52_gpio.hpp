
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
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52 {
namespace Hardware {

    template <std::uint32_t BaseAddress, std::uint16_t Irq>
    struct GpioController {
        struct Out {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x504;
            using Pins = Bitfield<Out, std::uint32_t, 0, 32, Access::ReadWrite>;
        };
        struct Outset {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x508;
            using Pins = Bitfield<Outset, std::uint32_t, 0, 32, Access::ReadWrite>;
        };
        struct Outclr {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x50c;
            using Pins = Bitfield<Outclr, std::uint32_t, 0, 32, Access::ReadWrite>;
        };
        struct In {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x510;
            using Pins = Bitfield<Out, std::uint32_t, 0, 32, Access::ReadWrite>;
        };
        struct Dir {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x514;
            using Pins = Bitfield<Out, std::uint32_t, 0, 32, Access::ReadWrite>;
        };
        struct Dirset {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x518;
            using Pins = Bitfield<Out, std::uint32_t, 0, 32, Access::ReadWrite>;
        };
        struct Dirclr {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x51c;
            using Pins = Bitfield<Out, std::uint32_t, 0, 32, Access::ReadWrite>;
        };
        struct Latch {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x520;
            using Pins = Bitfield<Out, std::uint32_t, 0, 32, Access::ReadWrite>;
        };
        struct Detectmode {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x524;
            using Value = Bitfield<Detectmode, bool, 0, 1, Access::ReadWrite>;
        };

        template<std::uint32_t Number>
        struct Pin_Cnf {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x700 + (Number * sizeof(WidthType));
            using Dir = Bitfield<Pin_Cnf, bool, 0, 1, Access::ReadWrite>;
            using Input = Bitfield<Pin_Cnf, bool, 1, 1, Access::ReadWrite>;
            using Pull = Bitfield<Pin_Cnf, std::uint8_t, 2, 2, Access::ReadWrite>;
            using Drive = Bitfield<Pin_Cnf, std::uint8_t, 8, 3, Access::ReadWrite>;
            using Sense = Bitfield<Pin_Cnf, std::uint8_t, 16, 2, Access::ReadWrite>;
        };
    };
}
} // end of namespace nrf52
