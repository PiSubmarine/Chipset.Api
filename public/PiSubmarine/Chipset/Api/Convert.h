#pragma once

#include <chrono>
#include <PiSubmarine/Amperes.h>

#include "PiSubmarine/Volts.h"
#include "PiSubmarine/Chipset/Api/Status.h"
#include "PiSubmarine/NormalizedIntFraction.h"
#include "PiSubmarine/Celsius.h"

namespace PiSubmarine::Chipset::Api
{
    Status ConvertStatus(uint32_t status);
    std::chrono::seconds ConvertRtcToSeconds(uint32_t rtcHigh, uint32_t rtcLow);
    std::pair<uint32_t, uint32_t> ConvertSecondsToRtc(const std::chrono::seconds& rtc);
    Volts ConvertToVolts(uint32_t reg);
    Amperes ConvertToAmperes(uint32_t reg);
    NormalizedIntFraction<12> ConvertToIntFraction(uint32_t ballastPosition);
    Celsius ConvertToCelsius(uint32_t temperature);

}