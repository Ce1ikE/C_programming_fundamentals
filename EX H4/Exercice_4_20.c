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
	/* Exercice 4.20

	Write a program that asks the user to enter the invoice number, the
	number of products ordered and the price per unit. Calculate the total
	amount to be paid and print it to the screen.

	*/


	printf("\n\t----\tDit is oefening 4.20 van 'Cprogrammingfundamentals2020' Pg53\t----\n\n\n\n");

	int Number, C, D, U;// => C = Centaines(French for hundreds) ; D = Dizaines(French for Tens) ; U = Unité(French for Units)

	printf("\n\nEnter an integer number with 3 digits: ");
	scanf("%d%*c", &Number);
	C = Number / 100;
	D = (Number - C * 100) / 10;
	U = (Number - C * 100 - D * 10);
	printf("The number printed backwards is: %d%d%d\n\n", U, D, C);

	return 0;
}