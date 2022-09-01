//
//  Vector.cpp
//  Matrix Calculator
//
//  Created by Lawrence Lee on 6/21/22.
//

#include <stdio.h>
#include "Matrix.hpp"

Vector::Vector(int rows) : Matrix(rows, 1){}

Vector::Vector(const Vector& A) : Matrix(A)
{
    matrix = new double*[m_rows];
    for (int i = 0; i < m_rows; i++)
        matrix[i] = new double[m_cols];
    for (int i = 0; i < m_rows; i++)
        matrix[i][0] = A.matrix[i][0];
}

Vector& Vector::operator=(const Vector& other)
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

Vector::Vector(const Matrix& A, int col) : Matrix(A.m_rows,1)
{
    for (int i = 0; i < m_rows; i++)
        matrix[i][0] = A.matrix[i][col];
}

Vector::~Vector() {}

double Vector::dotProduct(Vector& v1, Vector& v2) const
{
    double total = 0;
    for (int i = 0; i < v1.m_rows; i++)
        total += v1.get_mValue(v1, i, 0) * v2.get_mValue(v2, i, 0);
    return total;
}

bool v_subtraction(Vector &v1, Vector &v2, Vector& result)
{
    for (int i = 0; i < result.get_rows(result); i++)
    {
        double value = v1.get_mValue(v1, i, 0) - v2.get_mValue(v2, i, 0);
        result.setMatrixValue(result, i, 0, value);
    }
    return true;
}

Vector* Vector::vScalar(double scalar, Vector &v1)
{
    for (int i = 0; i < this->m_rows; i++)
        this->matrix[i][0] = scalar * v1.matrix[i][0];
    return this;
}

double Vector::magnitude(Vector& v1) const
{
    double magnitude = 0;
    for (int i = 0; i < v1.m_rows; i++)
        magnitude += v1.matrix[i][0] * v1.matrix[i][0];
    magnitude = sqrt(magnitude);
    return magnitude;
}

void Vector::normalize(Vector &A)
{
    double scalar = magnitude(A);
    A.vScalar(1/scalar, A);
}

double Vector::compSmth(Vector &v1, Vector &v2) // Vector Projection
{
    double scalar = dotProduct(v1, v2), magnitude = 0;
    for (int i = 0; i < v1.m_rows; i++)
        magnitude += v1.matrix[i][0] * v1.matrix[i][0];
    if (scalar == 0 && magnitude == 0)
        return 0;
    return scalar / magnitude;
}

Vector Vector::projection(Vector &onto, Vector &project)
{
    return *(vScalar(compSmth(onto, project), onto));
}

Vector* Vector::v_addSub(Vector& v1, Vector& v2, bool sign)
{
    Vector* result = new Vector(v1.get_rows(v1));
    if (!sign)
    {
        for (int i = 0; i < result->get_rows(*result); i++)
        {
            double value = v1.get_mValue(v1, i, 0) - v2.get_mValue(v2, i, 0);
            result->setMatrixValue(*result, i, 0, value);
        }
    }
    else
    {
        for (int i = 0; i < result->get_rows(*result); i++)
        {
            double value = v1.get_mValue(v1, i, 0) + v2.get_mValue(v2, i, 0);
            result->setMatrixValue(*result, i, 0, value);
        }
    }
    return result;
}
