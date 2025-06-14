/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Macro's */

#define MAX2(a,b)		(a > b ? a : b)
#define MAX3(a,b,c)		(MAX2(MAX2(a,b),c))
#define MAX4(a,b,c,d)	(MAX2(MAX3(a,b,c),d))
#define MAX5(a,b,c,d,e) (MAX2(MAX4(a,b,c,d),e))

#define TOUPPER(a)		(a < 123 && a > 96 ? a = a - 32 : a )
#define TOLOWER(a)		(a < 91 && a > 64 ? a = a + 32 : a )
#define IS_CAPITAL(a)	(a < 91 && a > 64 ?  1  : 0)
#define IS_SMALL(a)		(a < 123 && a > 96 ?  1  : 0)
#define IS_LETTER(a)	(IS_SMALL(a) ? 1 : IS_CAPITAL(a))

/* Headers */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#define Max_numbers 40
#define Max_Generate 25 // actual range is 50 [-25 , 25] since we take also negative values later on. 

/* Function declarations */

void Hello(void);
void Bye_Message(void);
void Fill_Array(int[]);
int Sort(int[]);
void Print_Array(int[],int);

int main(void)
{
	/* Exercice 10.2

	Assignment:

	Bubble sort is another method used to order arrays. It is an 
	algorithm that repeatedly steps through the list to be sorted. In each 
	pass, each pair of adjacent items is compared and swapped if they 
	are in the wrong order. If, for instance, ordering from smallest to 
	largest is needed, the biggest element will end up at the end of the 
	list after the first pass. The algorithm, is named for the way bigger
	elements "bubble" to the end of the list. The next pass can stop a bit 
	sooner (the last element is already in place). 
	
	How many passes are needed? Can you stop sooner? 

	Write a program, with functions, that orders a list of numbers using 
	the bubble sort method.

	*/

	printf("\n\t----\tDit is oefening 10.2 van 'Cprogrammingfundamentals2020' Pg150\t----\n\n\n\n");

	Hello();

	int Array[Max_numbers],SWAP_Counter;

	Fill_Array(Array);

	SWAP_Counter = Sort(Array);

	Print_Array(Array,SWAP_Counter);

	Bye_Message();


	return 0;
}

/* Function definitions */

void Fill_Array(int A[])
{
	char Answer;
	printf("Do you want to enter the numbers Manually(m) or automatically(a)? => ");
	scanf("%c%*c", &Answer);

	while (Answer != 'm' && Answer != 'a')
	{
		printf("\n\n\tERROR\n\nDo you want to enter the numbers Manually(m) or automatically(a)? => ");
		scanf("%c%*c", &Answer);
	}

	if (Answer == 'm')
	{
		for (int i = 0; i < Max_numbers; i++)
		{
			printf("\nEnter Nr. %d :", i + 1);
			scanf("%d%*c", &A[i]);
			while (!(-32768 < A[i] < 32767)) // We control if the entered value is a int type with the operator '!' and the range of a short int ]-32768 , 32767[ (Excluded = ][ )
			{
				printf("\n\n\tERROR\t%d number NOT INTEGER TYPE\n\nEnter Nr. %d :", i + 1, i + 1);
				scanf("%d%*c", &A[i]);

			}

		}

		printf("\nHere is your array:\n");
		int Counter = 0;
		for (int t = 0; t < Max_numbers; t++)
		{
			printf("%3d ", A[t]);
			Counter++;
			if (Counter == 10)
			{
				printf("\n"); // Prints just a newline to keep things clean
				Counter = 0;
			}		
		}

		
	}
	else
	{
		srand(time(NULL));

		printf("\n\nOkay i will generate %d numbers in the interval [%d,%d[\nHere is your array:\n", Max_numbers,-Max_Generate, Max_Generate);
		int Counter = 0;
		for (int i = 0; i < Max_numbers; i++)
		{
			if (rand() % 2 == 0) // Generate Positive
			{
				A[i] = rand() % Max_Generate + 1;
				printf("%3d ", A[i]);

				Counter++;
				if (Counter == 10)
				{
					printf("\n"); // Prints just a newline to keep things clean
					Counter = 0;
				}
			}
			else // Generate Negative
			{
				A[i] = -rand() % Max_Generate + 1;
				printf("%3d ", A[i]);

				Counter++;
				if (Counter == 10)
				{
					printf("\n"); // Prints just a newline to keep things clean
					Counter = 0;
				}
			}


		}
		
	}

}


int Sort(int A[])
{
	int Swap_Counter = 0;
	for (int i = 0; i < Max_numbers - 1; i++)
	{
		for (int t = 0; t < Max_numbers - 1 - i; t++)
		{
			if (A[t] > A[t + 1])
			{

				int Help = A[t];
				A[t] = A[t + 1];
				A[t + 1] = Help;
				Swap_Counter++;
			}
		}

	}


	return Swap_Counter;
}


void Print_Array(int A[],int SWAPS)
{
	printf("\n\n\nHere is the sorted array:\n");
	int Counter = 0;
	for (int i = 0; i < Max_numbers; i++)
	{
		printf("%3d ",A[i]);

		Counter++;
		if (Counter == 10)
		{
			printf("\n"); // Prints just a newline to keep things clean
			Counter = 0;
		}
	}
	
	printf("\n\n SWAPS NEEDED : %d", SWAPS);

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