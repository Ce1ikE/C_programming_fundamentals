/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Function declarations */

int isLeapYear(int);
int numberOfDays(int, int);

int main(void)
{
	/* Exercice 6.14

	Assignment:
	Since a year is not exactly 365 days, we have a leap year once every 4 years except if the year is dividable by 100. 
	If the year is dividable by 400, the year is considered as a leap year anyway.
	Write a function with header:

	int isLeapYear( int year)

	that determines if a year is a leap year or not and gives a different 
	function return value for both cases.
	Write also a function with header:

	int numberOfDays(int month, int year)

	that calculates the number of days in the month month of the year given.
	Write a main function that reads a month and a year and prints the number of days in that month of that year.

	*/

	printf("\n\t----\tDit is oefening 6.14 van 'Cprogrammingfundamentals2020' Pg107\t----\n\n\n\n");

	int year, month, days;
	printf("\n Please enter a Year and a mont (YYYY MM) : => ");
	scanf("%d%d%*c", &year, &month);

	while (year < 0 || month < 0 || month > 12)
	{
		printf("\n Enter a valid date");
		printf("\n Please enter a Year and a mont (YYYY MM) : => ");
		scanf("%d%d%*c", &year, &month);
	}

	
	days = numberOfDays(month,year);

	printf("\n\n month %d of %d has %d days\n\n\n", month,year,days);

	return 0;
}

int isLeapYear(int year)
{

	int Days;

	Days = 365;

	if (year % 4 == 0)
	{
		Days = 366;

		if (year % 100 == 0)
		{
			Days = 365;

		}
		if (year % 400 == 0)
		{
			Days = 366;
		}
	}	
	
	
	return Days;
}


int numberOfDays(int month, int year)
{
	int Days;

	Days = isLeapYear(year);

	if (month == 12 || month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
	{
		Days = 31;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		Days = 30;
	}
	if (month == 2)
	{
		if (Days == 366)
		{
			Days = 29;
		}
		if (Days == 365)
		{
			Days = 28;
		}
	}
	


	return Days;


}

