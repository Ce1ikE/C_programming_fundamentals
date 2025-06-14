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
	/* Exercice 4.6

	Assignement:

	Write a program that asks the user to enter 2 real numbers, calculates
	the quotient and stores it into a variable of the type float. Print the
	quotient with 20 numbers after the decimal point.

	*/
	printf("--\tDit is oefening 4.06 van 'Cprogrammingfundamentals2020' Pg51\t--\n\n\n");

	float real1, real2,quo;
	printf("Enter 2 real numbers\n> ");
	scanf("%f%f%*c",&real1,&real2);

	quo = real1 / real2;

	printf("The quotient of %4.2f %4.2f is %.20f\n\n\n",real1,real2,quo);



	return 0;
}