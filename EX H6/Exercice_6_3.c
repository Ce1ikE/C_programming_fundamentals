/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/* Function declarations */


int main(void)
{
	/* Exercice 6.3

	Assignment:
	Write a program that calculates the square root of a number entered 
	by the user.


	*/

	printf("\n\t----\tDit is oefening 6.3 van 'Cprogrammingfundamentals2020' Pg104\t----\n\n\n\n");


	double Number, square_root;


	printf("Enter a Number : \t => ");

	scanf("%lf%*c",&Number);

	square_root = sqrt(Number);

	printf("\n\n The square root of %.2lf is equal to %.3lf \n\n\n",Number, square_root);



}