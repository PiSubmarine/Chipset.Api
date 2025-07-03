#pragma once

#include <cstdint>
#include <iostream>

namespace PiSubmarine::Chipset::Api
{
	template<size_t Base>
	class Percentage
	{
	public:
		using ValueType = uint64_t;

		explicit constexpr Percentage(ValueType value = 0) noexcept
			: Value(value)
		{
		}

		constexpr ValueType Get() const noexcept { return Value; }

		constexpr double ToFactor() const noexcept
		{
			return static_cast<double>(Value) / (1 << Base - 1);
		}


	private:
		ValueType Value;
	};
}
