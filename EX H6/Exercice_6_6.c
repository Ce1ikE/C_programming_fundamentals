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


float Y_value_cal(float);

int main(void)
{
	/* Exercice 6.6

	Assignment:
	Write a program that prints a table with 2 columns. The first column 
	contains x values from -5 till +5 with a step of 0.5. The second column 
	contains the corresponding y values according to the equation

	y = 2*x*x +2*x - 3
	Make sure the calculation of the y values is done in a separate function.
	*/

	printf("\n\t----\tDit is oefening 6.6 van 'Cprogrammingfundamentals2020' Pg104\t----\n\n\n\n");

	float X, Y;
	
	X = -5;

	printf("  X value  |  Y value  \n");
	printf("-----------------------\n");

	for (int i = 0; i < 21; i++)
	{
		Y = Y_value_cal(X);

		printf("  %7.2f  |  %7.2f  \n", X, Y);

		X = X + 0.5;
	}
	printf("\n\n\n");
	return 0;
}


/* Function definition */


float Y_value_cal(float X)
{
	

	float Y = ((2 * X * X) + (2 * X) - 3);

	return Y;
}