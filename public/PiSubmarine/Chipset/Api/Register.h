#pragma once

#include <cstddef>
#include <cstdint>

namespace PiSubmarine::Chipset::Api
{
    constexpr size_t RegisterSizeBytes = sizeof(uint32_t);

    enum class Register
    {
        Status = 0x00,
        RtcHigh,
        RtcLow,
        ChipsetVdd,
        Reg5Voltage,
        RegPiVoltage,
        BallastPosition,
        ChipsetTemperature,
        ChargerTemperature,

        Command
    };
}
