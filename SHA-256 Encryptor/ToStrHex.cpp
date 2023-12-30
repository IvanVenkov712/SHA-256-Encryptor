#include "ToStrHex.h"

const char dictionary[17] = "0123456789ABCDEF";

bool ToStrHex(char* dst, size_t nDst, unsigned int value)
{
	size_t valDigsCount = sizeof(value) * 2;
	if (nDst < valDigsCount + 1) {
		return false;
	}
	unsigned int cnt = valDigsCount - 1;
	dst[valDigsCount] = '\0';
	do {
		dst[cnt] = dictionary[value % 16];
		--cnt;
		value /= 16;
	} while (value != 0);
	return true;

}
