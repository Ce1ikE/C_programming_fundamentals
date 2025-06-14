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
	/* Exercice 5.3.2.

	Assignment:
	Write a program that asks the user to enter an integer number and 
	prints the multiplication table of that number

	*/

	printf("\n\t----\tDit is oefening 5.3.2. van 'Cprogrammingfundamentals2020' Pg82\t----\n\n\n\n");

	int NUMBER,table;
	printf("Please enter a integer:");
	scanf("%d%*c", &NUMBER);

	printf("\n\nThe multiplication table of %d is:\n\n", NUMBER);
	for (int i = 0; i <= 20; i++)
	{
		table = i * NUMBER;
		printf("------------------\n");
		printf("|%3d x %3d = %3d | \n",i,NUMBER,table);
	}

	printf("\n\n\tTHATS ALL FOR NOW !!\n\n");

	return 0;

}