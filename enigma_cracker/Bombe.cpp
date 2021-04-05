#include "Bombe.h"
#include "Utility.h"
#include <iostream>

Bombe::Bombe(std::vector<std::vector<LoopEdge>> loops)
{
	this->loops = loops;
}

void Bombe::crack()
{

	// TRIAL CODE
	std::string initRotorPosition = "EDI";
	
	std::vector<int> rotorSetting = {4, 3, 1};

	enigma.rotorPosition = initRotorPosition;
	enigma.rotorSettings = rotorSetting;

	for (auto& loop : loops) {

		char resChar = '0';
		char finalChar = loop[loop.size() - 1].second;
		bool isBreak = false;

		// iterate through all edges in loop
		for (auto& edge : loop) {

			enigma.rotorPosition = initRotorPosition;

			resChar = edge.first;
			// try to do without considering the plugboards first
			// type the same character so to check the target index character
			for (int pressCount = 0; pressCount < edge.index; pressCount++) {
				resChar = enigma.emulatePress(edge.first);
			}
		}

		if (resChar != finalChar) {
			std::cout << "Incorrect rotor wheels!" << std::endl;
			return;
		}
	}

	std::cout << "Correct rotor wheels!" << std::endl;
	return;


	// TRIAL CODE ENDS HERE

	//std::vector<std::vector<int>> rotorCombinations = getPermutation({1,2,3,4,5}, 3);
	//
	//// iterate through the rotor combinations
	//for (auto& rotorSetting : rotorCombinations) {

	//	enigma.rotorSettings = rotorSetting;

	//	// iterate through he rotor init positions
	//	for (int leftRotorPos = 0; leftRotorPos < 26; leftRotorPos++) {
	//		for (int centerRotorPos = 0; centerRotorPos < 26; centerRotorPos++) {
	//			for (int rightRotorPos = 0; rightRotorPos < 26; rightRotorPos++) {

	//				std::string initRotorPosition({ indexToChar(leftRotorPos),
	//												indexToChar(centerRotorPos),
	//												indexToChar(rightRotorPos),
	//												'\0' });

	//				enigma.rotorPosition = initRotorPosition;

	//				// iterate through all loops
	//				for (auto& loop : loops)
	//					
	//					// iterate through all edges in loop
	//					for (auto& edge : loop) {
	//						
	//						// try to do without considering the plugboards first
	//						// type the same character so to check the target index character
	//						for (int pressCount; pressCount < edge.index; pressCount++) {
	//							
	//						}
	//					}
	//					// TODO
	//					continue;
	//				}
	//			}
	//		}
	//	}
	//}

}
