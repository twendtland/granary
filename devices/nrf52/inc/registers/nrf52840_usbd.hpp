
#pragma once

#include <cstdint>
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52840 {

namespace Usbd {

	enum class RecipientType {
		Device = 0,
		Interface = 1,
		Endpoint = 2,
		Other = 3
	};

	enum class TypeType {
		Standard = 0,
		Class = 1,
		Vendor = 2
	};

	enum class BrequestType {
		Std_Get_Status = 0,
		Std_Clear_Feature = 1,
		Std_Set_Feature = 3,
		Std_Set_Address = 5,
		Std_Get_Descriptor = 6,
		Std_Set_Descriptor = 7,
		Std_Get_Configuration = 8,
		Std_Set_Configuration = 9,
		Std_Get_Interface = 10,
		Std_Set_Interface = 11,
		Std_Synch_Frame = 12
	};

	enum class StateType {
		Resume = 1,
		J = 2,
		K = 4
	};

	enum class ValueType {
		Nop = 0,
		Data0 = 1,
		Data1 = 2
	};

	template <std::uint32_t BaseAddress, std::uint16_t Irq>
	struct Controller {
		static constexpr std::uint32_t Interrupt = Irq;
		struct Tasks_Startepins {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x004;
			using Value = Bitfield<Tasks_Startepins, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Startisoin {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x024;
			using Value = Bitfield<Tasks_Startisoin, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Startepouts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x028;
			using Value = Bitfield<Tasks_Startepouts, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Startisoout {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x048;
			using Value = Bitfield<Tasks_Startisoout, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Ep0Rcvout {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x04c;
			using Value = Bitfield<Tasks_Ep0Rcvout, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Ep0Status {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x050;
			using Value = Bitfield<Tasks_Ep0Status, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Ep0Stall {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x054;
			using Value = Bitfield<Tasks_Ep0Stall, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Dpdmdrive {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x058;
			using Value = Bitfield<Tasks_Dpdmdrive, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Tasks_Dpdmnodrive {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x05c;
			using Value = Bitfield<Tasks_Dpdmnodrive, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Usbreset {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x100;
			using Value = Bitfield<Events_Usbreset, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Started {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x104;
			using Value = Bitfield<Events_Started, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Endepins {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x108;
			using Value = Bitfield<Events_Endepins, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Ep0Datadone {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x128;
			using Value = Bitfield<Events_Ep0Datadone, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Endisoin {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x12c;
			using Value = Bitfield<Events_Endisoin, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Endepouts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x130;
			using Value = Bitfield<Events_Endepouts, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Endisoout {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x150;
			using Value = Bitfield<Events_Endisoout, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Sof {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x154;
			using Value = Bitfield<Events_Sof, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Usbevent {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x158;
			using Value = Bitfield<Events_Usbevent, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Ep0Setup {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x15c;
			using Value = Bitfield<Events_Ep0Setup, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Epdata {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x160;
			using Value = Bitfield<Events_Epdata, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Events_Accessfault {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x164;
			using Value = Bitfield<Events_Accessfault, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Shorts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x200;
			using Ep0Datadone_Startepin0 = Bitfield<Shorts, bool, 0, 1, Access::ReadWrite>;
			using Ep0Datadone_Startepout0 = Bitfield<Shorts, bool, 1, 1, Access::ReadWrite>;
			using Ep0Datadone_Ep0Status = Bitfield<Shorts, bool, 2, 1, Access::ReadWrite>;
			using Endepout0_Ep0Status = Bitfield<Shorts, bool, 3, 1, Access::ReadWrite>;
			using Endepout0_Ep0Rcvout = Bitfield<Shorts, bool, 4, 1, Access::ReadWrite>;
		};
		struct Inten {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x300;
			using Usbreset = Bitfield<Inten, bool, 0, 1, Access::ReadWrite>;
			using Started = Bitfield<Inten, bool, 1, 1, Access::ReadWrite>;
			using Endepin0 = Bitfield<Inten, bool, 2, 1, Access::ReadWrite>;
			using Endepin1 = Bitfield<Inten, bool, 3, 1, Access::ReadWrite>;
			using Endepin2 = Bitfield<Inten, bool, 4, 1, Access::ReadWrite>;
			using Endepin3 = Bitfield<Inten, bool, 5, 1, Access::ReadWrite>;
			using Endepin4 = Bitfield<Inten, bool, 6, 1, Access::ReadWrite>;
			using Endepin5 = Bitfield<Inten, bool, 7, 1, Access::ReadWrite>;
			using Endepin6 = Bitfield<Inten, bool, 8, 1, Access::ReadWrite>;
			using Endepin7 = Bitfield<Inten, bool, 9, 1, Access::ReadWrite>;
			using Ep0Datadone = Bitfield<Inten, bool, 10, 1, Access::ReadWrite>;
			using Endisoin = Bitfield<Inten, bool, 11, 1, Access::ReadWrite>;
			using Endepout0 = Bitfield<Inten, bool, 12, 1, Access::ReadWrite>;
			using Endepout1 = Bitfield<Inten, bool, 13, 1, Access::ReadWrite>;
			using Endepout2 = Bitfield<Inten, bool, 14, 1, Access::ReadWrite>;
			using Endepout3 = Bitfield<Inten, bool, 15, 1, Access::ReadWrite>;
			using Endepout4 = Bitfield<Inten, bool, 16, 1, Access::ReadWrite>;
			using Endepout5 = Bitfield<Inten, bool, 17, 1, Access::ReadWrite>;
			using Endepout6 = Bitfield<Inten, bool, 18, 1, Access::ReadWrite>;
			using Endepout7 = Bitfield<Inten, bool, 19, 1, Access::ReadWrite>;
			using Endisoout = Bitfield<Inten, bool, 20, 1, Access::ReadWrite>;
			using Sof = Bitfield<Inten, bool, 21, 1, Access::ReadWrite>;
			using Usbevent = Bitfield<Inten, bool, 22, 1, Access::ReadWrite>;
			using Ep0Setup = Bitfield<Inten, bool, 23, 1, Access::ReadWrite>;
			using Epdata = Bitfield<Inten, bool, 24, 1, Access::ReadWrite>;
			using Accessfault = Bitfield<Inten, bool, 25, 1, Access::ReadWrite>;
		};
		struct Intenset {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x304;
			using Usbreset = Bitfield<Intenset, bool, 0, 1, Access::ReadWrite>;
			using Started = Bitfield<Intenset, bool, 1, 1, Access::ReadWrite>;
			using Endepin0 = Bitfield<Intenset, bool, 2, 1, Access::ReadWrite>;
			using Endepin1 = Bitfield<Intenset, bool, 3, 1, Access::ReadWrite>;
			using Endepin2 = Bitfield<Intenset, bool, 4, 1, Access::ReadWrite>;
			using Endepin3 = Bitfield<Intenset, bool, 5, 1, Access::ReadWrite>;
			using Endepin4 = Bitfield<Intenset, bool, 6, 1, Access::ReadWrite>;
			using Endepin5 = Bitfield<Intenset, bool, 7, 1, Access::ReadWrite>;
			using Endepin6 = Bitfield<Intenset, bool, 8, 1, Access::ReadWrite>;
			using Endepin7 = Bitfield<Intenset, bool, 9, 1, Access::ReadWrite>;
			using Ep0Datadone = Bitfield<Intenset, bool, 10, 1, Access::ReadWrite>;
			using Endisoin = Bitfield<Intenset, bool, 11, 1, Access::ReadWrite>;
			using Endepout0 = Bitfield<Intenset, bool, 12, 1, Access::ReadWrite>;
			using Endepout1 = Bitfield<Intenset, bool, 13, 1, Access::ReadWrite>;
			using Endepout2 = Bitfield<Intenset, bool, 14, 1, Access::ReadWrite>;
			using Endepout3 = Bitfield<Intenset, bool, 15, 1, Access::ReadWrite>;
			using Endepout4 = Bitfield<Intenset, bool, 16, 1, Access::ReadWrite>;
			using Endepout5 = Bitfield<Intenset, bool, 17, 1, Access::ReadWrite>;
			using Endepout6 = Bitfield<Intenset, bool, 18, 1, Access::ReadWrite>;
			using Endepout7 = Bitfield<Intenset, bool, 19, 1, Access::ReadWrite>;
			using Endisoout = Bitfield<Intenset, bool, 20, 1, Access::ReadWrite>;
			using Sof = Bitfield<Intenset, bool, 21, 1, Access::ReadWrite>;
			using Usbevent = Bitfield<Intenset, bool, 22, 1, Access::ReadWrite>;
			using Ep0Setup = Bitfield<Intenset, bool, 23, 1, Access::ReadWrite>;
			using Epdata = Bitfield<Intenset, bool, 24, 1, Access::ReadWrite>;
			using Accessfault = Bitfield<Intenset, bool, 25, 1, Access::ReadWrite>;
		};
		struct Intenclr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x308;
			using Usbreset = Bitfield<Intenclr, bool, 0, 1, Access::ReadWrite>;
			using Started = Bitfield<Intenclr, bool, 1, 1, Access::ReadWrite>;
			using Endepin0 = Bitfield<Intenclr, bool, 2, 1, Access::ReadWrite>;
			using Endepin1 = Bitfield<Intenclr, bool, 3, 1, Access::ReadWrite>;
			using Endepin2 = Bitfield<Intenclr, bool, 4, 1, Access::ReadWrite>;
			using Endepin3 = Bitfield<Intenclr, bool, 5, 1, Access::ReadWrite>;
			using Endepin4 = Bitfield<Intenclr, bool, 6, 1, Access::ReadWrite>;
			using Endepin5 = Bitfield<Intenclr, bool, 7, 1, Access::ReadWrite>;
			using Endepin6 = Bitfield<Intenclr, bool, 8, 1, Access::ReadWrite>;
			using Endepin7 = Bitfield<Intenclr, bool, 9, 1, Access::ReadWrite>;
			using Ep0Datadone = Bitfield<Intenclr, bool, 10, 1, Access::ReadWrite>;
			using Endisoin = Bitfield<Intenclr, bool, 11, 1, Access::ReadWrite>;
			using Endepout0 = Bitfield<Intenclr, bool, 12, 1, Access::ReadWrite>;
			using Endepout1 = Bitfield<Intenclr, bool, 13, 1, Access::ReadWrite>;
			using Endepout2 = Bitfield<Intenclr, bool, 14, 1, Access::ReadWrite>;
			using Endepout3 = Bitfield<Intenclr, bool, 15, 1, Access::ReadWrite>;
			using Endepout4 = Bitfield<Intenclr, bool, 16, 1, Access::ReadWrite>;
			using Endepout5 = Bitfield<Intenclr, bool, 17, 1, Access::ReadWrite>;
			using Endepout6 = Bitfield<Intenclr, bool, 18, 1, Access::ReadWrite>;
			using Endepout7 = Bitfield<Intenclr, bool, 19, 1, Access::ReadWrite>;
			using Endisoout = Bitfield<Intenclr, bool, 20, 1, Access::ReadWrite>;
			using Sof = Bitfield<Intenclr, bool, 21, 1, Access::ReadWrite>;
			using Usbevent = Bitfield<Intenclr, bool, 22, 1, Access::ReadWrite>;
			using Ep0Setup = Bitfield<Intenclr, bool, 23, 1, Access::ReadWrite>;
			using Epdata = Bitfield<Intenclr, bool, 24, 1, Access::ReadWrite>;
			using Accessfault = Bitfield<Intenclr, bool, 25, 1, Access::ReadWrite>;
		};
		struct Eventcause {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x400;
			using Isooutcrc = Bitfield<Eventcause, bool, 0, 1, Access::ReadWrite>;
			using Suspend = Bitfield<Eventcause, bool, 8, 1, Access::ReadWrite>;
			using Resume = Bitfield<Eventcause, bool, 9, 1, Access::ReadWrite>;
			using Ready = Bitfield<Eventcause, bool, 11, 1, Access::ReadWrite>;
		};
		struct Busstate {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x404;
			using Dm = Bitfield<Busstate, bool, 0, 1, Access::ReadWrite>;
			using Dp = Bitfield<Busstate, bool, 1, 1, Access::ReadWrite>;
		};
		struct Halted {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x420;
			using Value = Bitfield<Halted, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Epstatus {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x468;
			using Epin0 = Bitfield<Epstatus, bool, 0, 1, Access::ReadWrite>;
			using Epin1 = Bitfield<Epstatus, bool, 1, 1, Access::ReadWrite>;
			using Epin2 = Bitfield<Epstatus, bool, 2, 1, Access::ReadWrite>;
			using Epin3 = Bitfield<Epstatus, bool, 3, 1, Access::ReadWrite>;
			using Epin4 = Bitfield<Epstatus, bool, 4, 1, Access::ReadWrite>;
			using Epin5 = Bitfield<Epstatus, bool, 5, 1, Access::ReadWrite>;
			using Epin6 = Bitfield<Epstatus, bool, 6, 1, Access::ReadWrite>;
			using Epin7 = Bitfield<Epstatus, bool, 7, 1, Access::ReadWrite>;
			using Epin8 = Bitfield<Epstatus, bool, 8, 1, Access::ReadWrite>;
			using Epout0 = Bitfield<Epstatus, bool, 16, 1, Access::ReadWrite>;
			using Epout1 = Bitfield<Epstatus, bool, 17, 1, Access::ReadWrite>;
			using Epout2 = Bitfield<Epstatus, bool, 18, 1, Access::ReadWrite>;
			using Epout3 = Bitfield<Epstatus, bool, 19, 1, Access::ReadWrite>;
			using Epout4 = Bitfield<Epstatus, bool, 20, 1, Access::ReadWrite>;
			using Epout5 = Bitfield<Epstatus, bool, 21, 1, Access::ReadWrite>;
			using Epout6 = Bitfield<Epstatus, bool, 22, 1, Access::ReadWrite>;
			using Epout7 = Bitfield<Epstatus, bool, 23, 1, Access::ReadWrite>;
			using Epout8 = Bitfield<Epstatus, bool, 24, 1, Access::ReadWrite>;
		};
		struct Epdatastatus {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x46c;
			using Epin1 = Bitfield<Epdatastatus, bool, 1, 1, Access::ReadWrite>;
			using Epin2 = Bitfield<Epdatastatus, bool, 2, 1, Access::ReadWrite>;
			using Epin3 = Bitfield<Epdatastatus, bool, 3, 1, Access::ReadWrite>;
			using Epin4 = Bitfield<Epdatastatus, bool, 4, 1, Access::ReadWrite>;
			using Epin5 = Bitfield<Epdatastatus, bool, 5, 1, Access::ReadWrite>;
			using Epin6 = Bitfield<Epdatastatus, bool, 6, 1, Access::ReadWrite>;
			using Epin7 = Bitfield<Epdatastatus, bool, 7, 1, Access::ReadWrite>;
			using Epout1 = Bitfield<Epdatastatus, bool, 17, 1, Access::ReadWrite>;
			using Epout2 = Bitfield<Epdatastatus, bool, 18, 1, Access::ReadWrite>;
			using Epout3 = Bitfield<Epdatastatus, bool, 19, 1, Access::ReadWrite>;
			using Epout4 = Bitfield<Epdatastatus, bool, 20, 1, Access::ReadWrite>;
			using Epout5 = Bitfield<Epdatastatus, bool, 21, 1, Access::ReadWrite>;
			using Epout6 = Bitfield<Epdatastatus, bool, 22, 1, Access::ReadWrite>;
			using Epout7 = Bitfield<Epdatastatus, bool, 23, 1, Access::ReadWrite>;
		};
		struct Usbaddr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x470;
			using Addr = Bitfield<Usbaddr, std::uint8_t, 0, 7, Access::ReadWrite>;
		};
		struct Bmrequesttype {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x480;
			using Recipient = Bitfield<Bmrequesttype, RecipientType, 0, 5, Access::ReadWrite>;
			using Type = Bitfield<Bmrequesttype, TypeType, 5, 2, Access::ReadWrite>;
			using Direction = Bitfield<Bmrequesttype, bool, 7, 1, Access::ReadWrite>;
		};
		struct Brequest {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x484;
			using Value = Bitfield<Brequest, BrequestType, 0, 8, Access::ReadWrite>;
		};
		struct Wvaluel {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x488;
			using Value = Bitfield<Wvaluel, std::uint8_t, 0, 8, Access::ReadWrite>;
		};
		struct Wvalueh {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x48c;
			using Value = Bitfield<Wvalueh, std::uint8_t, 0, 8, Access::ReadWrite>;
		};
		struct Windexl {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x490;
			using Value = Bitfield<Windexl, std::uint8_t, 0, 8, Access::ReadWrite>;
		};
		struct Windexh {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x494;
			using Value = Bitfield<Windexh, std::uint8_t, 0, 8, Access::ReadWrite>;
		};
		struct Wlengthl {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x498;
			using Value = Bitfield<Wlengthl, std::uint8_t, 0, 8, Access::ReadWrite>;
		};
		struct Wlengthh {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x49c;
			using Value = Bitfield<Wlengthh, std::uint8_t, 0, 8, Access::ReadWrite>;
		};
		struct Size {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x4a0;
			using Value = Bitfield<Size, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Enable {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x500;
			using Value = Bitfield<Enable, bool, 0, 1, Access::ReadWrite>;
		};
		struct Usbpullup {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x504;
			using Connect = Bitfield<Usbpullup, bool, 0, 1, Access::ReadWrite>;
		};
		struct Dpdmvalue {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x508;
			using State = Bitfield<Dpdmvalue, StateType, 0, 5, Access::ReadWrite>;
		};
		struct Dtoggle {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x50c;
			using Ep = Bitfield<Dtoggle, std::uint8_t, 0, 3, Access::ReadWrite>;
			using Io = Bitfield<Dtoggle, bool, 7, 1, Access::ReadWrite>;
			using Value = Bitfield<Dtoggle, ValueType, 8, 2, Access::ReadWrite>;
		};
		struct Epinen {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x510;
			using In0 = Bitfield<Epinen, bool, 0, 1, Access::ReadWrite>;
			using In1 = Bitfield<Epinen, bool, 1, 1, Access::ReadWrite>;
			using In2 = Bitfield<Epinen, bool, 2, 1, Access::ReadWrite>;
			using In3 = Bitfield<Epinen, bool, 3, 1, Access::ReadWrite>;
			using In4 = Bitfield<Epinen, bool, 4, 1, Access::ReadWrite>;
			using In5 = Bitfield<Epinen, bool, 5, 1, Access::ReadWrite>;
			using In6 = Bitfield<Epinen, bool, 6, 1, Access::ReadWrite>;
			using In7 = Bitfield<Epinen, bool, 7, 1, Access::ReadWrite>;
			using Isoin = Bitfield<Epinen, bool, 8, 1, Access::ReadWrite>;
		};
		struct Epouten {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x514;
			using Out0 = Bitfield<Epouten, bool, 0, 1, Access::ReadWrite>;
			using Out1 = Bitfield<Epouten, bool, 1, 1, Access::ReadWrite>;
			using Out2 = Bitfield<Epouten, bool, 2, 1, Access::ReadWrite>;
			using Out3 = Bitfield<Epouten, bool, 3, 1, Access::ReadWrite>;
			using Out4 = Bitfield<Epouten, bool, 4, 1, Access::ReadWrite>;
			using Out5 = Bitfield<Epouten, bool, 5, 1, Access::ReadWrite>;
			using Out6 = Bitfield<Epouten, bool, 6, 1, Access::ReadWrite>;
			using Out7 = Bitfield<Epouten, bool, 7, 1, Access::ReadWrite>;
			using Isoout = Bitfield<Epouten, bool, 8, 1, Access::ReadWrite>;
		};
		struct Epstall {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x518;
			using Ep = Bitfield<Epstall, std::uint8_t, 0, 3, Access::ReadWrite>;
			using Io = Bitfield<Epstall, bool, 7, 1, Access::ReadWrite>;
			using Stall = Bitfield<Epstall, bool, 8, 1, Access::ReadWrite>;
		};
		struct Isosplit {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x51c;
			using Split = Bitfield<Isosplit, std::uint16_t, 0, 16, Access::ReadWrite>;
		};
		struct Framecntr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x520;
			using Value = Bitfield<Framecntr, std::uint16_t, 0, 11, Access::ReadWrite>;
		};
		struct Isoinconfig {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x530;
			using Response = Bitfield<Isoinconfig, bool, 0, 1, Access::ReadWrite>;
		};
		struct Epins {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x600;
			using Value = Bitfield<Epins, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Isoin {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x6a0;
			using Value = Bitfield<Isoin, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Epouts {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x700;
			using Value = Bitfield<Epouts, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
		struct Isoout {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x7a0;
			using Value = Bitfield<Isoout, std::uint32_t, 0, 32, Access::ReadWrite>;
		};
	};

}
	using Usbd = Usbd::Controller<0X40027000, 39>;

} // end of namespace nrf52840