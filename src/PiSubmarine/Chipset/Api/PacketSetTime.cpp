#include "PiSubmarine/Chipset/Api/PacketSetTime.h"

namespace PiSubmarine::Chipset::Api
{
	size_t PacketSetTime::Serialize(uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc) const
	{
		return size_t();
	}

	bool PacketSetTime::Deserialize(const uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc)
	{
		return false;
	}

}