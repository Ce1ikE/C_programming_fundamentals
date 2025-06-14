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
	/* Exercice 5.3.9.

	Assignment:
	Write a program that prints the mean of a number of integers. The 
	exact number of integers is not known upfront. If the number 999 is 
	read, the program stops reading new numbers. 999 cannot be taken 
	into account for the calculation of the mean.

	*/

	printf("\n\t----\tDit is oefening 5.3.9. van 'Cprogrammingfundamentals2020' Pg83\t----\n\n\n\n");

	int NUMBER, SUM, NUMBERS_ENTERED;
	float Avg;
	SUM = 0;
	NUMBERS_ENTERED = 0;
	NUMBER = 0;
	printf("Please enter any amount of integers you want. End by entering 999 : \n\t => ");
	scanf("%d%*c", &NUMBER);
	while (NUMBER != 999)
	{
		SUM = SUM + NUMBER;
		NUMBERS_ENTERED++;
		scanf("%d%*c", &NUMBER);
	} 

	if (NUMBERS_ENTERED > 0)
	{
		Avg = (float)SUM / (float)NUMBERS_ENTERED;
		printf("\n\n The average is equal to %.2f \n\n\n", Avg);
	}
	else
	{
		printf("\n\tNO NUMBERS WERE ENTERED\n\n");
	}


}