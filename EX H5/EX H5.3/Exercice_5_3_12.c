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
	/* Exercice 5.3.12

	Assignment:
	Repeat exercise 5.3.11 but with n being an integer (both
	positive and negative values are possible).

	*/

	printf("\n\t----\tDit is oefening 5.3.11 van 'Cprogrammingfundamentals2020' Pg83\t----\n\n\n\n");

	int b, n;
	float result = 1;
	printf("\nEnter the base of the exponentiation: ");
	scanf("%d%*c", &b);
	printf("\nEnter the exponent of the exponentiation: ");
	scanf("%d%*c", &n);

	if (n < 0)
	{
		for (int i = 0; i < -n; i++)
		{
			result *= b;
		}
		result = 1 / result;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			result *= b;
		}
	}
	printf("\n\n%d to the power of %d is equal to %.5f", b, n, result);


	return 0;
}