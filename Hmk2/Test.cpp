//
// Created by matthew on 9/16/19.
//

#include "ECE_Matrix.h"

int main() {
    const ECE_Matrix M1(3, 5.0);
    ECE_Matrix M3;
    const ECE_Matrix M2(5, 5, 200.0);
    std::cout << "M3: " << std::endl << M1 + M2 << std::endl;
}
