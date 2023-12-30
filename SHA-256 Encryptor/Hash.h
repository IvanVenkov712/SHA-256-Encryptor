#pragma once
#include "FileHelpers.h"
#include "ToStrHex.h"

struct Hash {
	unsigned int h0 = 0;
	unsigned int h1 = 0; 
	unsigned int h2 = 0;
	unsigned int h3 = 0;
	unsigned int h4 = 0;
	unsigned int h5 = 0;
	unsigned int h6 = 0;
	unsigned int h7 = 0;

};

unsigned int rightrotate(unsigned int value, unsigned int n);
bool HashFile(const char* fileName, Hash* out);
bool HashToStr(char* dst, size_t nDst, const Hash* hash);