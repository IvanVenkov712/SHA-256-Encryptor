/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Ivan Venkov
* @idnumber 1MI0600291
* @compiler VC
*
* Source: Contains definitions of helper functions for conversion LE to BE and vice-versa
*
*/

#include "Endianness.h"

bool IsLittleEndian()
{
	unsigned short s = 0b1000000000000000;
	unsigned char* ptr = (unsigned char*)(&s);
	return *ptr == 0;
}

unsigned long long SwapBytesLLU(unsigned long long value)
{
	unsigned long long res = value;
	unsigned char* ptr = (unsigned char*)&res;
	unsigned int size = sizeof(res);
	for (unsigned int i = 0; i < size / 2; ++i) {
		unsigned char tmp = ptr[i];
		ptr[i] = ptr[size - 1 - i];
		ptr[size - 1 - i] = tmp;
	}
	return res;
}

unsigned int SwapBytesU(unsigned int value)
{
	unsigned int res = value;
	unsigned char* ptr = (unsigned char*)&res;
	unsigned int size = sizeof(res);
	for (unsigned int i = 0; i < size / 2; ++i) {
		unsigned char tmp = ptr[i];
		ptr[i] = ptr[size - 1 - i];
		ptr[size - 1 - i] = tmp;
	}
	return res;
}

unsigned long long ToBigEndianLLU(unsigned long long value)
{
	if (IsLittleEndian()) {
		return SwapBytesLLU(value);
	}
	return value;
}

unsigned int ToBigEndianU(unsigned int value)
{
	if (IsLittleEndian()) {
		return SwapBytesU(value);
	}
	return value;
}
