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
	/* Exercice 5.3.15

	Assignment:
	Write a program that calculates the greatest common divisor 
	of 2 positive integers. Use Euclid’s algorithm to determine the gcd. In 
	this algorithm, the biggest number is replaced by the difference of 
	both numbers. Repeat this until both numbers are equal. This 
	number is the gcd. Print the gcd and all intermediate steps.

	*/

	printf("\n\t----\tDit is oefening 5.3.15 van 'Cprogrammingfundamentals2020' Pg84\t----\n\n\n\n");

	int Num1, Num2,int1,int2;
	printf("\n\nEnter 2 positive integer numbers: ");
	scanf("%d%d%*c", &Num1, &Num2);

	while (Num1 < 0 || Num2 < 0)
	{
		printf("\n\nBoth numbers must be positive!!\n");
		printf("\n\nEnter 2 positive integer numbers: ");
		scanf("%d%d%*c", &Num1, &Num2);
	}

	int1 = Num1;
	int2 = Num2;

	while (Num1 != Num2)
	{
		printf("\n%4d\t%4d", Num1, Num2);
		if (Num1 < Num2)
		{
			Num2 -= Num1;
		}

		if (Num1 > Num2)
		{
			Num1 -= Num2;
		}
	}

	printf("\n%4d\t%4d", Num1, Num2);

	printf("\n\nThe GCD of %d and %d equals %d", int1, int2, Num1);

	return 0;

}