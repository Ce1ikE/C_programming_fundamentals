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
	/* Exercice 5.2.11.

	Assignment:
	Write a program that reads 3 numbers and prints them
	ranked form small to large.

	*/

	printf("\n\t----\tDit is oefening 5.2.11. van 'Cprogrammingfundamentals2020' Pg67\t----\n\n\n\n");
	
	float N_1, N_2, N_3;
	printf("Enter 3 real numbers please:\t");
	scanf("%f%f%f%*c", &N_1, &N_2, &N_3);


	if (N_1 < N_2)
	{
		if (N_2 < N_3)
		{
		printf("\n\n The ascending order is %.1f %.1f %.1f\n\n\n", N_1, N_2, N_3);
		}
		else //(N_2 > N_3)
		{
			if (N_1 < N_3)
			{
				printf("\n\n The ascending order is %.1f %.1f %.1f\n\n\n", N_1, N_3, N_2);
			}
			else //(N_1 < N_3)
			{
				printf("\n\n The ascending order is %.1f %.1f %.1f\n\n\n", N_3,N_1, N_2);
			}
		}
	}
	else //(N_1 > N_2)
	{
		if (N_1 < N_3)
		{
		printf("\n\n The ascending order is %.1f %.1f %.1f\n\n\n", N_2, N_1, N_3);
		}
		else //(N_1 > N_3)
		{
			if (N_2 < N_3)
			{
			printf("\n\n The ascending order is %.1f %.1f %.1f\n\n\n", N_2, N_3, N_1);
			}
			else //(N_2 > N_3)
			{
			printf("\n\n The ascending order is %.1f %.1f %.1f\n\n\n", N_3, N_2, N_1);
			}
			
		}

		
	}
	

	return 0;
}