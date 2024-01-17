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
* Header: Contains declarations of helper functions for hashing 
*
*/

#pragma once
#include "FileHelpers.h"
#include "StringHelpers.h"

/*
* This structure is used for storing hash codes
*/
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

/*
* performs the 'rightrotate' operation on the bytes of 'value'.
*/
unsigned int rightrotate(unsigned int value, unsigned int n);

/*
* Performs SHA-256 hashing on the 'fileName' file.
* Returns 'true' and stores the hash code of 'fileName' into 'out' on success.
* Returns 'false' if an error occurs.
*/
bool HashFile(const char* fileName, Hash* out);

/*
* Performs SHA-256 hashing on the buffer pointed by 'str'.
* Returns 'true' and stores the hash code of ''str' into 'out' on success.
* Returns 'false' if an error occurs.
*/
bool HashString(const char* str, Hash* out);

/*
* converts the hash code stored into a string. The string representation is hexadecimal and into
* lower-case.
*/
bool HashToStr(char* dst, size_t nDst, const Hash* hash);

/*
* Pads 'str' into a buffer allocated with 'new' suited for hashing
*/
Byte* PadString(const char* str, int& size);

/*
* Checks if some string of length 'n' has hash code 'hash'.
* Returns a pointer to that string if it is found, otherwise false.
*/
char* TryAllMessagesOfLenN(unsigned int n, const char* hash);

/*
* Checks if some string of length 'n' has hash code 'hash'.
* Returns a pointer to that string if it is found, otherwise false. Uses 'initBuff' to store that string.
*/
char* TryAllMessagesOfLenN(unsigned int n, char* initBuff, const char* hash);

/*
* Returns a null-terminated string which has hash code 'hash'. 
* If the string is not found or has length greater than 'maxLen', returns nullptr.
*/
char* GetStringFromHash(const char* hash, unsigned int maxLen);
