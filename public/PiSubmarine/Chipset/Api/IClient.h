#pragma once

#include "PiSubmarine/Chipset/Api/Status.h"
#include <chrono>
#include <expected>
#include <PiSubmarine/Celsius.h>
#include <PiSubmarine/Volts.h>

#include "Command.h"
#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Chipset
{
    class IClient
    {
    public:
        enum class Status
        {
            NoError,
            ChipsetError,
            ProtocolError
        };

        virtual ~IClient() = default;

        virtual std::expected<Api::Status, Status> GetStatus() const = 0;

        virtual std::expected<std::chrono::seconds, Status> GetRtc() = 0;
        virtual Status SetRtc(const std::chrono::seconds& timestamp) = 0;
        virtual std::expected<Volts, Status> GetChipsetVoltage() = 0;
        virtual std::expected<Volts, Status> GetRegulator5Voltage() = 0;
        virtual std::expected<Volts, Status> GetRegulatorPiVoltage() = 0;
        virtual std::expected<NormalizedFraction, Status> GetBallastPosition() = 0;
        virtual std::expected<Celsius, Status> GetChipsetTemperature() = 0;
        virtual std::expected<Celsius, Status> GetChargerTemperature() = 0;

        virtual std::expected<Celsius, Status> GetChargerBusCurrent() = 0;
        virtual std::expected<Celsius, Status> GetBatteryCurrent() = 0;
        virtual std::expected<Celsius, Status> GetChargerBusVoltage() = 0;
        virtual std::expected<Celsius, Status> GetBatteryVoltage() = 0;
        virtual std::expected<Celsius, Status> GetChargerSystemVoltage() = 0;
        virtual std::expected<Celsius, Status> GetBatteryTemperature() = 0;

        virtual Status SendCommand(Api::Command command) = 0;

    };
}
