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
#include <math.h>
#define Max_numbers 10
#define Max_generate 100

/* Function declarations */

void Hello(void);
void Bye_Message(void);
void Fill_Array(int[]);
void Swap_min_MAX(int[]);
void Print_Array(int[]);


int main(void)
{
	/* Exercice 10.1

	Assignment:

	Write a program with functions.

	- In the main function, an array of 10 integers is declared.
		
	- A first function reads the 10 integers and stores them in the
	array.
		
	- A second function swaps the first integer with the min value
	present in the array.Swapping must be done in the same
	array, without using a second array.Using an extra auxiliary
	variable is allowed.All other numbers need to stay in their
	original places.
		
	- A third function prints the array after swapping.

	*/

	printf("\n\t----\tDit is oefening 10.1 van 'Cprogrammingfundamentals2020' Pg149\t----\n\n\n\n");

	Hello();

	int Numbers[Max_numbers];
	
	Fill_Array(Numbers);

	Swap_min_MAX(Numbers);

	Print_Array(Numbers);

	Bye_Message();


	return 0;
}

/* Function definitions */

void Fill_Array(int A[])
{
	char Answer;
	printf("Do you want to enter the numbers Manually(m) or automatically(a)? => ");
	scanf("%c%*c",&Answer);

	while (Answer != 'm' && Answer != 'a')
	{
		printf("\n\n\tERROR\n\nDo you want to enter the numbers Manually(m) or automatically(a)? => ");
		scanf("%c%*c", &Answer);
	}

	if (Answer == 'm')
	{
		for (int i = 0; i < Max_numbers; i++)
		{
			printf("\nEnter Nr. %d :",i + 1);
			scanf("%d%*c", &A[i]);
			while (!(-32768 < A[i] < 32767)) // We control if the entered value is a int type with the operator '!' and the range of a short int ]-32768 , 32767[ (Excluded = ][ )
			{
				printf("\n\n\tERROR\t%d number NOT INTEGER TYPE\n\nEnter Nr. %d :", i + 1, i + 1);
				scanf("%d%*c", &A[i]);

			}

		}

		printf("\nHere is your array:\n[ ");

		for (int t = 0; t < Max_numbers; t++)
		{
			printf("%2d ", A[t]);
		}

		printf("]");
	}
	else
	{
		srand(time(NULL));

		printf("\n\nOkay i will generate %d numbers in the interval [%d,%d[\nHere is your array:\n[ ",Max_numbers,-Max_generate,Max_generate);

		for (int i = 0; i < Max_numbers; i++)
		{
			if (rand()%2==0) // Generate Positive
			{
				A[i] = rand() % Max_generate + 1;
				printf("%2d ", A[i]);
			}
			else // Generate Negative
			{
				A[i] = -rand() % Max_generate + 1;
				printf("%2d ", A[i]);
			}
			

		}
		printf("]");
	}



}

void Swap_min_MAX(int A[])
{
	int min = 0, MAX = 0;

	for (int i = 0; i < Max_numbers; i++) // Checking the MAX and min values's indexes to see where they are in the array
	{
		if (A[min] > A[i])
		{
			min = i;
		}

		if (A[MAX] < A[i])
		{
			MAX = i;
		}
	}

	int Help; // We make use of a help variable to store one of the two values in order to swap

	Help = A[min];
	A[min] = A[MAX];
	A[MAX] = Help;


}

void Print_Array(int A[])
{

	printf("\n\nHere is the array after the swap of the min value and MAX value:\n[ ");

	for (int i = 0; i < Max_numbers; i++)
	{
		printf("%2d ", A[i]);
	}
	printf("]");

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