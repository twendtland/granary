
#pragma once

#include "nrf52_gpio.hpp"

namespace nrf52832 {
    using P0 = nrf52::hardware::gpio::Controller<0X50000000, 0xFF>;
}
