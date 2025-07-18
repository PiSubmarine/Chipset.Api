#pragma once

#include <array>
#include "gtest/gtest.h"
#include "PiSubmarine/Chipset/Api/Command.h"
#include "PiSubmarine/Chipset/Api/PacketSetTime.h"
#include "PiSubmarine/Chipset/Api/Stm32Crc.h"

using namespace std::chrono_literals;

namespace PiSubmarine::Chipset::Api
{
	TEST(PacketSetTimeTest, Serialization)
	{
		Stm32Crc crcProvider;

		PacketSetTime packet;
		packet.RtcTime = 0xABCDms;
		std::array<uint8_t, 13> dataBuffer{ 0 };

		// (79, 0x4F), '\xC7' (199), '\xCA' (202), '\x1D' (29)
		std::array<uint8_t, 13> expectedData{ static_cast<uint8_t>(Command::SetTime),  0xCD, 0xAB, 0, 0, 0, 0, 0, 0, 0x4F, 0xC7, 0xCA, 0x1D };
		Crc32Func crcFunc = [crcProvider](const uint8_t* data, size_t len) {return crcProvider.Calculate(data, len); };
		size_t serOut = packet.Serialize(dataBuffer.data(), dataBuffer.size(), crcFunc);
		EXPECT_EQ(serOut, 13);
		EXPECT_EQ(dataBuffer, expectedData);

		PacketSetTime deserialized;
		bool deserOk = deserialized.Deserialize(dataBuffer.data(), dataBuffer.size(), crcFunc);
		EXPECT_TRUE(deserOk);

		EXPECT_EQ(packet.RtcTime, deserialized.RtcTime);
	}
}