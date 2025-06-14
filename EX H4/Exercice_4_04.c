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
	/* Exercice 4.4

	Assignement:

	Write a program that asks the user to enter 2 real numbers and prints
	their sum and product to the screen.

	*/

	float real1,real2,sum,Product;

	printf("--\tDit is oefening 4.04 van 'Cprogrammingfundamentals2020' Pg50\t--\n\n\n");
	
	printf("Please enter 2 real numbers:\n> ");
	scanf("%f%f%*c",&real1,&real2);
	sum = real1 + real2;
	Product = real1 * real2;
	printf("The sum of %4.2f and %4.2f is %6.2f\nThe product of %4.2f and %4.2f is %6.2f\n\n",real1,real2,sum,real1,real2,Product);

	return 0;
}