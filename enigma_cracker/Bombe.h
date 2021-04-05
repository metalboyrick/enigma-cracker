#pragma once
#ifndef BOMBE_H
#define BOMBE_H

#include "Enigma.h"
#include <unordered_map>
#include <vector>

struct LoopEdge {
	char first;
	char second;
	int index;
};

class Bombe {
private:
	Enigma enigma;
	std::vector<std::vector<LoopEdge>> loops;
	std::unordered_map<char, char> failedPlugboards;

public:
	Bombe(std::vector<std::vector<LoopEdge>> loops);
	
};

#endif
