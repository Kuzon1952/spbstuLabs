#include "../src/mystring.hpp"
#include <fstream>
using namespace std;

MyString addTxtExtension(const MyString& path) {
    return path + ".txt";
}

int main() {
    MyString filename("filename");
    MyString full = addTxtExtension(filename);

    //saving to data/filename.txt
    ofstream outFile("data/" + string(full.get_data()));
    outFile << "this is a test string inside " << full.get_data();
    outFile.close();

    return 0;
}
