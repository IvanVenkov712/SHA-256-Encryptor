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
* Source: Contains definitions of helper functions for files
*
*/

#include "FileHelpers.h"

int AlignBuffSize(int val)
{
	if (val < 0) {
		return -1;
	}
	val += ULLSIZE + 1;
	return val + CHUNKSIZE - val % CHUNKSIZE;

}

int FileSize(const char* fileName)
{
	std::ifstream fStream(fileName, std::ios::binary);
	if (!fStream.is_open()) {
		return -1;
	}
	std::streampos begin = fStream.tellg();
	fStream.seekg(0, fStream.end);
	int n = fStream.tellg() - begin;
	fStream.close();
	return n;
}

Byte* LoadFileInMemory(const char* fileName, int& size)
{
	int fSize = FileSize(fileName);
	if (fSize < 0) {
		return nullptr;
	}
	int buffSize = AlignBuffSize(fSize);
	std::ifstream fStream(fileName, std::ios::binary);
	if (!fStream.is_open()) {
		return nullptr;
	}
	char* buff = new char[buffSize];
	for (int i = 0; i < buffSize; ++i) {
		buff[i] = 0;
	}
	buff[fSize] = 0b10000000;
	unsigned long long BEfSize = ToBigEndianLLU(8 * ((unsigned long long)fSize));
	MemoryCopy(&BEfSize, sizeof(BEfSize), buff + buffSize - sizeof(BEfSize));
	fStream.read(buff, fSize);
	fStream.close();
	size = buffSize;
	return (Byte*)buff;
}