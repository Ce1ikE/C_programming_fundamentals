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
	/* Exercice 4.19

	Write a program that asks the user to enter the invoice number, the
	number of products ordered and the price per unit. Calculate the total
	amount to be paid and print it to the screen.

	*/


	printf("\n\t----\tDit is oefening 4.19 van 'Cprogrammingfundamentals2020' Pg53\t----\n\n\n\n");


	int invoice, n_ordered, price;
	printf("Enter invoice number:");
	scanf("%d%*c",&invoice);
	printf("\nEnter the number of products ordered:");
	scanf("%d%*c", &n_ordered);
	printf("\nEnter the price per unit:");
	scanf("%d%*c", &price);


	int total = n_ordered * price;

	printf("\n\n INVOICE\t NUMBER\t PRICE/UNIT\t TOTAL\n %d     \t %d    \t %d        \t %d\n\n\n"
		,invoice,n_ordered,price,total);

	return 0;
}