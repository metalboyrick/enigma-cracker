#pragma once
#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

extern std::string shiftLeft(std::string v, int times);									// perform right shift on a string
extern std::string shiftRight(std::string v, int times);								// perform left shift on a string
extern std::vector<std::vector<int>> getPermutation(std::vector<int> v, int r);			// get nPr combinations of an int vector

#endif


