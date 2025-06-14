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
	/* Exercice 15.8

	Assignment:

	Write a program that searches the age and wages of a person based 
	upon a name entered by the user:

	*/

	TITLE_EX(15.8,216);

	Hello(2);

	char Filename[StrLength];
	FILE* fs; // fs == file source

	printf("Which is the name of the file from which you want to read the data: ");
	scanf("%s%*c", Filename);

	fs = fopen(Filename, "r");

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
	char PersonTBSF[StrLength]; // Person to be searched for 
	printf("\nWhat is the name of the person you want to search for?: ");
	gets(PersonTBSF);
	int Found = 0;
	while (fread(&emp,sizeof(employee),1,fs) > 0)
	{

		if (strcmp(emp.Pers.name,PersonTBSF) == 0)
		{
			COLOR_ON(2);
			printf("\n\nName: %s\nAge: %d\nSalary: %d\n",emp.Pers.name,emp.Pers.Age,emp.Salary);
			Found = 1;
			COLOR_OFF();
		}
	}

	if (Found == 0)
	{
		COLOR_ON(1);
		printf("\n\n\tNO MATCHING RESULT");
		COLOR_OFF();
	}

}


