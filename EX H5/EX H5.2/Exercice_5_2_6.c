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
	/* Exercice 5.2.6.

	Assignment:
	Write a program that asks the user to enter 5 integer numbers one 
	by one. While reading the numbers, the program calculates the 
	minimum of those numbers. At the end, this minimum is printed. Try 
	to limit the number of variables in your program to 2 (or max 3) but 
	do not introduce loops yet


	*/

	printf("\n\t----\tDit is oefening 5.2.6. van 'Cprogrammingfundamentals2020' Pg66\t----\n\n\n\n");


	int min,NUMBER;
	// 1st NUMBER
	printf("\n\nPlease enter a number:");
	scanf("%d%*c",&NUMBER);
	min = NUMBER;

	if (NUMBER < min)
	{
		min = NUMBER;
	}
	//2nd NUMBER
	printf("\n\nPlease enter a other number:");
	scanf("%d%*c", &NUMBER);
	if (NUMBER < min)
	{
		min = NUMBER;
	}
	//3rd NUMBER
	printf("\n\nPlease enter a other number:");
	scanf("%d%*c", &NUMBER);
	if (NUMBER < min)
	{
		min = NUMBER;
	}
	//4th NUMBER
	printf("\n\nPlease enter a other number:");
	scanf("%d%*c", &NUMBER);
	if (NUMBER < min)
	{
		min = NUMBER;
	}
	//5th NUMBER
	printf("\n\nPlease enter a other number:");
	scanf("%d%*c", &NUMBER);
	if (NUMBER < min)
	{
		min = NUMBER;
	}

	printf("\n\nThe lowest number you entered is %d\n\n\n", min);


	return 0;







}