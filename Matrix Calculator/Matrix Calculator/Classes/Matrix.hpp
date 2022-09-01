//
//  Matrix.hpp
//  Matrix Calculator
//
//  Created by Lawrence Lee on 6/18/22.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <cmath>

//class Utilities;
struct Vector;
class Matrix
{
public:
    //Main Matrix Functions
    Matrix(int rows, int cols);
    Matrix(const Matrix& A);
    Matrix& operator=(const Matrix& other);
    virtual ~Matrix();
    Matrix* m_multiplication(Matrix& A, Matrix& B);
    Matrix* m_addition(Matrix& A, Matrix& B);
    Matrix* gram_schmidt(Matrix& A);
    Matrix* orthonormalize(Matrix& A);
    void rref(Matrix& A);
    
    //Getter Functions
    int get_rows(Matrix& A) const {return A.m_rows;}
    int get_cols(Matrix& A) const {return A.m_cols;}
    double get_mValue(Matrix& A, int row, int col) const {return A.matrix[row][col];}
    //Setter Functions
    void setMatrixValue(Matrix& A, int row, int col, double value) {A.matrix[row][col] = value;}
    
    //Utility Functions for Matrices
    friend void setMatrix(Matrix& A);
    friend void display(const Matrix& A);
    friend void format(const Matrix& A);
    friend struct Vector;
    
private:
    //Helper Functions
    void gram_helper(Vector* other[], int cols);
    Matrix* rref_helper(Vector* other[], int row);
    //Matrix Variables
    int m_rows;
    int m_cols;
    double** matrix;
};

struct Vector : public Matrix
{
    Vector(int rows);
    Vector(const Vector& A);
    Vector& operator=(const Vector& other);
    Vector(const Matrix& A, int col);
    ~Vector();
    double dotProduct(Vector& v1, Vector& v2) const;
    double magnitude(Vector& v1) const;
    double compSmth(Vector& v1, Vector& v2);
    Vector* vScalar(double scalar, Vector& v1);
    Vector projection(Vector& v1, Vector& v2);
    Vector* v_addSub(Vector& v1, Vector& v2, bool sign);

    //Vector Related Functions
    friend bool v_addition(Vector& v1, Vector& v2, Vector& result);
    friend bool v_subtraction(Vector& v1, Vector& v2, Vector& result);
    friend bool projection(Vector& v1, Vector& v2, Vector& result);
    void normalize(Vector& A);
};
#endif /* Matrix_hpp */

