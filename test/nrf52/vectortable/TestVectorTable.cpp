
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

#include "VectorTable.hpp"

// this comes from a header file normally
typedef enum {
  Reset_IRQn                    = -15,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn           = -14,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = -13,              /*!<   3  Hard Fault, all classes of Fault                                 */
  MemoryManagement_IRQn         = -12,             

  UsageFault_IRQn               = -10,              /*!<   6  Usage Fault, i.e. Undef Instruction, Illegal State Transition    */
  SVCall_IRQn                   =  -5,              /*!<  11  System Service Call via SVC instruction                          */
  DebugMonitor_IRQn             =  -4,              /*!<  12  Debug Monitor                                                    */
  PendSV_IRQn                   =  -2,              /*!<  14  Pendable request for system service                              */
  SysTick_IRQn                  =  -1,              /*!<  15  System Tick Timer                                                */

  POWER_CLOCK_IRQn              =   0,              /*!<   0  POWER_CLOCK                                                      */
  RADIO_IRQn                    =   1,              /*!<   1  RADIO                                                            */
  UARTE0_UART0_IRQn             =   2,              /*!<   2  UARTE0_UART0                                                     */
  SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0_IRQn=   3,      /*!<   3  SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0                                */
  SPIM1_SPIS1_TWIM1_TWIS1_SPI1_TWI1_IRQn=   4,      /*!<   4  SPIM1_SPIS1_TWIM1_TWIS1_SPI1_TWI1                                */
  NFCT_IRQn                     =   5,              /*!<   5  NFCT                                                             */
  GPIOTE_IRQn                   =   6,              /*!<   6  GPIOTE                                                           */
  SAADC_IRQn                    =   7,              /*!<   7  SAADC                                                            */
  TIMER0_IRQn                   =   8,              /*!<   8  TIMER0                                                           */
  TIMER1_IRQn                   =   9,              /*!<   9  TIMER1                                                           */
  TIMER2_IRQn                   =  10,              /*!<  10  TIMER2                                                           */
  RTC0_IRQn                     =  11,              /*!<  11  RTC0                                                             */
  TEMP_IRQn                     =  12,              /*!<  12  TEMP                                                             */
  RNG_IRQn                      =  13,              /*!<  13  RNG                                                              */
  ECB_IRQn                      =  14,              /*!<  14  ECB                                                              */
  CCM_AAR_IRQn                  =  15,              /*!<  15  CCM_AAR                                                          */
  WDT_IRQn                      =  16,              /*!<  16  WDT                                                              */
  RTC1_IRQn                     =  17,              /*!<  17  RTC1                                                             */
  QDEC_IRQn                     =  18,              /*!<  18  QDEC                                                             */
  COMP_LPCOMP_IRQn              =  19,              /*!<  19  COMP_LPCOMP                                                      */
  SWI0_EGU0_IRQn                =  20,              /*!<  20  SWI0_EGU0                                                        */
  SWI1_EGU1_IRQn                =  21,              /*!<  21  SWI1_EGU1                                                        */
  SWI2_EGU2_IRQn                =  22,              /*!<  22  SWI2_EGU2                                                        */
  SWI3_EGU3_IRQn                =  23,              /*!<  23  SWI3_EGU3                                                        */
  SWI4_EGU4_IRQn                =  24,              /*!<  24  SWI4_EGU4                                                        */
  SWI5_EGU5_IRQn                =  25,              /*!<  25  SWI5_EGU5                                                        */
  TIMER3_IRQn                   =  26,              /*!<  26  TIMER3                                                           */
  TIMER4_IRQn                   =  27,              /*!<  27  TIMER4                                                           */
  PWM0_IRQn                     =  28,              /*!<  28  PWM0                                                             */
  PDM_IRQn                      =  29,              /*!<  29  PDM                                                              */
  MWU_IRQn                      =  32,              /*!<  32  MWU                                                              */
  PWM1_IRQn                     =  33,              /*!<  33  PWM1                                                             */
  PWM2_IRQn                     =  34,              /*!<  34  PWM2                                                             */
  SPIM2_SPIS2_SPI2_IRQn         =  35,              /*!<  35  SPIM2_SPIS2_SPI2                                                 */
  RTC2_IRQn                     =  36,              /*!<  36  RTC2                                                             */
  I2S_IRQn                      =  37,              /*!<  37  I2S                                                              */
  FPU_IRQn                      =  38               /*!<  38  FPU                                                              */
} IRQn_Type;

void ResetHandler(){
    for(;;){}
}

void SpiHandler(){
    for(;;){}
}
void UartHandler(){
    for(;;){}
}

void DefaultHandler(){
    for(;;){}
}

// check assembly output in asm.s to verify tables correctness
__attribute__((section(".isr_vector"), used))
constexpr auto isr = granary::makeVectorTable<48>(0x20003000, granary::makeVector(Reset_IRQn, ResetHandler), granary::makeVector(SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0_IRQn, SpiHandler));

int main(int argc, char** argv){

    return 0;
}
