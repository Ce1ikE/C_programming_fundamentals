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
	/* Exercice 4.5

	Assignement:

	Write a program that asks the user to enter 2 integer numbers and
	prints the result and remainder of the integer division of both
	numbers and the real quotient
	the screen dialogue should look like:
	
	Enter 2 integer numbers: 17 7
	integer quotient = 2
	remainder = 3
	quotient = 2.43

	*/

	int in1, in2,in_quot,rem;
	float quot;
	printf("--\tDit is oefening 4.05 van 'Cprogrammingfundamentals2020' Pg51\t--\n\n\n");
	printf("Enter 2 integer numbers:\n> ");
	scanf("%d%d%*c", &in1, &in2);

	in_quot = in1 / in2;
	rem = in1 % in2;
	quot = (float)in1 / (float)in2;

	printf("\n=> integer quotient = %d\n=> remainder = %d\n=> quotient = %6.2f\n\n\n", in_quot, rem, quot);


	return 0;

}