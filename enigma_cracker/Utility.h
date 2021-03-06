#pragma once
#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

extern std::string shiftLeft(std::string v, int times);									// perform right shift on a string
extern std::string shiftRight(std::string v, int times);								// perform left shift on a string
extern std::vector<std::vector<int>> getPermutation(std::vector<int> v, int r);			// get nPr combinations of an int vector
extern std::vector<std::string> getPermutation(std::string v, int r);
extern int charToIndex(char c);															// convert uppercase letter to index 0~25
extern char indexToChar(int index);														// convert index 0~25 to uppercase letter
std::string configPlugboard(std::unordered_map<char, char> plugboardMap, std::string currentPlugboard);		// convert a plugboard mapping to the format accepted by the enigma

#endif


