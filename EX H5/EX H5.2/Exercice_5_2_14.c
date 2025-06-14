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
	/* Exercice 5.2.14.

	Assignment:
	A gas company calculates its prices as follows: 
	- for a consumption ≤ 1m³ € 20,00
	- for a consumption > 1m³ € 20 for the first m³ + € 3,5/m³
	 for the part over 1m³
	The total amount needs to be increased with a tax of 21%.
	Write a program that asks the user to enter his/her consumption and 
	prints an invoice to the screen showing consumption, cost prince, 
	tax amount and total amount.

	*/

	printf("\n\t----\tDit is oefening 5.2.14. van 'Cprogrammingfundamentals2020' Pg68\t----\n\n\n\n");

	float  consumption, tax, total_amount, cost;


	printf("Please enter your consumption(m³) of gas:");
	scanf("%f%*c",&consumption);

	tax = 0.21; // == 21%

	if (consumption <= 1)
	{
		cost = 20;
		total_amount = cost + (cost * tax);
		printf("\n\n Your consumption: %.2f m\n Cost price: %.2f\n Tax amount: %.2f\n Total amount: %.2f\n\n\n",consumption,cost,tax,total_amount);
	}
	else (consumption > 1);
	{
		cost = 20 + 3.5 * (consumption - 1);
		total_amount = cost + (cost * tax);
		printf("\n\n Your consumption: %.2f m\n Cost price: %.2f\n Tax amount: %.2f\n Total amount: %.2f\n\n\n", consumption, cost, tax, total_amount);
	}
	return 0;
}