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

void ReadWriteData(FILE*);

int main(void)
{
	/* Exercice 15.6

	Assignment:

	Write a program that reads name, age and salary of a chosen 
	number of people and stores that information into a file. All data of 1 
	person is stored in a structure. Once the data of 1 person is read, the 
	structure containing that data is written to a file at once. Afterwards, 
	the data of the next person is read, … Make sure the names can contain 
	spaces!

	*/

	TITLE_EX(15.6,215);

	Hello(2);

	int MaxPeople;
	char Filename[StrLength];
	FILE* fd; // file destination
	printf("\nFor how many people do you want to enter data? => ");
	scanf("%d%*c", &MaxPeople);
	printf("\nTo Which file should the data be send to? => ");
	scanf("%s%*c",Filename);
	fd = fopen(Filename, "wb");
	CheckFile(fd, Filename); // Quite unnecessary because we are using the 'wb' mode which creates a new file or erases the content of the file 

	for (int i = 0; i < MaxPeople; i++)
	{
		ReadWriteData(fd);
	}


	Bye_Message(6,3,7);

	fclose(fd);

	return 0;
}

/* Function definitions */

void ReadWriteData(FILE * fd)
{
	employee emp;
	printf("\nEnter a name please: ");
	gets(emp.Pers.name);
	printf("\nEnter a age please: ");
	scanf("%d%*c", &(emp.Pers.Age));
	printf("\nEnter a salary: ");
	scanf("%d%*c", &(emp.Salary));

	fwrite(&emp,sizeof(employee), 1, fd);


}