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
* Header file: Contains the declarations of some helper functions for interacting with the user.
*
*/

#pragma once

#include <iostream>
#include <fstream>
#include <numeric>
#include <bitset>
#include "FileHelpers.h"
#include "StringHelpers.h"
#include "Hash.h"

/*
* Prints on the console information about available options and their meaning
*/
void PrintInformation();

/*
* Prompts the user to enter a string of variable length and gets its hash code.
* Returns 'true' and stores the hash code in string lower-case format  into 'dst'.
* If error occurs, returns false.
*/
bool GetHashOfInputMessage(char* dst, int dstSize);

/*
* Prompts the user to enter a file name and gets its hash code.
* Returns 'true' and stores the hash code in string lower-case format  into 'dst'.
* If error occurs, returns false.
*/
bool GetHashOfInputFile(char* dst, int dstSize);

/*
* Prompts the user to choose whether they will get the hash code of a file or that of a string.
* Then stores the hash code of the string or the file into 'dst' and returns true.
* Returns 'false' when error occurs.
*/
bool GetHashFromUserInput(char* dst, int dstSize);

/*
* Prompts the user to enter a name of a file and then saves 'str' into that file.
* Returns 'false' if error happens, otherwise true.
*/
bool SaveStringInInputFile(const char* str);
