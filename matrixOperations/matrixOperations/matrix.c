/*********************************************
Matrix Operations for SpaceHUAC

Author: Sam Rosa
Date: 9/10/2019

*********************************************/

#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

MATRIX createMatrix()
{
	int i;
	MATRIX matrix;
	//Matrix is assumed 3x3
	matrix = (int**)malloc(sizeof(int*) * 3);

	//Check for error
	if (matrix == NULL)
	{
		return NULL;
	}

	for (i = 0; i < 3; i++)
	{

		matrix[i] = (int*)malloc(sizeof(int) * 3);

		//Check for error
		if (matrix[i] == NULL)
		{

			if (i == 0) //If the first fails just need to free the first part
			{

				free(matrix);
				matrix = NULL;
				return NULL;

			}

			else //If the second or third fails
			{

				for (i; i != 0; i--) //Frees second and third, depending on how far in
				{

					free(matrix[i]);

				}

				free(matrix[i]); //i == 0 at this point
				free(matrix);

				return NULL;

			}

		}

	}

	return (MATRIX)matrix;

}

VECTOR createVector()
{

	int* vector;

	vector = malloc(sizeof(int*) * 3); //If is NULL will return NULL anyways, user must check

	return (VECTOR)vector;

}

void dotProduct(MATRIX a, MATRIX b, MATRIX* result)
{

	int i;
	int j;


	for (i = 0; i < 3; i++) //int i is used as the row
	{

		for (j = 0; j < 3; j++) //int j is used as the column
		{

			(*result)[i][j] = (a[i][0] * b[0][j]) + (a[i][1] * b[1][j]) + (a[i][2] * b[2][j]); //Calculate dot product for ith row jth column

		}

	}

}

void matrixAdd(MATRIX a, MATRIX b, MATRIX* result)
{

	int i;
	int j;
	
	for (i = 0; i < 3; i++)//Row
	{

		for (j = 0; j < 3; j++)//Column
		{

			(*result)[i][j] = a[i][j] + b[i][j];

		}

	}

}

void matrixSubtract(MATRIX a, MATRIX b, MATRIX* result)
{

	int i;
	int j;

	for (i = 0; i < 3; i++)//Row
	{

		for (j = 0; j < 3; j++)//Column
		{

			(*result)[i][j] = a[i][j] - b[i][j];

		}

	}

}

void matrixScalarMultiply(MATRIX a, int b, MATRIX* result)
{

	int i;
	int j;

	for (i = 0; i < 3; i++)//Row
	{

		for (j = 0; j < 3; j++)//Column
		{

			(*result)[i][j] = a[i][j] * b;

		}

	}

}

void crossProduct(VECTOR a, VECTOR b, VECTOR* result)
{

	(*result)[0] = (a[1] * b[2]) - (a[2] * b[1]);
	(*result)[1] = (a[0] * b[2]) - (a[2] * b[0]);
	(*result)[2] = (a[0] * b[1]) - (a[1] * b[0]);

}

void vectorScalarMultiply(VECTOR a, int b, VECTOR* result)
{

	int i;

	for (i = 0; i < 3; i++)
	{

			(*result)[i] = a[i] * b;

	}

}

void matrixDestroy(MATRIX* matrix)
{

	int i;

	for (i = 0; i < 3; i++) //Clean up all the int*'s
	{

			free((*matrix)[i]);

	}

	free(*matrix); //Clean up the last thing

	*matrix = NULL; //Set to null for user

}

void vectorDestroy(VECTOR* vector)
{

	free(*vector);

	*vector = NULL;

}