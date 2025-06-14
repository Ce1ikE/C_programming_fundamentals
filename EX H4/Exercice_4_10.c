/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020" 4.10

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{

	/* Exercice 4.10

	   Assignment:
	   Write a program that asks the user to enter a number of seconds
	   and prints the corresponding number of days, hours (<24), minutes
	   (<60) and seconds (<60).

	*/

	printf("\n\t----\tDit is oefening 4.10 van 'Cprogrammingfundamentals2020' Pg51\t----\n\n\n\n");

	int seconds, minutes, hours, days;
	printf("Please input a positive number of seconds:\n> ");
	scanf("%d%*c",&seconds);

	minutes = ((seconds - seconds % 60) / 60);
	hours = ((minutes - minutes % 60) / 60);
	days = ((hours - hours % 24) / 24);
	seconds = seconds % 60;
	minutes = minutes % 60;
	hours = hours % 24;
	printf("\nYour number of seconds equal to %d days %d hours %d minutes %d seconds\n\n\n", days, hours, minutes, seconds);


	return 0;
}