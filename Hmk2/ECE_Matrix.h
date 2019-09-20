/*
Author: Matthew Lim
Class: ECE4122
Last Date Modified: Sept 20, 2019
Description: Header file for defining functions related to the ECE_Matrix Class. The ECE_Matrix class is simply a
 Matrix class that can use simple notations by overriding operators.
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#ifndef HMK2_ECE_MATRIX_H
#define HMK2_ECE_MATRIX_H


class ECE_Matrix {
private:
    int mRows;
    int nColumns;
    std::vector<double> arr;
public:
    /* ================= Constructors ================= */
    /**
     * Default Constructor
     * Sets matrix to size 0 x 0
     */
    ECE_Matrix ();
    /**
     * 1-Value Constructor
     * @param fileName is the name of file to retrieve the ECE_Matrix
     */
    ECE_Matrix (const std::string fileName);
    /**
     * 2-Value Constructor
     * @param rows in the ECE_Matrix
     * @param allValues is the value that initially fill the ECE_Matrix
     */
    ECE_Matrix (int sqr, double allValues);
    /**
    * 3-Value Constructor
    * @param rows in the ECE_Matrix
    * @param columns in the ECE_Matrix
    * @param allValues are the values that initially fill the ECE_Matrix
    */
    ECE_Matrix (int rows, int columns, double allValues);

    /* ============== Operator Overrides ============== */
    /**
     * Override for the << so you can print out ECE_Matrix using cout
     * @param os ostream object
     * @param matrix matrix object
     * @return ostream object with the correct print sequence
     */
    friend std::ostream& operator<<(std::ostream& os, const ECE_Matrix& matrix);
    /**
     * Override when a ECE_Matrix + ECE_Matrix
     * @param matrix the second matrix
     * @return a new matrix with the sum.
     */
    ECE_Matrix operator+ (ECE_Matrix const &matrix) const;
    /**
     * Override when a ECE_Matrix + double
     * @param number the double that is added
     * @return a new matrix with the sum.
     */
    ECE_Matrix operator+ (double number) const;
    /**
     * Override when a double + ECE_Matrix
     * @param number the double that is added
     * @param matrix the matrix that is added
     * @return a new matrix with the sum.
     */
    friend ECE_Matrix operator+ (double number, ECE_Matrix const &matrix);
    /**
     * Override when a ECE_Matrix - ECE_Matrix
     * @param matrix the second matrix
     * @return a new matrix with the result.
     */
    ECE_Matrix operator- (ECE_Matrix const &matrix) const;
    /**
     * Override when a ECE_Matrix - double
     * @param number the double that is added
     * @return a new matrix with the result.
     */
    ECE_Matrix operator- (double number) const;
    /**
     * Override when a double - ECE_Matrix
     * @param number the double
     * @param matrix the matrix that is subtracted
     * @return a new matrix with the result.
     */
    friend ECE_Matrix operator- (double number, ECE_Matrix const &matrix);
    /**
     * Simple increment
     * @param matrix that is used to sum
     */
    void operator+= (ECE_Matrix const &matrix);
    /**
     * Simple decrement
     * @param matrix that is used to subtract
     */
    void operator-= (ECE_Matrix const &matrix);
    /**
     * Multiply a matrix by a scalar
     * @param number to scale the matrix by
     * @return the resulting matrix
     */
    ECE_Matrix operator* (double number) const;
    /**
     * Multiply a number by a matrix
     * Assuming the number is simply a 1x1 matrix
     * @param number that forms the 1x1 matrix
     * @return the resulting matrix
     */
    friend ECE_Matrix operator* (double number, ECE_Matrix const &matrix);
    /**
     * divide a matrix by a scalar
     * @param number to divide the matrix by
     * @return the resulting matrix
     */
    ECE_Matrix operator/ (double number) const;
    /* ================ Other functions =============== */
    /**
     * Simple transpose for a matrix
     * @return the resulting matrix.
     */
    ECE_Matrix transpose() const;
};


#endif //HMK2_ECE_MATRIX_H
