/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	/* Exercice 5.2.5.

	Assignment:
	Write a program that asks the user to enter a real number and prints 
	whether that number is positive, zero or negative.


	*/

	printf("\n\t----\tDit is oefening 5.2.5. van 'Cprogrammingfundamentals2020' Pg66\t----\n\n\n\n");


	float Number;
	printf("Please enter a real number: ");
	scanf("%f%*c",&Number);

	if (Number > 0)
	{
		printf("\n\nYour Number is POSITIVE\n\n");
	}
	else 
	{
		if (Number < 0)
		{
			printf("\n\nYour Number is NEGATIVE\n\n");
		}
		else // (Number == 0)
		{
			printf("\n\nYour Number is equal to ZERO\n\n");
		}
		
	}
   

	return 0;

}