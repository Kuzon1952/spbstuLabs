#include "list.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main() {

        List circleList;

        //open input file
        std::ifstream fin("inputData/circles.txt");
        if (!fin) {
            std::cerr << "error: cannot open inputData/circles.txt\n";
            return 1;
        }
    
        fin >> circleList;
        fin.close();
    
        std::cout << "read " << circleList.size() << " circles from file.\n";
        std::cout << "original list:\n" << circleList << "\n";
        circleList.display(std::cout);
        std::cout << "\n";
    
        circleList.sortByArea();
        std::cout << "list sorted by area:\n" << circleList << "\n";
        circleList.display(std::cout);
        std::cout << "\n";
    
        //ask for output filename
        char filename[100];
        std::cout << "enter output file name: ";
        std::cin.getline(filename, 100);
    
        if (strlen(filename) == 0) {
            std::cerr << "no file name provided. exiting.\n";
            return 1;
        }
    
        //outputData/ to the filename
        char fullPath[200] = "outputData/";
        strncat(fullPath, filename, sizeof(fullPath) - strlen(fullPath) - 1);
    
        std::ofstream fout(fullPath);
        if (!fout) {
            std::cerr << "error: cannot open file " << fullPath << "\n";
            return 1;
        }
    
        fout << circleList;
        fout.close();
    
        std::cout << "sorted list written to " << fullPath << "\n";
        
    return 0;
}
