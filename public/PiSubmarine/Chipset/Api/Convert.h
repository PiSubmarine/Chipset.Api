#pragma once

#include <chrono>
#include "PiSubmarine/Volts.h"
#include "PiSubmarine/Chipset/Api/Status.h"
#include "PiSubmarine/NormalizedIntFraction.h"
#include "PiSubmarine/Celsius.h"

namespace PiSubmarine::Chipset::Api
{
    Status StatusToEnum(uint32_t status);
    std::chrono::seconds RtcToSeconds(uint32_t rtcHigh, uint32_t rtcLow);
    std::pair<uint32_t, uint32_t> SecondsToRtc(const std::chrono::seconds& rtc);
    Volts RegulatorToVolts(uint32_t reg);
    NormalizedIntFraction<12> BallastPositionToFraction(uint32_t ballastPosition);
    Celsius TemperatureToCelsius(uint32_t temperature);

}