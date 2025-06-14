/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define Max_Rows 10
#define Max_Columns 10
#define Max_number 500

/* Function declarations */

void Hello(void);
void Bye_Message(void);
void Fill_Matrix(int[][Max_Columns]);
void Swap_min_MAX(int[][Max_Columns]);
void Print_Matrix(int[][Max_Columns]);


int main(void)
{
	/* Exercice 9.5

	Assignment:

	Write a program with functions that:
	- declares an array with dimensions 10 x 10 in the main
	- uses a function to read the array elements
	- uses a function to find the min and max element in the array and
	swaps them (inside the array, using an auxiliary variable is allowed)
	- uses a function to print the array after swapping

	*/

	printf("\n\t----\tDit is oefening 9.5 van 'Cprogrammingfundamentals2020' Pg139\t----\n\n\n\n");

	Hello();

	int Matrix[Max_Rows][Max_Columns];

	Fill_Matrix(Matrix);

	Swap_min_MAX(Matrix);

	Print_Matrix(Matrix);

	Bye_Message();


	return 0;
}

/* Function definitions */

void Fill_Matrix(int M[][Max_Columns])
{
	char Answer;
	printf("\nDo you want to enter the value Manually(m) or Automatically(a): ");
	scanf("%c%*c",&Answer);

	while (Answer != 'm' && Answer != 'a')
	{
		printf("\n\n\tERROR\nDo you want to enter the value Manually(m) or Automatically(a): ");
		scanf("%c%*c", &Answer);
	}

	if (Answer == 'm')
	{
		for (int i = 0; i < Max_Rows; i++)
		{
			for (int t = 0; t < Max_Columns; t++)
			{
			
				scanf("%d%*c", &M[i][t]);

				while (!(-2147483647 < M[i][t] < 2147483647))
				{
					printf("\nEnter a integer please : ");
					scanf("%d%*c", &M[i][t]);
				}
			
			}
		}

		printf("   ");
		for (int i = 0; i < Max_Columns; i++)
		{
			printf("%3d ", i + 1);
		}
		printf("\n   ---------------------------------------\n");
		for (int i = 0; i < Max_Rows; i++)
		{
			printf("%2d|", i + 1);
			for (int t = 0; t < Max_Columns; t++)
			{
				printf("%3d ", M[i][t]);
			}
			printf("\n");
		}


	}
	else // If Answer is 'a'
	{
		srand(time(NULL));

		for (int i = 0; i < Max_Rows; i++)
		{
			for (int t = 0; t < Max_Columns; t++)
			{
				if (rand() % 2 == 0) // Positive number
				{
					M[i][t] = rand() % Max_number;
				}
				else // Negative number
				{
					M[i][t] = rand() % Max_number;
				}

			}

		}

		printf("   ");
		for (int i = 0; i < Max_Columns; i++)
		{
			printf("%3d ", i + 1);
		}
		printf("\n   ---------------------------------------\n");
		for (int i = 0; i < Max_Rows; i++)
		{
			printf("%2d|", i + 1);
			for (int t = 0; t < Max_Columns; t++)
			{
				printf("%3d ", M[i][t]);
			}
			printf("\n");
		}

	}


}


void Swap_min_MAX(int M[][Max_Columns])
{

	int min_row = 0, min_column = 0, MAX_row = 0, MAX_column = 0; // We need to recover the index of both row and column of the minimum value and the maximum 

	for (int i = 0; i < Max_Rows; i++)
	{
		for (int t = 0; t < Max_Columns; t++)
		{

			if (M[min_row][min_column] > M[i][t]) // min value
			{
				min_row = i;
				min_column = t;
			}

			if (M[MAX_row][MAX_column] < M[i][t]) // MAX value
			{
				MAX_row = i;
				MAX_column = t;
			}

		}
	}

	printf("\n\nMIN VALUE IN ROW: %d COLUMN: %d	MAX VALUE IN ROW: %d COLUMN: %d",min_row + 1,min_column + 1,MAX_row + 1,MAX_column + 1);

	int Help = M[min_row][min_column];
	M[min_row][min_column] = M[MAX_row][MAX_column];
	M[MAX_row][MAX_column] = Help;

	printf("\n\nAFTER SWAP\n\nMIN VALUE IN ROW: %d COLUMN: %d	MAX VALUE IN ROW: %d COLUMN: %d", MAX_row + 1, MAX_column + 1,min_row + 1, min_column + 1);


}

void Print_Matrix(int M[][Max_Columns])
{

	printf("\n\nHere is the matrix with the minimum and maximum swapped :\n\n   ");

	for (int i = 0; i < Max_Columns; i++)
	{
		printf("%3d ", i + 1);
	}
	printf("\n   ---------------------------------------\n");
	for (int i = 0; i < Max_Rows; i++)
	{
		printf("%2d|", i + 1);
		for (int t = 0; t < Max_Columns; t++)
		{
			printf("%3d ",M[i][t]);
		}
		printf("\n");
	}



}


void Hello(void)
{

	printf("\n\n\033[0;32m");

	printf("\n\t\t      \x5F\x5F\x5F\x5F          \x5F\x5F\x5F\x5F           \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F                ");
	printf("\n\t\t     \x2F   \x2F\x5C        \x2F   \x2F\x5C         \x2F   \x2F\x5C      \x2F   \x2F\x5C      \x2F   \x2F\x5C                                       ");
	printf("\n\t\t    \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x3A\x5C       \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x3A\x5C                 ");
	printf("\n\t\t   \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     ");
	printf("\n\t\t  \x2F   \x2F\x3A\x3A\x5C \x5F\x5F\x5F  \x2F   \x2F\x3A\x3A\x5C \x5C\x3A\x5C   \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F  \x5C\x3A\x5C    ");
	printf("\n\t\t \x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C  \x2F\x5C\x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C \x5C\x3A\x5C \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F \x5C\x5F\x5F\x5C\x3A\x5C    ");
	printf("\n\t\t \x5C\x5F\x5F\x5F\x5C\x2F  \x5C\x3A\x5C\x2F\x3A\x2F\x5C   \x5C\x3A\x5C \x5C\x3A\x5C\x5F\x5C\x2F \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C \x2F  \x2F\x3A\x2F  ");
	printf("\n\t\t      \x5C\x5F\x5F\x5F\x5C\x3A\x3A\x2F  \x5C   \x5C\x3A\x5C \x5C\x3A\x5C    \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C  \x2F\x3A\x2F     ");
	printf("\n\t\t      \x2F   \x2F\x3A\x2F    \x5C   \x5C\x3A\x5C\x5F\x5C\x2F     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C\x2F\x3A\x2F       ");
	printf("\n\t\t     \x2F\x5F\x5F\x5F\x2F\x3A\x2F      \x5C   \x5C\x3A\x5C        \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x3A\x2F                   ");
	printf("\n\t\t     \x5C\x5F\x5F\x5F\x5C\x2F        \x5C\x5F\x5F\x5F\x5C\x2F         \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F   ");

	printf("\n\n\n\033[0m");

}


void Bye_Message(void)
{
	for (int c = 6, t = 7, s = 3; c <= 6; c++)
	{
		printf("\033[%d;%d%dm", t, s, c);
		printf("\n\n");

		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDC\xDB\xDB\xDC\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xDC\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDF\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");

		printf("\n\n\n");
		printf("\033[0m");
	}
}