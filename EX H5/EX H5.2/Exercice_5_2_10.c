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
	/* Exercice 5.2.10.

	Assignment:
	Write a program that reads a start and end time, calculates 
	the time difference and prints it in the format:" hh hours mm minutes ss seconds".
	You can read hours, minutes and seconds separately.
	If the start time appears to be later than the end time, you can 
	assume the start time to be from the previous day.

	*/

	printf("\n\t----\tDit is oefening 5.2.10. van 'Cprogrammingfundamentals2020' Pg67\t----\n\n\n\n");


	int hours_start, minutes_start, seconds_start, hours_finish, minutes_finish, seconds_finish, hours_diff, minutes_diff, seconds_diff;

	printf("Please enter your starting TIME (HH MM SS):\t");
	scanf("%d%d%d%*c",&hours_start,&minutes_start,&seconds_start);
	printf("\n\nPlease enter your end TIME (HH MM SS):\t");
	scanf("%d%d%d%*c",&hours_finish, &minutes_finish, &seconds_finish);
	
	// Boundary(upper)
	// => sec 60
	// => min 60
	// => hour 24

	

	// there are a few ways of calculating this but my way of doing this is as follows :
	// first we are bound to a lower and upper boundary for the hours[0;24] minutes[0;60] and seconds[0;60]
	// secondly I select the direction we are going to calculate to (2 ways '+' or '-') my way is to add =>		start + diff = finish <==> diff = finish - start
	// if our number obtained is negatif we add the MAX boundary (upper)

	// calculation for seconds
	seconds_diff = seconds_finish - seconds_start;

	if (seconds_diff < 0)
	{
		minutes_finish--;
		seconds_diff += 60;
	}

	// calculation for minutes
	minutes_diff = minutes_finish - minutes_start;

	if (minutes_diff < 0)
	{
		hours_finish--;
		minutes_diff += 60;
	}

	// calculation for hours
	hours_diff = hours_finish - hours_start;

	if (hours_diff < 0)
	{
		hours_diff += 24;
	}

	printf("\n\n The time difference is :\t %d hours %d minutes %d seconds\n\n\n",hours_diff,minutes_diff,seconds_diff);

	return 0;
}