
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

#include <tuple>

namespace granary {
    template<typename Pin, typename ... Pins>
    class PinWrapper {
        public:
            template<typename Config>
            static constexpr void init(Config config){
                init_each(config, std::tuple<Pin, Pins...>{});
            }

        private:
            template<typename Config>
            static constexpr void init_each(Config conf, std::tuple<>){}

            template<typename Config, typename P, typename ... Ps>
            static constexpr void init_each(Config conf, std::tuple<P, Ps...>){
                P::init(conf);
                init_each(conf, std::tuple<Ps...>{});
            }
    };
}
