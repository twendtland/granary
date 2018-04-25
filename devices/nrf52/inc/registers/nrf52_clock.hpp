
#pragma once

#include <cstdint>
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52 {
namespace Hardware {
namespace Clock {

	enum class SrcType {
		Rc = 0,
		Xtal = 1,
		Synth = 2
	};

	enum class TraceportspeedType {
		Mhz32 = 0,
		Mhz16 = 1,
		Mhz8 = 2,
		Mhz4 = 3
	};

	enum class TracemuxType {
		Gpio = 0,
		Serial = 1,
		Parallel = 2
	};

	template <std::uint32_t BaseAddress, std::uint16_t Irq>
	struct Controller {
		struct Tasks_Hfclkstart {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x000;
			using Value = Bitfield<Tasks_Hfclkstart, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Hfclkstop {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x004;
			using Value = Bitfield<Tasks_Hfclkstop, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Lfclkstart {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x008;
			using Value = Bitfield<Tasks_Lfclkstart, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Lfclkstop {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x00c;
			using Value = Bitfield<Tasks_Lfclkstop, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Cal {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x010;
			using Value = Bitfield<Tasks_Cal, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Ctstart {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x014;
			using Value = Bitfield<Tasks_Ctstart, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Ctstop {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x018;
			using Value = Bitfield<Tasks_Ctstop, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Hfclkstarted {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x100;
			using Value = Bitfield<Events_Hfclkstarted, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Lfclkstarted {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x104;
			using Value = Bitfield<Events_Lfclkstarted, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Done {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x10c;
			using Value = Bitfield<Events_Done, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Ctto {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x110;
			using Value = Bitfield<Events_Ctto, bool, 0, 1, Access::ReadWrite>;
		};
		struct Intenset {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x304;
			using Hfclkstarted = Bitfield<Intenset, bool, 0, 1, Access::ReadWrite>;
			using Lfclkstarted = Bitfield<Intenset, bool, 1, 1, Access::ReadWrite>;
			using Done = Bitfield<Intenset, bool, 3, 1, Access::ReadWrite>;
			using Ctto = Bitfield<Intenset, bool, 4, 1, Access::ReadWrite>;
		};
		struct Intenclr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x308;
			using Hfclkstarted = Bitfield<Intenclr, bool, 0, 1, Access::ReadWrite>;
			using Lfclkstarted = Bitfield<Intenclr, bool, 1, 1, Access::ReadWrite>;
			using Done = Bitfield<Intenclr, bool, 3, 1, Access::ReadWrite>;
			using Ctto = Bitfield<Intenclr, bool, 4, 1, Access::ReadWrite>;
		};
		struct Hfclkrun {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x408;
			using Status = Bitfield<Hfclkrun, bool, 0, 1, Access::ReadWrite>;
		};
		struct Hfclkstat {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x40c;
			using Src = Bitfield<Hfclkstat, bool, 0, 1, Access::ReadWrite>;
			using State = Bitfield<Hfclkstat, bool, 16, 1, Access::ReadWrite>;
		};
		struct Lfclkrun {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x414;
			using Status = Bitfield<Lfclkrun, bool, 0, 1, Access::ReadWrite>;
		};
		struct Lfclkstat {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x418;
			using Src = Bitfield<Lfclkstat, SrcType, 0, 2, Access::ReadWrite>;
			using State = Bitfield<Lfclkstat, bool, 16, 1, Access::ReadWrite>;
		};
		struct Lfclksrccopy {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x41c;
			using Src = Bitfield<Lfclksrccopy, SrcType, 0, 2, Access::ReadWrite>;
		};
		struct Lfclksrc {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x518;
			using Src = Bitfield<Lfclksrc, SrcType, 0, 2, Access::ReadWrite>;
			using Bypass = Bitfield<Lfclksrc, bool, 16, 1, Access::ReadWrite>;
			using External = Bitfield<Lfclksrc, bool, 17, 1, Access::ReadWrite>;
		};
		struct Ctiv {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x538;
			using Value = Bitfield<Ctiv, std::uint8_t, 0, 7, Access::ReadWrite>;
		};
		struct Traceconfig {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x55c;
			using Traceportspeed = Bitfield<Traceconfig, TraceportspeedType, 0, 2, Access::ReadWrite>;
			using Tracemux = Bitfield<Traceconfig, TracemuxType, 16, 2, Access::ReadWrite>;
		};
	};

}
}
	using SysClock = Hardware::Clock::Controller<0X40000000, 0>;

} // end of namespace nrf52
