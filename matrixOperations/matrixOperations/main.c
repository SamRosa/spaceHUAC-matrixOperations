/*********************************************
Matrix Operations for SpaceHUAC

Author: Sam Rosa
Date: 9/10/2019

*********************************************/

#include <stdio.h>
#include "matrix.h"

void matrixPrint(int** matrix);
void printVector(int* vector);

int main()
{

	int** matrix;
	int** matrix2;
	int** result;

	int* vector;
	int* vector2;
	int* vresult;

	int i;
	int j;

	matrix = createMatrix();
	matrix2 = createMatrix();
	result = createMatrix();

	vector = createVector();
	vector2 = createVector();
	vresult = createVector();

	for (i = 0; i < 3; i++) //Row
	{
		for (j = 0; j < 3; j++) //Column
		{

			matrix[i][j] = 0;
			matrix2[i][j] = 0;

		}
	}
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;

	matrix2[0][0] = 3;
	matrix2[1][1] = 3;
	matrix2[2][2] = 3;

	for (i = 0; i < 100000000; i++)
	{
		dotProduct(matrix, matrix2, result);
	}

	matrixPrint(result);

	matrixPrint(result);

	matrixAdd(matrix, matrix2, result);

	matrixPrint(result);

	matrixSubtract(matrix, matrix2, result);

	matrixPrint(result);

	matrixScalarMultiply(matrix, 2, result);

	matrixPrint(result);

	matrixDestroy(&matrix);
	matrixDestroy(&matrix2);
	matrixDestroy(&result);

	for (i = 0; i < 3; i++)
	{

		vector[i] = 1;
		vector2[i] = i;

	}

	crossProduct(vector, vector2, vresult);

	printVector(vresult);

	vectorScalarMultiply(vector, 2, vresult);

	printVector(vresult);

	vectorScalarMultiply(vector2, 2, vresult);

	printVector(vresult);

	vectorAdd(vector, vector2, vresult);

	printVector(vresult);

	vectorSubtract(vector, vector2, vresult);

	printVector(vresult);

	vectorDestroy(&vector);
	vectorDestroy(&vector2);
	vectorDestroy(&vresult);

	return 0;
}

void matrixPrint(int** matrix)
{

	int i;
	int j;

	for (i = 0; i < 3; i++) //Row
	{
		for (j = 0; j < 3; j++) //Column
		{

			printf("%d ", matrix[i][j]);

		}
		printf("\n");
	}
	printf("\n");

}

void printVector(int* vector)
{

	int i;

	for (i = 0; i < 3; i++) //Row
	{

		printf("%d ", vector[i]);

	}
	printf("\n\n");

}
