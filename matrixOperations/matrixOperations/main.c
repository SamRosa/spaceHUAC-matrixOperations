/*********************************************
Matrix Operations for SpaceHUAC

Author: Sam Rosa
Date: 9/10/2019

*********************************************/

#include <stdio.h>
#include "matrix.h"

void matrixPrint(int** matrix);

int main()
{

	int** matrix;
	int** matrix2;
	int** result;
	int i;
	int j;
	matrix = createMatrix();
	matrix2 = createMatrix();
	result = createMatrix();

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

	matrixScalarMultiply(matrix, 2, &result);

	matrixPrint(result);

	scanf_s("");

	matrixDestroy(&matrix);

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

}
