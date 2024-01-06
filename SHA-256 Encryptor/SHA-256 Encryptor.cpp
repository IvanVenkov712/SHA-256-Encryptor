// SHA-256 Encryptor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <numeric>
#include <bitset>
#include "FileHelpers.h"
#include "Hash.h"

using namespace std;

bool GetChar(char& ch);
char* TryAllMessagesOfLenN(unsigned int n, const char* hash);
char* TryAllMessagesOfLenN(unsigned int n, char* initBuff, const char* hash );

int main()
{
	//cout << "Available options:" << endl;
	//cout << "\te - to hash a file" << endl;
	//cout << "\tr - to read a hashed message" << endl;
	//cout << "\tx - to exit" << endl;
	//cout << "Enter an option: ";
	//char option = '\0';
	//if (!GetChar(option)) {
	//	cout << "Not an option" << endl;
	//}
	//else if (option == 'e') {
	//	//...
	//}
	//else if (option == 'r') {
	//	//...
	//}
	//else if (option == 'x') {
	//	return 0;
	//}
	//else {
	//	cout << "Unrecognised option" << endl;
	//}
	//while (true) {
	//	Hash h = {};
	//	char hashStr[sizeof(h) * 2 + 1] = {};
	//	char msg[2048] = {};
	//	cin.getline(msg, sizeof(msg));
	//	HashMessage(msg, &h);
	//	HashToStr(hashStr, sizeof(hashStr), &h);
	//	cout << hashStr << endl;
	//	ToStrHex(hashStr, sizeof(hashStr), 1);
	//
	//}
	cout << "Enter hash: ";
	char hash[257];
	cin.getline(hash, 256);
	char* orig;
	for (int i = 0; i < 30; ++i) {
		 orig = TryAllMessagesOfLenN(i, hash);
		if (orig) {
			break;
		}
	}
	if(orig != nullptr){	
		cout << "Original message: " << orig << endl;
		delete[] orig;

	}

}

bool GetChar(char& ch)
{
	char str[2] = {};
	cin.getline(str, 2);
	bool res = !cin.fail();
	if (res) {
		ch = str[0];
	}
	else {
		ch = '\0';
	}
	cin.clear();
	return res;
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
			HashMessage(initBuff, &h);
			HashToStr(hashMsg, 257, &h);
			if (strcmp(hash, hashMsg) == 0) {
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
