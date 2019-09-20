//
// Created by matthew on 9/15/19.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#ifndef HMK2_ECE_MATRIX_H
#define HMK2_ECE_MATRIX_H


class ECE_Matrix {
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
    /* =============== Getters/Setters ================= */
    int getRows() const;
    int getColumns() const;
    double getElement(int row, int column) const;
    void setElement(int row, int column, double value);


     /* ============== Operator Overrides ============== */
    /**
     * Override for the << so you can print out using cout
     * @param os
     * @param matrix
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os, const ECE_Matrix& matrix);
    ECE_Matrix operator+ (ECE_Matrix const obj) const;
    ECE_Matrix operator+ (double obj) const {}
    ECE_Matrix operator- (ECE_Matrix const &obj) {}
    ECE_Matrix operator- (double obj) {}
};


#endif //HMK2_ECE_MATRIX_H
