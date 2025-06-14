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
void ReadDate(date*);

int main(void)
{
	/* Exercice 15.2

	Assignment:

	 Repeat exercise 15.1 with following additions:
	- a structure Date with a day(int), a month(string) and a year(int)
	- a function that reads a Date
	- a function that prints a Date
	- add a dateOfBirth to the structure Person. dateOfBirth must be
	of the type Date.
	- the function to read a Date must be called in the function
	readPerson
	- the function to print a Date must be called in the function
	printPerson

	*/

	TITLE_EX(15.2, 214);

	Hello(2);

	person People[MaxPeople];

	for (int i = 0; i < MaxPeople; i++)
	{
		printf("\nPersonNr.%2d Data:\n", i + 1);
		People[i] = ReadData();
	}
	printf("\n\n================== COMPLETE DATA SHEET ====================\n\n");
	for (int t = 0; t < MaxPeople; t++)
	{
		printf("\nPersonNr.%2d Data:\n", t + 1);
		PrintData(People[t]);
	}

	Bye_Message(6, 3, 7);

	return 0;
}

/* Function definitions */


person ReadData(void)
{
	person p;
	printf("Enter a Name please => ");
	scanf("%s%*c", p.name);
	printf("Enter a Firstname please => ");
	scanf("%s%*c", p.firstname);
	ReadDate(&(p.DayofBirth));
	return p;
}


void PrintData(person People)
{
	COLOR_ON(4);
	printf("\n\tName: %s\n\tFirstname: %s", People.name, People.firstname);
	PrintDate(People.DayofBirth);
	COLOR_OFF();
}


void PrintDate(date dayofbirth)
{
	printf("\n\tBirthday: %d %s %d",dayofbirth.Day,dayofbirth.Month,dayofbirth.Year);
}

void ReadDate(date * d)
{
	// Day
	printf("Enter a day(int) please => ");
	scanf("%d%*c",&(d->Day));
	// Month
	printf("Enter a month please => ");
	scanf("%s%*c",d->Month);
	// Year
	printf("Enter a year(int) please => ");
	scanf("%d%*c",&(d->Year));
	return d;
}

