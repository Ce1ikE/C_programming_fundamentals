/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis

*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	/* Exercice 4.7

	Assignement:

	Write a program that asks the user to enter hours, minutes and
	seconds separately and prints them in a sentence like:
	The entered time is: hh hours mm minutes and ss seconds
	where hh and mm can only be integer numbers. ss can have digits
	after the decimal point

	*/
	printf("--\tDit is oefening 4.07 van 'Cprogrammingfundamentals2020' Pg51\t--\n\n\n");

	int hours, minutes;
	float seconds;

	printf("please enter a amount of hours:\n> ");
	scanf("%d%*c",&hours);

	printf("please enter a amount of minutes:\n> ");
	scanf("%d%*c",&minutes);

	printf("please enter a amount of seconds:\n> ");
	scanf("%f%*c",&seconds);

	
	printf("The entered time is: %5d hours %5d minutes %5.3f seconds\n\n\n",hours ,minutes ,seconds);


	return 0;
}