/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#include "MyHeaderEC.h"
#define Namefile "DataSheet.txt"

/* Function declarations */

void Hello(void);
void Bye_Message(void);
void WriteToFile(FILE*);

int main(void)
{
	/* Exercice 14.12

	Assignment:

	Write a program that asks the user to enter the name and 
	age of a chosen number of people and writes that data to a file. The 
	names do not contain any spaces.

	*/

	printf("\n\t----\tDit is oefening 14.12 van 'Cprogrammingfundamentals2020' Pg202\t----\n\n\n\n");

	Hello();

	FILE* fd; // File destination
	char FileName[32] = Namefile;

	fd = fopen(FileName,"w"); // mode "w" => Create or erase to have a clean data file

	if (fd == NULL)
	{
		printf("\n\n\tERROR\n\nUnable to create datafile.");
		exit(-1);
	}

	WriteToFile(fd);

	fclose(fd);

	Bye_Message();


	return 0;
}

/* Function definitions */

void WriteToFile(FILE * fd)
{

	int People;
	printf("For how many people do you want to enter data? => ");
	scanf("%d%*c", &People);

	for (int i = 0; i < People; i++)
	{
		int Age;
		char Name[32];
		printf("Enter name and age: ");
		scanf("%s%d%*c", Name, &Age);
		fprintf(fd, "Name: %s\nAge: %d\n", Name, Age);
		/*	FORMAT IN FILE:
		
		NAME: *******
		AGE: **

		NAME: *******
		AGE: **

		etc..
		
		*/
	}

}