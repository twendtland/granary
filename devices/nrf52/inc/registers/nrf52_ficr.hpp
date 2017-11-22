
#pragma once

#include <cstdint>
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52 {

namespace Ficr {

	template <std::uint32_t BaseAddress, std::uint16_t Irq>
	struct Controller {
		static constexpr std::uint32_t Interrupt = Irq;
		struct Codepagesize {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x010;
			using Value = Bitfield<Codepagesize, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Codesize {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x014;
			using Value = Bitfield<Codesize, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Deviceid {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x060;
			using Value = Bitfield<Deviceid, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Er {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x080;
			using Value = Bitfield<Er, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Ir {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x090;
			using Value = Bitfield<Ir, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Deviceaddrtype {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x0a0;
			using Value = Bitfield<Deviceaddrtype, bool, 0, 1, Access::ReadWrite>;
		};
		struct Deviceaddr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x0a4;
			using Value = Bitfield<Deviceaddr, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Info {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x100;
			using Value = Bitfield<Info, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Temp {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x404;
			using Value = Bitfield<Temp, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Nfc {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x450;
			using Value = Bitfield<Nfc, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
	};

}
	using Ficr0 = Ficr::Controller<0X10000000, 0xFF>;

} // end of namespace nrf52
