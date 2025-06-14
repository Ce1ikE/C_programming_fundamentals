/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#include "MyHeaderEC.h"
#define MaxPeople 2

/* Function declarations */

person ReadData(void);
void PrintData(person);
void PrintDate(date);
date ReadDate(void);

int main(void)
{
	/* Exercice 15.3

	Assignment:

	Repeat exercise 15.2 with addition of an enrollmentDate added to 
	the structure Person. Change only the structure Person and use the 
	existing functions to read and write a Date at the right place.

	*/

	TITLE_EX(15.3, 214);

	Hello(2);

	person People[MaxPeople];

	for (int i = 0; i < MaxPeople; i++)
	{

		printf("\n------------------\nPersonNr.%2d Data:\n", i + 1);
		People[i] = ReadData();
	}
	printf("\n\n================== COMPLETE DATA SHEET ====================\n\n");
	for (int t = 0; t < MaxPeople; t++)
	{
		printf("\n------------------\nPersonNr.%2d Data:\n", t + 1);
		PrintData(People[t]);
	}

	Bye_Message(6, 3, 7);

	return 0;
}

/* Function definitions */


person ReadData(void)
{
	person p;
	printf("\nEnter a Name please => ");
	scanf("%s%*c", p.name);
	printf("\nEnter a Firstname please => ");
	scanf("%s%*c", p.firstname);
	printf("\nFill in birthdate please:");
	p.DayofBirth = ReadDate();
	printf("\nFill in enrollement date please:");
	p.EnrollementDate = ReadDate();
	return p;
}


void PrintData(person People)
{
	COLOR_ON(2);
	printf("\n\tName: %s\n\tFirstname: %s", People.name, People.firstname);

	printf("\n\tBirthDate: ");
	PrintDate(People.DayofBirth);

	printf("\n\tEnrollementDate: ");
	PrintDate(People.EnrollementDate);
	COLOR_OFF();
}

void PrintDate(date AnyDate)
{
	printf(" %d %s %d", AnyDate.Day,AnyDate.Month,AnyDate.Year);
}

date ReadDate(void)
{
	date d;
	// Day
	printf("\nEnter a day(int) please => ");
	scanf("%d%*c", &(d.Day));
	// Month
	printf("\nEnter a month please => ");
	scanf("%s%*c", d.Month);
	// Year
	printf("\nEnter a year(int) please => ");
	scanf("%d%*c", &(d.Year));
	return d;
}

