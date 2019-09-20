//
// Created by Jongmook on 9/20/2019.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int main(int argc, char *argv[]) {
    std::cout << argv[1] << "\n";
    std::ifstream myfile;
    std::string line;
    myfile.open(argv[1]);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::cout << line << '\n';
        }
        myfile.close();
    }
    else {
        std::cout << "Unable to open file";
    }
    return 0;
}