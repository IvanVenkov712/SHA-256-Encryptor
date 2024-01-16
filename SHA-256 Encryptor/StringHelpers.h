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

/** 
* Reads a character from the console.
*     If the character has been read successfully,
* returns true and stores the read character into 'ch'
*     Otherwise, returns false and sets 'ch' to 0.
**/
bool GetChar(char& ch);

/**
* Reads a character from the console.
*     If the character has been read successfully,
* returns true and stores the read character converted to lower-case into 'ch'
*     Otherwise, returns false and sets 'ch' to 0.
**/
bool GetOption(char& ch);

/**
* Helper function for GetString.
* Resizes a string allocated with 'new'
**/
char* ResizeString(char* str, int oldSize, int newSize);

/**
* Reads a variable-length string from the console until it meets 'delim' and returns a 
* pointer to its first element as result
* The string is allocated with 'new'.
* If an error happens, the function returns 'nullptr'.
**/
char* GetString(char delim);

/*
* Checks if a string is a valid hash code.
* 'str' is a valid hash code when:
*    - has length 64
*    - contains a hexadecimal number into lowercase
*/
bool IsValidHashCode(const char* str);

char ToLowerCase(char c);
void ToLowerCase(char* str);