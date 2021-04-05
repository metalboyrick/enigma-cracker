// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Enigma.h"
#include "Constants.h"
#include "Utility.h"
#include "Bombe.h"

int main()
{
    /*Enigma enigma({4, 3, 1}, DEF_PLUG_SETTINGS, "EDI");
    std::string ptext = "ILOVESOFTWAREENGINEERING";
    for(int i = 0; i < ptext.length(); i++)
         std::cout << enigma.emulatePress(ptext[i]);
    std::cout << std::endl;*/

    // making the loops
    std::vector<std::vector<LoopEdge>> loops;
    std::vector<LoopEdge> loop1 = { LoopEdge{'G', 'A', 16}, 
                                    LoopEdge{'A', 'O', 3},
                                    LoopEdge{'O', 'G', 24} };
    std::vector<LoopEdge> loop2 = { LoopEdge{'E', 'V', 4},
                                    LoopEdge{'V', 'R', 12},
                                    LoopEdge{'R', 'J', 21},
                                    LoopEdge{'J', 'E', 19} };
    loops.push_back(loop1);
    loops.push_back(loop2);
    
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
