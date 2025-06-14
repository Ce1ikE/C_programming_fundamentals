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
	/* Exercice 4.15

	   Assignment:
	   Write a program that reads 6 integer numbers and prints them in a
	   table format with 3 rows and 2 columns.

	*/

	int in1, in2, in3, in4, in5, in6; //in = integer + n° of position in the table from L to R and Up to Bottom
	printf("\n--\tDit is oefening 4.15 van 'Cprogrammingfundamentals2020' Pg52\t--\n\n\n\n");

	printf("Please enter 6 integers:\n> ");
	scanf("%d%d%d%d%d%d%*c", &in1, &in2, &in3, &in4, &in5, &in6);

	printf("\n%3d\t%3d\n%3d\t%3d\n%3d\t%3d\n", in1, in2, in3, in4, in5, in6);

	return 0;
}