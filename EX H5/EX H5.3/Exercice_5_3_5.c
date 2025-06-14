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
	/* Exercice 5.3.5.

	Assignment:
	Write a program that first asks the user to enter an integer number. 
	Afterwards more integers are asked until the sum of those integers 
	equals or exceeds the first number entered.

	*/

	printf("\n\t----\tDit is oefening 5.3.5. van 'Cprogrammingfundamentals2020' Pg82\t----\n\n\n\n");

	int NUMBER,SUM,number_2;
	SUM = 0;
	printf("Please enter a integer:");
	scanf("%d%*c", &NUMBER);

	
	while (NUMBER < 0)
	{
		printf("\n\n The Number must be positive");
		printf("\nPlease enter a integer:");
		scanf("%d%*c", &NUMBER);
	}

	printf("\n\nThe Number %d is the limit\n", NUMBER);
	while (SUM < NUMBER)
	{
		printf("\nEnter a Number:");
		scanf("%d%*c",&number_2);
		SUM += number_2;
	}
	
	printf("\n\n YOU HAVE REACHED OR EXCEEDED THE LIMIT \n\n\n");
	return 0;
}