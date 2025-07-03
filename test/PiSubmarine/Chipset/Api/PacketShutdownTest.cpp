#pragma once

#include <array>
#include "gtest/gtest.h"
#include "PiSubmarine/Chipset/Api/Command.h"
#include "PiSubmarine/Chipset/Api/PacketShutdown.h"
#include "PiSubmarine/Chipset/Api/Stm32Crc.h"

using namespace std::chrono_literals;

namespace PiSubmarine::Chipset::Api
{
	TEST(PacketOutTest, Serialization)
	{
		Stm32Crc crcProvider;

		PacketShutdown packet;
		packet.Delay = 0xABCDms;
		std::array<uint8_t, 13> dataBuffer{ 0 };

		std::array<uint8_t, 13> expectedData{ static_cast<uint8_t>(Command::Shutdown),  0xCD, 0xAB, 0, 0, 0, 0, 0, 0, 0x29, 0x6D, 0xCA, 0xEF };
		Crc32Func crcFunc = [crcProvider](const uint8_t* data, size_t len) {return crcProvider.Calculate(data, len); };
		size_t serOut = packet.Serialize(dataBuffer.data(), dataBuffer.size(), crcFunc);
		EXPECT_EQ(serOut, 13);
		EXPECT_EQ(dataBuffer, expectedData);

		PacketShutdown deserialized;
		bool deserOk = deserialized.Deserialize(dataBuffer.data(), dataBuffer.size(), crcFunc);
		EXPECT_TRUE(deserOk);

		EXPECT_EQ(packet.Delay, deserialized.Delay);
	}
}