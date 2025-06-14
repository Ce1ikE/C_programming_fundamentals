/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#include "MyHeaderEC.h"
#define UpperBoundary 30

/* Function declarations */

void CreateMatrix(int*, int,int);

int main(void)
{
	/* Exercice 17.2

	Assignment:

	Write a program that asks the user to enter the wanted number of 
	rows and columns, creates the matrix dynamically, fills it and prints the 
	content. Use a separate function to fill the matrix and one to print the 
	matrix. Fill every matrix element with (row+1)*(column + 1)

	*/

	TITLE_EX(17.2,227);

	Hello(2);

	int Rows, Columns;

	printf("Enter the number of rows and columns for the matrix: => ");
	scanf("%d%d%*c", &Rows, &Columns);

	int* MemP = (int*)malloc((Rows) * (Columns) * sizeof(int)); // "MemP" stands for memory pointer
	if (MemP == NULL) // Check if "malloc" has failed or not
	{
		COLOR_ON(1);
		printf("\n\n\tMEMORY ALLOCATION FAILED");
		COLOR_OFF();
		exit(-1);
	}

	CreateMatrix(MemP, Rows, Columns);

	Bye_Message(6,3,7);

	free(MemP);

	return 0;
}

/* Function definitions */

void CreateMatrix(int * A, int Rows, int Columns)
{
	srand(time(NULL));
	for (int i = 0; i < Rows; i++)
	{
		for (int t = 0; t < Columns; t++)
		{
			if (rand() % 2 == 0) // Negative
			{
				*(A + t + i * Columns) = -(rand() % UpperBoundary);
			}
			else // Positive
			{
				*(A + t + i * Columns) = (rand() % UpperBoundary);
			}
		}
	}
	printf("\n\n\nHere is the matrix: \n");
	for (int i = 0; i < (Rows * Columns); i++)
	{
		printf("%4d", *(A + i));

		if ((i + 1) % Columns == 0)
		{
			printf("\n");
		}
	}
}
