
#pragma once

#include <cstdint>
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52 {

namespace Uicr {


	template <std::uint32_t BaseAddress, std::uint16_t Irq>
	struct Controller {
		static constexpr std::uint32_t Interrupt = Irq;
		struct Unused0 {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x000;
			using Value = Bitfield<Unused0, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Unused1 {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x004;
			using Value = Bitfield<Unused1, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Unused2 {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x008;
			using Value = Bitfield<Unused2, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Unused3 {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x010;
			using Value = Bitfield<Unused3, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Nrffw {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x014;
			using Value = Bitfield<Nrffw, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Nrfhw {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x050;
			using Value = Bitfield<Nrfhw, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Customer {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x080;
			using Value = Bitfield<Customer, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Pselreset {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x200;
			using Pin = Bitfield<Pselreset, std::uint8_t, 0, 5, Access::ReadWrite>;
			using Connect = Bitfield<Pselreset, bool, 31, 1, Access::ReadWrite>;
		};
		struct Approtect {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x208;
			using Pall = Bitfield<Approtect, std::uint8_t, 0, 8, Access::ReadWrite>;
		};
		struct Nfcpins {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x20c;
			using Protect = Bitfield<Nfcpins, bool, 0, 1, Access::ReadWrite>;
		};
	};

}
	using Uicr0 = Uicr::Controller<0X10001000, 0xFF>;

} // end of namespace nrf52
