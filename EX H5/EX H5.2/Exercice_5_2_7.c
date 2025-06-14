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
	/* Exercice 5.2.7.

	Assignment:
	Write a program that compares your speed with the speed limit. If 
	you are speeding, the program will calculate your fine. If not, 
	nothing happens. The fine consists of a fixed amount of € 100 and a 
	variable amount of € 2.5 for every km over the speed limit.


	*/

	printf("\n\t----\tDit is oefening 5.2.7. van 'Cprogrammingfundamentals2020' Pg66\t----\n\n\n\n");

	int velocity,MAX_Speed,speed_diff;
	float Fine;
	printf("Be aware! Speeding is heavily fined!\n\n");
	printf("Enter your speed:");
	scanf("%d%*c", &velocity);
	printf("\n\nEnter the speed limit :");
	scanf("%d%*c", &MAX_Speed);

	if (MAX_Speed < velocity)
	{
		speed_diff = velocity - MAX_Speed;
		Fine = 100 + (2.5 * speed_diff);

		printf("\n\nYour speed is %d km/h over the speed limit.\n\nYour fine amounts %.2f euro.\n\n\n", speed_diff, Fine);

	}
	else
	{
		printf("\n\nHave a nice day!\n\n");
	}

	return 0;


}