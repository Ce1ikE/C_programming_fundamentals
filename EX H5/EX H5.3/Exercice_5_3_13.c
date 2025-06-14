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
	/* Exercice 5.3.13.

	Assignment:
	Write a program that prints the minimum and maximum 
	value of 10 numbers entered by the user. Use only 4 variables in 
	your program.

	*/

	printf("\n\t----\tDit is oefening 5.3.13. van 'Cprogrammingfundamentals2020' Pg83\t----\n\n\n\n");
	int Number,min,MAX;

	printf("\nPlease enter number nr%d: ", 1);
	scanf("%d%*c", &Number);
	min = Number;
	MAX = Number;

	for (int i = 2; i < 11; i++)
	{
		printf("\nPlease enter number nr%d: ",i);
		scanf("%d%*c",&Number);

		if (Number < min )
		{
			min = Number;


		}

		if (Number > MAX )
		{
			MAX = Number;

		}





	}

	
	printf("\nThe highest number you entered is %d and the lowest number you entered is %d\n\n\n", MAX, min);




	return 0;

}