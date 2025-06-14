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
	/* Exercice 5.2.1.

	Assignment:
	Write a program that asks the user to enter an integer number and 
	prints whether that number is even or odd.
	*/

	printf("\n\t----\tDit is oefening 5.2.2. van 'Cprogrammingfundamentals2020' Pg66\t----\n\n\n\n");

	int Number;

	printf("Please enter a number:");
	scanf("%d%*c",&Number);

	if (Number % 2 == 0)
	{
		printf("\nYour number is EVEN\n\n\n");
	}
	else
	{
		printf("\nYour number is ODD\n\n\n");
	}

	return 0;


}