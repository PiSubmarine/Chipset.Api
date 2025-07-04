#include "PiSubmarine/Chipset/Api/PacketOut.h"
#include "PiSubmarine/Chipset/Api/Command.h"
#include <string.h>

namespace PiSubmarine::Chipset::Api
{
	size_t PacketOut::Serialize(uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc) const
	{
		if (bufferLength < 1 + 8 + 4)
		{
			return 0;
		}

		size_t pos = 0;
		buffer[pos++] = static_cast<uint8_t>(Command::DataOut);

		uint64_t chipsetTime = ChipsetTime.count();
		memcpy(buffer + pos, &chipsetTime, sizeof(chipsetTime));
		pos += sizeof(chipsetTime);

		uint64_t adcTime = AdcTime.count();
		memcpy(buffer + pos, &adcTime, sizeof(adcTime));
		pos += sizeof(adcTime);

		uint64_t batchgTime = BatchgTime.count();
		memcpy(buffer + pos, &batchgTime, sizeof(batchgTime));
		pos += sizeof(batchgTime);

		uint64_t status = static_cast<uint64_t>(Status);
		memcpy(buffer + pos, &status, sizeof(status));
		pos += sizeof(status);

		uint64_t reg5Voltage = Reg5Voltage.Get();
		memcpy(buffer + pos, &reg5Voltage, sizeof(reg5Voltage));
		pos += sizeof(reg5Voltage);

		uint64_t regPiVoltage = RegPiVoltage.Get();
		memcpy(buffer + pos, &regPiVoltage, sizeof(regPiVoltage));
		pos += sizeof(regPiVoltage);

		uint64_t ballastAdc = BallastAdc.Get();
		memcpy(buffer + pos, &ballastAdc, sizeof(ballastAdc));
		pos += sizeof(ballastAdc);

		uint64_t chipsetTemp = ChipsetTemperature.Get();
		memcpy(buffer + pos, &chipsetTemp, sizeof(chipsetTemp));
		pos += sizeof(chipsetTemp);

		uint64_t batchgTemp = BatchgTemperature.Get();
		memcpy(buffer + pos, &batchgTemp, sizeof(batchgTemp));
		pos += sizeof(batchgTemp);

		uint32_t crc = crcFunc(buffer, pos);
		memcpy(buffer + pos, &crc, sizeof(crc));
		pos += sizeof(crc);
		return pos;
	}

	bool PacketOut::Deserialize(const uint8_t* buffer, size_t bufferLength, Crc32Func crcFunc)
	{
		size_t pos = 0;
		Command command = static_cast<Command>(buffer[pos++]);
		if (command != Command::DataOut)
		{
			return false;
		}

		uint64_t chipsetTime = 0;
		memcpy(&chipsetTime, buffer + pos, sizeof(chipsetTime));
		pos += sizeof(chipsetTime);
		ChipsetTime = std::chrono::milliseconds(chipsetTime);

		uint64_t adcTime = 0;
		memcpy(&adcTime, buffer + pos, sizeof(adcTime));
		pos += sizeof(adcTime);
		AdcTime = std::chrono::milliseconds(adcTime);

		uint64_t batchgTime = 0;
		memcpy(&batchgTime, buffer + pos, sizeof(batchgTime));
		pos += sizeof(batchgTime);
		BatchgTime = std::chrono::milliseconds(batchgTime);

		memcpy(&Status, buffer + pos, sizeof(Status));
		pos += sizeof(Status);

		uint64_t reg5Voltage = 0;
		memcpy(&reg5Voltage, buffer + pos, sizeof(reg5Voltage));
		pos += sizeof(reg5Voltage);
		Reg5Voltage = MicroVolts(reg5Voltage);

		uint64_t regPiVoltage = 0;
		memcpy(&regPiVoltage, buffer + pos, sizeof(regPiVoltage));
		pos += sizeof(regPiVoltage);
		RegPiVoltage = MicroVolts(regPiVoltage);

		uint64_t ballastAdc = 0;
		memcpy(&ballastAdc, buffer + pos, sizeof(ballastAdc));
		pos += sizeof(ballastAdc);
		BallastAdc = Percentage<12>(ballastAdc);

		uint64_t chipsetTemp = 0;
		memcpy(&chipsetTemp, buffer + pos, sizeof(chipsetTemp));
		pos += sizeof(chipsetTemp);
		ChipsetTemperature = MicroKelvins(chipsetTemp);

		uint64_t batchgTemp = 0;
		memcpy(&batchgTemp, buffer + pos, sizeof(batchgTemp));
		pos += sizeof(batchgTemp);
		BatchgTemperature = MicroKelvins(batchgTemp);

		uint32_t crcActual = crcFunc(buffer, pos);

		uint32_t crcExpected = 0;
		memcpy(&crcExpected, buffer + pos, sizeof(crcExpected));
		pos += sizeof(crcExpected);

		if (crcActual != crcExpected)
		{
			return false;
		}
		return true;
	}
}