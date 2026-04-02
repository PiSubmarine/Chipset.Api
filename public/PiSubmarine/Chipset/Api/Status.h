#pragma once

namespace PiSubmarine::Chipset::Api
{
    enum class Status : uint32_t
    {
        VBusConnected,
        ChargingInProgress,

        TestBit = 31
    };
}