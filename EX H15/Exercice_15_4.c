/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#include "MyHeaderEC.h"
#define MaxStudents 2

/* Function declarations */

student ReadData(void);
void PrintData(student);
void ReadAddress(address*);
void PrintAddress(address);

int main(void)
{
	/* Exercice 15.4

	Assignment:

	Define a structure Address with "streetAndNr", "postalCode", "town" and "phoneNr". 

	Define a structure Student with a "name", "homeAddress" and "schoolAddress".

	Write a program to test the structures defined.

	Write a function that reads an Address:
			readAddress(Address *p)
	
	Both addresses are read with this function. Change the parameters 
	passed on to the function to read in the correct type of address.
	Ditto to print an Address:
			printAddress( Address p)

	*/

	TITLE_EX(15.4,214);

	Hello(2);

	student Allstudents[MaxStudents];

	for (int i = 0; i < MaxStudents; i++)
	{
		printf("\n");
		Print_Line(27, '-');
		printf("\nFill in student data Nr.%2d:\n", i + 1);
		Allstudents[i] = ReadData();
	}
	Print_Line(40,'=');
	printf(" COMPLETE DATA SHEET ");
	Print_Line(40, '=');
	for (int t = 0; t < MaxStudents; t++)
	{
		printf("\n");
		Print_Line(27, '-');
		printf("\nstudent data Nr.%2d:\n", t + 1);
		PrintData(Allstudents[t]);
	}



	Bye_Message(6,3,7);


	return 0;
}

/* Function definitions */


student ReadData(void)
{
	student s;
	printf("\nEnter the name of the student please : ");
	scanf("%s%*c",s.Personal.name);
	printf("\nEnter the firstname of the student please : ");
	scanf("%s%*c", s.Personal.firstname);
	printf("\nFill in home address:\n"); // Goes to function 'ReadAdress'
	Print_Line(19, '+');
	ReadAddress(&(s.HomeAddress));
	printf("\nFill in School address:\n"); // Goes to function 'ReadAdress' again
	Print_Line(19, '+');
	ReadAddress(&(s.SchoolAddress));
	return s;
}

void PrintData(student AnyStudent)
{
	COLOR_ON(2);
	printf("\n\tName: %s\n\tFirstname: %s",AnyStudent.Personal.name,AnyStudent.Personal.firstname);
	printf("\n\tHome address:");
	PrintAddress(AnyStudent.HomeAddress);
	printf("\n\tSchool address:");
	PrintAddress(AnyStudent.SchoolAddress);
	COLOR_OFF();
}

void ReadAddress(address * AnyAddress)
{
	
	printf("\nEnter street name and Nr => ");
	gets(AnyAddress->StreetAndNr); // p->d == *(p).d

	printf("\nEnter postalcode => ");
	scanf("%d%*c",&(AnyAddress->PostaCode));

	printf("\nEnter town name => ");
	gets(AnyAddress->Town);

	printf("\nEnter phonenumber => ");
	gets(AnyAddress->PhoneNr);
	
}

void PrintAddress(address AnyAddress)
{
	printf("\n\tStreet name and Nr: %s\n\tPostalcode: %4d Town: %s\n\tPhonenumber: %s",AnyAddress.StreetAndNr,AnyAddress.PostaCode,AnyAddress.Town,AnyAddress.PhoneNr);
}

