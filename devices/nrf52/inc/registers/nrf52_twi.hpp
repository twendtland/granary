
#pragma once

#include <cstdint>
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52 {

namespace Twi {

	enum class FrequencyType{
		K100 = 0X01980000,
		K250 = 0X04000000,
		K400 = 0X06680000
	};

	template <std::uint32_t BaseAddress, std::uint16_t Irq>
	struct Controller {
		struct Tasks_Startrx {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x000;
			using Value = Bitfield<Tasks_Startrx, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Starttx {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x008;
			using Value = Bitfield<Tasks_Starttx, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Stop {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x014;
			using Value = Bitfield<Tasks_Stop, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Suspend {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x01c;
			using Value = Bitfield<Tasks_Suspend, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Resume {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x020;
			using Value = Bitfield<Tasks_Resume, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Stopped {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x104;
			using Value = Bitfield<Events_Stopped, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Rxdready {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x108;
			using Value = Bitfield<Events_Rxdready, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Txdsent {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x11c;
			using Value = Bitfield<Events_Txdsent, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Error {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x124;
			using Value = Bitfield<Events_Error, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Bb {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x138;
			using Value = Bitfield<Events_Bb, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Suspended {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x148;
			using Value = Bitfield<Events_Suspended, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Shorts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x200;
			using Bb_Suspend = Bitfield<Shorts, bool, 0, 1, Access::ReadWrite>;
			using Bb_Stop = Bitfield<Shorts, bool, 1, 1, Access::ReadWrite>;
		};
		struct Intenset {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x304;
			using Stopped = Bitfield<Intenset, bool, 1, 1, Access::ReadWrite>;
			using Rxdready = Bitfield<Intenset, bool, 2, 1, Access::ReadWrite>;
			using Txdsent = Bitfield<Intenset, bool, 7, 1, Access::ReadWrite>;
			using Error = Bitfield<Intenset, bool, 9, 1, Access::ReadWrite>;
			using Bb = Bitfield<Intenset, bool, 14, 1, Access::ReadWrite>;
			using Suspended = Bitfield<Intenset, bool, 18, 1, Access::ReadWrite>;
		};
		struct Intenclr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x308;
			using Stopped = Bitfield<Intenclr, bool, 1, 1, Access::ReadWrite>;
			using Rxdready = Bitfield<Intenclr, bool, 2, 1, Access::ReadWrite>;
			using Txdsent = Bitfield<Intenclr, bool, 7, 1, Access::ReadWrite>;
			using Error = Bitfield<Intenclr, bool, 9, 1, Access::ReadWrite>;
			using Bb = Bitfield<Intenclr, bool, 14, 1, Access::ReadWrite>;
			using Suspended = Bitfield<Intenclr, bool, 18, 1, Access::ReadWrite>;
		};
		struct Errorsrc {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x4c4;
			using Overrun = Bitfield<Errorsrc, bool, 0, 1, Access::ReadWrite>;
			using Anack = Bitfield<Errorsrc, bool, 1, 1, Access::ReadWrite>;
			using Dnack = Bitfield<Errorsrc, bool, 2, 1, Access::ReadWrite>;
		};
		struct Enable {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x500;
			using Value = Bitfield<Enable, std::uint8_t, 0, 4, Access::ReadWrite>;
		};
		struct Pselscl {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x508;
			using Value = Bitfield<Pselscl, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Pselsda {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x50c;
			using Value = Bitfield<Pselsda, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Rxd {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x518;
			using Value = Bitfield<Rxd, std::uint8_t, 0, 8, Access::ReadWrite>;
		};
		struct Txd {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x51c;
			using Value = Bitfield<Txd, std::uint8_t, 0, 8, Access::ReadWrite>;
		};
		struct Frequency {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x524;
			using Value = Bitfield<Frequency, FrequencyType, 0, 32, Access::ReadWrite>;
		};
		struct Address {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x588;
			using Value = Bitfield<Address, std::uint8_t, 0, 7, Access::ReadWrite>;
		};
	};

}
	using Twi0 = Twi::Controller<0X40003000, 3>;
	using Twi1 = Twi::Controller<0X40004000, 4>;

} // end of namespace nrf52
