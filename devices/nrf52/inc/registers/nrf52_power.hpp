
#pragma once

#include <cstdint>
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52 {
namespace Hardware {
namespace Power {

	enum class ThresholdType {
		V17 = 4,
		V18 = 5,
		V19 = 6,
		V20 = 7,
		V21 = 8,
		V2 = 9,
		V23 = 10,
		V24 = 11,
		V25 = 12,
		V26 = 13,
		V27 = 14,
		V28 = 15
	};

	enum class ThresholdvddhType {
		V27 = 0,
		V28 = 1,
		V29 = 2,
		V30 = 3,
		V31 = 4,
		V32 = 5,
		V3 = 6,
		V34 = 7,
		V35 = 8,
		V36 = 9,
		V37 = 10,
		V38 = 11,
		V39 = 12,
		V40 = 13,
		V41 = 14,
		V42 = 15
	};

	template <std::uint32_t BaseAddress, std::uint16_t Irq>
	struct Controller {
		static constexpr std::uint32_t Interrupt = Irq;
		struct Tasks_Constlat {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x078;
			using Value = Bitfield<Tasks_Constlat, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Lowpwr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x07c;
			using Value = Bitfield<Tasks_Lowpwr, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Pofwarn {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x108;
			using Value = Bitfield<Events_Pofwarn, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Sleepenter {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x114;
			using Value = Bitfield<Events_Sleepenter, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Sleepexit {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x118;
			using Value = Bitfield<Events_Sleepexit, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Usbdetected {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x11c;
			using Value = Bitfield<Events_Usbdetected, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Usbremoved {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x120;
			using Value = Bitfield<Events_Usbremoved, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Usbpwrrdy {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x124;
			using Value = Bitfield<Events_Usbpwrrdy, bool, 0, 1, Access::ReadWrite>;
		};
		struct Intenset {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x304;
			using Pofwarn = Bitfield<Intenset, bool, 2, 1, Access::ReadWrite>;
			using Sleepenter = Bitfield<Intenset, bool, 5, 1, Access::ReadWrite>;
			using Sleepexit = Bitfield<Intenset, bool, 6, 1, Access::ReadWrite>;
			using Usbdetected = Bitfield<Intenset, bool, 7, 1, Access::ReadWrite>;
			using Usbremoved = Bitfield<Intenset, bool, 8, 1, Access::ReadWrite>;
			using Usbpwrrdy = Bitfield<Intenset, bool, 9, 1, Access::ReadWrite>;
		};
		struct Intenclr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x308;
			using Pofwarn = Bitfield<Intenclr, bool, 2, 1, Access::ReadWrite>;
			using Sleepenter = Bitfield<Intenclr, bool, 5, 1, Access::ReadWrite>;
			using Sleepexit = Bitfield<Intenclr, bool, 6, 1, Access::ReadWrite>;
			using Usbdetected = Bitfield<Intenclr, bool, 7, 1, Access::ReadWrite>;
			using Usbremoved = Bitfield<Intenclr, bool, 8, 1, Access::ReadWrite>;
			using Usbpwrrdy = Bitfield<Intenclr, bool, 9, 1, Access::ReadWrite>;
		};
		struct Resetreas {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x400;
			using Resetpin = Bitfield<Resetreas, bool, 0, 1, Access::ReadWrite>;
			using Dog = Bitfield<Resetreas, bool, 1, 1, Access::ReadWrite>;
			using Sreq = Bitfield<Resetreas, bool, 2, 1, Access::ReadWrite>;
			using Lockup = Bitfield<Resetreas, bool, 3, 1, Access::ReadWrite>;
			using Off = Bitfield<Resetreas, bool, 16, 1, Access::ReadWrite>;
			using Lpcomp = Bitfield<Resetreas, bool, 17, 1, Access::ReadWrite>;
			using Dif = Bitfield<Resetreas, bool, 18, 1, Access::ReadWrite>;
			using Nfc = Bitfield<Resetreas, bool, 19, 1, Access::ReadWrite>;
			using Vbus = Bitfield<Resetreas, bool, 20, 1, Access::ReadWrite>;
		};
		struct Ramstatus {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x428;
			using Ramblock0 = Bitfield<Ramstatus, bool, 0, 1, Access::ReadWrite>;
			using Ramblock1 = Bitfield<Ramstatus, bool, 1, 1, Access::ReadWrite>;
			using Ramblock2 = Bitfield<Ramstatus, bool, 2, 1, Access::ReadWrite>;
			using Ramblock3 = Bitfield<Ramstatus, bool, 3, 1, Access::ReadWrite>;
		};
		struct Usbregstatus {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x438;
			using Vbusdetect = Bitfield<Usbregstatus, bool, 0, 1, Access::ReadWrite>;
			using Outputrdy = Bitfield<Usbregstatus, bool, 1, 1, Access::ReadWrite>;
		};
		struct Systemoff {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x500;
			using Value = Bitfield<Systemoff, bool, 0, 1, Access::ReadWrite>;
		};
		struct Pofcon {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x510;
			using Pof = Bitfield<Pofcon, bool, 0, 1, Access::ReadWrite>;
			using Threshold = Bitfield<Pofcon, ThresholdType, 1, 4, Access::ReadWrite>;
			using Thresholdvddh = Bitfield<Pofcon, ThresholdvddhType, 8, 4, Access::ReadWrite>;
		};
		struct Gpregret {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x51c;
			using Value = Bitfield<Gpregret, std::uint8_t, 0, 8, Access::ReadWrite>;
		};
		struct Gpregret2 {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x520;
			using Gpregret = Bitfield<Gpregret2, std::uint8_t, 0, 8, Access::ReadWrite>;
		};
		struct Dcdcen {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x578;
			using Value = Bitfield<Dcdcen, bool, 0, 1, Access::ReadWrite>;
		};
		struct Dcdcen0 {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x580;
			using Dcdcen = Bitfield<Dcdcen0, bool, 0, 1, Access::ReadWrite>;
		};
		struct Mainregstatus {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x640;
			using Value = Bitfield<Mainregstatus, bool, 0, 1, Access::ReadWrite>;
		};
		struct Rams {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x900;
			using Value = Bitfield<Rams, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
	};

}
}
	using Power = Hardware::Power::Controller<0X40000000, 0>;
} // end of namespace nrf52840
