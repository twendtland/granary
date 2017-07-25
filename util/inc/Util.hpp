
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

#pragma once

#include <type_traits>

namespace granary {
namespace Util {

    // check if type is in tuple
    template<typename T>
    constexpr bool has_type(std::tuple<>){
        return false ;
    }

    template<typename T, typename U, typename ... Us>
    constexpr bool has_type(std::tuple<U, Us...>){
        if (std::is_same<T, U>::value){
            return true;
        }
        else {
            return has_type<T>(std::tuple<Us...>{});
        }
    }

    // check if one tuple contains types not in the other
    template<typename Tuple>
    constexpr bool has_all_types(std::tuple<>){
        return true;
    }

    template<typename Tuple, typename T>
    constexpr bool has_all_types(std::tuple<T>){
        return has_type<T>(Tuple{});
    }

    template<typename Tuple, typename T, typename ... Ts>
    constexpr bool has_all_types(std::tuple<T, Ts...>){
        return has_type<T>(Tuple{}) && has_all_types<Tuple>(std::tuple<Ts...>{});
    }
}
}
