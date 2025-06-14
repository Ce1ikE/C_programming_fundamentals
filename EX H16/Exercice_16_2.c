/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#include "MyHeaderEC.h"
#define MaxLines 10

/* Function declarations */

void CompareFile(FILE*, FILE*);

int main(int argc, char* argv[])
{
	/* Exercice 16.2

	Assignment:

	Write a program with command line arguments that compares two text files. 
	If the files are identical, the program will print an appropriate message. 
	If not, all lines containing differences must be printed to the screen with their line numbers. 
	If the files differ in more than 10 lines, the program can stop printing after the 10th line.

	extra: try to redirect the screen output to a text file without changing the source code.

	*/

	// Check for 3 arguments  => 1) the execution file // 2) the 1st filename // 3) the 2nd filename

	if (argc < 3)
	{
		COLOR_ON(1);
		printf("\n\n\tTOO FEW ARGUMENTS GIVEN");
		COLOR_OFF();
		exit(-1);
	}

	if (argc > 3)
	{
		COLOR_ON(1);
		printf("\n\n\tTOO MANY ARGUMENTS GIVEN");
		COLOR_OFF();
		exit(-1);
	}

	TITLE_EX(16.2,219);
	
	Hello(2);

	FILE * fs1, * fs2;

	char Filename1[StrLength], Filename2[StrLength];
	strcpy(Filename1, argv[1]); // The second string of the string pointer "argv" is copied into "Filename1"
	strcpy(Filename2, argv[2]); // The third string of the string pointer "argv" is copied into "Filename2"

	fs1 = fopen(Filename1,"r");
	fs2 = fopen(Filename2,"r");

	CheckFile(fs1,Filename1); // Check if file exists
	CheckFile(fs2, Filename2);

	CompareFile(fs1, fs2);

	Bye_Message(6,3,7);

	fclose(fs1);
	fclose(fs2);

	return 0;
}

/* Function definitions */

void CompareFile(FILE* fs1, FILE* fs2)
{
	
	char LINE1[STR_BUFFER], LINE2[STR_BUFFER];
	int Counter = 0,Different = 0;

	while (fgets(LINE1,STR_BUFFER,fs1) != NULL && fgets(LINE2, STR_BUFFER, fs2) != NULL && Counter < 10)
	{
		Different = 0;
		if (strcmp(LINE1,LINE2) != 0) // If a letter of the same position in both lines is different in one of the lines then we will notice a change in their aplhabetical order
		{
			Different = 1;
		}

		if (Different == 1 && Counter < MaxLines)
		{
			printf("\n(%2d)\tFILE1: %s\n    \tFILE2: %s",Counter + 1,LINE1,LINE2);
			Counter++;
		}
	}

	if (0 < Counter && Counter < MaxLines)  // Print a appropriate message
	{
		COLOR_ON(1);
		printf("\n\n\tNOTICED %d DIFFERENCES",Counter);
		COLOR_OFF();
	}

	switch (Counter) // Print a appropriate message if the "MaxLines" limit is reached or not at all
	{
	case MaxLines:
	{
		COLOR_ON(1);
		printf("\n\n\tNOTICED MORE THEN %d DIFFERENCES", Counter + 1);
		COLOR_OFF();
		break;
	}
	case 0:
	{
		COLOR_ON(2);
		printf("\n\n\tNOTICED %d DIFFERENCES", Counter);
		COLOR_OFF();
		break;
	}
	default:
		break;
	}



}


