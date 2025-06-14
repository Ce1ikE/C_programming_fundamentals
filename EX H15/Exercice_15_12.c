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
#define FILENAME2 "phone.txt" // FILENAME already defined in header phone

/* Function declarations */

void PrintDataToFile(FILE*,FILE*);

int main(void)
{
	/* Exercice 15.12

	Assignment:

	Make a text file that contains:

	Will Smith; 132 King Street; 2000; Berkeley
	Kylie Minogue; 47 Jason Street; 2850; London 
	Kate O Neil; 65 York Street; 6547; Dover

	or

	Will Smith 132 King Street 2000 Berkeley
	Kylie Minogue 47 Jason Street 2850 London 
	Kate O Neil 65 York Street 6547 Dover

	write a program that reads 1 of these text files line by line and adds the 
	data into the file of the previous exercise.

	*/

	TITLE_EX(15.12,217);

	Hello(2);

	FILE * fs, * fd; // fs == File source , fd == File destination

	fs = fopen(FILENAME2,"r"); // Text file

	fd = fopen(FILENAME,"ab"); // Binary file   // Mode == "ab" Open a binary file in append mode for writing at the end of the file. fopen() creates the file if it does not exist.


	// Check if both files exist
	CheckFile(fs, FILENAME2);
	CheckFile(fd, FILENAME);

	PrintDataToFile(fs, fd);

	fclose(fs);
	fclose(fd);

	Bye_Message(6,3,7);


	return 0;
}

/* Function definitions */


void PrintDataToFile(FILE * fs, FILE * fd)
{
	fseek(fd, 0, SEEK_END); // Sets the cursor to the end of the file

	Phone addphD; // Add Phone Data //!! not Doctorate of Philosophy //!!

	// Use fscanf to scan from the txt file
	// Use fwrite to write into the binary file

	char String[StrLength]; // A help variable

	/* REMEMBER knowing the position of each data type is essential
																   1		2	   3	  4			5	   6	  7
	(Will) (Smith) (132) (King) (Street) (2000) (Berkeley)  => (char[]) (char[]) (int) (char[]) (char[]) (int) (char[])
	Kylie Minogue 47 Jason Street 2850 London					
	(Kate) (O) (Neil) 65 York Street 6547 Dover => But ATTENTION (char[]) (char[]) (char[]) (int) (char[]) (char[]) (int) (char[]) => names require while loop  
																	1		2		 3		  4		 5		   6	  7		 8
	*/

	int Number;

	srand(time(NULL));
	memset(&addphD, '\0', sizeof(Phone));

	while (fscanf(fs,"%s%*c",addphD.name) > 0)
	{
		while (fscanf(fs,"%d", &(addphD.HouseNumber)) == 0) // Continues as long it can't store a integer // Full house number => int
		{	
			fscanf(fs, "%s%*c", String);
			strcat(addphD.name, " ");
			strcat(addphD.name, String); // Full name => char[] + char[] + ... = char[]
		}

		fscanf(fs, "%s%*c", addphD.StreetName);
		fscanf(fs, "%s%*c", String);
		strcat(addphD.StreetName, " ");
		strcat(addphD.StreetName, String); // Full street name => char[] + char[] = char[]
		
		fscanf(fs, "%d%*c", &(addphD.PostalCode)); // Postal code => int

		fscanf(fs, "%s*c", addphD.TownName); // Full town name => char[]

		addphD.ID = rand() % 100; // Random ID number (NOT IMPORTANT!!)

		fwrite(&addphD, sizeof(Phone), 1, fd);

		memset(&addphD, '\0', sizeof(Phone));

	}

	COLOR_ON(2);
	printf("\n\n\tTRANSFER DATA COMPLETE");
	COLOR_OFF();


}
