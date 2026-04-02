#pragma once

#include <cstddef>
#include <cstdint>

namespace PiSubmarine::Chipset::Api
{
    constexpr size_t RegisterSizeBytes = sizeof(uint32_t);

    enum class Register
    {
        Status = 0x00,
        RtcHigh = 0x01,
        RtcLow = 0x02,
        Reg5Voltage = 0x03,
        RegPiVoltage = 0x04,
        BallastPosition = 0x05,
        ChipsetTemperature = 0x06,
        ChargerTemperature = 0x07,

        Command
    };
}
