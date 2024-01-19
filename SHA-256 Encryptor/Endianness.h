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
* Header: Contains declarations of helper functions for conversion LE to BE and vice-versa
*
*/

#pragma once

/*
* Checks if the computer architecture is little-endian or not
*/
bool IsLittleEndian();

/*
* Reverses the bytes of 'value'
*/
unsigned long long SwapBytesLLU(unsigned long long value);

/*
* Reverses the bytes of 'value'
*/
unsigned int SwapBytesU(unsigned int value);

/*
* Reverses the bytes of 'value' if the architecture is little-endian
*/
unsigned long long ToBigEndianLLU(unsigned long long value);

/*
* Reverses the bytes of 'value' if the architecture is little-endian
*/
unsigned int ToBigEndianU(unsigned int value);