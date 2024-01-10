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
* Source: Contains the definition of MemoryCopy
*
*/


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
