
#pragma once

#include <cstdint>
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52 {

namespace Uart {

	enum class OverrunType{
		Notpresent = 0,
		Present = 1
	};

	enum class ParityType{
		Notpresent = 0,
		Present = 1
	};

	enum class FramingType{
		Notpresent = 0,
		Present = 1
	};

	enum class BreakType{
		Notpresent = 0,
		Present = 1
	};

	enum class BaudrateType{
		Baud1200 = 0X0004F000,
		Baud2400 = 0X0009D000,
		Baud4800 = 0X0013B000,
		Baud9600 = 0X00275000,
		Baud14400 = 0X003B0000,
		Baud19200 = 0X004Ea000,
		Baud28800 = 0X0075F000,
		Baud31250 = 0X00800000,
		Baud38400 = 0X009D5000,
		Baud56000 = 0X00E50000,
		Baud57600 = 0X00Ebf000,
		Baud76800 = 0X013A9000,
		Baud115200 = 0X01D7E000,
		Baud230400 = 0X03Afb000,
		Baud250000 = 0X04000000,
		Baud460800 = 0X075F7000,
		Baud921600 = 0X0Ebed000,
		Baud1M = 0X10000000
	};

	template <std::uint32_t BaseAddress, std::uint16_t Irq>
	struct Controller {
		struct Tasks_Startrx {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x000;
			using Value = Bitfield<Tasks_Startrx, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Stoprx {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x004;
			using Value = Bitfield<Tasks_Stoprx, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Starttx {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x008;
			using Value = Bitfield<Tasks_Starttx, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Stoptx {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x00c;
			using Value = Bitfield<Tasks_Stoptx, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Suspend {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x01c;
			using Value = Bitfield<Tasks_Suspend, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Cts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x100;
			using Value = Bitfield<Events_Cts, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Ncts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x104;
			using Value = Bitfield<Events_Ncts, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Rxdrdy {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x108;
			using Value = Bitfield<Events_Rxdrdy, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Txdrdy {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x11c;
			using Value = Bitfield<Events_Txdrdy, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Error {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x124;
			using Value = Bitfield<Events_Error, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Rxto {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x144;
			using Value = Bitfield<Events_Rxto, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Shorts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x200;
			using Cts_Startrx = Bitfield<Shorts, bool, 3, 1, Access::ReadWrite>;
			using Ncts_Stoprx = Bitfield<Shorts, bool, 4, 1, Access::ReadWrite>;
		};
		struct Intenset {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x304;
			using Cts = Bitfield<Intenset, bool, 0, 1, Access::ReadWrite>;
			using Ncts = Bitfield<Intenset, bool, 1, 1, Access::ReadWrite>;
			using Rxdrdy = Bitfield<Intenset, bool, 2, 1, Access::ReadWrite>;
			using Txdrdy = Bitfield<Intenset, bool, 7, 1, Access::ReadWrite>;
			using Error = Bitfield<Intenset, bool, 9, 1, Access::ReadWrite>;
			using Rxto = Bitfield<Intenset, bool, 17, 1, Access::ReadWrite>;
		};
		struct Intenclr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x308;
			using Cts = Bitfield<Intenclr, bool, 0, 1, Access::ReadWrite>;
			using Ncts = Bitfield<Intenclr, bool, 1, 1, Access::ReadWrite>;
			using Rxdrdy = Bitfield<Intenclr, bool, 2, 1, Access::ReadWrite>;
			using Txdrdy = Bitfield<Intenclr, bool, 7, 1, Access::ReadWrite>;
			using Error = Bitfield<Intenclr, bool, 9, 1, Access::ReadWrite>;
			using Rxto = Bitfield<Intenclr, bool, 17, 1, Access::ReadWrite>;
		};
		struct Errorsrc {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x480;
			using Overrun = Bitfield<Errorsrc, OverrunType, 0, 1, Access::ReadWrite>;
			using Parity = Bitfield<Errorsrc, ParityType, 1, 1, Access::ReadWrite>;
			using Framing = Bitfield<Errorsrc, FramingType, 2, 1, Access::ReadWrite>;
			using Break = Bitfield<Errorsrc, BreakType, 3, 1, Access::ReadWrite>;
		};
		struct Enable {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x500;
			using Value = Bitfield<Enable, std::uint8_t, 0, 4, Access::ReadWrite>;
		};
		struct Pselrts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x508;
			using Value = Bitfield<Pselrts, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Pseltxd {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x50c;
			using Value = Bitfield<Pseltxd, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Pselcts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x510;
			using Value = Bitfield<Pselcts, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Pselrxd {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x514;
			using Value = Bitfield<Pselrxd, std::uint32_t, 0, 32, Access::ReadWrite>;
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
		struct Baudrate {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x524;
			using Value = Bitfield<Baudrate, BaudrateType, 0, 32, Access::ReadWrite>;
		};
		struct Config {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x56c;
			using Hwfc = Bitfield<Config, bool, 0, 1, Access::ReadWrite>;
			using Parity = Bitfield<Config, std::uint8_t, 1, 3, Access::ReadWrite>;
		};
	};

}
	using Uart0 = Uart::Controller<0X40002000, 2>;

} // end of namespace nrf52