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

int GCD(int, int);

int main(void)
{
	/* Exercice 6.11

	Assignment:
	Write a function with header:
	int gcd(int number1, int number2)
	that returns the greatest common divisor of the numbers number1 and
	number2 as function return value.
	Write a main program that reads 3 integer numbers, calculates the gcd
	of those 3 numbers and prints the result.
	Hint: gcd(a, b, c) = gcd( a, gcd(b, c))


	*/

	printf("\n\t----\tDit is oefening 6.11 van 'Cprogrammingfundamentals2020' Pg105\t----\n\n\n\n");

	int Num1, Num2, Num3;

	printf("\n\nEnter 3 integers: ");
	scanf("%d%d%d%*c", &Num1, &Num2, &Num3);

	printf("\n\nThe greatest common divisor of %d %d and %d is: ", Num1, Num2, Num3);

	Num1 = GCD(Num1, Num2);
	Num1 = GCD(Num1, Num3);

	printf("%d\n\n\n", Num1);

	return 0;
}


int GCD(int Num1, int Num2)
{
	while (Num1 != Num2)
	{
		if (Num1 < Num2)
		{
			Num2 -= Num1;
		}

		if (Num1 > Num2)
		{
			Num1 -= Num2;
		}
	}

	return Num1;
}