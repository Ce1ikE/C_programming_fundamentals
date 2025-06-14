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
	/* Exercice 5.3.1.

	Assignment:
	Write a program with only 1 variable, that prints the numbers -3, -1, 
	1, 3, 5, …, 25, comma separated to the screen. Nothing needs to be 
	read from the keyboard.

	*/

	printf("\n\t----\tDit is oefening 5.3.1. van 'Cprogrammingfundamentals2020' Pg82\t----\n\n\n\n");

	printf("Just watch\n\n");

		for (int i = -3; i <= 25; i += 2)
		{
		printf("%d,",i);
		}

		printf("\n\n\n\n");

}