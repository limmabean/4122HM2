//
// Created by matthew on 9/15/19.
//
#include "ECE_Matrix.h"

ECE_Matrix::ECE_Matrix(int rows, int columns, double allValues) {
    mRows = rows;
    nColumns = columns;
    arr.assign(rows * columns, allValues);
}
ECE_Matrix::ECE_Matrix(int sqr, double allValues) : ECE_Matrix(sqr, sqr, allValues) {}
ECE_Matrix::ECE_Matrix() : ECE_Matrix(0, 0, 0) {}
ostream& operator<<(std::ostream& os, const ECE_Matrix& matrix) {
    for (int i = 0; i < matrix.mRows; i++) {
        for (int j = 0; j < matrix.nColumns; j++) {
            os << matrix.arr[j + (matrix.mRows*i)] << ' ';
        }
        os << "\n";
    }
    return os;
}
