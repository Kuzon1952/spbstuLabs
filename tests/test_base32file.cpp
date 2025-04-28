#include "../src/base32file.hpp"
#include <cassert>
#include <cstdlib>
#include <iostream>

void test_double_read(const char *path) {
    char buf[100];
    for (int i = 0; i < 100; ++i) buf[i] = std::rand();
    {
        Base32File f(path, "w");
        f.write(buf, 100);
    }
  
    {
        Base32File f(path, "r");
        char buf2[64];

       
        f.read(buf2, 64);
        for (int i = 0; i < 64; ++i) assert(buf2[i] == buf[i]);

        
        f.read(buf2, 64);
        for (int i = 0; i < 36; ++i) assert(buf2[i] == buf[i + 64]);
    }
}


int main() {
    const char *path = "data/base32_test_base32file.txt";
    
    
    test_double_read(path);

    std::cout << "test passed!" << std::endl;
    return 0;
}
