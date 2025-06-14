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
	/* Exercice 4.1
	
	Assignement:

	Write a program that asks the user to enter an integer number, stores
	this number in a variable of the type short (short int) and prints it
	back to the screen. What values can be entered? What is the biggest
	number you can enter and print correctly? ([-32768;+32767])
	
	*/

	short int number;
	printf("Dit is oefening 4.01 van 'Cprogrammingfundamentals2020' Pg50");
	printf("\n\nplease enter a integer:\n> ");
	scanf("%hd%*c",&number);
	printf("your number is %hd\n\n\n",number);

	return 0;
}