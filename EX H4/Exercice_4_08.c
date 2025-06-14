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
	/* Exercice 4.8

	Assignement:

	 Write a program that asks the user to enter name and first name
	separately and prints them on 1 line. Test your program with names
	that contain white spaces (ex: Julia Rose Smith)

	*/
	printf("--\tDit is oefening 4.08 van 'Cprogrammingfundamentals2020' Pg51\t--\n\n\n");

	char first_name[20], last_name[20];
	printf("\nPlease enter firstname:  ");
	gets(first_name);
	printf("\nPlease enter lastname:  ");
	gets(last_name);

	printf("\nyour name is '%s %s'\n\n\n",first_name,last_name);

	return 0;


}