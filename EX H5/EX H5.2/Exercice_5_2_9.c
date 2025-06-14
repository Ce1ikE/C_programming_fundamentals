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
	/* Exercice 5.2.9.

	Assignment:
	Write a program that first reads 3 integer numbers that represent
	the current date and then reads again 3 integer numbers to be
	interpreted as a birth date. Based upon this information the program
	prints the age of that person in years and months.


	*/

	printf("\n\t----\tDit is oefening 5.2.9. van 'Cprogrammingfundamentals2020' Pg67\t----\n\n\n\n");

	int Day_current, Month_current, Year_current, Day_birth, Month_birth, Year_birth,Day_Age, Month_Age, Year_Age;

	printf("Enter the current date (DD MM YYYY):\t");
	scanf("%d%*c%d%*c%d%*c",&Day_current,&Month_current,&Year_current);

	printf("\n\nEnter your birthdate (DD MM YYYY):\t");
	scanf("%d%*c%d%*c%d%*c", &Day_birth, &Month_birth, &Year_birth);


	Year_Age = Year_current - Year_birth;
	Day_Age = Day_current - Day_birth;


	if (Day_Age < 0)
	{
		Month_current--;
	}

	Month_Age = Month_current - Month_birth;


	if (Month_Age < 0)
	{
		Month_Age = Month_Age + 12;
		Year_Age = Year_Age - 1;
	}
	

	printf("\n\nYour age is: %d years and %d months\n\n\n", Year_Age, Month_Age);


	return 0;

}
