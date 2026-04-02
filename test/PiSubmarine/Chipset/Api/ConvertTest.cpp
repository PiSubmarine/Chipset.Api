#pragma once

#include "gtest/gtest.h"
#include "PiSubmarine/Chipset/Api/Convert.h"
#include <array>

namespace PiSubmarine::Chipset::Api
{
	TEST(ConvertTest, Rtc)
	{
		std::chrono::steady_clock::time_point rtc = std::chrono::steady_clock::now();

		auto duration_since_epoch = rtc.time_since_epoch();
		auto sec = std::chrono::duration_cast<std::chrono::seconds>(duration_since_epoch);

		auto[rtcHigh, rtcLow] = SecondsToRtc(sec);
		auto rtcRestored = RtcToSeconds(rtcHigh, rtcLow);
		EXPECT_EQ(rtcRestored, sec);
	}
}