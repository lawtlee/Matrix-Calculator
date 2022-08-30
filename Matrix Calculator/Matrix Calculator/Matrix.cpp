//
//  Matrix.cpp
//  Matrix Calculator
//
//  Created by Lawrence Lee on 6/18/22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cmath>
#include <iostream>

using namespace std;

//Utilities
void setMatrix(Matrix& A)
{
    format(A);
    for (int i = 0; i < A.m_rows; i++)
    {
        for (int j = 0; j < A.m_cols; j++)
            cin >> A.matrix[i][j];
        cin.clear();
    }
}

void display(const Matrix& A)
{
    for (int i = 0; i < A.m_rows; i++)
    {
        for (int j = 0; j < A.m_cols; j++)
            cout << A.matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void format(const Matrix& A)
{
    cout << "Enter the " << A.m_rows << " X " << A.m_cols << " matrix using the following format: " << endl;
    for (int i = 0; i < A.m_rows; i++)
    {
        for (int j = 0; j < A.m_cols; j++)
            cout << "# ";
        cout << endl;
    }
    cout << endl;
}

//Matrix Functions
Matrix::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols)
{
    matrix = new double*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new double[cols];
}

Matrix::Matrix(const Matrix& A) : m_rows(A.m_rows), m_cols(A.m_cols)
{
    matrix = new double*[m_rows];
    for (int i = 0; i < m_rows; i++)
        matrix[i] = new double[m_cols];
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            matrix[i][j] = A.matrix[i][j];
}

Matrix& Matrix::operator=(const Matrix& other)
{
    delete[] matrix;
    m_rows = other.m_rows; m_cols = other.m_cols;
    matrix = new double*[m_rows];
    for (int i = 0; i < m_rows; i++)
        matrix[i] = new double[m_cols];
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            matrix[i][j] = other.matrix[i][j];
    return *this;
}

Matrix::~Matrix()
{
    delete[] matrix;
}

Matrix* Matrix::m_addition(Matrix &A, Matrix &B)
{
    if ((A.m_rows != B.m_rows) || (A.m_cols != B.m_cols))
        return nullptr;
    Matrix* result = new Matrix(A.m_rows, A.m_cols);
    for (int i = 0; i < result->m_rows; i++)
        for (int j = 0; j < result->m_cols; j++)
            result->matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    return result;
}

Matrix* Matrix::m_multiplication(Matrix &A, Matrix &B)
{
    if (A.m_cols != B.m_rows)
        return nullptr;
    Matrix* result = new Matrix(A.m_rows, B.m_cols);
    for (int i = 0; i < result->m_rows; i++)
    {
        for (int j = 0; j < result->m_cols; j++)
        {
            double total = 0;
            for (int k = 0; k < A.m_rows; k++)
                total += A.matrix[i][k] * B.matrix[k][j];
            result->matrix[i][j] = total;
        }
    }
    return result;
}

void Matrix::gram_schmidt(Matrix &A)
{
    Matrix const temp = A;
    Vector* other[A.m_cols];
    for (int i = 0; i < temp.m_cols; i++)
        other[i] = new Vector(temp, i);
    for (int i = 0, j = 1; i < A.m_cols; i++, j++)
        gram_helper(&other[i], j);
    for (int i = 0; i < A.m_rows; i++)
    {
        for (int j = 0; j < A.m_cols; j++)
            A.matrix[i][j] = other[j]->matrix[i][0];
    }
    for (int i = 0; i < A.m_cols; i++)
        delete other[i];
}

Matrix* Matrix::orthonormalize(Matrix &A)
{
    gram_schmidt(A);
    Vector* other[A.m_cols];
    for (int i = 0; i < A.m_cols; i++)
        other[i] = new Vector(A, i);
    for (int i = 0; i < A.m_cols; i++)
        for (int j = 0; j < A.m_rows; j++)
            other[i]->matrix[j][0] = A.matrix[j][i];
    for (int i = 0; i < A.m_cols; i++)
        other[i]->normalize(*other[i]);
    return &A;
}

void Matrix::rref(Matrix &A)
{
    Vector* other[A.m_rows];
    for (int i = 0; i < A.m_rows; i++)
        other[i] = new Vector(A, i);
    for (int i = 0; i < A.m_cols; i++)
        for (int j = 0; j < A.m_rows; j++)
            other[i]->matrix[j][0] = A.matrix[j][i];
    
}

//Helper Functions
void Matrix::gram_helper(Vector* other[], int cols)
{
    if (cols - 1 == 0)
        return;
    Vector* v2 = other[cols-3];
    Vector* temp = new Vector(v2->get_rows(*v2));
    *temp = temp->projection(*v2, **other);
    v_subtraction(**other, *temp, **other);
    v2 = nullptr;
    gram_helper(other, cols-1);
    delete temp;
}

//Matrix* rref_helper(Vector* rows[], int row)
//{
//    if (row == 0)
//        return this;
//
//}

double compareRows(Vector* rows[], int colNum, int numRows)
{
    if (allZero(rows, colNum, numRows))
        return 0;
    for (int i = 0; i < numRows; i++)
        
}

bool allZero(Vector* rows[], int colNum, int numRows)
{
    for (int i = 0; i < numRows; i++)
        if (rows[i]->get_mValue(*rows[i], colNum, 0) != 0)
            return false;
    return true;
}
