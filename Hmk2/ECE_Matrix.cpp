/*
Author: Matthew Lim
Class: ECE4122
Last Date Modified: Sept 20, 2019
Description: CPP file for functions related to the ECE_Matrix Class. The ECE_Matrix class is simply a
 Matrix class that can use simple notations by overriding operators.
*/
#include "ECE_Matrix.h"
/* ================= Constructors ========================================== */
ECE_Matrix::ECE_Matrix(const std::string fileName) {
    std::string str;
    std::ifstream inputFile(fileName);
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
ECE_Matrix::ECE_Matrix(int rows, int columns, double allValues) {
    mRows = rows;
    nColumns = columns;
    //Using vectors allows for simple and quick dynamic memory allocation
    //I used a 1-d vector because it is simpler.
    arr.assign(rows * columns, allValues);
}
//Assuming C++ 11+ we can use this notation for constructors.
ECE_Matrix::ECE_Matrix(int sqr, double allValues) : ECE_Matrix(sqr, sqr, allValues) {}
ECE_Matrix::ECE_Matrix() : ECE_Matrix(0, 0, 0.0) {}

/* ============== Operator Overrides ======================================= */
std::ostream& operator<<(std::ostream& os, const ECE_Matrix& matrix) {
    //Simple printer for the vector. Uses the two for loops to determine the index in the vector to cout
    os << std::scientific  << std::setprecision(3);
    for (int i = 0; i < matrix.mRows; i++) {
        for (int j = 0; j < matrix.nColumns; j++) {
            os << std::setw(12) << matrix.arr[j + (matrix.nColumns*i)] << ' ';
        }
        os << "\n";
    }
    return os;
}
ECE_Matrix ECE_Matrix::operator+ (ECE_Matrix const &matrix) const {
    //Almost all the functions use this format
    //Create a new matrix with the correct size (max ensures they are the largest size)
    ECE_Matrix result(std::max(mRows, matrix.mRows),std::max(nColumns, matrix.nColumns), 0.0);
    for (int i = 0; i < result.mRows; i++) {
        for (int j = 0; j < result.nColumns; j++) {
            //These if statements just check if they were in the range of the original matrix
            if(i < mRows && j < nColumns) {
                result.arr[j + result.nColumns*i] = arr[j + nColumns*i];
            }
            //Then we subtract from those filled in values
            if(i < matrix.mRows && j < matrix.nColumns) {
                result.arr[j + result.nColumns*i] += matrix.arr[j + matrix.nColumns*i];
            }
        }
    }
    return result;
}
ECE_Matrix ECE_Matrix::operator+ (double number) const {
    //Simply add the number to each element of the vector
    ECE_Matrix result(mRows, nColumns, 0.0);
    for (int i = 0; i < mRows*nColumns; i++) {
        result.arr[i] = arr[i] + number;
    }
    return result;
}
ECE_Matrix operator+ (double number, ECE_Matrix const &matrix) {
    //Essentially create a 1x1 matrix with the number then use the add from before
    ECE_Matrix result(1, number);
    return result + matrix;
}
void ECE_Matrix::operator+= (ECE_Matrix const &matrix) {
    //We can use the addition of matrixs from before
    *(this) = *(this) + matrix;
}
ECE_Matrix ECE_Matrix::operator-(ECE_Matrix const &matrix) const {\
    //Same format as the ECE_Matrix+ECE_Matrix section
    ECE_Matrix result(std::max(mRows, matrix.mRows),std::max(nColumns, matrix.nColumns), 0.0);
    for (int i = 0; i < result.mRows; i++) {
        for (int j = 0; j < result.nColumns; j++) {
            if(i < mRows && j < nColumns) {
                result.arr[j + result.nColumns*i] = arr[j + nColumns*i];
            }
            if(i < matrix.mRows && j < matrix.nColumns) {
                result.arr[j + result.nColumns*i] -= matrix.arr[j + matrix.nColumns*i];
            }
        }
    }
    return result;
}
ECE_Matrix ECE_Matrix::operator- (double number) const {
    //See operator+ for these parameters
    ECE_Matrix result(mRows, nColumns, 0.0);
    for (int i = 0; i < mRows*nColumns; i++) {
        result.arr[i] = arr[i] - number;
    }
    return result;
}
void ECE_Matrix::operator-= (ECE_Matrix const &matrix) {
    //See operater +=
    *(this) = *(this) - matrix;
}
ECE_Matrix operator- (double number, ECE_Matrix const &matrix) {
    //See operator - with these parameters
    ECE_Matrix result(1, number);
    return result - matrix;
}
ECE_Matrix ECE_Matrix::operator* (double number) const {
    //Simply multiply each vector element to the number
    ECE_Matrix result(mRows, nColumns, 0.0);
    for (int i = 0; i < mRows*nColumns; i++) {
        result.arr[i] = arr[i] * number;
    }
    return result;
}
ECE_Matrix operator* (double number, ECE_Matrix const &matrix) {
    //Use the * operator from before.
    return matrix * number;
}
ECE_Matrix ECE_Matrix::operator/ (double number) const {
    //See the multiplier operator except with a if clause to catch if divide by 0.0.
    ECE_Matrix result(mRows, nColumns, 0.0);
    if (number != 0.0) {
        for (int i = 0; i < mRows*nColumns; i++) {
            result.arr[i] = arr[i] / number;
        }
    } else {
        for (int i = 0; i < mRows*nColumns; i++) {
            result.arr[i] = 0;
        }
    }
    return result;
}
ECE_Matrix ECE_Matrix::transpose() const {
    //Simply switching the columns and rows allows for transpose.
    ECE_Matrix result(nColumns, mRows, 0.0);
    for (int i = 0; i < nColumns; i++) {
        for (int j = 0; j < mRows; j++) {
            result.arr[j + i * mRows] = arr[i + j*nColumns];
        }
    }
    return result;
}