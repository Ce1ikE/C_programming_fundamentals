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
#define LowerBoundary 5

/* Function declarations */

void ReadArray(int[],int);
void Calculate(int[],int,int*,int*,int*);

int main(void)
{
	/* Exercice 17.1

	Assignment:

	Write a program that sums all elements of the matrix diagonals and 
	prints the maximal array element. The matrix dimensions are chosen by the user.
	Use a function readArray to read the content of the matrix and a
	function calculate to calculate the diagonals and the maximum
	number. Printing can be done in the main function.

	*/


	TITLE_EX(17.1, 227);

	Hello(2);

	int Dimension,Sum_D_BL_TR, Sum_D_TL_BR,MaxValue;

	printf("\n\nEnter the dimension of the marix : ");
	scanf("%d%*c",&Dimension);

	int * MemP;
	MemP = (int*)malloc(Dimension*Dimension*sizeof(int)); // => The matrix is a square matrix n x n
	if (MemP == NULL) // Check if "malloc" has failed or not
	{
		COLOR_ON(1);
		printf("\n\n\tMEMORY ALLOCATION FAILED");
		COLOR_OFF();
		exit(-1);
	}

	
	ReadArray(MemP, Dimension);

	Calculate(MemP, Dimension, &Sum_D_BL_TR, &Sum_D_TL_BR, &MaxValue); 
	// The variable Dimension is not going to be altered in the function
	// On the other hand the variables "Sum_D_BL_TR" , "Sum_D_TL_BR" and "MaxValue" are going to be altered so we pass them on as pointers

	printf("The diagonal top left to bottom right sums up to \033[32m%d\033[m\nThe diagonal bottom left to top right sums up to \033[32m%d\033[m",Sum_D_TL_BR,Sum_D_BL_TR);
	printf("\nThe maximum number in the matrix is \033[32m%d\033[m", MaxValue);

	Bye_Message(6,3,7);

	free(MemP);

	return 0;
}

/* Function definitions */

void ReadArray(int * A,int Dimension)
{
	char Answer;

	printf("\n\nDo you want to enter the numbers manually(m) or automatically(a): => ");
	scanf("%c%*c", &Answer);

	while (Answer != 'm' && Answer != 'a')
	{
		printf("\n\n\tERROR INVALID ANSWER\nenter a valid choice\n\nDo you want to enter the numbers manually(m) or automatically(a): => ");
		scanf("%c%*c", &Answer);
	}

	if (Answer == 'm')
	{
		printf("Enter the matrix:\n");

		for (int i = 0; i < Dimension; i++)
		{
			for (int t = 0; t < Dimension; t++)
			{
				scanf("%d%*c", (A + t + i * Dimension)); 
				// The Pointer 'A' points to a address to which we add up some value, in this case 't' and 'i' times dimension,
				// So that we can move through the addresses just like a array has a starting address the pointer acts in the same way only the syntax is different
				


				// Side note:
				// Even 2D arrays and 3D arrays behave in the same way but thanks to a simple trick they can move through the address in such a way that it seems that they different dimension.
				// For example: if 'A' is a 3D array defined as fellows A[2][2][2] then the value assigned to A[0][0][3] == A[1][0][0]  

			}
		}
	}
	else // Answer == 'a'
	{
		printf("\n\nHere is random generated matrix:\n\n");
		srand(time(NULL));

		for (int i = 0; i < Dimension; i++)
		{
			for (int t = 0; t < Dimension; t++)
			{
				if (rand() % 2 == 0) // Negative number
				{
					*(A + t + i * Dimension) = - (rand() % UpperBoundary);
				}
				else // Positive number
				{
					*(A + t + i * Dimension) = (rand() % UpperBoundary);
				}
			}
		}

		for (int i = 0; i < (Dimension * Dimension); i++)
		{
			printf("%4d", *(A + i));

			if ((i + 1) % Dimension == 0)
			{
				printf("\n");
			}
		}
	}

	
}

void Calculate(int * A,int Dimension,int * Sum_D_BL_TR,int * Sum_D_TL_BR,int * MaxValue)
{
	// We can calculate the sum of both diagonales and the max value all at the same time
	*MaxValue = *A;
	*Sum_D_BL_TR = 0;
	*Sum_D_TL_BR = 0;
	for (int i = 0; i < Dimension; i++)
	{
		*Sum_D_BL_TR += *(A + i + (Dimension - 1 - i) * Dimension);
		*Sum_D_TL_BR += *(A + i + i * Dimension);

		for (int t = 0; t < Dimension; t++)
		{
			if (*MaxValue < *(A + t + i * Dimension))
			{
				*MaxValue = *(A + t + i * Dimension);
			}
		}
	}
}



