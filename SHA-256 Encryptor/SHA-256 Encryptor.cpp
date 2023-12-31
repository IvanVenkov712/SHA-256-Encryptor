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
	while (true) {
		Hash h = {};
		char hashStr[sizeof(h) * 2 + 1] = {};
		char msg[2048] = {};
		cin.getline(msg, sizeof(msg));
		HashMessage(msg, &h);
		HashToStr(hashStr, sizeof(hashStr), &h);
		cout << hashStr << endl;
		ToStrHex(hashStr, sizeof(hashStr), 1);
	
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
