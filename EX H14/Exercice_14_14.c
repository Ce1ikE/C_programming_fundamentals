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

void SearchFile(FILE*);


int main(void)
{
	/* Exercice 14.14

	Assignment:

	Write a program that searches a name entered by the user in 
	the file created in exercise 14.12 and prints the corresponding age to 
	the screen. Make sure a message is printed when the name is not 
	present in the file.

	*/

	TITLE_EX(14.14, 203);

	Hello(2);

	FILE* fs; //  fs == file source
	char FileName[32];

	printf("\nFrom which file do you want to read the data: => ");
	scanf("%s%*c", FileName);

	fs = fopen(FileName, "r");

	if (fs == NULL)
	{
		printf("\n\n\tERROR\n\nUnable to open data sheet\n");
		exit(-1);
	}
	
	SearchFile(fs);

	Bye_Message(6,3,7);

	fclose(fs);

	return 0;
}

/* Function definitions */

void SearchFile(FILE * fs)
{
	char NameSearching[32];
	printf("\n\nEnter the name of the person you want to find: ");
	scanf("%s%*c", NameSearching);

	printf("\nSearch results:\n================\n");
	int Found = 0;
	char NameFile[32];
	while (fgets(NameFile,32,fs) != NULL)
	{
		for (int i = 0; i < 32; i++)
		{
			int m = 0;
			while (NameFile[i + m] == NameSearching[m])
			{

				m++;
				if (NameSearching[m] == '\0')
				{
					// Knowing the age of the person we are searching for is on the next line
					printf("\n%s",NameFile);
					Found = 1;
					char Age[32];
					fgets(Age,32,fs);
					printf("%s",Age);
				}
			}

		}
	}

	if (Found == 0)
	{
		printf("\n\033[31m==================\nNO MATCHES FOUND\n==================\033[0m");
	}

}

