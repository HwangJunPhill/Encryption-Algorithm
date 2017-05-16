#include <iostream>
#include <cstdint>
#include "Rijndael.h"

int main()
{
	AES::RijndaelPart::ShiftRows ShiftRows;
	AES::RijndaelPart::InvertedShiftRows InvertedShiftRows;

	std::array<int, 24> test;

	int i = 0;
	for (auto& var : test)
		var = i++;

	ShiftRows(test);

	for (auto& var : test)
		std::cout << var << ' ';

	std::cout << std::endl;

	InvertedShiftRows(test);

	for (auto& var : test)
		std::cout << var << ' ';
}