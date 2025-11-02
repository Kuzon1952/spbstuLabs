#pragma once
#include <vector>
#include <string>
using namespace std;

//--------------------------------------------------
// GrayCodeGenerator
// Generates binary Gray codes for given bit length
//--------------------------------------------------
class GrayCodeGenerator {
public:
    static vector<string> generate(int n);
};
