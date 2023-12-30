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
void Hash(const char* fileName) {
	int buffSize = 0;
	Byte* buff = LoadFileInMemory(fileName, buffSize);
	if (buff == nullptr) {
		return;
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
		for (int i = 0; i < 64; ++i) {
			w[i] = SwapBytesU(w[i]);
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
			unsigned int temp2 = S0+ maj;
			h = g;
			g = f;
			f = e;
			e = d + temp1;
			d = c;
			c = b;
			b = a;
			a = temp1 + temp2;
		}
		h0 = h0+ a;
		h1 = h1+ b;
		h2 = h2+ c;
		h3 = h3+ d;
		h4 = h4+ e;
		h5 = h5+ f;
		h6 = h6+ g;
		h7 = h7+ h;
	}
	std::cout << 
		std::hex << (h0) << 
		std::hex << (h1) << 
		std::hex << (h2) << 
		std::hex << (h3) << 
		std::hex << (h4) << 
		std::hex << (h5) << 
		std::hex << (h6) <<
		std::hex << (h7) << std::endl;
}