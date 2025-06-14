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
	/* Exercice 5.2.12

	Assignment:
	Write a program that reads a digit (0, 1, … , 9) and prints this
	digit as a word. If the entered number is not a digit, a warning
	should be printed

	*/

	printf("\n\t----\tDit is oefening 5.2.12 van 'Cprogrammingfundamentals2020' Pg67\t----\n\n\n\n");

	int Number;
	printf("\nEnter a digit: ");
	scanf("%d%*c", &Number);

	switch (Number)
	{
	case 1:printf("\nYou have entered the digit ONE\n\n\n"); break;
	case 2:printf("\nYou have entered the digit TWO\n\n\n"); break;
	case 3:printf("\nYou have entered the digit THREE\n\n\n"); break;
	case 4:printf("\nYou have entered the digit FOUR\n\n\n"); break;
	case 5:printf("\nYou have entered the digit FIVE\n\n\n"); break;
	case 6:printf("\nYou have entered the digit SIX\n\n\n"); break;
	case 7:printf("\nYou have entered the digit SEVEN\n\n\n"); break;
	case 8:printf("\nYou have entered the digit EIGHT\n\n\n"); break;
	case 9:printf("\nYou have entered the digit NINE\n\n\n"); break;
	case 0:printf("\nYou have entered the digit ZERO\n\n\n"); break;
	default:printf("\nThe number you entered is not a digit.\n\n\n");	break;
	}


	return 0;
}