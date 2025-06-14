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
	/* Exercice 4.9

	Assignement:

	Write a program that asks the user to enter the radius of a circle,
	calculates the surface area of that circle and prints the result to the
	screen. (Pi can be approximated as 3.141592653589793. Define Pi as
	a constant in your program).

	*/
	printf("--\tDit is oefening 4.09 van 'Cprogrammingfundamentals2020' Pg51\t--\n\n\n");

	float area_of_circle, radius;
	printf("Please enter a radius number (positive only):\n> ");
	scanf("%f%*c",&radius);
	const float pi = 3.141592653589793;
	area_of_circle = pi * radius * radius;
	printf("\nYour circle has a radius of %.3f and area of %.5f\n\n",radius,area_of_circle);


	return 0;

}
