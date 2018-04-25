
#pragma once

#include <cstdint>
#include <utility>
#include <type_traits>
#include <tuple>


template<typename T, std::uint8_t offset>
struct Parameter {
    T t;
};


namespace Usb {

    enum class State {
        Powered,
        Default,
        Addressed,
        Configured,
        Suspended
    };

    struct DeviceDescriptor {
        std::uint8_t bLength;
        std::uint8_t bDescriptorType;

        using Length = Parameter<uint8_t, 0>;

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

    template<typename T>
    constexpr auto makeDeviceDescriptor(T t) {
        return DeviceDescriptor::Length {std::get<DeviceDescriptor::Length>(t)};
    }

    //makeDeviceDescriptor(bLength,13)
}
