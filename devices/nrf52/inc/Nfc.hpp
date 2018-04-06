
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

#include "Config.hpp"
#include "Callback.hpp"
#include "NfcProtocol.hpp"

#include "nrf52_nfct.hpp"
#include "nrf52_uicr.hpp"
#include "nrf52_ficr.hpp"

#include <cstring>

namespace nrf52 {

    enum class NfcEvent {
        Ready,
        FieldDetected,
        FieldLost,
        TxFrameStart,
        TxFrameEnd,
        RxFrameStart,
        RxFrameEnd,
        Error,
        Collision,
        Selected,
        Started,
        TxEnded,
        AutoDetectionStarted
    };

    template<typename ... Values>
    constexpr auto makeNfcConfig(Values ... values){
        constexpr nrf52::Nfct::FramedelaymodeType delaymode = nrf52::Nfct::FramedelaymodeType::Freerun;
        constexpr auto defaults = std::make_tuple(nrf52::Nfct::BitframesddType{nrf52::Nfct::BitframesddType::Sdd00000}, delaymode);
        return granary::makeConfig(values..., defaults);
    }

    template<typename Instance>
    class NfcTag {
        using IrqHandler = granary::Callback<void, const NfcEvent>;
        static constexpr std::uint16_t BufferSize = 16;
        public:
            template<typename Config>
            static void init(const Config config, const IrqHandler handler);

            static void start();
            static void stop();

            static constexpr void transmit(const std::uint8_t* data, const std::uint16_t len);

            static void handleIrq();

        private:
            static IrqHandler callback;
            static std::uint8_t cmdBuffer[BufferSize];
            static std::uint8_t responseBuffer[BufferSize];
    };
}

// -----------------------------------------------------------------------------

template<typename Instance>
typename nrf52::NfcTag<Instance>::IrqHandler nrf52::NfcTag<Instance>::callback;

template<typename Instance>
std::uint8_t nrf52::NfcTag<Instance>::cmdBuffer[BufferSize];

template<typename Instance>
std::uint8_t nrf52::NfcTag<Instance>::responseBuffer[BufferSize];

// -----------------------------------------------------------------------------

template<typename Instance>
template<typename Config>
void nrf52::NfcTag<Instance>::init(const Config config, const IrqHandler handler){
    nrf52::Uicr0::Nfcpins::Protect::set();

    Instance::Inten::Ready::set();
    Instance::Inten::Fielddetected::set();
    Instance::Inten::Fieldlost::set();
    Instance::Inten::Endtx::set();
    Instance::Inten::Endrx::set();
    Instance::Inten::Rxframestart::set();
    Instance::Inten::Rxframeend::set();
    Instance::Inten::Started::set();
    Instance::Inten::Txframestart::set();
    Instance::Inten::Selected::set();
    Instance::Inten::Error::set();

    const auto delaymode = granary::getParam<nrf52::Nfct::FramedelaymodeType>(config);
    Instance::Framedelaymode::Value::write(delaymode);

    const auto id = nrf52::Ficr0::Nfc::Value::read(1);
    Instance::Nfcid1_Last::Nfcid1_W::write(std::uint8_t{id>>24 & 0xFF});
    Instance::Nfcid1_Last::Nfcid1_X::write(std::uint8_t{id>>16 & 0xFF});
    Instance::Nfcid1_Last::Nfcid1_Y::write(std::uint8_t{id>>8 & 0xFF});
    Instance::Nfcid1_Last::Nfcid1_Z::write(std::uint8_t{id & 0xFF});

    Instance::Packetptr::Ptr::write(reinterpret_cast<std::uint32_t>(&cmdBuffer));
    Instance::Maxlen::Value::write(std::uint16_t{BufferSize});

    NVIC_EnableIRQ(static_cast<IRQn_Type>(Instance::Interrupt));

    callback = handler;
}

// -----------------------------------------------------------------------------

template<typename Instance>
void nrf52::NfcTag<Instance>::start(){
    Instance::Tasks_Sense::Value::set();
    Instance::Tasks_Enablerxdata::Value::set();
    //Instance::Tasks_Activate::Value::set();
}

// -----------------------------------------------------------------------------

template<typename Instance>
void nrf52::NfcTag<Instance>::stop(){
    Instance::Tasks_Disable::Value::set();
}

// -----------------------------------------------------------------------------

template<typename Instance>
constexpr void nrf52::NfcTag<Instance>::transmit(const std::uint8_t* data, const std::uint16_t len){
    ::memcpy(cmdBuffer, data, len);
    Instance::TxAmount::TxDataBits::write(std::uint8_t{0});
    Instance::TxAmount::TxDataBytes::write(len);
    //Instance::Maxlen::Value::write(len);
    Instance::Tasks_Starttx::Value::set();
}

// -----------------------------------------------------------------------------

template<typename Instance>
void nrf52::NfcTag<Instance>::handleIrq(){
    if (Instance::Events_Autocolresstarted::Value::read() == true){
        Instance::Events_Autocolresstarted::Value::clear();
        callback(NfcEvent::AutoDetectionStarted);
    }
    if (Instance::Events_Collision::Value::read() == true){
        Instance::Events_Collision::Value::clear();
        callback(NfcEvent::Collision);
        return;
    }
    if (Instance::Events_Error::Value::read() == true){
        Instance::Events_Error::Value::clear();
        callback(NfcEvent::Error);
    }
    if (Instance::Events_Fielddetected::Value::read() == true){
        Instance::Events_Fielddetected::Value::clear();
        Instance::Tasks_Activate::Value::set();
        callback(NfcEvent::FieldDetected);
    }
    if (Instance::Events_Fieldlost::Value::read() == true){
        Instance::Events_Fieldlost::Value::clear();
        callback(NfcEvent::FieldLost);
    }
    if (Instance::Events_Selected::Value::read() == true){
        Instance::Events_Selected::Value::clear();
        callback(NfcEvent::Selected);
    }
    if (Instance::Events_Rxframestart::Value::read() == true){
        Instance::Events_Rxframestart::Value::clear();
        callback(NfcEvent::RxFrameStart);
    }
    if (Instance::Events_Rxframeend::Value::read() == true){
        Instance::Events_Rxframeend::Value::clear();
        Nfc::Command cmd = static_cast<Nfc::Command>(cmdBuffer[0]);

        std::uint16_t num_bytes = Instance::RxAmount::Bytes::read();
        std::uint8_t num_bits = Instance::RxAmount::Bits::read();
        if (cmd == Nfc::Command::SensReq){
            // SENS_RES response
            std::uint8_t resp[2] = {0};
            //resp[0] = static_cast<std::uint8_t>(Instance::Sensres::Nfcidsize::read()) << 6 | static_cast<std::uint8_t>(Instance::Sensres::Bitframesdd::read());
            //resp[1] = static_cast<std::uint8_t>(Instance::Sensres::Platfconfig::read());
            // @todo: transmit correct bytes
            resp[0] = 0x2;
            resp[1] = 0x1;
            //transmit(resp, sizeof(resp));
            if (num_bytes == 1){
                callback(NfcEvent::RxFrameEnd);
            }
            else if (num_bytes == 2){
                callback(NfcEvent::TxEnded);
            }
            if (num_bits == 7){
                callback(NfcEvent::Selected);
            }
            return;
        }
        if (cmd == Nfc::Command::SddCl1){
            // SDD_RES response
            if (cmdBuffer[1] == 0x20){
                //callback(NfcEvent::TxEnded);
                // @todo: read SEL_PAR
                std::uint8_t resp[5] = {0};
                resp[0] = Instance::Nfcid1_Last::Nfcid1_Y::read();
                resp[1] = Instance::Nfcid1_Last::Nfcid1_X::read();
                resp[2] = Instance::Nfcid1_Last::Nfcid1_W::read();
                resp[3] = 0x8;//Instance::Nfcid1_Last::Nfcid1_W::read();
                resp[4] = resp[0] ^ resp[1] ^ resp[2] ^ resp[3];
                //transmit(resp, sizeof(resp));
            }
            if (cmdBuffer[1] == 0x70){

            }
            return;
        }
        if (cmd == Nfc::Command::AttrReq){
            callback(NfcEvent::Selected);
        }
        //memset(cmdBuffer, 0, sizeof(cmdBuffer));
    }
    if (Instance::Events_Endtx::Value::read() == true){
        Instance::Events_Endtx::Value::clear();

        Instance::Maxlen::Value::write(BufferSize);
        callback(NfcEvent::TxEnded);
    }
}
