#include "GrayCodeGenerator.h"
using namespace std;

//--------------------------------------------------
// generate(n): returns a vector of n-bit Gray codes
//--------------------------------------------------
vector<string> GrayCodeGenerator::generate(int n) {
    vector<string> gray;
    if (n <= 0) return gray; // Empty universe for 0 bits

    gray.push_back("0");
    gray.push_back("1");

    for (int i = 2; i < (1 << n); i <<= 1) {
        for (int j = i - 1; j >= 0; j--)
            gray.push_back(gray[j]);

        for (int j = 0; j < i; j++)
            gray[j] = "0" + gray[j];
        for (int j = i; j < 2 * i; j++)
            gray[j] = "1" + gray[j];
    }
    return gray;
}
