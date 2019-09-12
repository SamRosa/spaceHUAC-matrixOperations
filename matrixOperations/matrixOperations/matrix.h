/*********************************************
Matrix Operations for SpaceHUAC

Author: Sam Rosa
Date: 9/10/2019

*********************************************/
#ifndef MATRIX_H
#define MATRIX_H

#define MATRIX int**
#define VECTOR int*

/**********************
Creates a matrix 'object' 
pointer to be used in operations
a matrix being a int**
**********************/
MATRIX createMatrix();

/**********************
Creates a vector 'object'
pointer to be used in operations
a vector being a int*
**********************/
VECTOR createVector();

/**********************
Calculates the dot product of
two matrices and copies the 
result into a matrix
**********************/
void dotProduct(MATRIX a, MATRIX b, MATRIX* result);

/**********************
Calculates the sum of
two matrices and copies the 
result into a matrix
**********************/
void matrixAdd(MATRIX a, MATRIX b, MATRIX* result);

/**********************
Calculates the difference of
two matrices and copies the 
result into a matrix
**********************/
void matrixSubtract(MATRIX a, MATRIX b, MATRIX* result);

/**********************
Calculates the product of
a scalar and a matrix and
copies the result into a matrix
**********************/
void matrixScalarMultiply(MATRIX a, int b, MATRIX* result);

/**********************
Calculates the cross product of
two vector matrices and copies
the result into a vector
**********************/
void crossProduct(VECTOR a, VECTOR b, VECTOR* result);

/**********************
Calculates the product of
a scalar and a vector and
copies the result into a vector
**********************/
void vectorScalarMultiply(VECTOR a, int b, VECTOR* result);

/**********************
Destroys a matrix object and
sets value to NULL
**********************/
void matrixDestroy(MATRIX* matrix);

/**********************
Destroys a vector object and
sets value to NULL
**********************/
void vectorDestroy(VECTOR* vector);

#endif