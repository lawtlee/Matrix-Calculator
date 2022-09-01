//
//  Utilities.cpp
//  Matrix Calculator
//
//  Created by Lawrence Lee on 6/18/22.
//

#include "Utilities.hpp"
#include <iostream>
using namespace std;
void clearSpace()
{
    cin.ignore(100000,'\n');
    cin.clear();
}

void greeting()
{
    cout << "Welcome to the Matrix Calculator, what calculations would you like to perform?" << endl;
    cout << "1. Matrix Calculations\n2. Vector Calculations\n3. Quit\n\n";
    char choice;
    cin >> choice;
    clearSpace();
    switch (choice) {
        case '1':
            matrixCalculator();
            break;
        case '2':
            vectorCalculator();
            break;
        case '3':
            return;
        default:
            break;
    }
    cout << "Thank you for using this Matrix Calculator!" << endl;
}

void matrixCalculator()
{
    reprompt:
    cout << "What computation would you like to be done?" << endl;
    cout << "1. Reduce Row Echelon Form\n2.Addition\n3.Multiplication\n4.Gram-Schmidt\n5.Orthonormalization\n6.Finding Eigen Values/Vectors\n7.Quit\n\n";
    char choice;
    cin >> choice;
    cin.ignore(10000,'\n');
    cin.clear();
    while (choice < 49 || choice > 55)
    {
        cout << "\n\n";
        cout << "Please enter an acceptable value." << endl;
        cout << "What computation would you like to be done?" << endl;
        cout << "1. Reduce Row Echelon Form\n2. Addition\n3. Multiplication\n4. Gram-Schmidt\n5. Orthonormalization\n6. Finding Eigen Values/Vectors\n7. Quit\n\n";
        cin >> choice;
        cin.ignore(10000,'\n');
        cin.clear();
    }
    switch (choice) {
        case '1':{
            cout << "Sorry this feature has not been added yet.\n\n" << endl;
            break;
        }
        case '2':{
            Matrix* result = addition();
            cout << "\nThe result of these two matrices added is:\n";
            display(*result);
            break;
        }
        case '3':{
            Matrix* result = multiplication();
            cout << "\nThe result of these two matrices multiplied is:\n";
            display(*result);
            break;
        }
        case '4':{
            Matrix* result = gram_Schmidt();
            cout << "\nThe resulting matrix is:\n";
            display(*result);
            break;
        }
        case '5':{
            Matrix* result = orthonormalization();
            cout << "\nThe result of these two matrices multiplied is:\n";
            display(*result);
            break;
        }
        case '6':{
            cout << "Sorry this feature has not been added yet.\n\n" << endl;
            break;
        }
        case '7':
        default:
            break;
    }
}

int moreComp()
{
    cout << "Would you like to make any more computations?" << endl;
    cout << "1. Yes\n2. No\n3. Continue with the answer" << endl;
    char choice;
    cin >> choice;
    cin.ignore(1000,'\n');
    cin.clear();
    while (choice < 49 || choice > 51)
    {
        cout << "\n\n";
        cout << "Please enter an acceptable value." << endl;
        cout << "Would you like to make any more computations?" << endl;
        cout << "1. Yes\n2. No\n3. Continue on using the answer" << endl;
        cin >> choice;
        cin.ignore(1000,'\n');
        cin.clear();
    }
    if (choice == '2')
        return -1;
    else if (choice == '1')
        return 0;
    else
        return 1;
}

Matrix* addition()
{
    int size[2]; //stores the size of the matrices being added
    cout << "Please enter the size of the matrices being by rows x colums (# #): ";
    cin >> size[0] >> size[1];
    cin.ignore(1000,'\n');
    cin.clear();
    Matrix A(size[0], size[1]), B(size[0], size[1]);
    cout << "Please enter the values for the first matrix. ";
    setMatrix(A);
    cout << "\nPlease enter the values for the second matrix. ";
    setMatrix(B);
    return A.m_addition(A, B);
}

Matrix* multiplication()
{
    int size[4];
    do
    {
        cout << "Please enter the size of the first matrix (Matrix A) by rows x colums (# #): ";
        cin >> size[0] >> size[1];
        clearSpace();
        cout << "Please enter the size of the second matrix (Matrix B) by rows x colums (# #): ";
        cin >> size[2] >> size [3];
        clearSpace();
        if (size[1] != size[2])
        {
            cout << "These matrices can not be multiplied against each other because Matrix A's columns do not match Matrix B's rows. Please restart\n\n";
        }
    } while (size[1] != size[2]);
    Matrix A(size[0], size[1]), B(size[2], size[3]);
    cout << "Please enter the values for Matrix A. ";
    setMatrix(A);
    cout << "Please enter the values for Matrix B. ";
    setMatrix(B);
    return A.m_multiplication(A, B);
}

Matrix* gram_Schmidt()
{
    int size[2];
    cout << "Please enter the size of the matrix you want to orthogonalize by rows x colums (# #): ";
    cin >> size[0] >> size[1];
    clearSpace();
    Matrix A(size[0], size[1]);
    setMatrix(A);
    return A.gram_schmidt(A);
}

Matrix* orthonormalization()
{
    int size[2];
    cout << "Please enter the size of the matrix you want to orthogonalize by rows x colums (# #): ";
    cin >> size[0] >> size[1];
    clearSpace();
    Matrix A(size[0], size[1]);
    setMatrix(A);
    return A.orthonormalize(A);
}

void vectorCalculator()
{
    reprompt:
    cout << "What computation would you like to be done?" << endl;
    cout << "1. Addition\n2. Subtraction\n3. Dot Product\n4. Scalar\n5. Magnitude\n6.  Vector Projection\n7. Normalization\n 8. Quit\n\n";
    char choice;
    cin >> choice;
    clearSpace();
    while (choice < 49 || choice > 56)
    {
        cout << "\n\n";
        cout << "Please enter an acceptable value." << endl;
        cout << "What computation would you like to be done?" << endl;
        cout << "1. Addition\n2. Subtraction\n3. Dot Product\n4. Scalar\n5. Magnitude\n6.  Vector Projection\n7. Normalization\n8. Quit\n\n";
        cin >> choice;
        clearSpace();
    }
    switch (choice) {
        case '1':{
            Vector* result = addSub(true);
            cout << "The resulting vector is:\n";
            display(*result);
            break;
        }
        case '2':{
            Vector* result = addSub(false);
            cout << "The resulting vector is:\n";
            display(*result);
            break;
        }
        case '3':{
            dot_Product();
            break;
        }
        case '4':{
            Vector* result = scalar();
            cout << "The resulting vector is:\n";
            display(*result);
            break;
        }
        case '5':{
            magnitude();
            break;
        }
        case '6':{
            Vector result = projection();
            display(result);
            break;
        }
        case '7':{
            int size;
            cout << "Please enter the # of rows for the Vectors: ";
            cin >> size;
            clearSpace();
            Vector A(size);
            cout << "Please enter the values for the vector. ";
            setMatrix(A);
            cout << "The vector normalized is:\n";
            A.normalize(A);
            display(A);
            break;
        }
        case '8':
        default:
            break;
    }
}

Vector* addSub(bool sign)
{
    int size;
    cout << "Please enter the # of rows for the Vectors: ";
    cin >> size;
    Vector A(size), B(size);
    cout << "Please enter the values for the first Vector. ";
    setMatrix(A);
    clearSpace();
    cout << "Please enter the values for the second Vector: ";
    setMatrix(B);
    return A.v_addSub(A, B, sign);
}

void dot_Product()
{
    int size;
    cout << "Please enter the # of rows for the Vectors: ";
    cin >> size;
    Vector A(size), B(size);
    cout << "Please enter the values for the first Vector. ";
    setMatrix(A);
    clearSpace();
    cout << "Please enter the values for the second Vector: ";
    setMatrix(B);
    clearSpace();
    cout << "The dot product between these two vectors is: " << A.dotProduct(A, B) << endl;
}

Vector* scalar()
{
    double size;
    cout << "Please enter the # of rows for the Vectors: ";
    cin >> size;
    clearSpace();
    Vector A(size);
    cout << "Please enter the values for the vector. ";
    setMatrix(A);
    cout << "Please enter the value of the scalar: ";
    cin >> size;
    return A.vScalar(size, A);
}

void magnitude()
{
    int size;
    cout << "Please enter the # of rows for the Vectors: ";
    cin >> size;
    clearSpace();
    Vector A(size);
    cout << "Please enter the values for the vector. ";
    setMatrix(A);
    cout << "The magnitude for the givven vector is: " << A.magnitude(A) << endl;
}

Vector projection()
{
    int size;
    cout << "Please enter the # of rows for the Vectors: ";
    cin >> size;
    Vector A(size), B(size);
    cout << "Vector A will be projected onto Vector B.\n";
    cout << "Please enter the values for Vector A. ";
    setMatrix(A);
    clearSpace();
    cout << "Please enter the values for Vector B. ";
    setMatrix(B);
    clearSpace();
    cout << "The result of projecting Vector A onto B is:\n";
    return A.projection(B, A);
}
