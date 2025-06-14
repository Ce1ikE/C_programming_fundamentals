/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

#define MaxNumber 100
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/* Function declarations */


int main(void)
{
	/* Exercice 6.5

	Assignment:
	Write a program for a guessing game. First a random number
	between 1 and 100 is chosen by the program. Afterwards, the user can
	start guessing. If the guess was too high or too low, the program needs
	to print “too high” or “too low”. This is repeated until the number was
	found. In the end, the program prints how many guesses the user
	needed to find the secret number.

	*/

	printf("\n\t----\tDit is oefening 6.5 van 'Cprogrammingfundamentals2020' Pg104\t----\n\n\n\n");

	srand(time(NULL));
	int Guesses = 0;
	int Number = rand() % MaxNumber + 1;
	int Choice;

	do
	{
		do
		{
			printf("\nEnter a number between 0 and %d: => ", MaxNumber);
			scanf("%d*c", &Choice);
		} while (Choice > MaxNumber || Choice < 0);

		Guesses++;

		if (Choice < Number)
		{
			printf("\n\n\t\t\t\033[31m =>TOO LOW<= \033[0m\n");
		}

		if (Choice > Number)
		{
			printf("\n\n\t\t\t\033[31m =>TOO HIGH<= \033[0m\n");
		}

	} while (Choice != Number);


	printf("\n\nYou chose the correct number in %d guesses!! Congratulation\n", Guesses);

	printf("\n\n\n");



}