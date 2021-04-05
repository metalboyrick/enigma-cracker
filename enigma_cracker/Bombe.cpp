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

	// TRIAL CODE
	//std::string initRotorPosition = "EDI";
	//
	//std::vector<int> rotorSetting = {4, 3, 1};

	//enigma.rotorPosition = initRotorPosition;
	//enigma.rotorSettings = rotorSetting;

	//for (auto& loop : loops) {

	//	char resChar = '0';
	//	char finalChar = loop[loop.size() - 1].second;
	//	bool isBreak = false;
	//	
	//	std::unordered_map<char,char> loopChar;
	//	std::unordered_map<char, char> loopCharReverse;

	//	// track down all involved chars inthe loop
	//	// the purpose is to assign plugboard values in them

	//	std::vector<std::string> plugCombinations = getPermutation(DEF_PLUG_SETTINGS, loop.size());
 //       
	//	for (auto& combination : plugCombinations) {

	//		// assign members of the loop to a permutation
	//		for (int i = 0; i < combination.length(); i++) {
	//			loopChar[loop[i].first] = combination[i];
	//			loopCharReverse[combination[i]] = loop[i].first;

	//			std::cout << loop[i].first << combination[i] << " ";
	//		}
	//		std::cout << std::endl;

	//		// set up the enigma
	//		enigma.plugSettings = configPlugboard(loopChar, enigma.plugSettings);

	//		// iterate through all edges in loop
	//		for (auto& edge : loop) {

	//			enigma.rotorPosition = initRotorPosition;

	//			resChar = loopChar[edge.first];
	//			// try to do without considering the plugboards first
	//			// type the same character so to check the target index character
	//			for (int pressCount = 0; pressCount < edge.index; pressCount++) {
	//				resChar = enigma.emulatePress(loopChar[edge.first]);
	//			}

	//		}

	//		if (resChar == finalChar) {
	//			std::cout << "CORRECT ROTOR WHEELS!" << std::endl;
	//			break;
	//		}
	//	}
	//}

	//std::cout << "Correct rotor wheels!" << std::endl;
	//return;


	// TRIAL CODE ENDS HERE
	std::vector<int> rotorSet({ 1,2,3,4,5 });
	std::vector<std::vector<int>> rotorCombinations = getPermutation(rotorSet, 3);
	
	// iterate through the rotor combinations
	for (auto& rotorSetting : rotorCombinations) {

		bool isBreak = false;
		enigma.rotorSettings = rotorSetting;

		// iterate through he rotor init positions
		for (int leftRotorPos = 0; leftRotorPos < 26; leftRotorPos++) {
			for (int centerRotorPos = 0; centerRotorPos < 26; centerRotorPos++) {
				for (int rightRotorPos = 0; rightRotorPos < 26; rightRotorPos++) {

					std::string initRotorPosition({ indexToChar(leftRotorPos),
													indexToChar(centerRotorPos),
													indexToChar(rightRotorPos),
													'\0' });

					enigma.rotorPosition = initRotorPosition;
					
					//// print the current configuration
					//for (auto& content : rotorSetting) std::cout << content;
					//
					//std::cout << ":" << initRotorPosition << std::endl;

					int loopCount = 0;

					// iterate through all loops
					for (auto& loop : loops) {
						char resChar = '0';
						char finalChar = loop[loop.size() - 1].second;

						//std::unordered_map<char, char> loopChar;
						//std::unordered_map<char, char> loopCharReverse;

						//// track down all involved chars inthe loop
						//// the purpose is to assign plugboard values in them

						//std::vector<std::string> plugCombinations = getPermutation(DEF_PLUG_SETTINGS, loop.size());

						/*for (auto& combination : plugCombinations) {*/

							//// assign members of the loop to a permutation
							//for (int i = 0; i < combination.length(); i++) {
							//	loopChar[loop[i].first] = combination[i];
							//	loopCharReverse[combination[i]] = loop[i].first;

							//	std::cout << loop[i].first << combination[i] << " ";
							//}
							//std::cout << std::endl;

							//// set up the enigma
							//enigma.plugSettings = configPlugboard(loopChar, enigma.plugSettings);

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
