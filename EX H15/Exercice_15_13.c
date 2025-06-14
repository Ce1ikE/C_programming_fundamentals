/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#include "MyHeaderEC.h"
#include "Phone.h"
#define MaxPeople 25


/* Function declarations */

void GetNames(FILE*, char[][StrLength],int*);
void OrderList(char[][StrLength],int*);
void PrintOrderedList(FILE*, char[][StrLength],int*);


int main(void)
{
	/* Exercice 15.13

	Assignment:

	Repeat exercise 15.7 and add a function that prints the 
	addresses ordered with the names(CORRECTION) alphabetically. 

	Hint: define a two dimensional array with a record number for every 
	person in the file:

	*/

	TITLE_EX(15.13,217);

	Hello(2);

	char Names[MaxPeople][StrLength];
	int * TotalPeople;
	FILE* fs; 
	fs = fopen(FILENAME, "rb"); // Mode == 'rb' => file must exist
	CheckFile(fs,FILENAME); // Perform a test to see wether "FILENAME"(phone.dat) truly exists

	GetNames(fs, Names,&TotalPeople);


	OrderList(Names,&TotalPeople);

	PrintOrderedList(fs, Names, &TotalPeople);

	Bye_Message(6,3,7);


	return 0;
}

/* Function definitions */

void GetNames(FILE * fs, char Names[][StrLength],int * TotalPeople)
{
	fseek(fs, 0, SEEK_SET); // Set cursor of the file to the begining
	Phone a;
	int i = 0; // Index for the matrix "Names"

	while (fread(&a,sizeof(Phone), 1, fs) > 0 && i < MaxPeople) // fread because we are reading from a binary file
	{
		strcpy(Names[i],a.name);
		i++;
	}
	*TotalPeople = i;
	fseek(fs, 0, SEEK_SET);
	Print_Line(100, '=');
	printf("\n\nLIST NOT ORDERED\n\n%2s  %10s   %12s\n","Nr", "Names", "Address");
	i = 0;
	while (fread(&a, sizeof(Phone), 1, fs) > 0 && i < MaxPeople)
	{
		printf("%2d  %15s   %15s  %4d %15s\n", i + 1, Names[i], a.StreetName, a.PostalCode, a.TownName);
		i++;
	}

}

void OrderList(char Names[][StrLength],int * TotalPeople)
{
	char GetHelp[StrLength];
	int m;
	// Use bubble sort

	for (int i = 0; i < (*TotalPeople - 1); i++)
	{
		for (int m = 0; m < (*TotalPeople - 1 - i); m++)
		{
			if (strcmp(Names[m], Names[m + 1]) > 0)
			{
				strcpy(GetHelp, Names[m + 1]);
				strcpy(Names[m + 1], Names[m]);
				strcpy(Names[m], GetHelp);
			}
		}	
	}
}

void PrintOrderedList(FILE * fs, char Names[][StrLength],int * TotalPeople)
{
	fseek(fs, 0, SEEK_SET);

	Print_Line(100, '=');
	printf("\n\n");

	Phone a;
	int i = 0;
	printf("\n\nLIST ORDERED\n\n");
	while (fread(&a,sizeof(Phone), 1, fs) > 0 && i < TotalPeople)
	{
		if (strcmp(a.name,Names[i]) == 0)
		{
			COLOR_ON(2);
			printf("\n\n\tName: %s\n\tStreet name and Nr: %s %2d\n\tPostal: %d\n\tTown name: %s",a.name,a.StreetName,a.HouseNumber,a.PostalCode,a.TownName);
			COLOR_OFF();
			i++;
			fseek(fs, 0, SEEK_SET);
		}
	}



}
