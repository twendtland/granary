

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
namespace hardware {
namespace gpio {

    enum class ModeType {
        Input,
        Output
    };

    enum class PullType {
        Disabled = 0,
        Pulldown = 1,
        Pullup = 3
    };

    enum class DriveType {
        SS01 = 0,
        HS01 = 1,
        SH01 = 2,
        HH01 = 3,
        DS01 = 4,
        DH01 = 5,
        SD01 = 6,
        HD01 = 7
    };

    enum class SenseType {
        Disabled = 0,
        High = 2,
        Low = 3
    };

    template <std::uint32_t BaseAddress, std::uint16_t Irq>
    struct Controller {
        static constexpr std::uint32_t Interrupt = Irq;
        struct Out {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x504;
            template<std::uint32_t PinNumber>
            using Pin = Bitfield<Out, bool, PinNumber, 1, Access::ReadWrite>;
        };
        struct Outset {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x508;
            template<std::uint32_t PinNumber>
            using Pin = Bitfield<Outset, bool, PinNumber, 1, Access::ReadWrite>;
        };
        struct Outclr {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x50c;
            template<std::uint32_t PinNumber>
            using Pin = Bitfield<Outclr, bool, PinNumber, 1, Access::ReadWrite>;
        };
        struct In {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x510;
            template<std::uint32_t PinNumber>
            using Pin = Bitfield<In, bool, PinNumber, 1, Access::ReadOnly>;
        };
        struct Dir {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x514;
            template<std::uint32_t PinNumber>
            using Pin = Bitfield<Dir, bool, PinNumber, 1, Access::ReadWrite>;
        };
        struct Dirset {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x518;
            template<std::uint32_t PinNumber>
            using Pin = Bitfield<Dirset, bool, PinNumber, 1, Access::ReadWrite>;
        };
        struct Dirclr {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x51c;
            template<std::uint32_t PinNumber>
            using Pin = Bitfield<Dirclr, bool, PinNumber, 1, Access::ReadWrite>;
        };
        struct Latch {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x520;
            template<std::uint32_t PinNumber>
            using Pin = Bitfield<Latch, bool, PinNumber, 1, Access::ReadWrite>;
        };
        struct Detectmode {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x524;
            using Value = Bitfield<Detectmode, bool, 0, 1, Access::ReadWrite>;
        };

        template<std::uint32_t PinNumber>
        struct Pin_Cnfs {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x700 + (0x4 *PinNumber);
            using Dir = Bitfield<Pin_Cnfs, bool, 0, 1, Access::ReadWrite>;
            using Input = Bitfield<Pin_Cnfs, bool, 1, 1, Access::ReadWrite>;
            using Pull = Bitfield<Pin_Cnfs, PullType, 2, 2, Access::ReadWrite>;
            using Drive = Bitfield<Pin_Cnfs, DriveType, 8, 3, Access::ReadWrite>;
            using Sense = Bitfield<Pin_Cnfs, SenseType, 16, 2, Access::ReadWrite>;
        };
    };

}
}
} // end of namespace nrf52
