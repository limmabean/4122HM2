//
// Created by matthew on 9/15/19.
//
#include "ECE_Matrix.h"
// Constructors
ECE_Matrix::ECE_Matrix(const std::string fileName) {
    std::string str;
    std::ifstream inputFile(fileName);
    std::cout<<fileName;
    if (inputFile.is_open())
    {
        //First line is row and columns
        getline(inputFile, str);
        size_t spaceIndex = str.find(" ");
        mRows = std::stoi(str.substr(0, spaceIndex));
        nColumns = std::stoi(str.substr(spaceIndex, str.length() - spaceIndex));
    } else {
        std::cout<<"Unable to open file.";
    }
    inputFile.close();
}
ECE_Matrix::ECE_Matrix(int rows, int columns, double allValues) {
    mRows = rows;
    nColumns = columns;
    arr.assign(rows * columns, allValues);
}
ECE_Matrix::ECE_Matrix(int sqr, double allValues) : ECE_Matrix(sqr, sqr, allValues) {}
ECE_Matrix::ECE_Matrix() : ECE_Matrix(0, 0, 0) {}
// Getters
int ECE_Matrix::getRows() const {return mRows;}
int ECE_Matrix::getColumns() const {return nColumns;}
// Gets element in matrix
double ECE_Matrix::getElement(int row, int column) const {
    if (row >= 0 && row < mRows && column >= 0 && column < nColumns) {
        return arr[column + row * nColumns];
    } else {
        std::cout << "Out of bounds";
        return -1;
    }
}
// Overriding Operators
std::ostream& operator<<(std::ostream& os, const ECE_Matrix& matrix) {
    for (int i = 0; i < matrix.mRows; i++) {
        for (int j = 0; j < matrix.nColumns; j++) {
            os << matrix.arr[j + (matrix.nColumns*i)] << ' ';
        }
        os << "\n";
    }
    return os;
}
ECE_Matrix ECE_Matrix::operator+ (ECE_Matrix const obj) const {
    ECE_Matrix result(std::max(mRows, obj.mRows),std::max(nColumns, obj.nColumns), 0);
    
    return result;
}
