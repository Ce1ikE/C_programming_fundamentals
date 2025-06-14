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
	/* Exercice 5.3.6.

	Assignment:
	Write a program that asks the user to enter an integer number in the 
	interval [-2, 4.5[ (i.e. -2 ≤ number < 4.5) and prints it to the screen. 
	If a wrong number is entered, a new number must be requested until 
	a valid number is entered.


	*/

	printf("\n\t----\tDit is oefening 5.3.6. van 'Cprogrammingfundamentals2020' Pg82\t----\n\n\n\n");

	float NUMBER;

	printf("Please Enter a number between [-2 , 4.5[ => ");
	scanf("%f%*c", &NUMBER);
	while (NUMBER < -2 || 4.5 <= NUMBER )
	{
		printf("\n\n\t\tERROR\n\n");
		printf("Please Enter a number between -2 and 4.5 (4.5 excluded) => ");
		scanf("%f%*c", &NUMBER);
	}

	printf("\nYour number : %.0f\n\n\n",NUMBER);

}