
#pragma once

#include <cstdint>
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52 {

namespace Timer {

    enum class Channel {
        Channel0,
        Channel1,
        Channel2,
        Channel3,
        Channel4,
        Channel5
    };

	enum class ModeType {
		Timer = 0,
		Counter = 1,
		Lowpowercounter = 2
	};

	enum class BitmodeType {
		Bit16 = 0,
		Bit08 = 1,
		Bit24 = 2,
		Bit32 = 3
	};

	template <std::uint32_t BaseAddress, std::uint16_t Irq, std::uint8_t Nc>
	struct Controller {
        static constexpr std::uint8_t NumChannels = Nc;
		struct Tasks_Start {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x000;
			using Value = Bitfield<Tasks_Start, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Stop {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x004;
			using Value = Bitfield<Tasks_Stop, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Count {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x008;
			using Value = Bitfield<Tasks_Count, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Clear {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x00c;
			using Value = Bitfield<Tasks_Clear, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Shutdown {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x010;
			using Value = Bitfield<Tasks_Shutdown, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Capture {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x040;
			using Value = Bitfield<Tasks_Capture, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Compare {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x140;
			using Value = Bitfield<Events_Compare, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Shorts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x200;
			using Compare0_Clear = Bitfield<Shorts, bool, 0, 1, Access::ReadWrite>;
			using Compare1_Clear = Bitfield<Shorts, bool, 1, 1, Access::ReadWrite>;
			using Compare2_Clear = Bitfield<Shorts, bool, 2, 1, Access::ReadWrite>;
			using Compare3_Clear = Bitfield<Shorts, bool, 3, 1, Access::ReadWrite>;
			using Compare4_Clear = Bitfield<Shorts, bool, 4, 1, Access::ReadWrite>;
			using Compare5_Clear = Bitfield<Shorts, bool, 5, 1, Access::ReadWrite>;
			using Compare0_Stop = Bitfield<Shorts, bool, 8, 1, Access::ReadWrite>;
			using Compare1_Stop = Bitfield<Shorts, bool, 9, 1, Access::ReadWrite>;
			using Compare2_Stop = Bitfield<Shorts, bool, 10, 1, Access::ReadWrite>;
			using Compare3_Stop = Bitfield<Shorts, bool, 11, 1, Access::ReadWrite>;
			using Compare4_Stop = Bitfield<Shorts, bool, 12, 1, Access::ReadWrite>;
			using Compare5_Stop = Bitfield<Shorts, bool, 13, 1, Access::ReadWrite>;
		};
		struct Intenset {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x304;
			using Compare = Bitfield<Intenset, std::uint8_t, 16, 6, Access::ReadWrite>;
		};
		struct Intenclr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x308;
			using Compare = Bitfield<Intenset, std::uint8_t, 16, 6, Access::ReadWrite>;
		};
		struct Mode {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x504;
			using Value = Bitfield<Mode, ModeType, 0, 2, Access::ReadWrite>;
		};
		struct Bitmode {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x508;
			using Value = Bitfield<Bitmode, BitmodeType, 0, 2, Access::ReadWrite>;
		};
		struct Prescaler {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x510;
			using Value = Bitfield<Prescaler, std::uint8_t, 0, 4, Access::ReadWrite>;
		};

		struct Cc {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x540;
            static constexpr std::uint32_t NumRegisters = 5;
			using Value = Bitfield<Cc, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
	};

}
	using Timer0 = Timer::Controller<0X40008000, 8, 4>;
	using Timer1 = Timer::Controller<0X40009000, 9, 4>;
	using Timer2 = Timer::Controller<0X4000A000, 10, 4>;
	using Timer3 = Timer::Controller<0X4001A000, 26, 6>;
	using Timer4 = Timer::Controller<0X4001B000, 27, 6>;

} // end of namespace nrf52
