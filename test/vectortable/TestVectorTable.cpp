
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

void ResetHandler(){
    for(;;){}
}

void UsbHandler(){
    for(;;){}
}
void UartHandler(){
    for(;;){}
}

void DefaultHandler(){
    for(;;){}
}

// check assembly output in asm.s to verify tables correctness
__attribute__((section(".isr_vector")))
constexpr auto isr = granary::makeVectorTable<12>(0x20003000, granary::makeVector(0, ResetHandler), granary::makeVector(11, UsbHandler));

int main(int argc, char** argv){

    return 0;
}
