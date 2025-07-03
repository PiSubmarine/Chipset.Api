#pragma once

#include <chrono>
#include "PiSubmarine/Chipset/Api/MicroVolts.h"
#include "PiSubmarine/Chipset/Api/MicroAmperes.h"
#include "PiSubmarine/Chipset/Api/MicroAmpereHours.h"
#include "PiSubmarine/Chipset/Api/Percentage.h"
#include "PiSubmarine/Chipset/Api/Crc32Func.h"

namespace PiSubmarine::Chipset::Api
{
	enum class StatusFlags : uint64_t
	{
		VbusConnected = (1 << 0),
		ChargingInProgress = (1 << 1)
	};

	struct PacketOut
	{
	public:
		constexpr static size_t Size = 1 + 6 * 8 + 4;

		/// <summary>
		/// Chipset time at the beginning of transaction. 0 if time was not set.
		/// </summary>
		std::chrono::milliseconds ChipsetTime{ 0 };

		/// <summary>
		/// Chipset time at packet creation. 0 if chipset time was not set.
		/// </summary>
		std::chrono::milliseconds PacketTime{ 0 };

		StatusFlags Status{ 0 };

		/*
		MicroVolts BatteryVoltage;
		MicroAmperes BatteryCurrent;
		Percentage<8> BatteryStateOfCharge;
		std::chrono::milliseconds BatteryTimeToEmpty;
		std::chrono::milliseconds BatteryTimeToFull;
		*/
		
		MicroVolts Reg5Voltage{ 0 };
		MicroVolts RegPiVoltage{ 0 };
		Percentage<12> BallastAdc{ 0 };
		
		

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