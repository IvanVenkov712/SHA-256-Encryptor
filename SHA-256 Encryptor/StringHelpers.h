#pragma once
#include <iostream>
int StrLen(const char* str);
int StrCmp(const char* str1, const char* str2);
bool ToStrHex(char* dst, size_t nDst, unsigned int value);
bool GetChar(char& ch);
char* ResizeString(char* str, int oldSize, int newSize);
char* GetString(char delim);