
#pragma once

#include "Util.hpp"

#include <cstdint>
#include <utility>
#include <type_traits>
#include <tuple>
#include "Util.hpp"

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
    //
    // struct DescriptorField {
    //     using ValueType = uint8_t;
    //     constexpr DescriptorField(std::uint32_t n, std::uint8_t v) : index{n}, value{v} {}
    //     std::uint32_t index;
    //     std::uint8_t value;
    // };
    //
    // struct DescriptorFieldLong {
    //     constexpr DescriptorFieldLong(std::uint32_t n, std::uint16_t v) : index{n}, value{granary::Util::toByteTuple(v)} {}
    //     std::uint32_t index;
    //     std::tuple<std::uint8_t, std::uint8_t> value;
    // };
    //
    // template<typename FieldType>
    // struct ElemLocator {
    //
    // template<std::uint32_t N, typename Defaults>
    // static constexpr auto elemForPos(Defaults defaults) {
    //     return std::get<N>(defaults);
    // }
    //
    // template<std::uint32_t N, typename Defaults, typename T, typename ... Ts>
    // static constexpr auto elemForPos(Defaults defaults, T t, Ts ... ts) {
    //     if (t.index == N) {
    //         return t.value;
    //     }
    //     return elemForPos<N>(defaults, ts...);
    // }
    //
    // };
    //
    // template<>
    // struct ElemLocator<std::tuple<DescriptorField, DescriptorField>> {
    //
    // template<std::uint32_t N, typename Defaults>
    // static constexpr auto elemForPos(Defaults defaults) {
    //     return std::get<N>(defaults);
    // }
    //
    // template<std::uint32_t N, typename Defaults, typename T, typename ... Ts>
    // static constexpr auto elemForPos(Defaults defaults, T t, Ts ... ts) {
    //     if (std::get<0>(t).index == N) {
    //         return std::get<0>(t).value;
    //     }
    //     return elemForPos<N>(defaults, ts...);
    // }
    //
    // };
    //
    // template<std::uint32_t Size, typename FieldType>
    // struct Descriptor {
    //     static constexpr auto Index = Size-1;
    //     template<typename DefaultType, typename T, typename ... Ts>
    //     static constexpr auto make(DefaultType defaults, T t, Ts ... ts) {
    //         return std::make_tuple(std::make_tuple(ElemLocator<T>::template elemForPos<Index>(defaults, t, ts...)), Descriptor<Index, T>::make(defaults, t, ts...));
    //     }
    // };
    //
    // template<typename FieldType>
    // struct Descriptor<1, FieldType> {
    //     template<typename DefaultType, typename T, typename ... Ts>
    //     static constexpr auto make(DefaultType defaults, T t, Ts ... ts) {
    //         return std::make_tuple(ElemLocator<T>::template elemForPos<0>(defaults, t, ts...));
    //     }
    // };
    //
    // constexpr auto makeField(std::uint32_t n, std::uint8_t v) {
    //     return Usb::DescriptorField{n,v};
    // }
    //
    // constexpr auto makeFieldLong(std::uint32_t n, std::uint16_t v) {
    //     return std::make_tuple(Usb::DescriptorField{n,(v>>8 & 0xFF)}, Usb::DescriptorField{n+1,(v & 0xFF)});
    // }
    //
    // template<std::uint32_t Size, typename T, typename ... Ts>
    // constexpr auto makeDescriptor(T t, Ts ... ts) {
    //     static_assert(sizeof...(Ts)<=Size, "Descriptor: too many elements for given size");
    //     return Usb::Descriptor<Size, T>::make(Usb::DeviceDescriptorDefaults, t, ts...);
    // }
    //
    // template<typename ... Ts>
    // constexpr auto makeDeviceDescriptor(Ts ... ts) {
    //     return makeDescriptor<DeviceDescriptor::Length>(ts...);
    // }
}
