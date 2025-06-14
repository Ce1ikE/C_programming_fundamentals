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
	/* Exercice 5.3.3.

	Assignment:
	Write a program that asks the user to enter an integer number n and 
	prints the sum 1+2+3+4+…+n

	*/

	printf("\n\t----\tDit is oefening 5.3.3. van 'Cprogrammingfundamentals2020' Pg82\t----\n\n\n\n");

	int number,SUM = 0;
	printf("Please enter a integer:");
	scanf("%d%*c", &number);

	printf("\n This is the sum from 1 to %d \n\n", number);
	for (int i = 1; i < number; i++)
	{
		printf("%d+", i);
		SUM += i;
	}
	printf("%d", number);
	SUM += number;
	printf(" = %d\n\n\n\n", SUM);

}
