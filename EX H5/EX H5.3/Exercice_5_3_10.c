/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

int main(void)
{
	/* Exercice 5.3.10.

	Assignment:
	Write a program that reads a natural number n, calculates n! 
	and prints the result to the screen.


	*/

	printf("\n\t----\tDit is oefening 5.3.10. van 'Cprogrammingfundamentals2020' Pg83\t----\n\n\n\n");

	int NUMBER_n, Factorial;
	Factorial = 1;

	printf("Please enter a NATURAL number : \t => ");
	scanf("%d%*c",&NUMBER_n);

	while (NUMBER_n < 0)
	{
		printf("\n NUMBER INVALID \n");

		printf("Please enter a NATURAL number [0,+inf[ : \t => ");
		scanf("%d%*c", &NUMBER_n);

	}



	if (NUMBER_n == 0)
	{
		printf("\n %d! = %d \n\n\n",NUMBER_n, Factorial);
	}
	else
	{


		for (int i = 1; i < NUMBER_n; i++)
		{
			
			Factorial = Factorial * (i + 1);
		}


		printf("\n %d! = %d \n\n\n",NUMBER_n, Factorial);
	}

	

}