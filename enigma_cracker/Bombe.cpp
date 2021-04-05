#include "Bombe.h"
#include "Utility.h"
#include "Constants.h"
#include <iostream>

Bombe::Bombe(std::vector<std::vector<LoopEdge>> loops)
{
	this->loops = loops;
}

void Bombe::crack()
{
	std::vector<int> rotorSet({ 1,2,3,4,5 });
	std::vector<std::vector<int>> rotorCombinations = getPermutation(rotorSet, 3);
	
	// iterate through the rotor combinations
	for (auto& rotorSetting : rotorCombinations) {

		bool isBreak = false;
		enigma.rotorSettings = rotorSetting;

		// iterate through the rotor init positions
		for (int leftRotorPos = 0; leftRotorPos < 26; leftRotorPos++) {
			for (int centerRotorPos = 0; centerRotorPos < 26; centerRotorPos++) {
				for (int rightRotorPos = 0; rightRotorPos < 26; rightRotorPos++) {

					std::string initRotorPosition({ indexToChar(leftRotorPos),
													indexToChar(centerRotorPos),
													indexToChar(rightRotorPos),
													'\0' });
					
					int loopCount = 0;

					// iterate through all loops
					for (auto& loop : loops) {
						char resChar = '0';
						char finalChar = loop[loop.size() - 1].second;

						for (auto& edge : loop) {

							enigma.rotorPosition = initRotorPosition;

							resChar = edge.first;
							// try to do without considering the plugboards first
							// type the same character so to check the target index character
							for (int pressCount = 0; pressCount < edge.index; pressCount++) {
								resChar = enigma.emulatePress(edge.first);
							}

							if (resChar != edge.second) {
								break;
							}

						}

						if (resChar != finalChar) {
							break;
						}

						loopCount += 1;
					}
					
					if (loopCount == loops.size()) {
						std::cout << "Rotor position: " << initRotorPosition << std::endl;
						std::cout << "Rotor number: " << rotorSetting[0] << " " << rotorSetting[1] << " " << rotorSetting[2] << std::endl;
						return;
					}
				}
			}
		}
	}

}
