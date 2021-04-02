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


