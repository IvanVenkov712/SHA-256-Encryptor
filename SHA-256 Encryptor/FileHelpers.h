#pragma once
#include <fstream>
#include "Endianness.h"
#include "Memory.h"

using Byte = unsigned char;
const int CHUNKSIZE = 64;
const int ULLSIZE = 8;

int AlignBuffSize(int val);
int FileSize(const char* fileName);
Byte* LoadFileInMemory(const char* fileName, int& size);