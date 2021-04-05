#include "Bombe.h"
#include "Utility.h"
#include <iostream>

Bombe::Bombe(std::vector<std::vector<LoopEdge>> loops)
{
	loops = loops;
}

void Bombe::crack()
{
	std::vector<std::vector<int>> rotorCombinations = getPermutation({1,2,3,4,5}, 3);
	
	// iterate through the rotor combinations
	for (auto& rotorSetting : rotorCombinations) {

		// iterate through he rotor init positions
		for (int leftRotorPos = 0; leftRotorPos < 26; leftRotorPos++) {
			for (int centerRotorPos = 0; centerRotorPos < 26; centerRotorPos++) {
				for (int rightRotorPos = 0; rightRotorPos < 26; rightRotorPos++) {

					// iterate through all loops
					for (auto& loop : loops) {

						// set up the enigma machine
						enigma.rotorSettings = rotorSetting;
						enigma.rotorPosition = std::string({indexToChar(leftRotorPos), 
															indexToChar(centerRotorPos),
															indexToChar(rightRotorPos),
															'\0'});



						// TODO
						continue;
					}
				}
			}
		}
	}

}
