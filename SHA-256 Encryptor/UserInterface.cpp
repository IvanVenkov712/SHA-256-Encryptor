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
* Source file: Contains the definitions of some helper functions for interacting with the user.
*
*/

#include "UserInterface.h"

void PrintInformation()
{
	std::cout << "Available options:" << std::endl;
	std::cout << "\th - Hash a file or a message" << std::endl;
	std::cout << "\tc - Compare the hash of a message or a file with another hash" << std::endl;
	std::cout << "\tr - Tries to retrieve the message with a certain hash code (it may take a lot of time)" << std::endl;
	std::cout << "\tx - Exit" << std::endl;
	std::cout << "\tNote: The program is case-insensitive (assumes 'A' and 'a' are equal)" << 
		"for user input(options, and hash codes).Depends on OS whether" << 
		"the program is case-sensitive for file names." << std::endl;
	std::cout << std::endl;
}

bool GetHashOfInputMessage(char* dst, int dstSize)
{
	Hash h = {};
	std::cout << "Enter message: ";
	char* msg = GetString('\n');
	if (msg == nullptr) {
		std::cout << "Incorrect input" << std::endl;
		return false;
	}
	if (!HashString(msg, &h)) {
		std::cout << "An error occurred" << std::endl;
		delete[] msg;
		return false;
	}
	if (!HashToStr(dst, dstSize, &h)) {
		std::cout << "An error occurred" << std::endl;
		delete[] msg;
		return false;
	}
	delete[] msg;
	return true;
}

bool GetHashOfInputFile(char* dst, int dstSize)
{
	Hash h = {};
	std::cout << "Enter file path of hash source: ";
	char* filePath = GetString('\n');
	if (filePath == nullptr) {
		std::cout << "Incorrect input" << std::endl;
		return false;
	}
	if (!HashFile(filePath, &h)) {
		delete[] filePath;
		std::cout << "An error opening file" << std::endl;
		return false;
	}
	if (!HashToStr(dst, dstSize, &h)) {
		delete[] filePath;
		std::cout << "An error occurred" << std::endl;
		return false;
	}
	delete[] filePath;
	return true;
}

bool GetHashFromUserInput(char* dst, int dstSize)
{
	std::cout << "Enter 'm' or 'f' to get the hashcode of a message or a file." << std::endl;
	std::cout << "('m' or 'f'): ";
	char hSource = '\0';
	bool getHashSuccess = false;
	GetOption(hSource);
	if (hSource == 'm') {
		getHashSuccess = GetHashOfInputMessage(dst, dstSize);
	}
	else if (hSource == 'f') {
		getHashSuccess = GetHashOfInputFile(dst, dstSize);
	}
	else {
		std::cout << "Incorrect input" << std::endl;
		return false;
	}
	return getHashSuccess;
}

bool SaveStringInInputFile(const char* str)
{
	std::cout << "Enter file path: ";
	char* filePath = GetString('\n');
	if (!filePath) {
		std::cout << "Incorrect input" << std::endl;
		return false;
	}
	std::ofstream f(filePath, std::ios::binary);
	if (f.is_open()) {
		f << str;
		f.close();
		delete[] filePath;
		return true;
	}
	else {
		std::cout << "Error opening file" << std::endl;
		delete[] filePath;
		return false;
	}
}
