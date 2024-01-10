#include "StringHelpers.h"

int StrLen(const char* str)
{
	if (!str) {
		return 0;
	}
	const char* begin = str;
	while (*str != '\0') {
		++str;
	}
	return str - begin;
}

int StrCmp(const char* str1, const char* str2)
{
	if (str1 == nullptr && str2 == nullptr) {
		return 0;
	}
	else if (str1 == nullptr || str2 == nullptr) {
		return str1 - str2;
	}
	while (*str1 != '\0' && (*str1 == *str2)) {
		++str1;
		++str2;
	}
	return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

bool ToStrHex(char* dst, size_t nDst, unsigned int value)
{
	const char dictionary[17] = "0123456789abcdef";

	int valDigsCount = sizeof(value) * 2;
	if (nDst < valDigsCount + 1) {
		return false;
	}
	unsigned int cnt = valDigsCount - 1;
	dst[valDigsCount] = '\0';
	for (int i = valDigsCount - 1; i >= 0; --i) {
		dst[i] = dictionary[value % 16];
		value /= 16;
	}
	return true;

}

bool GetChar(char& ch)
{
	char str[2] = {};
	std::cin.getline(str, 2);
	bool res = !std::cin.fail();
	if (res) {
		ch = str[0];
	}
	else {
		ch = '\0';
	}
	std::cin.clear();
	return res;
}

char* ResizeString(char* str, int oldSize, int newSize)
{
	if (oldSize < 0 || newSize < 0 || newSize < oldSize) {
		return nullptr;
	}
	char* newStr = new char[newSize * sizeof(char)];
	for (int i = 0; i < oldSize; ++i) {
		newStr[i] = str[i];
	}
	delete[] str;
	return newStr;
}

char* GetString(char delim)
{
	int strCapacity = 64;
	int strLen = 0;

	char* str = new char[strCapacity + 1];
	char ch = '\0';
	while ((ch = std::cin.get()) != delim) {
		if (strLen >= strCapacity) {
			char* tmp = ResizeString(str, strCapacity, strCapacity * 2 + 1);
			if (tmp == nullptr) {
				delete[] str;
				return nullptr;
			}
			str = tmp;
			strCapacity *= 2;
		}
		str[strLen++] = ch;
	}
	str[strLen] = '\0';
	return str;
}
