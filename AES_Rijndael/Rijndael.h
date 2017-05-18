#pragma once
#include "SubBytes.h"
#include "ShiftRows.h"
#include "MixColumns.h"

namespace AES
{
	class Rijndael
	{
	private:
		RijndaelPart::SubBytes SubBytes;
		RijndaelPart::InvertedSubBytes InvertedSubBytes;
		//RijndaelPart::ShiftRows ShiftRows;
		//RijndaelPart::InvertedShiftRows InvertedShiftRows;
		
	};
}