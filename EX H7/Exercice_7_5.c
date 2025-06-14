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
#define Size 15
#define Columns 3

/* Function declarations */

void Hello(void);
void Read_Array(int[], int);
void Print_Matrix(int[], int, int);

int main(void)
{
	/* Exercice 7.5

	Assignment:
	Write a program with following main function:

	- The function ReadArray reads 12 (SIZE) numbers and stores them in
	the one dimensional array a
	- The function PrintMatrix prints the 12 numbers on 4 lines of 3
	(COLUMNS) numbers each
	By adapting only SIZE and COLUMNS the program must also be able to
	print for instance 20 numbers in a 5 x 4 matrix

	*/

	printf("\n\t----\tDit is oefening 7.5 van 'Cprogrammingfundamentals2020' Pg120\t----\n\n\n\n");

	Hello();

	int Matrix[Size];

	Read_Array(Matrix, Size);
	
	Print_Matrix(Matrix, Size, Columns);
	
	printf("\n\n");

	return 0;
}




void Read_Array(int x[], int S)
{
	char Answer;

	printf("\n do you want to enter matrix Numbers ? (Y/N) : => ");
	scanf("%c%*c", &Answer);

	while (Answer == "y" || Answer == "n")
	{
		printf("\n Answer not correct. \n Please do you want to enter matrix Numbers ? (Y/N) : ");
		scanf("%c%*c", &Answer);
	}


	if (Answer == 'y')
	{
		printf("\n Please enter numbers : =>");

		for (int i = 0; i < S; i++)
		{
			scanf("%d%*c",x[i]);
		}
	}

	printf("\n Then i will generate random numbers between [1 ; 100]");

	if (Answer == 'n')
	{
		srand(time(NULL));
		int Help_var;

		for (int t = 0; t < S; t++)
		{
			Help_var = rand()%100 + 1;
			x[t] = Help_var;
		}

	}


}


void Print_Matrix(int x[], int S, int C)
{
	printf("\n\n Here is the matrix : \n\n");

	for (int i = 0; i < S/C; i++)
	{
		for (int t = 0; t < C; t++)
		{
			printf("%d \t",x[t + i]);
		}
		
		printf("\n\n");
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