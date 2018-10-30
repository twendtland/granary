
#pragma once

#include "nrf52_gpio.hpp"

namespace nrf52840 {
    using P0 = nrf52::hardware::gpio::Controller<0X50000000, 0xFF>;
    using P1 = nrf52::hardware::gpio::Controller<0X50000300, 0xFF>;
}
