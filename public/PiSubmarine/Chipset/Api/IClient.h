#pragma once

#include "PiSubmarine/Chipset/Api/Status.h"
#include <chrono>
#include <expected>
#include <PiSubmarine/Celsius.h>
#include <PiSubmarine/Volts.h>

#include "Command.h"
#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Chipset::Client
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

        virtual std::expected<std::chrono::milliseconds, Status> GetRtc() = 0;
        virtual Status SetRtc(const std::chrono::milliseconds& timestamp) = 0;
        virtual std::expected<Volts, Status> GetRegulator5Voltage() = 0;
        virtual std::expected<Volts, Status> GetRegulatorPiVoltage() = 0;
        virtual std::expected<NormalizedFraction, Status> GetBallastPosition() = 0;
        virtual std::expected<Celsius, Status> GetChipsetTemperature() = 0;
        virtual std::expected<Celsius, Status> GetChargerTemperature() = 0;

        virtual Status SendCommand(Api::Command command) = 0;

    };
}
