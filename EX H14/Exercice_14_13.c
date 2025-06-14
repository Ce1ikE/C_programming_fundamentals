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
void ReadFromFile(FILE*);

int main(void)
{
	/* Exercice 14.13

	Assignment:

	Write a program that reads the file created in exercise 14.12 
	and prints all data to the screen

	*/

	TITLE_EX(14.13, 203);

	Hello();

	FILE* fd; // File destination
	char FileName[32] = Namefile;

	fd = fopen(FileName, "r"); // mode "r" => Data file must already exist before reading

	if (fd == NULL)
	{
		printf("\n\n\tERROR\n\nUnable to open datafile.");
		exit(-1);
	}

	ReadFromFile(fd);

	fclose(fd);

	Bye_Message();

	return 0;
}

/* Function definitions */

void ReadFromFile(FILE* fd)
{
	char Line[STR_BUFFER];
	printf("\n\nOUTPUT datafile:\n================\n\n");
	while (fgets(Line,STR_BUFFER,fd) != NULL)
	{
		COLOR_ON(2);
		printf("%s",Line);
		COLOR_OFF();
	}
	printf("\n=================");
	/*	FORMAT IN FILE:

	NAME: *******
	AGE: **

	NAME: *******
	AGE: **

	etc..

	*/


}