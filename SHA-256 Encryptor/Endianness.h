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
bool IsLittleEndian();
unsigned long long SwapBytesLLU(unsigned long long value);
unsigned long long SwapBytesU(unsigned int value);
unsigned long long ToBigEndianLLU(unsigned long long value);
unsigned int ToBigEndianU(unsigned int value);
unsigned int BigEndianAddU(unsigned int a, unsigned int b);