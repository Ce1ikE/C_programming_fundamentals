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
#define Max 20


/* Function declarations */

void Hello(void);
void Read_Numbers(int[]);
void Cleanup(int[]);

int main(void)
{
	/* Exercice 7.14

	Assignment:
	Write a program with functions:
	- a first function reads 20 numbers and stores them in an array. 
	- a second function makes sure none of the numbers in the array 
	occurs more than once. To this end, the second, third, … occurrence
	of a number is removed from the array and all other array elements
	are shifted to the left.

	*/

	printf("\n\t----\tDit is oefening 7.14 van 'Cprogrammingfundamentals2020' Pg122\t----\n\n\n\n");

	Hello();


	int List_numbers[Max];

	Read_Numbers(List_numbers);

	Cleanup(List_numbers);

	return 0;

}


/* Function definitions */

void Read_Numbers(int x[])
{
	printf("Enter a list of %d numbers:\n", Max);

	for (int i = 0; i < Max; i++)
	{
		scanf("%d%*c", &x[i]);
	}

}


void Cleanup(int x[])
{

	int unique_numbers;
	unique_numbers = 0;
	int i;
	

	
	for (int m = 0; m < Max - unique_numbers; m++) // This loop shifts the comparing gap. EX: 1st com => 0 1  2nd com => 0 2
	{ 
		i = 0;
		while (i + 1 + m < Max - unique_numbers)
		{
			
			if (x[i] == x[i + 1 + m]) // Comparing current to the element, if the two elements are the same we shift all other elements to the left
			{
				for (int t = 0; t + i + 1 < Max - unique_numbers; t++)
				{
				x[i + t] = x[i + 1 + t]; // This 'for' loop takes every element and shifts it to the left

				}
				
				unique_numbers++;
			}
			else // If the two elements are not alike we move on to the next element. EX: 1st com => 0 1  2nd com => 1 2
			{
			i++;
			}
		}
		
	}




	printf("\n\nHere are the unique numbers: \n");

	for (int s = 0; s < Max - unique_numbers; s++)
	{
		printf(" %d", x[s]);
	}

	printf("\n\n\n");
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