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
* Source file: Contains the entry point of the program
*
*/

#include <iostream>
#include <fstream>
#include <numeric>
#include <bitset>
#include "FileHelpers.h"
#include "StringHelpers.h"
#include "Hash.h"

using namespace std;
const int HASH_STR_SIZE = 100;
const int FILE_PATH_LEN = 255;

int RunProgram();

void PrintInformation();
bool GetHashOfInputMessage(char* dst, int dstSize);
bool GetHashOfInputFile(char* dst, int dstSize);
bool GetHashFromUserInput(char* dst, int dstSize);
bool SaveStringInInputFile(const char* hash);

int ActionsOnOptionH();
int ActionsOnOptionC();
int ActionsOnOptionR();

//Program entry point
int main()
{
	return RunProgram();
}

//Program logic here
int RunProgram()
{
	PrintInformation();
	cout << "Enter option: ";
	char option = '\0';
	GetChar(option);
	option = ToLowerCase(option);
	switch (option) {
	case 'h':
		return ActionsOnOptionH();
	case 'c':
		return ActionsOnOptionC();
	case 'r':
		return ActionsOnOptionR();
	case 'x':
		return 0;
	default:
		cout << "Unrecoognised option" << endl;
		return 1;
	}
}
int ActionsOnOptionH()
{
	char hash[HASH_STR_SIZE] = {};

	if (!GetHashFromUserInput(hash, HASH_STR_SIZE)) {
		return 1;
	}
	cout << "Hash code: " << hash << endl;
	cout << "Do you want to save it in a file? (y/n): ";
	char c = '\0';
	GetChar(c);
	if (c == 'y') {
		if (!SaveStringInInputFile(hash)) {
			return 1;
		}
	}
	else if (c != 'n') {
		cout << "Incorrect input" << endl;
		return 1;
	}
	return 0;
}

int ActionsOnOptionC()
{
	char hash1[HASH_STR_SIZE] = {};
	char hash2[HASH_STR_SIZE] = {};
	cout << "Enter a hash (lower case): ";
	cin.getline(hash1, HASH_STR_SIZE);
	if (cin.fail() || !IsValidHashCode(hash1)) {
		cout << "Incorrect input" << endl;
		return 1;
	}
	if (!GetHashFromUserInput(hash2, HASH_STR_SIZE)) {
		return 1;
	}
	bool equals = StrCmp(hash1, hash2) == 0;
	if (equals) {
		cout << "The hash codes are the same" << endl;
	}
	else {
		cout << "The hash codes are not the same" << endl;
	}
	return 0;
}

int ActionsOnOptionR()
{
	char hash[HASH_STR_SIZE] = {};
	cout << "Enter a hash code (lower case): ";
	cin.getline(hash, HASH_STR_SIZE);
	if (cin.fail() || !IsValidHashCode(hash)) {
		cout << "Incorrect input" << endl;
		return 1;
	}
	cout << "Enter max search length: ";
	unsigned int maxLen = 0;
	cin >> maxLen;
	if (cin.fail()) {
		cout << "Incorrect input" << endl;
		return 1;
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	char* res = GetStringFromHash(hash, maxLen);
	if (res == nullptr) {
		cout << "That hash code could not be dehashed." << endl;
		cout << "Note: Try with a bigger max search length." << endl;
	}
	else {
		cout << "Dehashed message: " << res << endl;
		cout << "Do you want to save it in a file? (y/n): ";
		char c = '\0';
		GetChar(c);
		if (c == 'y') {
			if (!SaveStringInInputFile(res)) {
				return 1;
			}
		}
		else if (c != 'n') {
			cout << "Incorrect input" << endl;
			return 1;
		}
	}
	return 0;
}

void PrintInformation()
{
	cout << "Available options:" << endl;
	cout << "\th - Hash a file or a message" << endl;
	cout << "\tc - Compare the hash of a message or a file with another hash" << endl;
	cout << "\tr - Tries to retrieve the message with a certain hash code (it may take a lot of time)" << endl;
	cout << "\tx - Exit" << endl;
	cout << "\tNote: The program is case-insensitive (assumes 'A' and 'a' are equal) for user input (options, and hash codes). Depends on OS whether the program is case-sensitive for file names." << endl;
	cout << endl;
}

bool GetHashOfInputMessage(char* dst, int dstSize)
{
	Hash h = {};
	cout << "Enter message: ";
	char* msg = GetString('\n');
	if (msg == nullptr) {
		cout << "Incorrect input" << endl;
		return false;
	}
	if (!HashString(msg, &h)) {
		cout << "An error occurred" << endl;
		delete[] msg;
		return false;
	}
	if (!HashToStr(dst, dstSize, &h)) {
		cout << "An error occurred" << endl;
		delete[] msg;
		return false;
	}
	delete[] msg;
	return true;
}

bool GetHashOfInputFile(char* dst, int dstSize)
{
	Hash h = {};
	cout << "Enter file path of hash source: ";
	char* filePath = GetString('\n');
	if (filePath == nullptr) {
		cout << "Incorrect input" << endl;
		return false;
	}
	if (!HashFile(filePath, &h)) {
		delete[] filePath;
		cout << "An error opening file" << endl;
		return false;
	}
	if (!HashToStr(dst, dstSize, &h)) {
		delete[] filePath;
		cout << "An error occurred" << endl;
		return false;
	}
	delete[] filePath;
	return true;
}

bool GetHashFromUserInput(char* dst, int dstSize)
{
	cout << "Enter 'm' or 'f' to get the hashcode of a message or a file." << endl;
	cout << "('m' or 'f'): ";
	char hSource = '\0';
	bool getHashSuccess = false;
	GetChar(hSource);
	hSource = ToLowerCase(hSource);
	if (hSource == 'm') {
		getHashSuccess = GetHashOfInputMessage(dst, dstSize);
	}
	else if (hSource == 'f') {
		getHashSuccess = GetHashOfInputFile(dst, dstSize);
	}
	else {
		cout << "Incorrect input" << endl;
		return false;
	}
	return getHashSuccess;
}

bool SaveStringInInputFile(const char* str)
{
	cout << "Enter file path: ";
	char* filePath = GetString('\n');
	if (!filePath) {
		cout << "Incorrect input" << endl;
		return false;
	}
	ofstream f(filePath, std::ios::binary);
	if (f.is_open()) {
		f << str;
		f.close();
		delete[] filePath;
	}
	else {
		cout << "Error opening file" << endl;
		delete[] filePath;
		return false;
	}
}