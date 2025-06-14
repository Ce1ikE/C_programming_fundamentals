/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis

*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	/* Exercice 4.3

	Assignement:
	Write a program that
	- asks the user to enter 2 integer numbers in one line
	- obtains those 2 numbers using only one call of the function scanf
	- prints both numbers on the next line
	 the screen dialogue should look like:

	Enter 2 integer numbers: 17 7
	The entered numbers are 17 and 7

	*/

	int number1, number2;
	printf("\tDit is oefening 4.03 van 'Cprogrammingfundamentals2020' Pg50\n\n\n");

	printf("Enter 2 integer numbers:\n> ");
	scanf("%d%d%*c",&number1,&number2);
	printf("The entered numbers are %d and %d\n\n\n", number1, number2);
	return 0;
}