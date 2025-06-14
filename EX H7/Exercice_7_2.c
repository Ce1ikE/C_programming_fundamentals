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
	/* Exercice 7.2

	Assignment:
	Change the previous exercise such that all days with a temperature 
	warmer than 10°C are printed

	*/

	printf("\n\t----\tDit is oefening 7.2 van 'Cprogrammingfundamentals2020' Pg119\t----\n\n\n\n");


	int Temperature[Days];
	float Mean;
	Mean = 0;

	for (int i = 0; i < Days; i++)
	{
		printf("\n Enter temperature for day %d : => ", i + 1);
		scanf("%d%*c", &Temperature[i]);

	}

	printf("\n\n All days with a temperature > 10\xA7 C :");

	for (int t = 0; t < Days; t++)
	{
		if (Temperature[t] > 10)
		{
			printf("\n Day %d ", t + 1);
		}
	}
	printf("\n\n\n");

	return 0;
}