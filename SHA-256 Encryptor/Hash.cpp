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
* Source: Contains definitions of helper functions for hashing
*
*/


#include "Hash.h"
#include <iostream>
#include <iomanip>

const unsigned int k[] =
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 
};
unsigned int rightrotate(unsigned int value, unsigned int n)
{
	unsigned int mask = UINT32_MAX >> (sizeof(value) * 8 - n);
	unsigned int remainingBits = (value & mask) << (sizeof(value) * 8 - n);
	return (value >> n) | remainingBits;
}
bool HashFile(const char* fileName, Hash* out) {
	int buffSize = 0;
	Byte* buff = LoadFileInMemory(fileName, buffSize);
	if (buff == nullptr) {
		return false;
	}
	unsigned int h0 = 0x6a09e667;
	unsigned int h1 = 0xbb67ae85;
	unsigned int h2 = 0x3c6ef372;
	unsigned int h3 = 0xa54ff53a;
	unsigned int h4 = 0x510e527f;
	unsigned int h5 = 0x9b05688c;
	unsigned int h6 = 0x1f83d9ab;
	unsigned int h7 = 0x5be0cd19;

	for (int i = 0; i < buffSize / CHUNKSIZE; ++i) {
		const unsigned char* chunk = buff + CHUNKSIZE * i;
		unsigned int w[64] = {};
		MemoryCopy(chunk, CHUNKSIZE, w);
		if (IsLittleEndian()) {
			for (int i = 0; i < 64; ++i) {
				w[i] = SwapBytesU(w[i]);
			}
		}
		for (int j = 16; j < 64; ++j) {
			unsigned int s0 = rightrotate(w[j - 15], 7) ^ rightrotate(w[j - 15], 18) ^ (w[j - 15] >> 3);
			unsigned int s1 = rightrotate(w[j - 2], 17) ^ rightrotate(w[j - 2], 19) ^ (w[j - 2] >> 10);
			w[j] = w[j - 16] + s0 + w[j - 7] + s1;
		}

		unsigned int a = h0;
		unsigned int b = h1;
		unsigned int c = h2;
		unsigned int d = h3;
		unsigned int e = h4;
		unsigned int f = h5;
		unsigned int g = h6;
		unsigned int h = h7;

		for (int j = 0; j < 64; ++j) {
			unsigned int S1 = rightrotate(e, 6) ^ rightrotate(e, 11) ^ rightrotate(e, 25);
			unsigned int ch = (e & f) ^ ((~e) & g);
			unsigned int temp1 = h + S1 + ch + k[j] + w[j];
			unsigned int S0 = rightrotate(a, 2) ^ rightrotate(a, 13) ^ rightrotate(a, 22);
			unsigned int maj = (a & b) ^ (a & c) ^ (b & c);
			unsigned int temp2 = S0 + maj;
			h = g;
			g = f;
			f = e;
			e = d + temp1;
			d = c;
			c = b;
			b = a;
			a = temp1 + temp2;
		}
		h0 = h0 + a;
		h1 = h1 + b;
		h2 = h2 + c;
		h3 = h3 + d;
		h4 = h4 + e;
		h5 = h5 + f;
		h6 = h6 + g;
		h7 = h7 + h;
	}
	out->h0 = h0;
	out->h1 = h1;
	out->h2 = h2;
	out->h3 = h3;
	out->h4 = h4;
	out->h5 = h5;
	out->h6 = h6;
	out->h7 = h7;
	delete[] buff;
	return true;
}

bool HashString(const char* str, Hash* out)
{
	int buffSize = 0;
	Byte* buff = PadString(str, buffSize);
	if (buff == nullptr) {
		return false;
	}
	unsigned int h0 = 0x6a09e667;
	unsigned int h1 = 0xbb67ae85;
	unsigned int h2 = 0x3c6ef372;
	unsigned int h3 = 0xa54ff53a;
	unsigned int h4 = 0x510e527f;
	unsigned int h5 = 0x9b05688c;
	unsigned int h6 = 0x1f83d9ab;
	unsigned int h7 = 0x5be0cd19;

	for (int i = 0; i < buffSize / CHUNKSIZE; ++i) {
		const unsigned char* chunk = buff + CHUNKSIZE * i;
		unsigned int w[64] = {};
		MemoryCopy(chunk, CHUNKSIZE, w);
		if (IsLittleEndian()) {
			for (int i = 0; i < 64; ++i) {
				w[i] = SwapBytesU(w[i]);
			}
		}
		for (int j = 16; j < 64; ++j) {
			unsigned int s0 = rightrotate(w[j - 15], 7) ^ rightrotate(w[j - 15], 18) ^ (w[j - 15] >> 3);
			unsigned int s1 = rightrotate(w[j - 2], 17) ^ rightrotate(w[j - 2], 19) ^ (w[j - 2] >> 10);
			w[j] = w[j - 16] + s0 + w[j - 7] + s1;
		}

		unsigned int a = h0;
		unsigned int b = h1;
		unsigned int c = h2;
		unsigned int d = h3;
		unsigned int e = h4;
		unsigned int f = h5;
		unsigned int g = h6;
		unsigned int h = h7;

		for (int j = 0; j < 64; ++j) {
			unsigned int S1 = rightrotate(e, 6) ^ rightrotate(e, 11) ^ rightrotate(e, 25);
			unsigned int ch = (e & f) ^ ((~e) & g);
			unsigned int temp1 = h + S1 + ch + k[j] + w[j];
			unsigned int S0 = rightrotate(a, 2) ^ rightrotate(a, 13) ^ rightrotate(a, 22);
			unsigned int maj = (a & b) ^ (a & c) ^ (b & c);
			unsigned int temp2 = S0 + maj;
			h = g;
			g = f;
			f = e;
			e = d + temp1;
			d = c;
			c = b;
			b = a;
			a = temp1 + temp2;
		}
		h0 = h0 + a;
		h1 = h1 + b;
		h2 = h2 + c;
		h3 = h3 + d;
		h4 = h4 + e;
		h5 = h5 + f;
		h6 = h6 + g;
		h7 = h7 + h;
	}
	out->h0 = h0;
	out->h1 = h1;
	out->h2 = h2;
	out->h3 = h3;
	out->h4 = h4;
	out->h5 = h5;
	out->h6 = h6;
	out->h7 = h7;
	delete[] buff;
	return true;
}

bool HashToStr(char* dst, size_t nDst, const Hash* hash)
{
	if (dst == nullptr || hash == nullptr || nDst < sizeof(*hash) * 2 + 1) {
		return false;
	}
	ToStrHex(dst, nDst, hash->h0);
	ToStrHex(dst + 8, nDst - 8, hash->h1);
	ToStrHex(dst + 16, nDst - 16, hash->h2);
	ToStrHex(dst + 24, nDst - 24, hash->h3);
	ToStrHex(dst + 32, nDst - 32, hash->h4);
	ToStrHex(dst + 40, nDst - 40, hash->h5);
	ToStrHex(dst + 48, nDst - 48, hash->h6);
	ToStrHex(dst + 56, nDst - 56, hash->h7);
	return true;
}
Byte* PadString(const char* str, int& size)
{
	int msgLen = StrLen(str);
	int buffSize = AlignBuffSize(msgLen);
	Byte* buff = new Byte[buffSize];
	for (int i = 0; i < buffSize; ++i) {
		buff[i] = 0;
	}
	for (int i = 0; i < msgLen; ++i) {
		buff[i] = str[i];
	}
	buff[msgLen] = 0b10000000;
	unsigned long long BEMsgLen = ToBigEndianLLU(8 * (unsigned long long)msgLen);
	MemoryCopy(&BEMsgLen, sizeof(BEMsgLen), buff + buffSize - sizeof(BEMsgLen));
	size = buffSize;
	return buff;
}
char* TryAllMessagesOfLenN(unsigned int n, const char* hash)
{
	char* buff = new char[n + 1];
	buff[n] = 0;
	char* res = TryAllMessagesOfLenN(n, buff, hash);
	if (res == nullptr) {
		delete[] buff;
	}
	return res;
}

char* TryAllMessagesOfLenN(unsigned int n, char* initBuff, const char* hash)
{
	if (n == 0) {
		return nullptr;
	}
	if (n == 1) {
		Hash h = {};
		char hashMsg[257] = {};
		for (unsigned char ch = 255; ch >= 1; --ch) {
			initBuff[0] = ch;
			HashString(initBuff, &h);
			HashToStr(hashMsg, 257, &h);
			if (StrCmp(hash, hashMsg) == 0) {
				return initBuff;
			}
		}
		return nullptr;
	}
	else {

		for (unsigned char ch = 255; ch >= 1; --ch) {
			initBuff[n - 1] = ch;
			char* res = TryAllMessagesOfLenN(n - 1, initBuff, hash);
			if (res != nullptr) {
				return res;
			}
		}
	}
	return nullptr;
}

char* GetStringFromHash(const char* hash, unsigned int maxLen)
{
	if (!IsValidHashCode(hash)) {
		return nullptr;
	}
	char* res = nullptr;
	for (unsigned int i = 0; i <= maxLen; ++i) {
		res = TryAllMessagesOfLenN(i, hash);
		if (res != nullptr) {
			return res;
		}
	}
	return nullptr;
}
