/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

int main(void)
{
	/* Exercice 5.2.17.

	Assignment:

	Write a program that reads 3 integer numbers that are to be
	interpreted as a date and prints the corresponding day of the week.

	The day of the week can be calculated as follows:

	day of the week = factor - (factor / 7) * 7

	where (factor / 7) == the integer part

	day of the week == [0-6] for saturday till friday

	0 saturday
	1 sunday
	2 monday
	3 tuesday
	4 wednesday
	5 thursday
	6 friday

	factor = 365 * year + day + 31 * (month - 1) + ((year - 1) / 4) - ((1 + (year - 1)/100) * 3 / 4)

	valid for january and february

	factor = 365 * year + day +31 * (month - 1) - (0.4 * month + 2.3) + (year / 4) - ((1 + (year - 1)/100) * 3 / 4)

	valid for march till december

	*/

	printf("\n\t----\tDit is oefening 5.2.17. van 'Cprogrammingfundamentals2020' Pg68\t----\n\n\n\n");

	int day, month, year;
	int factor;
	printf("Enter a date please in integer form (DD MM YYYY): => ");
	scanf("%d%d%d%*c", &day, &month, &year);

	while (31 < day || day <= 0 || 12 < month || month <= 0)
	{
		printf("\n\n\t\033[41mIncorrect Date\033[m");
		printf("\n\nEnter a date please in integer form (DD MM YYYY): => ");
		scanf("%d%d%d%*c", &day, &month, &year);
	}

	// For January and February
	if (month == 1 || month == 2)
	{
		factor = 365 * year + day + (31 * (month - 1)) + ((year - 1) / 4) - ((((float)(year - 1) / 100) + 1) * 3 / 4);
		day = factor - ((factor / 7) * 7);
	}

	// For March till December
	if (3 <= month && month <= 12)
	{
		factor = 365 * year + day + (31 * (month - 1)) - ((0.4 * month) + 2.3) + ((float)year / 4) - ((((float)(year - 1) / 100) + 1) * 3 / 4);
		day = factor - ((float)(factor / 7) * 7);
	}

	printf("\n\nThe day of the week was: ");
	printf("\033[32m");
	switch (day)
	{
	case 6: printf("Saturday"); break;
	case 0: printf("Sunday"); break;
	case 1: printf("Monday"); break;
	case 2: printf("Tuesday"); break;
	case 3: printf("Wednesday"); break;
	case 4: printf("Thursday"); break;
	case 5: printf("Friday"); break;
	default:
		break;
	}

	printf("\033[m\n\n\n");
	return 0;
}