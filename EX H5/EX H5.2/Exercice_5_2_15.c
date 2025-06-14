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
	/* Exercice 5.2.15.

	Assignment:
	The equivalent resistance (Req) for 2 parallel resistors R1 and R2 can be calculated with:
	1/𝑅𝑒𝑞 = 1/𝑅1 + 1/𝑅2
	Write a program that reads the values of R1 and R2, calculates Req
	and prints it to the screen. Make sure the program also works 
	correctly for an R1 and/or R2 equal to 0!

	*/

	printf("\n\t----\tDit is oefening 5.2.15. van 'Cprogrammingfundamentals2020' Pg68\t----\n\n\n\n");

	float R1, R2, R_eq;

	printf("Please enter the value of R1 and R2:\t");
	scanf("%f%f%*c", &R1, &R2);

	while (R1 == 0 || R2 == 0)
	{
		printf("\n\n Value impossible\n\n");
		printf("Please enter the value of R1 and R2:\t");
		scanf("%f%f%*c", &R1, &R2);
	}

	R_eq = (R1 * R2) / (R1 + R2);

	printf("\n\n The equivalent resistance (Req) for 2 parallel resistors R1 and R2 with a resistance of %f %f respectively is equal to %f \n\n\n", R1, R2, R_eq);

}