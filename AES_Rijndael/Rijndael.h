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
		RijndaelPart::InverseSubBytes InvertedSubBytes;
		
	};
}