#include "PiSubmarine/Chipset/Api/PacketShutdown.h"
#include "PiSubmarine/Chipset/Api/Command.h"
#include <string.h>

namespace PiSubmarine::Chipset::Api
{
	size_t PacketShutdown::Serialize(uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc) const
	{
		if (bufferLength < 1 + 8 + 4)
		{
			return 0;
		}

		size_t pos = 0;
		buffer[pos++] = static_cast<uint8_t>(Command::Shutdown);
		uint64_t delay = Delay.count();
		memcpy(buffer + pos, &delay, sizeof(delay));
		pos += sizeof(delay);
		uint32_t crc = crcFunc(buffer, pos);
		memcpy(buffer + pos, &crc, sizeof(crc));
		pos += sizeof(crc);
		return pos;
	}

	bool PacketShutdown::Deserialize(const uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc)
	{
		size_t pos = 0;
		Command command = static_cast<Command>(buffer[pos++]);
		if (command != Command::Shutdown)
		{
			return false;
		}

		uint64_t delay = 0;
		memcpy(&delay, buffer + pos, sizeof(delay));
		pos += sizeof(delay);
		
		uint32_t crcActual = crcFunc(buffer, pos);

		uint32_t crcExpected = 0;
		memcpy(&crcExpected, buffer + pos, sizeof(crcExpected));
		pos += sizeof(crcExpected);

		if (crcActual != crcExpected)
		{
			return false;
		}

		Delay = std::chrono::milliseconds(delay);
		return true;
	}
}