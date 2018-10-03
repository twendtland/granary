
#pragma once

#include "Util.hpp"

#include <cstdint>
#include <utility>
#include <type_traits>
#include <tuple>

namespace Usb {

    enum class State {
        Powered,
        Default,
        Addressed,
        Configured,
        Suspended
    };

    constexpr auto DeviceDescriptorDefaults = std::make_tuple(std::uint8_t{0xAA}, std::uint8_t{0xBB}, std::uint8_t{0xCC}, std::uint8_t{0xDD});

    struct DeviceDescriptor {
        static constexpr std::uint32_t Length = 0x4;
        std::uint8_t bLength;
        std::uint8_t bDescriptorType;
        // std::uint16_t bcdUSB;
        // std::uint8_t bDeviceClass;
        // std::uint8_t bDeviceSubClass;
        // std::uint8_t bDeviceProtocol;
        // std::uint8_t bMaxPacketSize;
        // std::uint16_t idVendor;
        // std::uint16_t idProduct;
        // std::uint16_t bcdDevice;
        // std::uint8_t iManufacturer;
        // std::uint8_t iProduct;
        // std::uint8_t iSerialNumber;
        // std::uint8_t bNumConfigurations;
    };

    struct DescriptorField {
        constexpr DescriptorField(std::uint32_t n, std::uint8_t v) : index{n}, value{v} {}
        std::uint32_t index;
        std::uint8_t value;
    };

    struct DescriptorFieldLong {
        constexpr DescriptorFieldLong(std::uint32_t n, std::uint16_t v) : index{n}, value{std::make_tuple(0x11, 0x22)} {}
        std::uint32_t index;
        std::tuple<std::uint8_t, std::uint8_t> value;
    };

    // template<typename E>
    struct Locator {

        template<std::uint32_t N, typename Defaults>
        static constexpr auto elemForPos(Defaults defaults) {
            return std::get<N>(defaults);
        }

        template<std::uint32_t N, typename Defaults, typename T, typename ... Ts>
        static constexpr auto elemForPos(Defaults defaults, T t, Ts ... ts) {
            if (t.index == N) {
                return t.value;
            }
            return elemForPos<N>(defaults, ts...);
        }

    };

    template<std::uint32_t Size>
    struct Descriptor {
        static constexpr auto Index = Size-1;
        template<typename DefaultType, typename T, typename ... Ts>
        static constexpr auto make(DefaultType defaults, T t, Ts ... ts) {
            return std::make_tuple(std::make_tuple(Locator::elemForPos<Index>(defaults, t, ts...)), Descriptor<Index>::make(defaults, t, ts...));
        }
    };

    template<>
    struct Descriptor<1> {
        template<typename DefaultType, typename T, typename ... Ts>
        static constexpr auto make(DefaultType defaults, T t, Ts ... ts) {
            return std::make_tuple(Locator::elemForPos<0>(defaults, ts...));
        }
    };

    constexpr auto makeField(std::uint32_t n, std::uint8_t v) {
        return Usb::DescriptorField{n,v};
    }

    // constexpr auto makeField(std::uint32_t n, std::uint16_t v) {
    //     return Usb::DescriptorFieldLong{n,v};
    // }

    template<std::uint32_t Size, typename ... Ts>
    constexpr auto makeDescriptor(Ts ... ts) {
        static_assert(sizeof...(Ts)<=Size, "Descriptor: too many elements for given size");
        return Usb::Descriptor<Size>::make(Usb::DeviceDescriptorDefaults, ts...);
    }

    template<typename ... Ts>
    constexpr auto makeDeviceDescriptor(Ts ... ts) {
        return makeDescriptor<DeviceDescriptor::Length>(ts...);
    }
}
