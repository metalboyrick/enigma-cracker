#include "Enigma.h"
#include "Constants.h"
#include "Utility.h"
#include <iostream>
#include <cstdlib>

// enumeration for the rotor position
enum RotorPosition {
	LEFT,
	CENTER,
	RIGHT
};

/*
	CONSTRUCTOR FOR THE ENIGMA SIMULATOR
	ARGS:
		rotorSettings: 3 integers not bigger than 5
		plugSettings: an array of characters, representing mappins for the plugboard
		rotorPosition: 3 chars, representing the position of the rotors
*/
Enigma::Enigma()
{
	this->rotorSettings = DEF_ROTOR_SETTINGS;
	this->plugSettings = DEF_PLUG_SETTINGS;
	this->rotorPosition = DEF_ROTOR_POSITION;
}

Enigma::Enigma(const std::vector<int>& rotorSettings, const std::string& plugSettings, const std::string& rotorPosition)
{
	// initialise all the values
	this->rotorSettings = rotorSettings;
	this->plugSettings = plugSettings;
	this->rotorPosition = rotorPosition;
}

char Enigma::emulatePress(char c)
{
	turnRotor();
	return passAll(c);
}



int Enigma::getRotorIndex(int rotorSlot,int c)
{
	int someval = (c + charToIndex(rotorPosition[rotorSlot])) % 26;
	return (c + charToIndex(rotorPosition[rotorSlot])) % 26;
}

void Enigma::turnRotor()
{
	char rpos = rotorPosition[RIGHT], lpos = rotorPosition[LEFT], cpos = rotorPosition[CENTER];
	
	// turn the left rotor
	if (cpos == ROTOR_NOTCHES[rotorSettings[CENTER] -1 ]) {
		if (lpos >= 'Z') lpos = 'A';
		else lpos += 1;
	};

	// turn the center rotor
	if (rpos == ROTOR_NOTCHES[rotorSettings[RIGHT] - 1]) {
		if (cpos >= 'Z') cpos = 'A';
		else cpos += 1;
	};
	
	// turn the right rotor
	if (rpos >= 'Z') rpos = 'A';
	else rpos += 1;

	// convert the results back into letters;
	rotorPosition[RIGHT] = rpos;
	rotorPosition[LEFT] = lpos;
	rotorPosition[CENTER] = cpos;

	/*std::cout << rotorPosition[LEFT] << rotorPosition[CENTER] << rotorPosition[RIGHT] << std::endl;*/

}


// pass through all 3 rotors
char Enigma::passRotors(char c)
{	
	int lastChar = charToIndex(c);

	for (int i = 2; i > -1; i--) {
		// shift the array to the left according to the rotor position
		std::string shiftedMapping = shiftLeft(ROTOR_WHEELS[rotorSettings[i] - 1], charToIndex(rotorPosition[i]));

		// get the corresponding value
		char mappedValue = shiftedMapping[lastChar];

		// minus the corresponding value with the rotor position
		if (rotorPosition[i] <= mappedValue) lastChar = (std::abs(mappedValue - rotorPosition[i]));
		else lastChar = (26 - std::abs(rotorPosition[i] - mappedValue));

		/*std::cout << indexToChar(lastChar) << "->";*/
	}
	
	return indexToChar(lastChar);
}

char Enigma::passRotorsReverse(char c)
{
	int lastChar = charToIndex(c);

	for (int i = 0; i < 3; i++) {
		// add the char index with the rotor position
		lastChar = (lastChar + charToIndex(rotorPosition[i])) % 26;

		// shift the array to the left according to the rotor position
		std::string shiftedMapping = shiftLeft(ROTOR_WHEELS[rotorSettings[i] - 1], charToIndex(rotorPosition[i]));

		// find the occurence in the rotor wheel string
		lastChar = shiftedMapping.find(indexToChar(lastChar), 0);

		/*std::cout << indexToChar(lastChar) << "->";*/
	}


	return indexToChar(lastChar);
}

// pass through the reflector
char Enigma::passReflector(char c)
{
	return REFLECTOR[charToIndex(c)];
}

// pass through the plugboard
char Enigma::passPlugboard(char c)
{
	return plugSettings[charToIndex(c)];
}

// pass through all the components with the correct order
char Enigma::passAll(char c)
{
	char currentChar = c;							// initialise a helper variable
	currentChar = passPlugboard(currentChar);		// pass the plugboard
	/*std::cout << currentChar << "->";*/
	currentChar = passRotors(currentChar);			// pass the rotors
	/*std::cout << currentChar << "->";*/
	currentChar = passReflector(currentChar);		// pass the reflector
	/*std::cout << currentChar << "->";*/
	currentChar = passRotorsReverse(currentChar);	// pass the rotors again
	/*std::cout << currentChar << "->";*/
	currentChar = passPlugboard(currentChar);
	/*std::cout << currentChar << '\n';*/
	return currentChar;				// pass the plugboard again
}
