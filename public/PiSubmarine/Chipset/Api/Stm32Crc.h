#pragma once

#include <cstdint>
#include <cstddef>

namespace PiSubmarine::Chipset::Api
{

    class Stm32Crc
    {
    public:
        Stm32Crc()
        {
            GenerateTable();
        }

        uint32_t Calculate(const uint8_t* bytes, size_t length) const
        {
            uint32_t crc = 0xFFFFFFFF;

            for (size_t i = 0; i < length; ++i)
            {
                uint8_t index = (uint8_t)((crc >> 24) ^ bytes[i]);
                crc = (crc << 8) ^ table[index];
            }

            return crc; // No final XOR
        }

    private:
        uint32_t table[256];

        void GenerateTable()
        {
            const uint32_t poly = 0x04C11DB7;
            for (uint32_t i = 0; i < 256; ++i)
            {
                uint32_t crc = i << 24;
                for (int j = 0; j < 8; ++j)
                {
                    if (crc & 0x80000000)
                        crc = (crc << 1) ^ poly;
                    else
                        crc <<= 1;
                }
                table[i] = crc;
            }
        }
    };

}