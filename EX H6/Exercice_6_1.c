/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

#define	_USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/* Function declarations */

int main(void)
{
	/* Exercice 6.1

	Assignment:
	Write a program that reads an angle in degrees and prints the
	corresponding sine. You can use standard functions.

	*/

	printf("\n\t----\tDit is oefening 6.1 van 'Cprogrammingfundamentals2020' Pg104\t----\n\n\n\n");

	double angle, answer;

	printf("What is the value of the angle:\t");
	scanf("%lf%*c", &angle);

	answer = sin(angle * M_PI / 180);

	printf("The corresponding sinus value of %.1lf degrees is : %.3lf\n\n",angle,answer);

}