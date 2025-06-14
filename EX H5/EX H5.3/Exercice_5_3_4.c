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
	/* Exercice 5.3.4.

	Assignment:
	 Write a program that prints a filled square to the screen by printing 
	22 lines of 40 black rectangles (the ASCII code for a black rectangle is 219).


	*/

	printf("\n\t----\tDit is oefening 5.3.4. van 'Cprogrammingfundamentals2020' Pg82\t----\n\n\n\n");


	for (int i = 0; i < 22; i++)
	{
		for (int t = 0; t < 40; t++)
		{
			printf("\xDB");
		}
		printf("\n");
	}

	return 0;


}