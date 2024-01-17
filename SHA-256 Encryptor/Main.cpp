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

#include "UserInterface.h"

const int HASH_STR_SIZE = 100;
const int FILE_PATH_LEN = 255;

int RunProgram();

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
	std::cout << "Enter option: ";
	char option = '\0';
	GetOption(option);
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
		std::cout << "Unrecognised option" << std::endl;
		return 1;
	}
}
int ActionsOnOptionH()
{
	char hash[HASH_STR_SIZE] = {};

	if (!GetHashFromUserInput(hash, HASH_STR_SIZE)) {
		return 1;
	}
	std::cout << "Hash code: " << hash << std::endl;
	std::cout << "Do you want to save it in a file? (y/n): ";
	char saveInFileOption = '\0';
	GetOption(saveInFileOption);
	if (saveInFileOption == 'y') {
		if (!SaveStringInInputFile(hash)) {
			return 1;
		}
	}
	else if (saveInFileOption != 'n') {
		std::cout << "Incorrect input" << std::endl;
		return 1;
	}
	return 0;
}

int ActionsOnOptionC()
{
	char hash1[HASH_STR_SIZE] = {};
	char hash2[HASH_STR_SIZE] = {};
	std::cout << "Enter a hash: ";
	std::cin.getline(hash1, HASH_STR_SIZE);
	if (std::cin.fail()) {
		std::cout << "Incorrect input" << std::endl;
		return 1;
	}
	ToLowerCase(hash1);
	if (!IsValidHashCode(hash1)) {
		std::cout << "Incorrect input" << std::endl;
		return 1;
	}
	if (!GetHashFromUserInput(hash2, HASH_STR_SIZE)) {
		return 1;
	}
	bool equals = StrCmp(hash1, hash2) == 0;
	if (equals) {
		std::cout << "The hash codes are the same" << std::endl;
	}
	else {
		std::cout << "The hash codes are not the same" << std::endl;
	}
	return 0;
}

int ActionsOnOptionR()
{
	char hash[HASH_STR_SIZE] = {};
	std::cout << "Enter a hash code (lower case): ";
	std::cin.getline(hash, HASH_STR_SIZE);
	if (std::cin.fail() || !IsValidHashCode(hash)) {
		std::cout << "Incorrect input" << std::endl;
		return 1;
	}
	std::cout << "Enter max search length: ";
	unsigned int maxLen = 0;
	std::cin >> maxLen;
	if (std::cin.fail()) {
		std::cout << "Incorrect input" << std::endl;
		return 1;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	char* res = GetStringFromHash(hash, maxLen);
	if (res == nullptr) {
		std::cout << "That hash code could not be dehashed." << std::endl;
		std::cout << "Note: Try with a bigger max search length." << std::endl;
	}
	else {
		std::cout << "Dehashed message: " << res << std::endl;
		std::cout << "Do you want to save it in a file? (y/n): ";
		char c = '\0';
		GetChar(c);
		if (c == 'y') {
			if (!SaveStringInInputFile(res)) {
				return 1;
			}
		}
		else if (c != 'n') {
			std::cout << "Incorrect input" << std::endl;
			return 1;
		}
	}
	return 0;
}