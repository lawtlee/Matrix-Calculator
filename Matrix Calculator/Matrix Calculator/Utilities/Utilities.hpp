//
//  Utilities.hpp
//  Matrix Calculator
//
//  Created by Lawrence Lee on 6/18/22.
//

#ifndef Utilities_hpp
#define Utilities_hpp

#include <stdio.h>
#include <iostream>
#include "Matrix.hpp"

//Miscellaneous
void matrixCalculator();
void vectorCalculator();
void greeting();
void clearSpace();
int moreComp();

//Matrix Functions
Matrix* addition();
Matrix* multiplication();
Matrix* gram_Schmidt();
Matrix* orthonormalization();

//Vector Functions
Vector* addSub(bool sign);
Vector* scalar();
Vector projection();
void dot_Product();
void magnitude();

#endif /* Utilities_hpp */
