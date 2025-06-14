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

double exponentiation(double, int);

int main(void)
{
	/* Exercice 6.10

	Assignment:
	Write a function with header:
	double exponentiation(double base, int exponent)
	that returns 𝑏𝑎𝑠𝑒
	𝑒𝑥𝑝𝑜𝑛𝑒𝑛𝑡 as function return value.
	Write a main function that reads a base and exponent, that calls the
	function exponentiation and that prints the result. Do not use the
	standard function pow!

	*/

	printf("\n\t----\tDit is oefening 6.10 van 'Cprogrammingfundamentals2020' Pg105\t----\n\n\n\n");

	double Base;
	int Exponent;

	printf("\nEnter the base of the exponentiation: ");
	scanf("%lf%*c", &Base);

	printf("\nEnter the exponent of the exponentiation: ");
	scanf("%d%*c", &Exponent);

	printf("\n\n%.2lf to the power of %d is equal to: ", Base, Exponent);

	Base = exponentiation(Base, Exponent);

	if (Exponent < 0)
	{
		Base = 1 / Base;
	}

	printf("%.3lf\n\n\n", Base);

	return 0;
}


/* Function definitions */


double exponentiation(double Base, int Exponent)
{
	if (Exponent < 0)
	{
		Exponent = -Exponent;
	}
	// Since we use the base as our initiator we must substract "1" from the exponent otherwise we multiply by the "base" 1 time to much
	for (int i = 0; i < Exponent - 1; i++)
	{
		Base *= Base;
	}

	return Base;
}
