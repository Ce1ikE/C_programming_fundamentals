/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#include "MyHeaderEC.h"

/* Function declarations */

void PrintData(FILE*);

int main(void)
{
	/* Exercice 15.7

	Assignment:

	Write a program that reads the data from the file written in the 
	previous exercise. Print the data to the screen as follows:

	Name: Smith
	Age: 25
	Salary: 1950

	*/

	TITLE_EX(15.7,216);

	Hello(2);

	char Filename[StrLength];
	FILE* fs; // fs == file source

	printf("Which is the name of the file from which you want to read the data: ");
	scanf("%s%*c",Filename);

	fs = fopen(Filename, "rb");

	CheckFile(fs, Filename);

	COLOR_ON(6);
	printf("\n\n");
	Print_Line(100, '=');
	printf("\n");
	Print_Line(100, '=');
	printf("\n\n");
	COLOR_OFF();

	PrintData(fs);

	Bye_Message(6,3,7);

	fclose(fs);

	return 0;
}

/* Function definitions */

void PrintData(FILE * fs)
{
	employee emp;
	while (fread(&emp,sizeof(employee),1,fs) > 0)
	{
		COLOR_ON(2);
		printf("\tName: %s\n",emp.Pers.name);
		printf("\tAge: %2d\n", emp.Pers.Age);
		printf("\tSalary: %4d\n", emp.Salary);
		printf("\n");
		COLOR_OFF();
	}
}

