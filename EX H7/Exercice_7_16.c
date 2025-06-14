/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>
#define MaxNrARRAY1 6
#define MaxNrARRAY2 6
#define Limit 50


/* Function declarations */

void Hello(void);
void Random_generator1(int[]);
void Random_generator2(int[]);
void CheckForDuplicates(int[], int[]);

int main(void)
{
	/* Exercice 7.16

	Assignment:
	Write a program with functions. A first function reads 2 rows of 
	maximal 10 positive integers. The reading process stops when a 0 or 10 
	integers are entered. (do not store the number 0!)
	A second function checks if both rows contain numbers that are equal.

	*/

	printf("\n\t----\tDit is oefening 7.16 van 'Cprogrammingfundamentals2020' Pg122\t----\n\n\n\n");

	Hello();

	int Array1[MaxNrARRAY1],Array2[MaxNrARRAY2];

	srand(time(NULL));
	Random_generator1(Array1);
	Random_generator2(Array2);

	printf("\n\nARRAY 1: ");
	for (int i = 0; i < MaxNrARRAY1; i++)
	{
		printf(" %2d ", Array1[i]);
	}
	printf("\n\nARRAY 2: ");
	for (int i = 0; i < MaxNrARRAY2; i++)
	{
		printf(" %2d ", Array2[i]);
	}

	CheckForDuplicates(Array1, Array2);

	printf("\n\n\n");

	return 0;
}



void Random_generator1(int x[])
{
	for (int i = 0; i < MaxNrARRAY1; i++)
	{
		x[i] = rand() % Limit;
	}
}


void Random_generator2(int x[])
{
	for (int i = 0; i < MaxNrARRAY2; i++)
	{
		x[i] = rand() % Limit;
	}
}

void CheckForDuplicates(int x[], int y[])
{
	int Duplicate = 0;
	for (int i = 0; i < MaxNrARRAY1; i++)
	{
		for (int t = 0; t < MaxNrARRAY2; t++)
		{
			if (x[i] == y[t])
			{
				Duplicate = 1;
			}
		}
	}

	switch (Duplicate)
	{
	case 0:
		printf("\n\n\tThe arrays contain \033[0;31mNO EQUAL\033[m numbers");
		break;
	case 1:
		printf("\n\n\tThe arrays contain \033[0;32mEQUAL\033[m numbers");
		break;
	default:
		break;
	}
}




void Hello(void)
{
	printf("\n\n");

	printf("\n      \x5F\x5F\x5F\x5F          \x5F\x5F\x5F\x5F           \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F                         ");
	printf("\n     \x2F   \x2F\x5C        \x2F   \x2F\x5C         \x2F   \x2F\x5C      \x2F   \x2F\x5C      \x2F   \x2F\x5C                                       ");
	printf("\n    \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x3A\x5C       \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x3A\x5C                 ");
	printf("\n   \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     ");
	printf("\n  \x2F   \x2F\x3A\x3A\x5C \x5F\x5F\x5F  \x2F   \x2F\x3A\x3A\x5C \x5C\x3A\x5C   \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F  \x5C\x3A\x5C    ");
	printf("\n \x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C  \x2F\x5C\x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C \x5C\x3A\x5C \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F \x5C\x5F\x5F\x5C\x3A\x5C    ");
	printf("\n \x5C\x5F\x5F\x5F\x5C\x2F  \x5C\x3A\x5C\x2F\x3A\x2F\x5C   \x5C\x3A\x5C \x5C\x3A\x5C\x5F\x5C\x2F \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C \x2F  \x2F\x3A\x2F  ");
	printf("\n      \x5C\x5F\x5F\x5F\x5C\x3A\x3A\x2F  \x5C   \x5C\x3A\x5C \x5C\x3A\x5C    \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C  \x2F\x3A\x2F     ");
	printf("\n      \x2F   \x2F\x3A\x2F    \x5C   \x5C\x3A\x5C\x5F\x5C\x2F     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C\x2F\x3A\x2F       ");
	printf("\n     \x2F\x5F\x5F\x5F\x2F\x3A\x2F      \x5C   \x5C\x3A\x5C        \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x3A\x2F                   ");
	printf("\n     \x5C\x5F\x5F\x5F\x5C\x2F        \x5C\x5F\x5F\x5F\x5C\x2F         \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F   ");

	printf("\n\n\n");


}