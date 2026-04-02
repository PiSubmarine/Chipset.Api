#pragma once

#include <cstdint>

namespace PiSubmarine::Chipset::Api
{
    enum class Status : uint32_t
    {
        TestBit,
        VBusConnected,
        ChargingInProgress,
        ChargerOvercurrent,
        ChargerOverheat
    };
}