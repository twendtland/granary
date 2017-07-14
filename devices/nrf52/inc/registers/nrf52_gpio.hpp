
#pragma once

#include <cstdint>
#include <tuple>
#include "Bitfield.hpp"

using namespace rye;

namespace nrf52 {
	template <std::uint32_t BaseAddress, std::uint16_t Irq>
	struct PinController {
		struct Out {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x504;
            using Pins = Bitfield<Out, std::uint32_t, 0, 32, AccessType::ReadWrite>;

			using Pin0 = Bitfield<Out, bool, 0, 1, AccessType::ReadWrite>;
			using Pin1 = Bitfield<Out, bool, 1, 1, AccessType::ReadWrite>;
			using Pin2 = Bitfield<Out, bool, 2, 1, AccessType::ReadWrite>;
			using Pin3 = Bitfield<Out, bool, 3, 1, AccessType::ReadWrite>;
			using Pin4 = Bitfield<Out, bool, 4, 1, AccessType::ReadWrite>;
			using Pin5 = Bitfield<Out, bool, 5, 1, AccessType::ReadWrite>;
			using Pin6 = Bitfield<Out, bool, 6, 1, AccessType::ReadWrite>;
			using Pin7 = Bitfield<Out, bool, 7, 1, AccessType::ReadWrite>;
			using Pin8 = Bitfield<Out, bool, 8, 1, AccessType::ReadWrite>;
			using Pin9 = Bitfield<Out, bool, 9, 1, AccessType::ReadWrite>;
			using Pin10 = Bitfield<Out, bool, 10, 1, AccessType::ReadWrite>;
			using Pin11 = Bitfield<Out, bool, 11, 1, AccessType::ReadWrite>;
			using Pin12 = Bitfield<Out, bool, 12, 1, AccessType::ReadWrite>;
			using Pin13 = Bitfield<Out, bool, 13, 1, AccessType::ReadWrite>;
			using Pin14 = Bitfield<Out, bool, 14, 1, AccessType::ReadWrite>;
			using Pin15 = Bitfield<Out, bool, 15, 1, AccessType::ReadWrite>;
			using Pin16 = Bitfield<Out, bool, 16, 1, AccessType::ReadWrite>;
			using Pin17 = Bitfield<Out, bool, 17, 1, AccessType::ReadWrite>;
			using Pin18 = Bitfield<Out, bool, 18, 1, AccessType::ReadWrite>;
			using Pin19 = Bitfield<Out, bool, 19, 1, AccessType::ReadWrite>;
			using Pin20 = Bitfield<Out, bool, 20, 1, AccessType::ReadWrite>;
			using Pin21 = Bitfield<Out, bool, 21, 1, AccessType::ReadWrite>;
			using Pin22 = Bitfield<Out, bool, 22, 1, AccessType::ReadWrite>;
			using Pin23 = Bitfield<Out, bool, 23, 1, AccessType::ReadWrite>;
			using Pin24 = Bitfield<Out, bool, 24, 1, AccessType::ReadWrite>;
			using Pin25 = Bitfield<Out, bool, 25, 1, AccessType::ReadWrite>;
			using Pin26 = Bitfield<Out, bool, 26, 1, AccessType::ReadWrite>;
			using Pin27 = Bitfield<Out, bool, 27, 1, AccessType::ReadWrite>;
			using Pin28 = Bitfield<Out, bool, 28, 1, AccessType::ReadWrite>;
			using Pin29 = Bitfield<Out, bool, 29, 1, AccessType::ReadWrite>;
			using Pin30 = Bitfield<Out, bool, 30, 1, AccessType::ReadWrite>;
			using Pin31 = Bitfield<Out, bool, 31, 1, AccessType::ReadWrite>;
		};
		struct Outset {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x508;
            using Pins = Bitfield<Outset, std::uint32_t, 0, 32, AccessType::ReadWrite>;

			using Pin0 = Bitfield<Outset, bool, 0, 1, AccessType::ReadWrite>;
			using Pin1 = Bitfield<Outset, bool, 1, 1, AccessType::ReadWrite>;
			using Pin2 = Bitfield<Outset, bool, 2, 1, AccessType::ReadWrite>;
			using Pin3 = Bitfield<Outset, bool, 3, 1, AccessType::ReadWrite>;
			using Pin4 = Bitfield<Outset, bool, 4, 1, AccessType::ReadWrite>;
			using Pin5 = Bitfield<Outset, bool, 5, 1, AccessType::ReadWrite>;
			using Pin6 = Bitfield<Outset, bool, 6, 1, AccessType::ReadWrite>;
			using Pin7 = Bitfield<Outset, bool, 7, 1, AccessType::ReadWrite>;
			using Pin8 = Bitfield<Outset, bool, 8, 1, AccessType::ReadWrite>;
			using Pin9 = Bitfield<Outset, bool, 9, 1, AccessType::ReadWrite>;
			using Pin10 = Bitfield<Outset, bool, 10, 1, AccessType::ReadWrite>;
			using Pin11 = Bitfield<Outset, bool, 11, 1, AccessType::ReadWrite>;
			using Pin12 = Bitfield<Outset, bool, 12, 1, AccessType::ReadWrite>;
			using Pin13 = Bitfield<Outset, bool, 13, 1, AccessType::ReadWrite>;
			using Pin14 = Bitfield<Outset, bool, 14, 1, AccessType::ReadWrite>;
			using Pin15 = Bitfield<Outset, bool, 15, 1, AccessType::ReadWrite>;
			using Pin16 = Bitfield<Outset, bool, 16, 1, AccessType::ReadWrite>;
			using Pin17 = Bitfield<Outset, bool, 17, 1, AccessType::ReadWrite>;
			using Pin18 = Bitfield<Outset, bool, 18, 1, AccessType::ReadWrite>;
			using Pin19 = Bitfield<Outset, bool, 19, 1, AccessType::ReadWrite>;
			using Pin20 = Bitfield<Outset, bool, 20, 1, AccessType::ReadWrite>;
			using Pin21 = Bitfield<Outset, bool, 21, 1, AccessType::ReadWrite>;
			using Pin22 = Bitfield<Outset, bool, 22, 1, AccessType::ReadWrite>;
			using Pin23 = Bitfield<Outset, bool, 23, 1, AccessType::ReadWrite>;
			using Pin24 = Bitfield<Outset, bool, 24, 1, AccessType::ReadWrite>;
			using Pin25 = Bitfield<Outset, bool, 25, 1, AccessType::ReadWrite>;
			using Pin26 = Bitfield<Outset, bool, 26, 1, AccessType::ReadWrite>;
			using Pin27 = Bitfield<Outset, bool, 27, 1, AccessType::ReadWrite>;
			using Pin28 = Bitfield<Outset, bool, 28, 1, AccessType::ReadWrite>;
			using Pin29 = Bitfield<Outset, bool, 29, 1, AccessType::ReadWrite>;
			using Pin30 = Bitfield<Outset, bool, 30, 1, AccessType::ReadWrite>;
			using Pin31 = Bitfield<Outset, bool, 31, 1, AccessType::ReadWrite>;
		};
		struct Outclr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x50c;
            using Pins = Bitfield<Outset, std::uint32_t, 0, 32, AccessType::ReadWrite>;

			using Pin0 = Bitfield<Outclr, bool, 0, 1, AccessType::ReadWrite>;
			using Pin1 = Bitfield<Outclr, bool, 1, 1, AccessType::ReadWrite>;
			using Pin2 = Bitfield<Outclr, bool, 2, 1, AccessType::ReadWrite>;
			using Pin3 = Bitfield<Outclr, bool, 3, 1, AccessType::ReadWrite>;
			using Pin4 = Bitfield<Outclr, bool, 4, 1, AccessType::ReadWrite>;
			using Pin5 = Bitfield<Outclr, bool, 5, 1, AccessType::ReadWrite>;
			using Pin6 = Bitfield<Outclr, bool, 6, 1, AccessType::ReadWrite>;
			using Pin7 = Bitfield<Outclr, bool, 7, 1, AccessType::ReadWrite>;
			using Pin8 = Bitfield<Outclr, bool, 8, 1, AccessType::ReadWrite>;
			using Pin9 = Bitfield<Outclr, bool, 9, 1, AccessType::ReadWrite>;
			using Pin10 = Bitfield<Outclr, bool, 10, 1, AccessType::ReadWrite>;
			using Pin11 = Bitfield<Outclr, bool, 11, 1, AccessType::ReadWrite>;
			using Pin12 = Bitfield<Outclr, bool, 12, 1, AccessType::ReadWrite>;
			using Pin13 = Bitfield<Outclr, bool, 13, 1, AccessType::ReadWrite>;
			using Pin14 = Bitfield<Outclr, bool, 14, 1, AccessType::ReadWrite>;
			using Pin15 = Bitfield<Outclr, bool, 15, 1, AccessType::ReadWrite>;
			using Pin16 = Bitfield<Outclr, bool, 16, 1, AccessType::ReadWrite>;
			using Pin17 = Bitfield<Outclr, bool, 17, 1, AccessType::ReadWrite>;
			using Pin18 = Bitfield<Outclr, bool, 18, 1, AccessType::ReadWrite>;
			using Pin19 = Bitfield<Outclr, bool, 19, 1, AccessType::ReadWrite>;
			using Pin20 = Bitfield<Outclr, bool, 20, 1, AccessType::ReadWrite>;
			using Pin21 = Bitfield<Outclr, bool, 21, 1, AccessType::ReadWrite>;
			using Pin22 = Bitfield<Outclr, bool, 22, 1, AccessType::ReadWrite>;
			using Pin23 = Bitfield<Outclr, bool, 23, 1, AccessType::ReadWrite>;
			using Pin24 = Bitfield<Outclr, bool, 24, 1, AccessType::ReadWrite>;
			using Pin25 = Bitfield<Outclr, bool, 25, 1, AccessType::ReadWrite>;
			using Pin26 = Bitfield<Outclr, bool, 26, 1, AccessType::ReadWrite>;
			using Pin27 = Bitfield<Outclr, bool, 27, 1, AccessType::ReadWrite>;
			using Pin28 = Bitfield<Outclr, bool, 28, 1, AccessType::ReadWrite>;
			using Pin29 = Bitfield<Outclr, bool, 29, 1, AccessType::ReadWrite>;
			using Pin30 = Bitfield<Outclr, bool, 30, 1, AccessType::ReadWrite>;
			using Pin31 = Bitfield<Outclr, bool, 31, 1, AccessType::ReadWrite>;
		};
		struct In {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x510;
			using Pin0 = Bitfield<In, bool, 0, 1, AccessType::ReadWrite>;
			using Pin1 = Bitfield<In, bool, 1, 1, AccessType::ReadWrite>;
			using Pin2 = Bitfield<In, bool, 2, 1, AccessType::ReadWrite>;
			using Pin3 = Bitfield<In, bool, 3, 1, AccessType::ReadWrite>;
			using Pin4 = Bitfield<In, bool, 4, 1, AccessType::ReadWrite>;
			using Pin5 = Bitfield<In, bool, 5, 1, AccessType::ReadWrite>;
			using Pin6 = Bitfield<In, bool, 6, 1, AccessType::ReadWrite>;
			using Pin7 = Bitfield<In, bool, 7, 1, AccessType::ReadWrite>;
			using Pin8 = Bitfield<In, bool, 8, 1, AccessType::ReadWrite>;
			using Pin9 = Bitfield<In, bool, 9, 1, AccessType::ReadWrite>;
			using Pin10 = Bitfield<In, bool, 10, 1, AccessType::ReadWrite>;
			using Pin11 = Bitfield<In, bool, 11, 1, AccessType::ReadWrite>;
			using Pin12 = Bitfield<In, bool, 12, 1, AccessType::ReadWrite>;
			using Pin13 = Bitfield<In, bool, 13, 1, AccessType::ReadWrite>;
			using Pin14 = Bitfield<In, bool, 14, 1, AccessType::ReadWrite>;
			using Pin15 = Bitfield<In, bool, 15, 1, AccessType::ReadWrite>;
			using Pin16 = Bitfield<In, bool, 16, 1, AccessType::ReadWrite>;
			using Pin17 = Bitfield<In, bool, 17, 1, AccessType::ReadWrite>;
			using Pin18 = Bitfield<In, bool, 18, 1, AccessType::ReadWrite>;
			using Pin19 = Bitfield<In, bool, 19, 1, AccessType::ReadWrite>;
			using Pin20 = Bitfield<In, bool, 20, 1, AccessType::ReadWrite>;
			using Pin21 = Bitfield<In, bool, 21, 1, AccessType::ReadWrite>;
			using Pin22 = Bitfield<In, bool, 22, 1, AccessType::ReadWrite>;
			using Pin23 = Bitfield<In, bool, 23, 1, AccessType::ReadWrite>;
			using Pin24 = Bitfield<In, bool, 24, 1, AccessType::ReadWrite>;
			using Pin25 = Bitfield<In, bool, 25, 1, AccessType::ReadWrite>;
			using Pin26 = Bitfield<In, bool, 26, 1, AccessType::ReadWrite>;
			using Pin27 = Bitfield<In, bool, 27, 1, AccessType::ReadWrite>;
			using Pin28 = Bitfield<In, bool, 28, 1, AccessType::ReadWrite>;
			using Pin29 = Bitfield<In, bool, 29, 1, AccessType::ReadWrite>;
			using Pin30 = Bitfield<In, bool, 30, 1, AccessType::ReadWrite>;
			using Pin31 = Bitfield<In, bool, 31, 1, AccessType::ReadWrite>;
		};
		struct Dir {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x514;
			using Pin0 = Bitfield<Dir, bool, 0, 1, AccessType::ReadWrite>;
			using Pin1 = Bitfield<Dir, bool, 1, 1, AccessType::ReadWrite>;
			using Pin2 = Bitfield<Dir, bool, 2, 1, AccessType::ReadWrite>;
			using Pin3 = Bitfield<Dir, bool, 3, 1, AccessType::ReadWrite>;
			using Pin4 = Bitfield<Dir, bool, 4, 1, AccessType::ReadWrite>;
			using Pin5 = Bitfield<Dir, bool, 5, 1, AccessType::ReadWrite>;
			using Pin6 = Bitfield<Dir, bool, 6, 1, AccessType::ReadWrite>;
			using Pin7 = Bitfield<Dir, bool, 7, 1, AccessType::ReadWrite>;
			using Pin8 = Bitfield<Dir, bool, 8, 1, AccessType::ReadWrite>;
			using Pin9 = Bitfield<Dir, bool, 9, 1, AccessType::ReadWrite>;
			using Pin10 = Bitfield<Dir, bool, 10, 1, AccessType::ReadWrite>;
			using Pin11 = Bitfield<Dir, bool, 11, 1, AccessType::ReadWrite>;
			using Pin12 = Bitfield<Dir, bool, 12, 1, AccessType::ReadWrite>;
			using Pin13 = Bitfield<Dir, bool, 13, 1, AccessType::ReadWrite>;
			using Pin14 = Bitfield<Dir, bool, 14, 1, AccessType::ReadWrite>;
			using Pin15 = Bitfield<Dir, bool, 15, 1, AccessType::ReadWrite>;
			using Pin16 = Bitfield<Dir, bool, 16, 1, AccessType::ReadWrite>;
			using Pin17 = Bitfield<Dir, bool, 17, 1, AccessType::ReadWrite>;
			using Pin18 = Bitfield<Dir, bool, 18, 1, AccessType::ReadWrite>;
			using Pin19 = Bitfield<Dir, bool, 19, 1, AccessType::ReadWrite>;
			using Pin20 = Bitfield<Dir, bool, 20, 1, AccessType::ReadWrite>;
			using Pin21 = Bitfield<Dir, bool, 21, 1, AccessType::ReadWrite>;
			using Pin22 = Bitfield<Dir, bool, 22, 1, AccessType::ReadWrite>;
			using Pin23 = Bitfield<Dir, bool, 23, 1, AccessType::ReadWrite>;
			using Pin24 = Bitfield<Dir, bool, 24, 1, AccessType::ReadWrite>;
			using Pin25 = Bitfield<Dir, bool, 25, 1, AccessType::ReadWrite>;
			using Pin26 = Bitfield<Dir, bool, 26, 1, AccessType::ReadWrite>;
			using Pin27 = Bitfield<Dir, bool, 27, 1, AccessType::ReadWrite>;
			using Pin28 = Bitfield<Dir, bool, 28, 1, AccessType::ReadWrite>;
			using Pin29 = Bitfield<Dir, bool, 29, 1, AccessType::ReadWrite>;
			using Pin30 = Bitfield<Dir, bool, 30, 1, AccessType::ReadWrite>;
			using Pin31 = Bitfield<Dir, bool, 31, 1, AccessType::ReadWrite>;
		};
		struct Dirset {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x518;
			using Pin0 = Bitfield<Dirset, bool, 0, 1, AccessType::ReadWrite>;
			using Pin1 = Bitfield<Dirset, bool, 1, 1, AccessType::ReadWrite>;
			using Pin2 = Bitfield<Dirset, bool, 2, 1, AccessType::ReadWrite>;
			using Pin3 = Bitfield<Dirset, bool, 3, 1, AccessType::ReadWrite>;
			using Pin4 = Bitfield<Dirset, bool, 4, 1, AccessType::ReadWrite>;
			using Pin5 = Bitfield<Dirset, bool, 5, 1, AccessType::ReadWrite>;
			using Pin6 = Bitfield<Dirset, bool, 6, 1, AccessType::ReadWrite>;
			using Pin7 = Bitfield<Dirset, bool, 7, 1, AccessType::ReadWrite>;
			using Pin8 = Bitfield<Dirset, bool, 8, 1, AccessType::ReadWrite>;
			using Pin9 = Bitfield<Dirset, bool, 9, 1, AccessType::ReadWrite>;
			using Pin10 = Bitfield<Dirset, bool, 10, 1, AccessType::ReadWrite>;
			using Pin11 = Bitfield<Dirset, bool, 11, 1, AccessType::ReadWrite>;
			using Pin12 = Bitfield<Dirset, bool, 12, 1, AccessType::ReadWrite>;
			using Pin13 = Bitfield<Dirset, bool, 13, 1, AccessType::ReadWrite>;
			using Pin14 = Bitfield<Dirset, bool, 14, 1, AccessType::ReadWrite>;
			using Pin15 = Bitfield<Dirset, bool, 15, 1, AccessType::ReadWrite>;
			using Pin16 = Bitfield<Dirset, bool, 16, 1, AccessType::ReadWrite>;
			using Pin17 = Bitfield<Dirset, bool, 17, 1, AccessType::ReadWrite>;
			using Pin18 = Bitfield<Dirset, bool, 18, 1, AccessType::ReadWrite>;
			using Pin19 = Bitfield<Dirset, bool, 19, 1, AccessType::ReadWrite>;
			using Pin20 = Bitfield<Dirset, bool, 20, 1, AccessType::ReadWrite>;
			using Pin21 = Bitfield<Dirset, bool, 21, 1, AccessType::ReadWrite>;
			using Pin22 = Bitfield<Dirset, bool, 22, 1, AccessType::ReadWrite>;
			using Pin23 = Bitfield<Dirset, bool, 23, 1, AccessType::ReadWrite>;
			using Pin24 = Bitfield<Dirset, bool, 24, 1, AccessType::ReadWrite>;
			using Pin25 = Bitfield<Dirset, bool, 25, 1, AccessType::ReadWrite>;
			using Pin26 = Bitfield<Dirset, bool, 26, 1, AccessType::ReadWrite>;
			using Pin27 = Bitfield<Dirset, bool, 27, 1, AccessType::ReadWrite>;
			using Pin28 = Bitfield<Dirset, bool, 28, 1, AccessType::ReadWrite>;
			using Pin29 = Bitfield<Dirset, bool, 29, 1, AccessType::ReadWrite>;
			using Pin30 = Bitfield<Dirset, bool, 30, 1, AccessType::ReadWrite>;
			using Pin31 = Bitfield<Dirset, bool, 31, 1, AccessType::ReadWrite>;
		};
		struct Dirclr {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x51c;
			using Pin0 = Bitfield<Dirclr, bool, 0, 1, AccessType::ReadWrite>;
			using Pin1 = Bitfield<Dirclr, bool, 1, 1, AccessType::ReadWrite>;
			using Pin2 = Bitfield<Dirclr, bool, 2, 1, AccessType::ReadWrite>;
			using Pin3 = Bitfield<Dirclr, bool, 3, 1, AccessType::ReadWrite>;
			using Pin4 = Bitfield<Dirclr, bool, 4, 1, AccessType::ReadWrite>;
			using Pin5 = Bitfield<Dirclr, bool, 5, 1, AccessType::ReadWrite>;
			using Pin6 = Bitfield<Dirclr, bool, 6, 1, AccessType::ReadWrite>;
			using Pin7 = Bitfield<Dirclr, bool, 7, 1, AccessType::ReadWrite>;
			using Pin8 = Bitfield<Dirclr, bool, 8, 1, AccessType::ReadWrite>;
			using Pin9 = Bitfield<Dirclr, bool, 9, 1, AccessType::ReadWrite>;
			using Pin10 = Bitfield<Dirclr, bool, 10, 1, AccessType::ReadWrite>;
			using Pin11 = Bitfield<Dirclr, bool, 11, 1, AccessType::ReadWrite>;
			using Pin12 = Bitfield<Dirclr, bool, 12, 1, AccessType::ReadWrite>;
			using Pin13 = Bitfield<Dirclr, bool, 13, 1, AccessType::ReadWrite>;
			using Pin14 = Bitfield<Dirclr, bool, 14, 1, AccessType::ReadWrite>;
			using Pin15 = Bitfield<Dirclr, bool, 15, 1, AccessType::ReadWrite>;
			using Pin16 = Bitfield<Dirclr, bool, 16, 1, AccessType::ReadWrite>;
			using Pin17 = Bitfield<Dirclr, bool, 17, 1, AccessType::ReadWrite>;
			using Pin18 = Bitfield<Dirclr, bool, 18, 1, AccessType::ReadWrite>;
			using Pin19 = Bitfield<Dirclr, bool, 19, 1, AccessType::ReadWrite>;
			using Pin20 = Bitfield<Dirclr, bool, 20, 1, AccessType::ReadWrite>;
			using Pin21 = Bitfield<Dirclr, bool, 21, 1, AccessType::ReadWrite>;
			using Pin22 = Bitfield<Dirclr, bool, 22, 1, AccessType::ReadWrite>;
			using Pin23 = Bitfield<Dirclr, bool, 23, 1, AccessType::ReadWrite>;
			using Pin24 = Bitfield<Dirclr, bool, 24, 1, AccessType::ReadWrite>;
			using Pin25 = Bitfield<Dirclr, bool, 25, 1, AccessType::ReadWrite>;
			using Pin26 = Bitfield<Dirclr, bool, 26, 1, AccessType::ReadWrite>;
			using Pin27 = Bitfield<Dirclr, bool, 27, 1, AccessType::ReadWrite>;
			using Pin28 = Bitfield<Dirclr, bool, 28, 1, AccessType::ReadWrite>;
			using Pin29 = Bitfield<Dirclr, bool, 29, 1, AccessType::ReadWrite>;
			using Pin30 = Bitfield<Dirclr, bool, 30, 1, AccessType::ReadWrite>;
			using Pin31 = Bitfield<Dirclr, bool, 31, 1, AccessType::ReadWrite>;
		};
		struct Latch {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x520;
			using Pin0 = Bitfield<Latch, bool, 0, 1, AccessType::ReadWrite>;
			using Pin1 = Bitfield<Latch, bool, 1, 1, AccessType::ReadWrite>;
			using Pin2 = Bitfield<Latch, bool, 2, 1, AccessType::ReadWrite>;
			using Pin3 = Bitfield<Latch, bool, 3, 1, AccessType::ReadWrite>;
			using Pin4 = Bitfield<Latch, bool, 4, 1, AccessType::ReadWrite>;
			using Pin5 = Bitfield<Latch, bool, 5, 1, AccessType::ReadWrite>;
			using Pin6 = Bitfield<Latch, bool, 6, 1, AccessType::ReadWrite>;
			using Pin7 = Bitfield<Latch, bool, 7, 1, AccessType::ReadWrite>;
			using Pin8 = Bitfield<Latch, bool, 8, 1, AccessType::ReadWrite>;
			using Pin9 = Bitfield<Latch, bool, 9, 1, AccessType::ReadWrite>;
			using Pin10 = Bitfield<Latch, bool, 10, 1, AccessType::ReadWrite>;
			using Pin11 = Bitfield<Latch, bool, 11, 1, AccessType::ReadWrite>;
			using Pin12 = Bitfield<Latch, bool, 12, 1, AccessType::ReadWrite>;
			using Pin13 = Bitfield<Latch, bool, 13, 1, AccessType::ReadWrite>;
			using Pin14 = Bitfield<Latch, bool, 14, 1, AccessType::ReadWrite>;
			using Pin15 = Bitfield<Latch, bool, 15, 1, AccessType::ReadWrite>;
			using Pin16 = Bitfield<Latch, bool, 16, 1, AccessType::ReadWrite>;
			using Pin17 = Bitfield<Latch, bool, 17, 1, AccessType::ReadWrite>;
			using Pin18 = Bitfield<Latch, bool, 18, 1, AccessType::ReadWrite>;
			using Pin19 = Bitfield<Latch, bool, 19, 1, AccessType::ReadWrite>;
			using Pin20 = Bitfield<Latch, bool, 20, 1, AccessType::ReadWrite>;
			using Pin21 = Bitfield<Latch, bool, 21, 1, AccessType::ReadWrite>;
			using Pin22 = Bitfield<Latch, bool, 22, 1, AccessType::ReadWrite>;
			using Pin23 = Bitfield<Latch, bool, 23, 1, AccessType::ReadWrite>;
			using Pin24 = Bitfield<Latch, bool, 24, 1, AccessType::ReadWrite>;
			using Pin25 = Bitfield<Latch, bool, 25, 1, AccessType::ReadWrite>;
			using Pin26 = Bitfield<Latch, bool, 26, 1, AccessType::ReadWrite>;
			using Pin27 = Bitfield<Latch, bool, 27, 1, AccessType::ReadWrite>;
			using Pin28 = Bitfield<Latch, bool, 28, 1, AccessType::ReadWrite>;
			using Pin29 = Bitfield<Latch, bool, 29, 1, AccessType::ReadWrite>;
			using Pin30 = Bitfield<Latch, bool, 30, 1, AccessType::ReadWrite>;
			using Pin31 = Bitfield<Latch, bool, 31, 1, AccessType::ReadWrite>;
		};
		struct Detectmode {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x524;
			using Value = Bitfield<Detectmode, bool, 0, 1, AccessType::ReadWrite>;
		};
        template<std::uint32_t Number>
		struct Pin_Cnf {
			using WidthType = std::uint32_t;
			static constexpr WidthType Address = BaseAddress + 0x700 + (sizeof(WidthType) * Number);
			using Dir = Bitfield<Pin_Cnf, bool, 0, 1, AccessType::ReadWrite>;
			using Input = Bitfield<Pin_Cnf, bool, 1, 1, AccessType::ReadWrite>;
			using Pull = Bitfield<Pin_Cnf, std::uint8_t, 2, 2, AccessType::ReadWrite>;
			using Drive = Bitfield<Pin_Cnf, std::uint8_t, 8, 3, AccessType::ReadWrite>;
			using Sense = Bitfield<Pin_Cnf, std::uint8_t, 16, 2, AccessType::ReadWrite>;
		};

        // using Pins_Cnfs = std::tuple<
        //     Pin_Cnf<0>,
        //     Pin_Cnf<1>,
        //     Pin_Cnf<2>,
        //     Pin_Cnf<3>,
        //     Pin_Cnf<4>,
        //     Pin_Cnf<5>,
        //     Pin_Cnf<6>,
        //     Pin_Cnf<7>,
        //     Pin_Cnf<8>,
        //     Pin_Cnf<9>,
        //     Pin_Cnf<10>,
        //     Pin_Cnf<11>,
        //     Pin_Cnf<12>,
        //     Pin_Cnf<13>,
        //     Pin_Cnf<14>,
        //     Pin_Cnf<15>,
        //     Pin_Cnf<16>,
        //     Pin_Cnf<17>,
        //     Pin_Cnf<18>,
        //     Pin_Cnf<19>,
        //     Pin_Cnf<20>,
        //     Pin_Cnf<21>,
        //     Pin_Cnf<22>,
        //     Pin_Cnf<23>,
        //     Pin_Cnf<24>,
        //     Pin_Cnf<25>,
        //     Pin_Cnf<26>,
        //     Pin_Cnf<27>,
        //     Pin_Cnf<28>,
        //     Pin_Cnf<29>,
        //     Pin_Cnf<30>,
        //     Pin_Cnf<31>
        // >;
	};

	using P0 = PinController<0X50000000, 0xFF>;

} // end of namespace nrf52
