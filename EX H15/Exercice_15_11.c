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

/* Function declarations */

char menu(void);
void add(FILE*);
void list(FILE*);
void search(FILE*);
void takeOut(FILE*);
void printPhone(Phone*, int);
void line(void);

int main(void)
{
	/* Exercice 15.11

	Assignment:

	Repeat exercises 15.10 and add for each Person also street,
	number, postal code and town information.

	*/

	TITLE_EX(15.11, 217);

	Hello(2);

	// Code 79 

	FILE* fp;
	int stop;

	if ((fp = fopen(FILENAME, "r+b")) == NULL)
	{
		if ((fp = fopen(FILENAME, "w+b")) == NULL)
		{
			printf("\"%s\" cannot be opened\n", FILENAME);
			exit(1);
		}
	}
	stop = 0;
	while (!stop)
	{
		switch (menu())
		{
		case 'e': stop = 1; break;
		case 'a': add(fp); break;
		case 'l': list(fp); break;
		case 's': search(fp); break;
		case 'r': takeOut(fp); break;
		}
	}
	fclose(fp);

	Bye_Message(6, 3, 7);


	return 0;
}

/* Function definitions */

char menu(void)
{
	char s[16]; int i;
	for (i = 0; i < MENU_SIZE; i++)
	{
		printf(" %s : %s\n", menutext[i][0], menutext[i][1]);
	}
	printf("Your choice: ");
	gets(s);
	return s[0];
}

void add(FILE* fp)
{
	Phone a;
	Phone* pa;
	pa = &a;
	memset(pa, '\0', sizeof(Phone)); // set all bytes in Phone to \0

	printf("Name: ");
	gets(pa->name);

	printf("Phone Number: ");
	gets(pa->phoneNr);

	printf("Street name: ");
	gets(pa->StreetName);

	printf("House number: ");
	scanf("%d%*c", &(pa->HouseNumber));

	printf("Postal Code: ");
	scanf("%d%*c", &(pa->PostalCode));

	printf("Town name: ");
	gets(pa->TownName);

	printf("ID: ");
	scanf("%d%*c", &(pa->ID));

	fseek(fp, 0, SEEK_END);
	fwrite(pa, sizeof(Phone), 1, fp);
}

void list(FILE* fp)
{
	Phone a;
	Phone* pa;
	int recnr = 0;
	pa = &a;
	line();
	printf("\n      %4s %20s %12s %12s %12s %9s %20s\n", "ID", "Name", "Phonenumber", "Street name", "House Nr", "Postal code", "Town name");
	line();
	fseek(fp, 0, SEEK_SET);
	while (fread(pa, sizeof(Phone), 1, fp) > 0)
	{
		// removed records with name[0]=='\0' cannot be printed
		if (pa->name[0] != '\0')
			printPhone(pa, recnr);
		recnr++;
	}
	line();
}

void search(FILE* fp)
{
	char Name[StrLength];
	int Found = 0;
	printf("\n\nEnter the name for the person your are looking for: ");
	gets(Name);
	Phone a;
	fseek(fp, 0, SEEK_SET);
	printf("%4s %20s %12s %12s %12s %9s %20s\n","ID", "Name","Phonenumber","Street name","House Nr","Postal code","Town name");
	while (fread(&a, sizeof(Phone), 1, fp) > 0)
	{
		if (strcmp(Name, a.name) == 0)
		{
			printf("%4d %20s %12s %12s %12d %9d %20s\n", a.ID,a.name, a.phoneNr,a.StreetName,a.HouseNumber,a.PostalCode,a.TownName);
			Found = 1;
		}
	}

	if (Found == 0)
	{
		printf("\n\nNo matching result");
	}
}

void takeOut(FILE* fp)
{
	fseek(fp, 0, SEEK_SET);
	char Name[StrLength];
	int Found = 0, Position = 0;
	// put all bytes to '\0' in the record you want to remove
	printf("\n\nWhose record do you wish to remove?Give the name please => ");
	gets(Name);
	Phone a;
	while (fread(&a, sizeof(Phone), 1, fp) > 0 && Found == 0) // Read the file until you come across the right name
	{
		if (strcmp(Name, a.name) == 0)
		{
			fseek(fp, Position * sizeof(Phone), SEEK_SET); // Sets the cusor back before the data you have just read such that we can override it
			strcpy(a.name, "\0");
			strcpy(a.phoneNr, "\0");
			strcpy(a.StreetName, "\0");
			strcpy(a.TownName, "\0");
			a.ID = 0;
			a.PostalCode = 0;
			a.HouseNumber = 0;
			
			fwrite(&a, sizeof(Phone), 1, fp);
			Found = 1;
		}
		Position++;
	}

	if (Found == 0)
	{
		printf("\n\nNo matching result");
	}
}

void printPhone(Phone* pa, int recnr)
{
	printf("%3d : %4d %20s %12s %12s %12d %9d %20s\n", recnr, pa->ID,pa->name, pa->phoneNr,pa->StreetName,pa->HouseNumber,pa->PostalCode,pa->TownName);
}

void line(void)
{
	int i;
	for (i = 0; i < 50; i++)
		printf("-");
	printf("\n");
}