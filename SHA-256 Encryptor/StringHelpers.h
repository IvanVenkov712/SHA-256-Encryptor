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
* Header: Contains declarations of helper functions for strings
*
*/

#pragma once
#include <iostream>
int StrLen(const char* str);
int StrCmp(const char* str1, const char* str2);
bool ToStrHex(char* dst, size_t nDst, unsigned int value);
bool GetChar(char& ch);
char* ResizeString(char* str, int oldSize, int newSize);
char* GetString(char delim);
bool IsValidHashCode(const char* str);