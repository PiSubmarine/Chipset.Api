#pragma once

#include "gtest/gtest.h"
#include "PiSubmarine/Chipset/Api/PacketOut.h"
#include "PiSubmarine/Chipset/Api/Stm32Crc.h"
#include <array>

namespace PiSubmarine::Chipset::Api
{
	TEST(PacketOutTest, Instantiation)
	{
		Stm32Crc crcProvider;
		Crc32Func crcFunc = [crcProvider](const uint8_t* data, size_t len) {return crcProvider.Calculate(data, len); };


		PacketOut packet;
		packet.ChipsetTime = std::chrono::milliseconds(0xABCD);
		packet.PacketTime = std::chrono::milliseconds(0x0102);
		packet.Status = StatusFlags::VbusConnected;
		packet.Reg5Voltage = MicroVolts(0x123456);
		packet.RegPiVoltage = MicroVolts(0x789ABC);
		packet.BallastAdc = Percentage<12>(0xECEC);

		std::array<uint8_t, PacketOut::Size> serialized{ 0 };
		size_t size = packet.Serialize(serialized.data(), serialized.size(), crcFunc);
		ASSERT_EQ(size, PacketOut::Size);

		PacketOut deserialized;
		bool deserializationOk = deserialized.Deserialize(serialized.data(), serialized.size(), crcFunc);
		ASSERT_TRUE(deserializationOk);

		EXPECT_EQ(packet.ChipsetTime, deserialized.ChipsetTime);
		EXPECT_EQ(packet.PacketTime, deserialized.PacketTime);
		EXPECT_EQ(packet.Status, deserialized.Status);
		EXPECT_EQ(packet.Reg5Voltage, deserialized.Reg5Voltage);
		EXPECT_EQ(packet.RegPiVoltage, deserialized.RegPiVoltage);
		EXPECT_EQ(packet.BallastAdc.Get(), deserialized.BallastAdc.Get());
	}
}