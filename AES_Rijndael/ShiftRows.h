#pragma once
#include <cstdint>

namespace AES
{
	namespace RijndaelPart
	{
		struct Shift
		{
			template<typename T>
			void operator()(T* data, size_t size, size_t move)//move left
			{
				if (move == 0) return;

				T tmp = data[0];

				for (size_t i = 0; i < size - 1; i++)
					data[i] = data[i + 1];

				data[size - 1] = tmp;

				Shift(data, size, move - 1);
			}
		};

		struct ShiftRows :protected Shift
		{
			void operator()(uint8_t* data)	//16byte//aes-128bit
			{
				for (size_t i = 0; i < 4; i++)
					Shift()(data + (i * 4), 4, i);
			}
		};
		struct InvertedShiftRows :protected Shift
		{
			void operator()(uint8_t* data)	//16byte//aes-128bit
			{
				for (size_t i = 0; i < 4; i++)
					Shift()(data + (i * 4), 4, 4 - i);
			}
		};
	}
}