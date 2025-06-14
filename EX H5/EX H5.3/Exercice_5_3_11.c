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
	/* Exercice 5.3.11

	Assignment:
	Write a program that reads 2 numbers: a base b (b ∈ R) and
	an exponent n (n ∈ N). Afterwards, the exponentiation b^n is
	calculated and the result is printed to the screen. Calculate b^n with a
	loop. Do not use a standard function.


	*/

	printf("\n\t----\tDit is oefening 5.3.11 van 'Cprogrammingfundamentals2020' Pg83\t----\n\n\n\n");

	int b, n,result = 1;
	printf("\nEnter the base of the exponentiation: ");
	scanf("%d%*c", &b);
	printf("\nEnter the exponent of the exponentiation: ");
	scanf("%d%*c", &n);
	while (n < 0)
	{
		printf("\n\nThe exponent must be a natural number!!");	
		printf("\nEnter the exponent of the exponentiation: ");
		scanf("%d%*c", &n);
	}

	for (int i = 0; i < n; i++)
	{
		result *= b;
	}

	printf("\n\n%d to the power of %d is equal to %d\n\n", b, n, result);


	return 0;
}