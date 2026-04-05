#include "PiSubmarine/Chipset/Api/Convert.h"
#include "PiSubmarine/NormalizedIntFraction.h"

namespace PiSubmarine::Chipset::Api
{
    Status ConvertStatus(uint32_t status)
    {
        return static_cast<Status>(status);
    }

    std::chrono::seconds ConvertRtcToSeconds(uint32_t rtcHigh, uint32_t rtcLow)
    {
        uint64_t rtc = static_cast<uint64_t>(rtcHigh) << 32 | rtcLow;
        return std::chrono::seconds(rtc);
    }

    std::pair<uint32_t, uint32_t> ConvertSecondsToRtc(const std::chrono::seconds& rtc)
    {
        return std::make_pair(static_cast<uint32_t>(rtc.count() >> 32ULL), static_cast<uint32_t>(rtc.count()));
    }

    Volts ConvertToVolts(uint32_t reg)
    {
        return Volts(static_cast<double>(reg) /  1'000'000);
    }

    Amperes ConvertToAmperes(uint32_t reg)
    {
        return Amperes(static_cast<double>(reg) /  1'000'000);
    }

    NormalizedIntFraction<12> ConvertToIntFraction(uint32_t ballastPosition)
    {
        return NormalizedIntFraction<12>(ballastPosition);
    }

    Celsius ConvertToCelsius(uint32_t temperature)
    {
        return Celsius(static_cast<double>(temperature) / 1'000'000 - 273.15);
    }
}
