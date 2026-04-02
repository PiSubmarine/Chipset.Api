#pragma once

namespace PiSubmarine::Chipset::Api
{
    enum class Command
    {
        ShutDown = 0xAB,
        Reboot = 0xCD,
    };
}