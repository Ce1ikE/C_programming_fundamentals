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

void CopyFile(FILE*, FILE*);

int main(int argc,char * argv[])
{
	/* Exercice 16.1

	Assignment:

	 Write a program with name "mycopy.exe" that expects 2 command 
	line arguments and that copies one file to another.
	Example:

	mycopy text.txt copy.txt
	
	copies the content of "text.txt" into the file "copy.txt".

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

	TITLE_EX(16.1,219);

	Hello(2);

	FILE* fs, * fd;
	char Filename1[StrLength], Filename2[StrLength];
	strcpy(Filename1, argv[1]); // The second string of the string pointer "argv" is copied into "Filename1"
	strcpy(Filename2, argv[2]); // The third string of the string pointer "argv" is copied into "Filename2"

	fs = fopen(Filename1,"r");
	fd = fopen(Filename2,"w");

	CheckFile(fs, Filename1);
	CheckFile(fd, Filename2);

	CopyFile(fs, fd);

	COLOR_ON(2);
	printf("\n\n\tCOPY SUCCEEDED");
	COLOR_OFF();

	Bye_Message(6,3,7);

	fclose(fs);
	fclose(fd);


	return 0;
}

/* Function definitions */

void CopyFile(FILE * fs, FILE * fd)
{
	char LINE[STR_BUFFER];

	while (fgets(LINE,STR_BUFFER,fs) != NULL) // get a string (LINE) of length "STR_BUFFER"(512) from file "fs" 
	{
		fprintf(fd, "%s", LINE);// Print the string "LINE" into the file "fd"
	}
}
