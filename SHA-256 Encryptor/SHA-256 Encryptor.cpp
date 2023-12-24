// SHA-256 Encryptor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	cout << "Available options:" << endl;
	cout << "\te - to hash a file" << endl;
	cout << "\tr - to read a hashed message" << endl;
	cout << "\tx - to exit" << endl;
	cout << "Enter an option: ";
	char option = '\0';
	cin >> option;
	if (cin.fail() || !cin.) {
		cout << "Not an option" << endl;
	}
	else if (option == 'e') {
		//...
	}
	else if (option == 'r') {
		//...
	}
	else if (option == 'x') {
		return 0;
	}
	else {
		cout << "Unrecognised option" << endl;
	}
}