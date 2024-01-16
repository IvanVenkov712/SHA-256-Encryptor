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
* Header: Contains declarations of helper functions for files
*
*/

#pragma once
#include <fstream>
#include "Endianness.h"
#include "Memory.h"

using Byte = unsigned char;
const int CHUNKSIZE = 64;
const int ULLSIZE = 8;

/*
* aligns 'val', to the closest bigger value of the type (k+1)*512 where k is a positive integer.
*/
int AlignBuffSize(int val);

/*
* returns the size of the 'fileName' file, in bytes, or -1 on error.
*/
int FileSize(const char* fileName);

/*
* Reads the 'fileName' file into a buffer suitable to start hash process. 
*/
Byte* LoadFileInMemory(const char* fileName, int& size);