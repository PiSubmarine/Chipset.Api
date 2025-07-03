#pragma once

#include <cstdint>
#include <iostream>

namespace PiSubmarine::Chipset::Api
{
	class MicroAmperes
	{
	public:
		using ValueType = int64_t;

		explicit constexpr MicroAmperes(ValueType value = 0) noexcept
			: Value(value)
		{
		}

		constexpr ValueType Get() const noexcept { return Value; }

		constexpr double ToAmperes() const noexcept
		{
			return static_cast<double>(Value) / 1'000'000.0;
		}

		// Arithmetic operators
		constexpr MicroAmperes operator+(const MicroAmperes& other) const noexcept
		{
			return MicroAmperes(Value + other.Value);
		}

		constexpr MicroAmperes operator-(const MicroAmperes& other) const noexcept
		{
			return MicroAmperes(Value - other.Value);
		}

		constexpr MicroAmperes operator*(uint64_t scalar) const noexcept
		{
			return MicroAmperes(Value * scalar);
		}

		constexpr MicroAmperes operator/(uint64_t scalar) const noexcept
		{
			return MicroAmperes(Value / scalar);
		}

		constexpr bool operator==(const MicroAmperes& other) const noexcept
		{
			return Value == other.Value;
		}

		constexpr bool operator!=(const MicroAmperes& other) const noexcept
		{
			return !(*this == other);
		}

	private:
		ValueType Value;
	};
}

constexpr PiSubmarine::Chipset::Api::MicroAmperes operator"" _uA(unsigned long long val)
{
	return PiSubmarine::Chipset::Api::MicroAmperes(static_cast<PiSubmarine::Chipset::Api::MicroAmperes::ValueType>(val));
}
