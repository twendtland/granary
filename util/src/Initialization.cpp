
#include "Initialization.hpp"

extern std::uint32_t __si_data__ ;
extern std::uint32_t __data_start__ ;
extern std::uint32_t __data_end__ ;

extern std::uint32_t __bss_start__ ;
extern std::uint32_t __bss_end__ ;

// -----------------------------------------------------------------------------

void granary::DataSection::init(){
    std::uint32_t* flash_data = &__si_data__;
    std::uint32_t size = reinterpret_cast<std::uint32_t>(&__data_end__) - reinterpret_cast<std::uint32_t>(&__data_start__);
    volatile std::uint32_t* ptr = &__data_start__;
    for (std::uint32_t i = 0; i<size; i+=4){
        *ptr++ = *flash_data++;
    }
}

// -----------------------------------------------------------------------------

void granary::BssSection::init(){
    for (volatile std::uint32_t* ptr = &__bss_start__; ptr != &__bss_end__; ptr++){
        *ptr = 0;
    }
}
