#include "Constants.h"

// rotor mapping
const std::string ROTOR_WHEELS[5] =	{ "EKMFLGDQVZNTOWYHXUSPAIBRCJ" , 
										"AJDKSIRUXBLHWTMCQGZNPYFVOE", 
										"BDFHJLCPRTXVZNYEIWGAKMUSQO",
										"ESOVPZJAYQUIRHXLNFTGKDCMWB", 
										"VZBRGITYUPSDNHLXAWMJQOFECK" };

// reflector mappings (UKW-B)
const std::string REFLECTOR = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

// rotor notches
const char ROTOR_NOTCHES[5] = { 'Q','E','V','J','Z' };

// DEFAULTS
const std::string DEF_PLUG_SETTINGS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string DEF_ROTOR_POSITION = "AAA";
const std::vector<int> DEF_ROTOR_SETTINGS = { 1, 2, 3 };