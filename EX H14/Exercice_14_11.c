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

void SearchFile(FILE*,char[]);


int main(void)
{
	/* Exercice 14.11

	Assignment:

	Write a program that searches patterns in a text file. A 
	certain string (pattern) needs to be searched in the text file. Every line 
	that contains that pattern, must be printed. Print also the line number.

	*/

	TITLE_EX(14.11, 202);

	Hello(2);

	char Filename[32];
	FILE * fs; // File source

	printf("\nWhich file do you want to read? => ");
	scanf("%s%*c", Filename);
	fs = fopen(Filename, "r");

	CheckFile(fs,Filename);

	SearchFile(fs,Filename);

	Bye_Message(6,3,7);


	return 0;
}

/* Function definitions */


void SearchFile(FILE * fs,char filename[])
{
	char pattern[32];
	printf("\nFor which pattern should I look out for? => ");
	scanf("%s%*c",pattern);

	char Line[STR_BUFFER];
	int WordCounter = 0;
	printf("\nSearch results:\n\nWord number  :\n==============\n");
	while (fscanf(fs,"%s%*c", Line) > 0)
	{
		for (int i = 0; i < STR_BUFFER; i++)
		{
			int m = 0;
			while (Line[i + m] == pattern[m])
			{
				m++;
				if (pattern[m] == '\0')
				{
					printf("%3d          |   %s\n", WordCounter + 1, Line);
				}
			}
		}

		WordCounter++;
	}
	fclose(fs);
	fs = fopen(filename, "r");
	int LineCounter = 0;
	printf("\n\n\nLine number  :\n==============\n");
	while (fgets(Line,STR_BUFFER,fs))
	{
		for (int i = 0; i < STR_BUFFER; i++)
		{
			int m = 0;
			while (Line[i + m] == pattern[m])
			{
				m++;
				if (pattern[m] == '\0')
				{
					printf("%3d          |   %s", LineCounter + 1, Line); // No newline feed required
				}
			}
		}
		LineCounter++;
	}



	fclose(fs);

}