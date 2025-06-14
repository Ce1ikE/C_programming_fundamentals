/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#include "MyHeaderEC.h"
#define MaxPeople 5 // => N = nbr of People

/* Function declarations */

person ReadData(void);
void PrintData(person);

int main(void)
{
	/* Exercice 15.1

	Assignment:

	Write a program with functions:
	- define a structure “Person” with 2 members: name and firstname
	- declare an array of N persons (take N = 5 for instance)
	- read the data of N persons
	- print that data
	write at least following functions:
	- a function to read the data of 1 Person
	- a function to print the data of 1 Person

	*/

	TITLE_EX(15.1,213);

	Hello(2);

	person People[MaxPeople];

	for (int i = 0; i < MaxPeople; i++)
	{
		printf("PersonNr.%2d Data:\n", i + 1);
		People[i] = ReadData();
	}
	printf("\n\n================== COMPLETE DATA SHEET ====================\n\n");
	for (int t = 0; t < MaxPeople; t++)
	{
		printf("PersonNr.%2d Data:", t + 1);
		PrintData(People[t]);
	}

	Bye_Message(6,3,7);

	return 0;
}

/* Function definitions */


person ReadData(void)
{
	person p;
	printf("Enter a Name please => ");
	scanf("%s%*c",p.name);
	printf("Enter a Firstname please => ");
	scanf("%s%*c",p.firstname);
	return p;
}


void PrintData(person People)
{
	COLOR_ON(4);
	printf("\n\tName: %s\n\tFirstname: %s\n",People.name,People.firstname);
	COLOR_OFF();
}
