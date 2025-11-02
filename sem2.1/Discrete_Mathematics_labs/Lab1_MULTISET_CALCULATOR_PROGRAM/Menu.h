#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "Multiset.h"

class Menu {
private:
    std::vector<std::string> universeVec;
    std::unordered_map<int, int> universeMap; // index -> multiplicity
    Multiset A, B;

    void printHeader();
    void printUniverse();

    // NEW: split creation
    void createA();
    void createB();

public:
    void start();
    void createMultisets(); // keeps both A then B (with back options)
    void runMenu();
};
