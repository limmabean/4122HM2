//
// Created by matthew on 9/16/19.
//

#include "ECE_Matrix.h"

int main() {
    const ECE_Matrix M1(3, 5.0);
    ECE_Matrix M3;
    const ECE_Matrix M2(6, 5, 200.0);
    //const ECE_Matrix M4("data_Problem1.txt"); // Construct matrix from file
    std::cout << "M3: " << std::endl << M2+M1 << std::endl;
}
