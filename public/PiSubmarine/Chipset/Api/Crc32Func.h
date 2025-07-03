#pragma once 

#include <cstdint>
#include <functional>

namespace PiSubmarine::Chipset::Api
{
	using Crc32Func = std::function<uint32_t(const uint8_t*, size_t)>;
}