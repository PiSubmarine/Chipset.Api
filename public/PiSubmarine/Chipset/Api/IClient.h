#pragma once

#include <PiSubmarine/Amperes.h>
#include <PiSubmarine/Celsius.h>
#include <PiSubmarine/Volts.h>
#include <chrono>

#include "PiSubmarine/Chipset/Api/Command.h"
#include "PiSubmarine/Chipset/Api/Status.h"
#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Chipset
{
    class IClient
    {
    public:
        virtual ~IClient() = default;

        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Api::Status> GetStatus() const = 0;

        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<std::chrono::seconds> GetRtc() = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> SetRtc(const std::chrono::seconds& timestamp) = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Volts> GetChipsetVoltage() = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Volts> GetRegulator5Voltage() = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Volts> GetRegulatorPiVoltage() = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<NormalizedFraction> GetBallastPosition() = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Celsius> GetChipsetTemperature() = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Celsius> GetChargerTemperature() = 0;

        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Amperes> GetChargerBusCurrent() = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Amperes> GetBatteryCurrent() = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Volts> GetChargerBusVoltage() = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Volts> GetBatteryVoltage() = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Volts> GetChargerSystemVoltage() = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Celsius> GetBatteryTemperature() = 0;

        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> SendCommand(Api::Command command) = 0;
    };
}
