#pragma once

#include <cstdint>

namespace PiSubmarine::Chipset::Api
{
    enum class Status : uint32_t
    {
        TestBit = (1 << 0),
        VBusConnected = (1 << 1),
        ChargingInProgress = (1 << 2),
        ChargerOvercurrent = (1 << 3),
        ChargerOverheat = (1 << 4),
        Reg12PowerGood = (1 << 5)
    };
}