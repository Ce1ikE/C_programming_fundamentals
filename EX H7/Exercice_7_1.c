/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Days 7

/* Function declarations */



int main(void)
{
	/* Exercice 7.1

	Assignment:
	Write a program that reads the temperatures of a whole week into 1 
	array ‘temperature[]’ and prints the mean temperature for that week.

	*/

	printf("\n\t----\tDit is oefening 7.1 van 'Cprogrammingfundamentals2020' Pg119\t----\n\n\n\n");


	int Temperature[Days];
	float Mean;
	Mean = 0;

	for (int i = 1; i <= Days; i++)
	{
		printf("\n Enter temperature for day %d : => ",i);
		scanf("%d%*c",&Temperature[i-1]);
	}

	for (int t = 0; t < Days; t++)
	{
		Mean = Mean + Temperature[t];
	}
	Mean = Mean / Days;

	printf("\n\n The mean temperature for this week is %.2f\n\n\n", Mean);

	return 0;

}