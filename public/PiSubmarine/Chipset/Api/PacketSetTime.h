#pragma once

#include <cstdint>
#include <chrono>
#include "PiSubmarine/Chipset/Api/Crc32Func.h"

namespace PiSubmarine::Chipset::Api
{
	struct PacketSetTime
	{
		std::chrono::milliseconds RtcTime;

		/// <summary>
		/// Fills byte buffer with fields values.
		/// </summary>
		/// <param name="buffer">Pointer to data buffer</param>
		/// <param name="bufferLength">Length of the buffer</param>
		/// <returns>Number of bytes that were actually written to the buffer. Returns 0 if buffer length was not enough.</returns>
		size_t Serialize(uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc) const;

		/// <summary>
		/// Fills fields with data received over communication channel.
		/// </summary>
		/// <param name="buffer">Pointer to data.</param>
		/// <param name="bufferLength">Length of received data.</param>
		/// <returns>True if deserialization succeeded, false if data was truncated or CRC check failed.</returns>
		bool Deserialize(const uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc);
	};
}