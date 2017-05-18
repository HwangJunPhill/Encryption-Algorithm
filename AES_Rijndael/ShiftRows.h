#pragma once
#include "Exception.h"
#include <cstdint>
#include <array>
#include <vector>

namespace AES
{
	namespace RijndaelPart
	{
		class ShiftRows
		{
		public:
			template<typename Container>
			Container operator()(const Container& container) const
			{
				return Shifts(container);
			}

		protected:
			template<typename Container>
			Container Shifts(const Container& container) const
			{
				if (container.size() % 4 != 0)
					throw Exception(Exception::ErrorCode::BadSize);

				std::array<std::vector<uint8_t>, 4> array;
				size_t count = 0;
				for (auto& quarter : array)
					for (size_t i = 0; i < (container.size() / 4); i++)
						quarter.push_back(container[count++]);

				count = 0;
				for (auto& quarter : array)
					Shift(quarter, count++);

				Container ret(container);

				count = 0;
				for (const auto& quarter : array)
					for (const auto& var : quarter)
						ret[count++] = var;

				return ret;
			}

			virtual void Shift(std::vector<uint8_t>& data, const size_t loop = 1) const
			{
				size_t size = data.size();

				for (size_t i = 0; i < loop; i++)
					for (size_t j = 0; j < size - 1; j++)
						std::swap(data[j], data[j + 1]);
			}
		};

		class InvertedShiftRows :public ShiftRows
		{
		public:
			template<typename Container>
			Container operator()(const Container& container) const
			{
				return Shifts(container);
			}

		protected:
			virtual void Shift(std::vector<uint8_t>& data, const size_t loop = 1) const
			{
				size_t size = data.size();

				for (size_t i = 0; i < loop; i++)
					for (size_t j = size - 1; j > 0; j--)
						std::swap(data[j], data[j - 1]);
			}
		};
	}
}