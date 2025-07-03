#pragma once

#include <cstdint>

namespace PiSubmarine::Chipset::Api
{
	enum class Command : uint8_t
	{
		DataOut = 0x00,
		SetTime = 0xA0,
		Shutdown = 0xA1
	};

	
}