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
	/* Exercice 4.2
	
	Assignement:
	Repeat the previous exercise but this time use a variable of the type
	int or long.

	*/

	long int number;
	printf("Dit is oefening 4.02 van 'Cprogrammingfundamentals2020' Pg50");

	printf("\n\nplease enter a integer\n> ");
	scanf("%d%*c",&number);
	printf("your number is %d\n\n", number);

	return 0;
}