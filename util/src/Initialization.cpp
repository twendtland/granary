
// Copyright 2017 Thomas Wendtland
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Initialization.hpp"
#include <cstddef>

extern "C" {

extern std::uint32_t __si_data__ ;
extern std::uint32_t __data_start__ ;
extern std::uint32_t __data_end__ ;

extern std::uint32_t __bss_start__ ;
extern std::uint32_t __bss_end__ ;

}

// providing our own memset here, since GCC will insert that and we're not
// using the libc (yet)
// -----------------------------------------------------------------------------

extern "C" {

void* memset(void* ptr, int value, size_t num) {
    std::uint8_t* p = reinterpret_cast<uint8_t*>(ptr);
    for (std::uint32_t i=0;i<num;i++) {
        *p++ = value;
    }
    return ptr;
}
}

// -----------------------------------------------------------------------------

void granary::DataSection::init() {
    std::uint32_t* flash_data = &__si_data__;
    std::uint32_t size = reinterpret_cast<std::uint32_t>(&__data_end__) - reinterpret_cast<std::uint32_t>(&__data_start__);
    volatile std::uint32_t* ptr = &__data_start__;
    for (std::uint32_t i = 0; i<size; i+=4) {
        *ptr++ = *flash_data++;
    }
}

// -----------------------------------------------------------------------------

void granary::BssSection::init() {
    for (volatile std::uint32_t* ptr = &__bss_start__; ptr != &__bss_end__; ptr++) {
        *ptr = 0;
    }
}
