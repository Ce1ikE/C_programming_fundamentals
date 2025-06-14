/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#include "MyHeaderEC.h"
#define MaxPeople 3

/* Function declarations */

person ReadPerson(void);
void SearchTown(person[],person);

int main(void)
{
	/* Exercice 15.5

	Assignment:

	Write a program that asks the user to enter the name and the home town of 3 persons.
	Name and home town are stored in a structure Person.
	The 3 persons are stored in an array.
	Afterwards, the program asks the user to enter a name and searches the town that person lives 
	in.

	Use the functions readPerson and searchTown. The function searchTown has 2 arguments:
	- the array that needs to be searched
	- a variable of the type Person that contains the name that needs to
	be searched. 
	The town member of that variable needs to be filled 
	with the town found by the function searchTown.
	Reading the name of the person you want to search for is done in the 
	main function. Printing the resulting town can also be done in the main
	function. If the name entered is not present in the array, an appropriate 
	message needs to be printed

	*/

	TITLE_EX(15.5,215);

	Hello(2);

	person People[MaxPeople],PersonTBSF; // => "Person to be searched for"

	for (int i = 0; i < MaxPeople; i++)
	{
		People[i] = ReadPerson();
	}

	COLOR_ON(6);
	printf("\n\n");
	Print_Line(100, '=');
	printf("\n");
	Print_Line(100, '=');
	printf("\n\n");
	COLOR_OFF();

	printf("Enter the name of the person you want to search for: ");
	scanf("%s%*c", PersonTBSF.name);

	SearchTown(People, PersonTBSF);

	Bye_Message(6,3,7);


	return 0;
}

/* Function definitions */

person ReadPerson(void)
{
	person AnyPerson;
	// Save Name
	printf("\nEnter a name please: ");
	gets(AnyPerson.name);
	// Save Home Town
	printf("\nEnter a hometown name please: ");
	scanf("%s%*c", AnyPerson.HomeTown);
	return AnyPerson;
}

void SearchTown(person People[], person AnyPerson)
{
	int Found = 0;
	for (int i = 0; i < MaxPeople; i++)
	{
		if (strcmp(People[i].name,AnyPerson.name) == 0)
		{
			COLOR_ON(2);
			printf("\n=> This person Lives in %s",People[i].HomeTown);
			COLOR_OFF();
			Found = 1;
		}
	}
	
	if (Found == 0)
	{
		COLOR_ON(1);
		printf("\n\n\tNO MATCHING RESULTS");
		COLOR_OFF();
	}
}
