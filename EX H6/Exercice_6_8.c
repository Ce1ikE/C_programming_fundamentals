/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/* Function declarations */

int readnumber(void);

int main(void)
{
	/* Exercice 6.8

	Assignment:
	Write a function that reads an integer number in the interval [0 , 10] 
	and returns that number as function return value. If the number is not 
	in the correct interval, the function needs to ask a new number until a 
	correct value was entered.

	make sure you write the declaration of the function readnumber()
	before the main function and the definition of the function after the main
	function.

	*/

	printf("\n\t----\tDit is oefening 6.8 van 'Cprogrammingfundamentals2020' Pg105\t----\n\n\n\n");

	int number;

	number = readnumber();
	printf("The number read is % d \n", number);
	return 0;

}

/* Function definition */

int readnumber(void)
{
	int X;
	printf("Choose a number : => ");
	scanf("%d%*c",&X);
	while (X < 0 || X > 10)
	{
		printf("\n The entered number is not in the interval [0 ; 10 ] please restrain your choice to this interval");
		printf("\n Choose a number : => ");
		scanf("%d%*c",&X);

	}


	return X;

}
