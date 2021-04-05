#include "Utility.h"


// comb code credits : https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c
// utitity function to generate combinations, to assist getPermutation
std::vector<std::vector<int>> comb(std::vector<int> intSet,int N, int K)
{
    std::vector<std::vector<int>> combinations;
    std::vector<int> subCombi;
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) subCombi.push_back(intSet[i]);
        }
        combinations.push_back(subCombi);
        subCombi.clear();
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    return combinations;
}

// utitity function to generate combinations, to assist getPermutation
std::vector<std::string> comb(int N, int K)
{
    std::vector<std::string> combinations;
    std::string subCombi;
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) subCombi.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i]);
        }
        combinations.push_back(subCombi);
        subCombi.clear();
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    return combinations;
}

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
    std::vector<std::vector<int>> combinations = comb(v, v.size(), r);  // vector containing all possibilies of nCr
    std::vector<std::vector<int>> permutations;                         // vector containing all possibilies of nPr

    // permute each combination
    for (auto& subCombi : combinations) {
        std::sort(subCombi.begin(), subCombi.end());
        do {
            permutations.push_back(subCombi);
        } while (std::next_permutation(subCombi.begin(), subCombi.end()));
    }
    
    return permutations;
}

std::vector<std::string> getPermutation(std::string v, int r)
{
    std::vector<std::string> combinations = comb(v.length(), r);    // vector containing all possibilies of nCr
    std::vector<std::string> permutations;                          // vector containing all possibilies of nPr

    // permute each combination
    for (auto& subCombi : combinations) {
        std::sort(subCombi.begin(), subCombi.end());
        do {
            permutations.push_back(subCombi);
        } while (std::next_permutation(subCombi.begin(), subCombi.end()));
    }
    
    return permutations;
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

std::string configPlugboard(std::unordered_map<char, char> plugboardMap, std::string currentPlugboard)
{

    for (auto& mapping : plugboardMap) {
        if (mapping.second != mapping.first) {
            currentPlugboard[charToIndex(mapping.first)] = mapping.second;
            currentPlugboard[charToIndex(mapping.second)] = mapping.first;
        }
    }

    return currentPlugboard;
}
