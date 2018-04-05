
#pragma once

#include <cstdint>
#include "Bitfield.hpp"

#include "nrf52_timer.hpp"

using namespace rye;

namespace nrf52840 {

    using Timer0 = Timer::Controller<0X40008000, 8>;
    using Timer1 = Timer::Controller<0X40009000, 9>;
    using Timer2 = Timer::Controller<0X4000A000, 10>;
    using Timer3 = Timer::Controller<0X4001A000, 26>;
    using Timer4 = Timer::Controller<0X4001B000, 27>;

} // end of namespace nrf52840
