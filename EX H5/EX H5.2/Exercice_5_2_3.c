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
	/* Exercice 5.2.3.

	Assignment:
	Write a program that asks the user to enter a real number and prints
	whether that number lies in [5,10[ or not ([5,10[ means 5 ? x < 10)
	*/

	printf("\n\t----\tDit is oefening 5.2.3. van 'Cprogrammingfundamentals2020' Pg66\t----\n\n\n\n");

	float Number;
	printf("Please enter a real number :\t");
	scanf("%f%*c",&Number);

	if (5 <= Number && Number < 10)
	{
		printf("\n\nThe Number %.2f lies within the boundary [5,10[\n\n\n",Number);
	}
	else
	{
		printf("\n\nThe Number %.2f does not lie within the boundary [5,10[\n\n\n", Number);
	}

	return 0;

}
