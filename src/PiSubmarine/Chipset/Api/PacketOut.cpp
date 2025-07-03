#include "PiSubmarine/Chipset/Api/PacketOut.h"

namespace PiSubmarine::Chipset::Api
{
	size_t PacketOut::Serialize(uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc) const
	{
		return 0;
	}

	bool PacketOut::Deserialize(const uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc)
	{
		return false;
	}
}