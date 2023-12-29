#include "Memory.h"

void MemoryCopy(void* src, int nSrc, void* dst)
{
	if (src == nullptr || dst == nullptr) {
		return;
	}
	unsigned char* pSrc = (unsigned char*)src;
	unsigned char* pDst = (unsigned char*)dst;
	for (int i = 0; i < nSrc; ++i) {
		pDst[i] = pSrc[i];
	}

}
