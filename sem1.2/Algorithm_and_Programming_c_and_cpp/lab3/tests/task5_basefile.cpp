#include "basefile.hpp"
#include <utility>//for std::move
#include <cstring>//for strlen

int main() {
    
    BaseFile file1("data/file1.txt", "w");
    if (file1.is_open()) {
        const char* text = "hello from file1\n";
        file1.write(text, strlen(text));
    }

    BaseFile file2 = std::move(file1);

    
    BaseFile file3("data/dummy.txt", "w");
    file3 = std::move(file2);

    return 0;
}
