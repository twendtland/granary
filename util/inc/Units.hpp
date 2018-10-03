
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

    namespace unit {
        struct ms {
            explicit ms(unsigned long long v) : val{v} {}
            unsigned long long val;
        };

        ms operator "" _ms (unsigned long long n) {
            return ms(n);
        }

        struct us {
            explicit us(unsigned long long v) : val{v} {}
            unsigned long long val;
        };

        us operator "" _us (unsigned long long n) {
            return us(n);
        }
    }

}
