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

void Read_Person(FILE*,person*);
void Calculate(person*,int*,char[],char[],int[]);

int main(int argc,char * argv[])
{
	/* Exercice 16.3

	Assignment:

	Write a program with command line arguments that calculates the 
	age (in number of years) of a number of people based upon their date 
	of birth and the current date.

	- make a text file containing a number of names with their 
	corresponding dates of birth. Make sure names and dates of birth
	are always written in the same way in the text file.

	- write a function “read_person” to read the data of 1 person from the 
	file and save that data into a struct of the type “Person”. This
	struct contains a name field and a field to save the date of birth,
	which is a struct of the type “Date”.

	- call the program from the command line with the current date and
	the text file as arguments

	- write a function “calculate” that calculates the age of a person in 
	years, months and days. This function also determines which person
	is the oldest and which person has the longest name.

	- printing the ages is done in the main function. Print also the names
	of the oldest person and of the person with the longest name.

	*/

	// Check for 5 arguments => 
	// (1) The execution file (.exe)
	// (2) The text's file name containing the data 
	// (3) the day of the current date 
	// (4) the month of the current date 
	// (5) the year of the current date

	// argv[0-4] = { "execution's file name" , "text's file name" , "Day" , "Month" , "Year" };
	//						[0]						 [1]			 [2]	   [3]      [4]

	Control_Arg(argc,5,5);

	TITLE_EX(16.3,220);

	Hello(4);

	FILE * fs; // fs == filesource
	char Filename[StrLength];

	strcpy(Filename, argv[1]);
	fs = fopen(Filename,"r"); // => Mode == 'r' so file has to exist otherwise the return value is "NULL"
	CheckFile(fs, Filename);

	person Somebody;

	int Date[3] = { atoi(argv[2]),atoi(argv[3]), atoi(argv[4]) };
	int MAX_Age,Counter = 0;
	char Longest_Name[NameLength] = "0",MAX_Age_Name[NameLength];

	printf("\n\nThe ages are:");
	while (fscanf(fs,"%s", Somebody.firstname) > 0) // get the name out of file "fs" and store it into the structure "Somebody" of type person
	{
		Counter++; // Keeps track of how many times we have scanned data from the file "fs" 

		Read_Person(fs,&Somebody);

		Calculate(&Somebody,&MAX_Age,MAX_Age_Name,Longest_Name,Date);

		printf("\n%s is %2d year old", Somebody.firstname,Somebody.Age);
	}

	// Print oldest person's name and age
	printf("\n\n\033[32m%s\033[m is the oldest of the \033[32m%d\033[m persons in the file.\n",MAX_Age_Name,Counter);
	// Print the person's name with the longest one
	printf("\nThe person with the longest name is: \033[32m%s\033[m",Longest_Name);

	Bye_Message(5,3,7);

	fclose(fs); // Close file

	return 0;
}

/* Function definitions */

void Read_Person(FILE * fs,person * Somebody)
{
	/* !! FORMAT IN FILE:
	
	Wilbur
	01 03 1996
	Tom
	25 12 1995
	Sarah
	06 06 1999

	*/

	// Day of birth
	fscanf(fs,"%d", &(Somebody->DayofBirth.Day));
	// Month of birth
	fscanf(fs,"%d", &(Somebody->DayofBirth.Month_int));
	// Year of birth
	fscanf(fs,"%d", &(Somebody->DayofBirth.Year));
}

void Calculate(person * Somebody,int * MAX_Age,char MAX_Age_Name[], char Longest_Name[],int Date[])
{
	// 1st calculate the age of the person
	// Current date - Birth date = Age

	// dd - dd
	int days = Date[0] - Somebody->DayofBirth.Day; // Normally we put '*' before a pointer but somebody is already a pointing to "DayofBirth" which is a structure containing a integer 

	// mm - mm
	int months = Date[1] - Somebody->DayofBirth.Month_int;
	if (days <= 0)
	{
		months -= 1;
	}

	// yyyy - yyyy
	Somebody->Age = Date[2] - Somebody->DayofBirth.Year;
	if (months < 0) // Since "days" is already positive "months" can be equal to zero 
	{
		Somebody->Age -= 1;
	}
	 
	// 2nd Verify if this person's age is the greatest so far
	if (*MAX_Age < Somebody->Age)
	{
		strcpy(MAX_Age_Name, Somebody->firstname);
		*MAX_Age = Somebody->Age;
	}

	// 3rd Verify if this person's name is the Longest so far
	if (strlen(Longest_Name) < strlen(Somebody->firstname))
	{
		strcpy(Longest_Name, Somebody->firstname);
	}
}
