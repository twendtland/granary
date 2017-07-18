
// Copyright 2017 Thomas Wendtland
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with \the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

namespace granary {
    enum class GpioType {
        Output,
        Input,
        PeripheralFunction,
        Analog
    };

    enum class GpioPullType {
        NoPull,
        PullDown,
        PullUp
    };

    enum class GpioDriveType {
        S0S1,
        H0S1,
        S0H1,
        H0H1,
        D0S1,
        D0H1,
        S0D1,
        H0D1
    };
}
