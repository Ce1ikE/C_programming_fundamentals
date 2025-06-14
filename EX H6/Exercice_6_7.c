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


void printline(int, char);

int main(void)
{
	/* Exercice 6.7

	Assignment:
	Write a function with header:

	void printline( int number, char c)

	that prints a line of number symbols c followed by a newline character. 
	Write a main program that calls this function several times with different parameters.
	*/

	printf("\n\t----\tDit is oefening 6.7 van 'Cprogrammingfundamentals2020' Pg104\t----\n\n\n\n");

	printf("Just Lines\n---------\n\n");

	printline(30,'*');

	printline(20,'=');

	printline(5, '$');

	printline(15, '.');


	printline(15, '#');
}




void printline(X,Y)
{

	for (int i = 0; i < X; i++)
	{
		printf("%c", Y);
	}




	printf("\n\n");



}