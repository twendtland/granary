
#pragma once

#include "nrf52_clock.hpp"

namespace nrf52 {
    class Clock {
        public:
            static constexpr void startHighSpeedOscillator();
            static constexpr void startLowSpeedOscillator();
        private:
    };
}

// -----------------------------------------------------------------------------

constexpr void nrf52::Clock::startHighSpeedOscillator() {
    SysClock::Tasks_Hfclkstart::Value::set();
}

// -----------------------------------------------------------------------------
