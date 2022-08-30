//
//  main.cpp
//  Matrix Calculator
//
//  Created by Lawrence Lee on 6/18/22.
//

#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "Utilities.hpp"
using namespace std;
int main() {
    Matrix A(4,4);
    int j = 2;
    for (int i = 0; i < A.get_rows(A); i++)
        for (int k = 0; k < A.get_cols(A); k++, j++)
            A.setMatrixValue(A, i, k, j);
    display(A);
    A.orthonormalize(A);
    display(A);
}
