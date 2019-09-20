/*
Author: Matthew Lim
Class: ECE4122
Last Date Modified: Sept 20, 2019
Description: CPP file for largest product problem. This takes in a string in the command line that has the text
file.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int main(int argc, char *argv[]) {
    int mRows = 0;
    int nColumns = 0;
    std::vector<int> arr;
    std::string str;
    std::ifstream inputFile(argv[1]);
    if (inputFile.is_open())
    {
        //First line is row and columns
        getline(inputFile, str);
        //Find Space
        size_t delimiterIndex = str.find(" ");
        //Substring till Space. Then turn into int.
        mRows = std::stoi(str.substr(0, delimiterIndex));
        //Remainder of the string.
        str = str.substr(delimiterIndex+1, str.length()-(delimiterIndex+2));
        nColumns = std::stoi(str);
        arr.assign(mRows * nColumns, 0.0);
        //Start reading data.
        for (int i = 0; i < mRows; i++) {
            //This is to make sure there is another line
            if(getline(inputFile, str)) {
                for (int j = 0; j < nColumns; j++) {
                    delimiterIndex = str.find(" ");
                    //This is to make sure there is another column
                    if(delimiterIndex) {
                        arr[j + i * nColumns] = std::stoi(str.substr(0, delimiterIndex));
                        str = str.substr(delimiterIndex+1, str.length());
                    } else {
                        std::cout << "Given columns do not match provided columns.";
                        break;
                    }
                }
            } else {
                std::cout << "Given rows do not match provided rows.";
                break;
            }
        }
    } else {
        std::cout<<"Unable to open file.";
    }
    inputFile.close();
}