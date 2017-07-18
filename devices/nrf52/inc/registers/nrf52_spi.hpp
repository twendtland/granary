
#pragma once

#include <cstdint>
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52 {

namespace Spi {

	enum class ReadyType{
		Usage,
		Set
	};

	enum class EnableType{
		Disabled,
		Enabled
	};

	enum class FrequencyType{
		K125,
		K250,
		K500,
		M1,
		M2,
		M4,
		M8
	};

	enum class OrderType{
		Msbfirst,
		Lsbfirst
	};

	enum class CphaType{
		Leading,
		Trailing
	};

	enum class CpolType{
		Activehigh,
		Activelow
	};

	template <std::uint32_t BaseAddress, std::uint16_t Irq>
	struct Controller {
		struct Events_Ready {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x108;
			using Value = Bitfield<Events_Ready, std::uint32_t, 0, 32, AccessType::ReadWrite>;
		};
		struct Intenset {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x304;
			using Ready = Bitfield<Intenset, ReadyType, 2, 1, AccessType::ReadWrite>;
		};
		struct Intenclr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x308;
			using Ready = Bitfield<Intenclr, ReadyType, 2, 1, AccessType::ReadWrite>;
		};
		struct Enable {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x500;
			using Value = Bitfield<Enable, EnableType, 0, 4, AccessType::ReadWrite>;
		};
		struct Psel {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x508;
			using Value = Bitfield<Psel, std::uint32_t, 0, 32, AccessType::ReadWrite>;
		};
		struct Rxd {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x518;
			using Value = Bitfield<Rxd, std::uint8_t, 0, 8, AccessType::ReadWrite>;
		};
		struct Txd {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x51c;
			using Value = Bitfield<Txd, std::uint8_t, 0, 8, AccessType::ReadWrite>;
		};
		struct Frequency {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x524;
			using Value = Bitfield<Frequency, FrequencyType, 0, 32, AccessType::ReadWrite>;
		};
		struct Config {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x554;
			using Order = Bitfield<Config, OrderType, 0, 1, AccessType::ReadWrite>;
			using Cpha = Bitfield<Config, CphaType, 1, 1, AccessType::ReadWrite>;
			using Cpol = Bitfield<Config, CpolType, 2, 1, AccessType::ReadWrite>;
		};
	};

}
	using Spi0 = Spi::Controller<0X40003000, 3>;
	using Spi1 = Spi::Controller<0X40004000, 4>;
	using Spi2 = Spi::Controller<0X40023000, 35>;

} // end of namespace nrf52