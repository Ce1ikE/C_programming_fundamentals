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
#include <string.h>
#define Max_Rows 10
#define Max_Colums 10

/* Function declarations */

void Hello(void);
int  ReadDimension(void);
void ReadRow(int[][Max_Colums],int);
void TransposeMatrix(int[][Max_Colums],int, int[][Max_Rows]);
void PrintMatrix(int[][Max_Colums],int, int[][Max_Rows]);
void Bye_Message(void);


int main(void)
{
	/* Exercice 9.4

	Assignment:
	Write a program that reads a square matrix, calculates its transpose 
	and prints both the original and the transposed matrix. The matrix 
	cannot be larger than 10 x 10. The wanted dimension is read at the 
	start of the program. Reading the dimension, reading the matrix 
	elements, transposing the matrix and printing the matrix is done in 4 
	different functions.


	*/

	printf("\n\t----\tDit is oefening 9.4 van 'Cprogrammingfundamentals2020' Pg139\t----\n\n\n\n");

	Hello();

	int Dimension;

	Dimension = ReadDimension();

	int Matrix[Max_Rows][Max_Colums],Transpose_Matrix[Max_Colums][Max_Rows];

	ReadRow(Matrix,Dimension);

	TransposeMatrix(Matrix, Dimension,Transpose_Matrix);

	PrintMatrix(Matrix, Dimension,Transpose_Matrix);

	Bye_Message();


	return 0;
}




int  ReadDimension(void)
{

	int D;

	printf("What dimension should the matrix be? : => ");
	scanf("%d%*c", &D);

	while (D < 2 || D > 10)
	{
		printf("\n Dimension incorrect. Please restrain yourself to the interval [2 ; 10]"); 
		printf("\n What dimension should the matrix be? : => ");
		scanf("%d%*c", &D);
	}

	return D;
}



void ReadRow(int M[][Max_Colums], int D)
{

	char Answer;

	printf("\n Do you want to enter the integers of the matrix (y/n) : => ");
	scanf("%c%*c", &Answer);

	while (Answer != 'y' && Answer != 'n')
	{
		printf("\n\n\t ANSWER INVALID \n Please answer the question.");
		printf("\n Do you want to enter the integers of the matrix (y/n) : => ");
		scanf("%c%*c", &Answer);
	}

	if (Answer == 'y')
	{
		printf("\n\n Enter %d x %d Integers:\n",D,D);

		for (int i = 0; i < D; i++)
		{
			for (int t = 0; t < D; t++)
			{

				scanf("%d%*c", M[i][t]);


			}
		}
	}




	if (Answer == 'n')
	{
		printf("\n\n Alright then i will generate a Matrix of dimension %d with numbers from 0 to 20",D);

		srand(time(NULL));

		for (int i = 0; i < D; i++)
		{
			for (int t = 0; t < D; t++)
			{

				M[i][t] = rand() % 20 + 1;


			}
		}

		

	}

}


void TransposeMatrix(int M[][Max_Colums], int D, int TM[][Max_Rows])
{
	/*
		In linear algebra, the transpose of a matrix is an operator which flips a matrix over its diagonal.
		that is, it switches the row and column indices of the matrix
	
		Example:

		| a  b  c |      | a  d  g |
		| d  e  f |   =  | b  e  h |
		| g  h  i |      | c  f  i |
	
	*/

	for (int i = 0; i < D; i++)
	{
		for (int t = 0; t < D; t++)
		{

			TM[t][i] = M[i][t];


		}

	}


	

}


void PrintMatrix(int M[][Max_Colums], int D, int TM[][Max_Rows])
{
	printf("\n Here is the Matrix:\n");
	for (int i = 0; i < D; i++)
	{
		for (int t = 0; t < D; t++)
		{

			printf(" %2d |", M[i][t]);


		}
		printf("\n");
	}

	printf("\n Here is the transposed Matrix:\n");
	for (int i = 0; i < D; i++)
	{
		for (int t = 0; t < D; t++)
		{

			printf(" %2d |", TM[i][t]);


		}
		printf("\n");
	}
}















void Hello(void)
{

	printf("\n\n");

	printf("\n\t      \x5F\x5F\x5F\x5F          \x5F\x5F\x5F\x5F           \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F                         ");
	printf("\n\t     \x2F   \x2F\x5C        \x2F   \x2F\x5C         \x2F   \x2F\x5C      \x2F   \x2F\x5C      \x2F   \x2F\x5C                                       ");
	printf("\n\t    \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x3A\x5C       \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x3A\x5C                 ");
	printf("\n\t   \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     ");
	printf("\n\t  \x2F   \x2F\x3A\x3A\x5C \x5F\x5F\x5F  \x2F   \x2F\x3A\x3A\x5C \x5C\x3A\x5C   \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F  \x5C\x3A\x5C    ");
	printf("\n\t \x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C  \x2F\x5C\x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C \x5C\x3A\x5C \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F \x5C\x5F\x5F\x5C\x3A\x5C    ");
	printf("\n\t \x5C\x5F\x5F\x5F\x5C\x2F  \x5C\x3A\x5C\x2F\x3A\x2F\x5C   \x5C\x3A\x5C \x5C\x3A\x5C\x5F\x5C\x2F \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C \x2F  \x2F\x3A\x2F  ");
	printf("\n\t      \x5C\x5F\x5F\x5F\x5C\x3A\x3A\x2F  \x5C   \x5C\x3A\x5C \x5C\x3A\x5C    \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C  \x2F\x3A\x2F     ");
	printf("\n\t      \x2F   \x2F\x3A\x2F    \x5C   \x5C\x3A\x5C\x5F\x5C\x2F     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C\x2F\x3A\x2F       ");
	printf("\n\t     \x2F\x5F\x5F\x5F\x2F\x3A\x2F      \x5C   \x5C\x3A\x5C        \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x3A\x2F                   ");
	printf("\n\t     \x5C\x5F\x5F\x5F\x5C\x2F        \x5C\x5F\x5F\x5F\x5C\x2F         \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F   ");

	printf("\n\n\n");


}



void Bye_Message(void)
{

	printf("\n\n");

	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDF\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDC\xDB\xDB\xDC\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xDC\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDF\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

	printf("\n\n\n");

}