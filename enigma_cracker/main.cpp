// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Enigma.h"
#include "Constants.h"
#include "Utility.h"
#include "Bombe.h"

int main()
{
    /*Enigma enigma({4, 2, 1}, DEF_PLUG_SETTINGS, "EEV");
    std::string ptext = "ILOVESOFTWAREENGINEERING";
    for(int i = 0; i < ptext.length(); i++)
         std::cout << enigma.emulatePress(ptext[i]);
    std::cout << std::endl;*/

    // making the loops
    std::vector<std::vector<LoopEdge>> loops;
    /*std::vector<LoopEdge> loop1 = { LoopEdge{'G', 'A', 16}, 
                                    LoopEdge{'A', 'O', 3},
                                    LoopEdge{'O', 'G', 24} };
    std::vector<LoopEdge> loop2 = { LoopEdge{'E', 'V', 4},
                                    LoopEdge{'V', 'R', 12},
                                    LoopEdge{'R', 'J', 21},
                                    LoopEdge{'J', 'E', 19} };
    std::vector<LoopEdge> loop3 = { LoopEdge{'E', 'I', 13},
                                    LoopEdge{'I', '0', 22},
                                    LoopEdge{'O', 'J', 7},
                                    LoopEdge{'J', 'E', 19} };
    std::vector<LoopEdge> loop4 = { LoopEdge{'E', 'L', 14},
                                    LoopEdge{'L', 'X', 2},
                                    LoopEdge{'X', 'I', 17},
                                    LoopEdge{'I', 'E', 13} };
    std::vector<LoopEdge> loop5 = { LoopEdge{'X', 'L', 2},
                                    LoopEdge{'L', 'F', 8},
                                    LoopEdge{'F', 'N', 15},
                                    LoopEdge{'N', 'A', 23},
                                    LoopEdge{'A', 'O', 3},
                                    LoopEdge{'O', 'I', 22},
                                    LoopEdge{'I', 'X', 17} };*/

    std::vector<LoopEdge> loop1 = {
                                    LoopEdge{'M','N',23},
                                    LoopEdge{'N','R',15},
                                    LoopEdge{'R','M',21}
    };
    std::vector<LoopEdge> loop2 = {
                                    LoopEdge{'M','G',16},
                                    LoopEdge{'G','O',24},
                                    LoopEdge{'O','M',3}
    };
    std::vector<LoopEdge> loop3 = {
                                    LoopEdge{'O','J',7},
                                    LoopEdge{'J','E',19},
                                    LoopEdge{'E','I',13},
                                    LoopEdge{'I','O',22}
    };
    std::vector<LoopEdge> loop4 = {
                                    LoopEdge{'E','I',13},
                                    LoopEdge{'I','X',17},
                                    LoopEdge{'X','L',2},
                                    LoopEdge{'L','E',14}
    };

    loops.push_back(loop1);
    loops.push_back(loop2);
    loops.push_back(loop3);
    loops.push_back(loop4);
    //loops.push_back(loop5);
    
    Bombe bombe(loops);
    bombe.crack();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
