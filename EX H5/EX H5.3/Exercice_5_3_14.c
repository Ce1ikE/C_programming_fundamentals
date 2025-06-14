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
	/* Exercice 5.3.14.

	Assignment:
	Write a program that prints the minimum and maximum
	value of 10 numbers entered by the user.The place at wich the min and MAX were enterd should also be displayed.

	*/

	printf("\n\t----\tDit is oefening 5.3.14. van 'Cprogrammingfundamentals2020' Pg84\t----\n\n\n\n");
	int Number, min, MAX,place_min,place_MAX;
	min = 0;
	MAX = 0;

	for (int i = 1; i < 11; i++)
	{
		printf("\nPlease enter number nr%d: ", i);
		scanf("%d%*c", &Number);

		if (Number < min)
		{
			min = Number;
			place_min = i;

		}

		if (Number > MAX)
		{
			MAX = Number;
			place_MAX = i;
		}





	}


	printf("\nThe highest number you entered is %d at place %d and the lowest number you entered is %d at place %d \n\n\n", MAX,place_MAX, min,place_min);




	return 0;

}