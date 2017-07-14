
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

/*
    Struct Config allows for compile time creation of configurations for peripherals,
    but all values used MUST be of different type. They can be returned with 'get'
    by choosing the type to get.
*/

#pragma once

#include <tuple>
#include <type_traits>

#include "Util.hpp"

namespace granary {

    template<typename Values, typename Defaults>
    class Config {
        public:
            static_assert(std::tuple_size<Defaults>::value > 0, "Config error: No defaults provided.");

            Values values {};      //
            Defaults defaults {};  // these have to be std::tuples

            template<typename T>
            auto constexpr get() const {
                Container<Values, Defaults, Util::has_type<T, Values>::value> container{values, defaults};
                return container.get<T>();
            }

        private:
            template<typename V, typename D, bool Contained>
            struct Container;

            template<typename V, typename D>
            struct Container<V, D, false> {
                V values;
                D defaults;
                template<typename T>
                constexpr auto get() const {
                    return std::get<T>(defaults);
                }
            };

            template<typename V, typename D>
            struct Container<V, D, true> {
                V values;
                D defaults;
                template<typename T>
                constexpr auto get() const {
                    return std::get<T>(values);
                }
            };
    };

    template<typename Values, typename Defaults>
    constexpr auto makeConfig(Values values, Defaults defaults){
        return Config<Values, Defaults>{values, defaults};
    }
}
