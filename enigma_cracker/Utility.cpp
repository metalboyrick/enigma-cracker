#include "Utility.h"

std::string shiftLeft(std::string v, int times) {
    for (int i = 0; i < times; i++) {
        char popElem = v[0];
        v.erase(v.begin());
        v.push_back(popElem);
    }

    return v;
}

std::string shiftRight(std::string v, int times) {
    for (int i = 0; i < times; i++) {
        char popElem = v[v.length() - 1];
        v.pop_back();
        v.insert(v.begin(), popElem);
    }

    return v;
}

std::vector<std::vector<int>> getPermutation(std::vector<int> v, int r)
{
    std::vector<std::vector<int>> combinations;             // vector containing all possibilies of nPr
    std::vector<int> sub_combi;                             // sub combination of r elements

    // sort in preparation for permutation
    std::sort(v.begin(), v.end());

    // iterate through the permutations
    do {
        sub_combi = { v.begin(), v.begin() + r };
        if (!std::count(combinations.begin(), combinations.end(), sub_combi)) {
            combinations.push_back(sub_combi);
        }
    } while (std::next_permutation(v.begin(), v.end()));
    
    return combinations;
}

// converts an UPPERCASE character to index 0-25
int charToIndex(char c)
{
    return static_cast<int>(c) - 65;
}

char indexToChar(int index)
{
    return static_cast<char>(index + 65);
}

std::string convertToPlugboard(std::unordered_map<char, char> plugboardMap)
{
    std::string resString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (auto& mapping : plugboardMap) {
        if (mapping.second != mapping.first) {
            resString[charToIndex(mapping.first)] = mapping.second;
            resString[charToIndex(mapping.second)] = mapping.first;
        }
    }

    return std::string();
}
