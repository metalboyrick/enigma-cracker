#pragma once
#ifndef ENIGMA_H
#define ENIGMA_H

#include <string>
#include <vector>

// class for the Enigma machine
class Enigma {
private:
	std::vector<int> rotorSettings;			// which 3 rotors to use
	std::string plugSettings;				// plugboard configuration
	std::string rotorPosition;				// current rotor position
public:
	Enigma(const std::vector<int>& rotorSettings, const std::string& plugSettings, const std::string& rotorPosition);
	char emulatePress(char c);

private:
	// indexing functions
	int getRotorIndex(int rotorSlot, int c);
	
	// rotor turning
	void turnRotor();

	// value mapping
	char passRotors(char c);
	char passRotorsReverse(char c);
	char passReflector(char c);
	char passPlugboard(char c);
	char passAll(char c);
};
#endif