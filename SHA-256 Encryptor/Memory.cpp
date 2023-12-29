#include "Memory.h"

void MemoryCopy(const void* src, int nSrc, void* dst)
{
	if (src == nullptr || dst == nullptr) {
		return;
	}
	unsigned const char* pSrc = (unsigned const char*)src;
	unsigned char* pDst = (unsigned char*)dst;
	for (int i = 0; i < nSrc; ++i) {
		pDst[i] = pSrc[i];
	}

}
