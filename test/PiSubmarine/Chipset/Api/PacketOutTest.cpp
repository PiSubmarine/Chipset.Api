#pragma once

#include "gtest/gtest.h"
#include "PiSubmarine/Chipset/Api/PacketOut.h"

namespace PiSubmarine::Chipset::Api
{
	TEST(PacketOutTest, Instantiation)
	{
		PacketOut packet;
	}
}