#include <iostream>
#include <cstdint>
#include "Rijndael.h"

int main()
{
	AES::RijndaelPart::ShiftRows ShiftRows;
	AES::RijndaelPart::InverseShiftRows InverseShiftRows;

	std::array<int, 24> test;
	
	int i = 0;
	for (auto& var : test)
		var = i++;

	try {
		test=ShiftRows(test);

		for (auto& var : test)
			std::cout << var << ' ';

		std::cout << std::endl;

		test=InverseShiftRows(test);

		for (auto& var : test)
			std::cout << var << ' ';
	}
	catch (AES::Exception e)
	{
		std::cerr << e.What() << std::endl;
	}
}