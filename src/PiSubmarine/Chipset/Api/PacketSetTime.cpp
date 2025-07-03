#include "PiSubmarine/Chipset/Api/PacketSetTime.h"
#include "PiSubmarine/Chipset/Api/Command.h"
#include <string.h>

namespace PiSubmarine::Chipset::Api
{
	size_t PacketSetTime::Serialize(uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc) const
	{
		if (bufferLength < 1 + 8 + 4)
		{
			return 0;
		}

		size_t pos = 0;
		buffer[pos++] = static_cast<uint8_t>(Command::SetTime);
		uint64_t rtcTime = RtcTime.count();
		memcpy(buffer + pos, &rtcTime, sizeof(rtcTime));
		pos += sizeof(rtcTime);
		uint32_t crc = crcFunc(buffer, pos);
		memcpy(buffer + pos, &crc, sizeof(crc));
		pos += sizeof(crc);
		return pos;
	}

	bool PacketSetTime::Deserialize(const uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc)
	{
		size_t pos = 0;
		Command command = static_cast<Command>(buffer[pos++]);
		if (command != Command::SetTime)
		{
			return false;
		}

		uint64_t rtcTime = 0;
		memcpy(&rtcTime, buffer + pos, sizeof(rtcTime));
		pos += sizeof(rtcTime);

		uint32_t crcActual = crcFunc(buffer, pos);

		uint32_t crcExpected = 0;
		memcpy(&crcExpected, buffer + pos, sizeof(crcExpected));
		pos += sizeof(crcExpected);

		if (crcActual != crcExpected)
		{
			return false;
		}

		RtcTime = std::chrono::milliseconds(rtcTime);
		return true;
	}

}