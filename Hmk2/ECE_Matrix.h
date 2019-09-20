//
// Created by matthew on 9/15/19.
//
#include <iostream>
#include <vector>
using namespace std;
#ifndef HMK2_ECE_MATRIX_H
#define HMK2_ECE_MATRIX_H


class ECE_Matrix {
    int mRows;
    int nColumns;
    vector<double> arr;
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
    ECE_Matrix (const char* fileName);
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
    /**
     * Override for the << so you can print out using cout
     * @param os
     * @param matrix
     * @return
     */
     /* ============== Operator Overrides ============== */
    friend ostream& operator<<(ostream& os, const ECE_Matrix& matrix);
    ECE_Matrix operator+ (ECE_Matrix const obj) const {return obj;}
    ECE_Matrix operator+ (double obj) const {}
    ECE_Matrix operator- (ECE_Matrix const &obj) {}
    ECE_Matrix operator- (double obj) {}
};


#endif //HMK2_ECE_MATRIX_H
