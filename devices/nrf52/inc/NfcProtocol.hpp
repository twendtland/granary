
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

namespace Nfc {

    enum class PlatformConfig {

    };

    enum class Command {
        AllReq = 0x52,
        SensReq = 0x26,
        SddCl1 = 0x93,
        SddCl2 = 0x95,
        SddCl3 = 0x97,
        AttrReq = 0xD4,
        Rats = 0xE0
    };

    void parse(const std::uint8_t* data, std::uint8_t* response){
        Command cmd = static_cast<Command>(data[0]);
        switch (cmd){
            case Command::AllReq:
                break;
            case Command::SensReq:
                break;
            default:
                break;
        }
    }

    void handleAttributeRequest(const std::uint8_t* data, std::uint8_t* response);
}

// -----------------------------------------------------------------------------

void Nfc::handleAttributeRequest(const std::uint8_t* data, std::uint8_t* response){

}
