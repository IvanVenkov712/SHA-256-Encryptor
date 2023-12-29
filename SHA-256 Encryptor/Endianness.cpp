#include "Endianness.h"

bool IsLittleEndian()
{
	unsigned short s = 0b1000000000000000;
	unsigned char* ptr = (unsigned char*)(&s);
	return *ptr == 0;
}

int ToBigEndian(int value)
{
	if (IsLittleEndian()) {
		unsigned int res = value;
		unsigned char* ptr = (unsigned char*)value;
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
