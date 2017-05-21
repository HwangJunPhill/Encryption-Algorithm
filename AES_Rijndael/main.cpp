#include <iostream>
#include <cstdint>
#include "Rijndael.h"
#include <vector>

int main()
{
	AES::RijndaelPart::ShiftRows ShiftRows;
	AES::RijndaelPart::InverseShiftRows InverseShiftRows;

	std::vector<int> test;
	
	for (int i = 0; i < 16; i++)
		test.push_back(i);
	

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