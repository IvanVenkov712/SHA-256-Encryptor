#include "Endianness.h"

bool IsLittleEndian()
{
	unsigned short s = 0b1000000000000000;
	unsigned char* ptr = (unsigned char*)(&s);
	return *ptr == 0;
}

unsigned long long ToBigEndian(unsigned long long value)
{
	if (IsLittleEndian()) {
		unsigned long long res = value;
		unsigned char* ptr = (unsigned char*)&res;
		unsigned int size = sizeof(res);
		for (int i = 0; i < size / 2; ++i) {
			unsigned char tmp = ptr[i];
			ptr[i] = ptr[size - 1 - i];
			ptr[size - 1 - i] = tmp;
		}
		return res;
	}
	return value;
}
