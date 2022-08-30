//
//  Vector.hpp
//  Matrix Calculator
//
//  Created by Lawrence Lee on 6/21/22.
//

#ifndef Vector_h
#define Vector_h
#include "Matrix.hpp"
struct Vector : public Matrix
{
    Vector(int rows);
    Vector(const Vector& A);
    Vector& operator=(const Vector& other);
    Vector(const Matrix& A, int col);
    ~Vector();
    double dotProduct(Vector& v1, Vector& v2);
    double magnitude(Vector& v1);
    double compSmth(Vector& v1, Vector& v2);
    Vector* vScalar(double scalar, const Vector& v1);
    Vector projection(Vector& v1, Vector& v2);
    
    //Vector Related Functions
    friend bool v_addition(Vector& v1, Vector& v2, Vector& result);
    friend bool v_subtraction(Vector& v1, Vector& v2, Vector& result);
    friend bool projection(Vector& v1, Vector& v2, Vector& result);
    void normalize(Vector& A);
};
#endif /* Vector_h */
