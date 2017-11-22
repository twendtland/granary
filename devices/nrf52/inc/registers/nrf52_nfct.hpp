
#pragma once

#include <cstdint>
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52 {

namespace Nfct {

	enum class FramedelaymodeType {
		Freerun = 0,
		Window = 1,
		Exactval = 2,
		Windowgrid = 3
	};

	enum class BitframesddType {
		Sdd00000 = 0,
		Sdd00001 = 1,
		Sdd00010 = 2,
		Sdd00100 = 4,
		Sdd01000 = 8,
		Sdd10000 = 16
	};

	enum class NfcidsizeType {
		Nfcid1Single = 0,
		Nfcid1Double = 1,
		Nfcid1Triple = 2
	};

	template <std::uint32_t BaseAddress, std::uint16_t Irq>
	struct Controller {
		static constexpr std::uint32_t Interrupt = Irq;
		struct Tasks_Activate {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x000;
			using Value = Bitfield<Tasks_Activate, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Disable {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x004;
			using Value = Bitfield<Tasks_Disable, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Sense {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x008;
			using Value = Bitfield<Tasks_Sense, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Starttx {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x00c;
			using Value = Bitfield<Tasks_Starttx, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Enablerxdata {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x01c;
			using Value = Bitfield<Tasks_Enablerxdata, bool, 0, 1, Access::ReadWrite>;
		};
		struct Tasks_Goidle {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x024;
			using Value = Bitfield<Tasks_Goidle, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Gosleep {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x028;
			using Value = Bitfield<Tasks_Gosleep, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Ready {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x100;
			using Value = Bitfield<Events_Ready, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Fielddetected {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x104;
			using Value = Bitfield<Events_Fielddetected, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Fieldlost {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x108;
			using Value = Bitfield<Events_Fieldlost, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Txframestart {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x10c;
			using Value = Bitfield<Events_Txframestart, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Txframeend {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x110;
			using Value = Bitfield<Events_Txframeend, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Rxframestart {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x114;
			using Value = Bitfield<Events_Rxframestart, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Rxframeend {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x118;
			using Value = Bitfield<Events_Rxframeend, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Error {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x11c;
			using Value = Bitfield<Events_Error, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Rxerror {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x128;
			using Value = Bitfield<Events_Rxerror, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Endrx {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x12c;
			using Value = Bitfield<Events_Endrx, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Endtx {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x130;
			using Value = Bitfield<Events_Endtx, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Autocolresstarted {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x138;
			using Value = Bitfield<Events_Autocolresstarted, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Collision {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x148;
			using Value = Bitfield<Events_Collision, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Selected {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x14c;
			using Value = Bitfield<Events_Selected, bool, 0, 1, Access::ReadWrite>;
		};
		struct Events_Started {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x150;
			using Value = Bitfield<Events_Started, bool, 0, 1, Access::ReadWrite>;
		};
		struct Shorts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x200;
			using Fielddetected_Activate = Bitfield<Shorts, bool, 0, 1, Access::ReadWrite>;
			using Fieldlost_Sense = Bitfield<Shorts, bool, 1, 1, Access::ReadWrite>;
		};
		struct Inten {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x300;
			using Ready = Bitfield<Inten, bool, 0, 1, Access::ReadWrite>;
			using Fielddetected = Bitfield<Inten, bool, 1, 1, Access::ReadWrite>;
			using Fieldlost = Bitfield<Inten, bool, 2, 1, Access::ReadWrite>;
			using Txframestart = Bitfield<Inten, bool, 3, 1, Access::ReadWrite>;
			using Txframeend = Bitfield<Inten, bool, 4, 1, Access::ReadWrite>;
			using Rxframestart = Bitfield<Inten, bool, 5, 1, Access::ReadWrite>;
			using Rxframeend = Bitfield<Inten, bool, 6, 1, Access::ReadWrite>;
			using Error = Bitfield<Inten, bool, 7, 1, Access::ReadWrite>;
			using Rxerror = Bitfield<Inten, bool, 10, 1, Access::ReadWrite>;
			using Endrx = Bitfield<Inten, bool, 11, 1, Access::ReadWrite>;
			using Endtx = Bitfield<Inten, bool, 12, 1, Access::ReadWrite>;
			using Autocolresstarted = Bitfield<Inten, bool, 14, 1, Access::ReadWrite>;
			using Collision = Bitfield<Inten, bool, 18, 1, Access::ReadWrite>;
			using Selected = Bitfield<Inten, bool, 19, 1, Access::ReadWrite>;
			using Started = Bitfield<Inten, bool, 20, 1, Access::ReadWrite>;
		};
		struct Errorstatus {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x404;
			using Framedelaytimeout = Bitfield<Errorstatus, bool, 0, 1, Access::ReadWrite>;
			using Nfcfieldtoostrong = Bitfield<Errorstatus, bool, 2, 1, Access::ReadWrite>;
			using Nfcfieldtooweak = Bitfield<Errorstatus, bool, 3, 1, Access::ReadWrite>;
		};
		struct Framestatus {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x40c;
			using Value = Bitfield<Framestatus, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Currentloadctrl {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x430;
			using Value = Bitfield<Currentloadctrl, std::uint8_t, 0, 6, Access::ReadWrite>;
		};
		struct Fieldpresent {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x43c;
			using Value = Bitfield<Fieldpresent, bool, 0, 1, Access::ReadWrite>;
			using Lockdetect = Bitfield<Fieldpresent, bool, 1, 1, Access::ReadWrite>;
		};
		struct Framedelaymin {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x504;
			using Value = Bitfield<Framedelaymin, std::uint16_t, 0, 16, Access::ReadWrite>;
		};
		struct Framedelaymax {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x508;
			using Value = Bitfield<Framedelaymax, std::uint16_t, 0, 16, Access::ReadWrite>;
		};
		struct Framedelaymode {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x50c;
			using Value = Bitfield<Framedelaymode, FramedelaymodeType, 0, 2, Access::ReadWrite>;
		};
		struct Packetptr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x510;
			using Ptr = Bitfield<Packetptr, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Maxlen {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x514;
			using Value = Bitfield<Maxlen, std::uint16_t, 0, 9, Access::ReadWrite>;
		};
		struct Txd {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x518;
            using Parity = Bitfield<Txd, bool, 0, 1, Access::ReadWrite>;
			using DiscardMode = Bitfield<Txd, bool, 1, 1, Access::ReadWrite>;
            using Sof = Bitfield<Txd, bool, 2, 1, Access::ReadWrite>;
            using CrcMode = Bitfield<Txd, bool, 4, 1, Access::ReadWrite>;
		};
        struct TxAmount {
            using WidthType = std::uint32_t;
            static constexpr WidthType Address = BaseAddress + 0x51C;
            using TxDataBits = Bitfield<Txd, std::uint8_t, 0, 3, Access::ReadWrite>;
            using TxDataBytes = Bitfield<Txd, std::uint16_t, 3, 9, Access::ReadWrite>;
        };
		struct Rxd {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x520;
			using Value = Bitfield<Rxd, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
        struct RxAmount {
            using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x524;
			using Bits = Bitfield<Rxd, std::uint8_t, 0, 3, Access::ReadWrite>;
            using Bytes = Bitfield<Rxd, std::uint16_t, 3, 9, Access::ReadWrite>;
        };
		struct Nfcid1_Last {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x590;
			using Nfcid1_Z = Bitfield<Nfcid1_Last, std::uint8_t, 0, 8, Access::ReadWrite>;
			using Nfcid1_Y = Bitfield<Nfcid1_Last, std::uint8_t, 8, 8, Access::ReadWrite>;
			using Nfcid1_X = Bitfield<Nfcid1_Last, std::uint8_t, 16, 8, Access::ReadWrite>;
			using Nfcid1_W = Bitfield<Nfcid1_Last, std::uint8_t, 24, 8, Access::ReadWrite>;
		};
		struct Nfcid1_2Nd_Last {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x594;
			using Nfcid1_V = Bitfield<Nfcid1_2Nd_Last, std::uint8_t, 0, 8, Access::ReadWrite>;
			using Nfcid1_U = Bitfield<Nfcid1_2Nd_Last, std::uint8_t, 8, 8, Access::ReadWrite>;
			using Nfcid1_T = Bitfield<Nfcid1_2Nd_Last, std::uint8_t, 16, 8, Access::ReadWrite>;
		};
		struct Nfcid1_3Rd_Last {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x598;
			using Nfcid1_S = Bitfield<Nfcid1_3Rd_Last, std::uint8_t, 0, 8, Access::ReadWrite>;
			using Nfcid1_R = Bitfield<Nfcid1_3Rd_Last, std::uint8_t, 8, 8, Access::ReadWrite>;
			using Nfcid1_Q = Bitfield<Nfcid1_3Rd_Last, std::uint8_t, 16, 8, Access::ReadWrite>;
		};
		struct Sensres {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x5a0;
			using Bitframesdd = Bitfield<Sensres, BitframesddType, 0, 5, Access::ReadWrite>;
			using Rfu5 = Bitfield<Sensres, bool, 5, 1, Access::ReadWrite>;
			using Nfcidsize = Bitfield<Sensres, NfcidsizeType, 6, 2, Access::ReadWrite>;
			using Platfconfig = Bitfield<Sensres, std::uint8_t, 8, 4, Access::ReadWrite>;
			using Rfu74 = Bitfield<Sensres, std::uint8_t, 12, 4, Access::ReadWrite>;
		};
		struct Selres {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x5a4;
			using Rfu10 = Bitfield<Selres, std::uint8_t, 0, 2, Access::ReadWrite>;
			using Cascade = Bitfield<Selres, bool, 2, 1, Access::ReadWrite>;
			using Rfu43 = Bitfield<Selres, std::uint8_t, 3, 2, Access::ReadWrite>;
			using Protocol = Bitfield<Selres, std::uint8_t, 5, 2, Access::ReadWrite>;
			using Rfu7 = Bitfield<Selres, bool, 7, 1, Access::ReadWrite>;
		};
	};

}
	using Nfc0 = Nfct::Controller<0X40005000, 5>;

} // end of namespace nrf52
