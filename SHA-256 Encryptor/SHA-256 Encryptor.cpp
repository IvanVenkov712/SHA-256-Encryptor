// SHA-256 Encryptor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <numeric>
#include <bitset>
#include "FileHelpers.h"
#include "StringHelpers.h"
#include "Hash.h"

using namespace std;

int main()
{
	cout << "Available options:" << endl;
	cout << "\th - Hash a file or a message" << endl;
	cout << "\tc - Compare the hash of a message or a file with another hash" << endl;
	cout << "\tx - Exit" << endl;
	cout << "Enter an option: ";
	char option = '\0';
	if (!GetChar(option)) {
		cout << "Unrecognised option" << endl;
		return 1;
	}
	else if (option == 'h') {
		cout << "Enter 'm' to hash a message or 'f' to hash a file." << endl;
		cout << "('m' or 'f'): ";
		char hSource = '\0';
		Hash h = {};			
		char strHash[100] = {};

		if (!GetChar(hSource)) {
			cout << "Incorrect input" << endl;
			return 1;
		}
		else if (hSource == 'm') {
			cout << "Enter message: ";
			char* msg = GetString('\n');
			if (msg == nullptr) {
				cout << "Incorrect input" << endl;
				return 1;
			}
			if (!HashString(msg, &h)) {
				cout << "An error occurred" << endl;
				delete[] msg;
				return 1;
			}
			HashToStr(strHash, 100, &h);
			delete[] msg;
		}
		else if (hSource == 'f') {
			cout << "Enter file path of hash source: ";
			char* filePath = GetString('\n');
			if (!HashFile(filePath, &h)) {
				delete[] filePath;
				cout << "An error opening file" << endl;
				return 1;
			}
			HashToStr(strHash, 100, &h);
		}
		cout << "Hash code: " << strHash << endl;
		cout << "Do you want to save it in a file? (y/n): ";
		char c = '\0';
		GetChar(c);
		if (c == 'y') {
			cout << "Enter file path: ";
			char* filePath = GetString('\n');
			if (!filePath) {
				cout << "Incorrect input" << endl;
				return 1;
			}
			ofstream f(filePath);
			if (f.is_open()) {
				f << strHash;
				f.close();
			}
			else {
				cout << "Error opening file" << endl;
				delete[] filePath;
				return 1;
			}
		}
	}
	else if (option == 'c') {
		char hash[100] = {};
		cout << "Enter a hash: ";

	}
	else if (option == 'x') {
		return 0;
	}
	else {
		cout << "Unrecognised option" << endl;
		return 1;
	}
}