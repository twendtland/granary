
// Copyright 2018 Thomas Wendtland
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
    Class Config allows for compile time creation of configurations for peripherals,
    but all values used MUST be of different type. They can be returned with 'get'
    by choosing the type to get.
*/

#pragma once

#include <tuple>
#include <type_traits>

#include "Util.hpp"

namespace granary {

    template<typename Defaults, typename ... Values>
    class Config {
        public:
            static_assert(Util::has_all_types<Defaults>(std::tuple<Values...>{}), "Config: type/value not in defaults");
            static_assert(std::tuple_size<Defaults>::value > 0, "Config error: No defaults provided.");

            Defaults defaults {};  // these have to be std::tuples
            std::tuple<Values...> values {};      //

            template<typename T>
            constexpr auto get() const {
                Proxy<std::tuple<Values...>, Defaults, Util::has_type<T>(std::tuple<Values...>{})> proxy{values, defaults};
                return proxy.template get<T>();
            }

        private:
            // class wrapper using template specialization to select
            // the 'correct' tuple
            template<typename V, typename D, bool Contained>
            struct Proxy;

            template<typename V, typename D>
            struct Proxy<V, D, false> {
                V values;
                D defaults;
                template<typename T>
                constexpr auto get() const {
                    return std::get<T>(defaults);
                }
            };

            template<typename V, typename D>
            struct Proxy<V, D, true> {
                V values;
                D defaults;
                template<typename T>
                constexpr auto get() const {
                    return std::get<T>(values);
                }
            };
    };

    template<typename T, typename Config>
    constexpr auto getParam(Config config) {
        return config.template get<T>();
    }

    template<typename Defaults, typename ... Values>
    constexpr auto makeConfig(Defaults defaults, Values ... values) {
        return Config<Defaults, Values ...>{defaults, values...};
    }
}
