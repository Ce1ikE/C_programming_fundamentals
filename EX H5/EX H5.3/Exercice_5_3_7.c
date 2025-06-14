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
	/* Exercice 5.3.7.

	Assignment:
	Write a program that asks the user to enter an integer number in the 
	interval [-30 , 30]. Make sure only valid numbers can be entered! 
	This number is then printed as a bar graph made out of * symbols. 
	Negative numbers are drawn from the middle to the left, positive 
	numbers are drawn from the middle to the right. Points are used to 
	fill up the empty places. The entered number itself is printed in the end. 
	Repeat the program until a 0 is entered.


	*/

	printf("\n\t----\tDit is oefening 5.3.7. van 'Cprogrammingfundamentals2020' Pg83\t----\n\n\n\n");

	int NUMBER;

	printf("Please enter a integer between the interval [-30 ; 30](Enter 0 to quit) :\t => ");
	scanf("%d%*c", &NUMBER);

	
	while (NUMBER != 0)
	{
		while (NUMBER < -30 || NUMBER > 30)
		{
			printf("\n\t NUMBER INVALID ENTER A NUMBER BETWEEN THE INTERVAL [-30 ; 30]\n\n");
			printf("Enter a integer (Enter 0 to quit) :\t => ");
			scanf("%d%*c", &NUMBER);

		}

		if (NUMBER > 0)
		{
			printf("\n number: %d \n", NUMBER);

			for (int i = 0; i < 30; i++)
			{
			printf(".");
			}
			printf("|");

			for (int s = 0; s < NUMBER; s++)
			{
			printf("*");
			}
			for (int d = 0; d < 30-NUMBER; d++)
			{
			printf(".");
			}

		}
		if (NUMBER < 0)
		{
			printf("\n number: %d \n", NUMBER);

			for (int h = 0; h < 30 + NUMBER; h++)
			{
			printf(".");
			}
			for (int m = 0; m < - NUMBER; m++)
			{
			printf("*");
			}
			printf("|");
			for (int l = 0; l < 30; l++)
			{
			printf(".");
			}

		}

		printf("\n\nPlease enter a integer between the interval [-30 ; 30](Enter 0 to quit) :\t => ");
		scanf("%d%*c", &NUMBER);

	}

	printf("\n\n\n");
	
	return 0;
}