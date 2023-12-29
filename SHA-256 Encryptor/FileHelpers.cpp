#include "FileHelpers.h"

int AlignFileSize(int val)
{
	/*if (val < 0) {
		return -1;
	}
	int res = CHUNKSIZE-ULLSIZE;
	while (res < val) {
		res += CHUNKSIZE;
	}
	return res + ULLSIZE;*/
	if (val < 0) {
		return -1;
	}
	val += ULLSIZE;
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
	int buffSize = AlignFileSize(fSize);
	std::ifstream fStream(fileName);
	if (!fStream.is_open()) {
		return nullptr;
	}
	char* buff = new char[buffSize];
	fSize = ToBigEndian(fSize);
	buff
	fStream.read(buff, fSize);
	fStream.close();

	//
	size = buffSize;
	return (Byte*)buff;
}
