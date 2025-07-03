#pragma once

#include <cstdint>

namespace PiSubmarine::Chipset::Api
{
	enum class Command : uint8_t
	{
		SetTime = 0xA0,
		Shutdown = 0xA1
	};

	
}