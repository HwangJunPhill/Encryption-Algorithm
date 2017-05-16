#pragma once
#include "Exception.h"
#include <cstdint>
#include <array>
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace AES
{
	namespace RijndaelPart
	{
		struct ShiftRows
		{
			template<typename Type, size_t size>
			void operator()(std::array<Type, size>& data)
			{
				if (size % 4 != 0) 
					throw Exception(Exception::ErrorCode::BadSize);
				
				std::array<std::array<Type, size / 4>, 4> quarter;
				size_t count=0;
				for (auto& array : quarter)
					for (auto& var : array)
						var = data[count++];

				for (int i = 0; i < 4; i++)
					Shift(quarter[i], i);

				count = 0;
				for (auto& array : quarter)
					for (auto& var : array)
						data[count++] = var;

				return;
			}

			template<typename Type, size_t size>
			void Shift(std::array<Type, size>& data, size_t loop = 1)
			{
				for (size_t i = 0; i < loop; i++)
					for (size_t j = 0; j < size - 1; j++)
						std::swap(data[j], data[j + 1]);
			}
		};

		struct InvertedShiftRows
		{
			template<typename Type, size_t size>
			void operator()(std::array<Type, size>& data)
			{
				if (size % 4 != 0) 
					throw Exception(Exception::ErrorCode::BadSize);
				
				std::array<std::array<Type, size / 4>, 4> quarter;
				size_t count=0;
				for (auto& array : quarter)
					for (auto& var : array)
						var = data[count++];

				for (int i = 0; i < 4; i++)
					Shift(quarter[i], i);

				count = 0;
				for (auto& array : quarter)
					for (auto& var : array)
						data[count++] = var;

				return;
			}

			template<typename Type, size_t size>
			void Shift(std::array<Type, size>& data, size_t loop = 1)
			{
				for (size_t i = 0; i < loop; i++)
					for (size_t j = size - 1; j > 0; j--)
						std::swap(data[j], data[j - 1]);
			}
		};
	}
}