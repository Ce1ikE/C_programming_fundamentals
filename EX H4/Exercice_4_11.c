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
	/* Exercice 4.11
	
	Assignement:

	Write a program that asks the user to enter 5 integer numbers one 
	by one. While reading the numbers, the program calculates the sum. 
	At the end, the mean of all 5 numbers is printed with a precision of 2 
	digits after the digital point. Try to limit the number of variables in 
	your program to 2 (or max 3) but do not introduce loops yet.
	
	*/


	printf("--\tDit is oefening 4.11 van 'Cprogrammingfundamentals2020' Pg51\t--\n\n\n");

	int number;
	float avg;
	printf("Enter a number (integer only):\n\t> ");
	scanf("%d%*c",&number);
	avg = number;
	printf("Enter another number (integer only):\n\t> ");
	scanf("%d%*c", &number);
	avg = avg + number;
	printf("Enter another number (integer only):\n\t> ");
	scanf("%d%*c", &number);
	avg = avg + number;
	printf("Enter another number (integer only):\n\t> ");
	scanf("%d%*c", &number);
	avg = avg + number;
	printf("Enter another number (integer only):\n\t> ");
	scanf("%d%*c", &number);
	avg = avg + number;
	avg = avg / 5;
	printf("The average of all your numbers is %.2f\n\n",avg);

	return 0;
}