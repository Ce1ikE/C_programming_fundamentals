/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Function declarations */

void hello(int);
void sum(int,int);
void goodbye(void);

int main(void)
{
	/* Exercice 6.13

	Assignment:
	Write a program with the functions:
	- hello: that welcomes the user and explains what is expected
	- main: that asks the user to enter 5 times 2 numbers
	- sum: that asks the user to enter the sum of the previously entered
	 numbers and gives feedback to the user
	- goodbye: that thanks the user for his/her cooperation

	*/

	printf("\n\t----\tDit is oefening 6.13 van 'Cprogrammingfundamentals2020' Pg106\t----\n\n\n\n");
	int Number_of_SUMS,NUMBER1 = 0,NUMBER2 = 0;
	
	Number_of_SUMS = 1;

	hello(Number_of_SUMS);
	for (int i = 0; i < Number_of_SUMS; i++)
	{
		printf("\n Enter 2 numbers < 100 : => ");
		scanf("%d%d%*c",&NUMBER1,&NUMBER2);
		while (NUMBER1 > 100 || NUMBER2 > 100)
		{
			printf("\n\n\t ERROR number must be < 100");
			printf("\n Enter 2 numbers < 100 : => ");
			scanf("%d%d%*c",&NUMBER1,&NUMBER2);
		}
		
		sum(NUMBER1, NUMBER2);

	}

	goodbye();

}


/* Function definitions */


void hello(int X)
{
	printf("\n Welcome, this program will ask you to solve %d sums.", X);

}




void sum(int A,int B)
{
	int SUM;
	
	printf("\n What is the sum of %d and %d : =>",A,B);
	scanf("%d%*c",&SUM);
	printf("\n According to you, the sum of %d and %d equals %d", A, B, SUM);

	if (SUM == A + B)
	{
		printf("\n That is correct");
		
	}
	else
	{
		printf("\n That is not correct");
		
	}

}


void goodbye(void)
{
	printf("\n\n");
	for (int i = 0; i < 30; i++)
	{
		printf("-");
	}

	printf("\n-----Thanks for playing-----\n");

	for (int t = 0; t < 30; t++)
	{
		printf("-");
	}

	printf("\n\n\n");
}