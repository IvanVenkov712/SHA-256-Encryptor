#include "ToStrHex.h"

const char dictionary[17] = "0123456789abcdef";

bool ToStrHex(char* dst, size_t nDst, unsigned int value)
{
	int valDigsCount = sizeof(value) * 2;
	if (nDst < valDigsCount + 1) {
		return false;
	}
	unsigned int cnt = valDigsCount - 1;
	dst[valDigsCount] = '\0';
	for (int i = valDigsCount - 1; i >= 0; --i) {
		dst[i] = dictionary[value % 16];
		value /= 16;
	}
	return true;

}
