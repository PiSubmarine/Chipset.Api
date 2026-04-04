#pragma once

namespace PiSubmarine::Chipset::Api
{
    enum class Command : uint32_t
    {
        ShutDown = 0xAB,
        Reboot = 0xCD,
    };
}