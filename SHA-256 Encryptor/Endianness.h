#pragma once

bool IsLittleEndian();
unsigned long long SwapBytesLLU(unsigned long long value);
unsigned long long SwapBytesU(unsigned int value);
unsigned long long ToBigEndianLLU(unsigned long long value);
unsigned int ToBigEndianU(unsigned int value);
unsigned int BigEndianAddU(unsigned int a, unsigned int b);