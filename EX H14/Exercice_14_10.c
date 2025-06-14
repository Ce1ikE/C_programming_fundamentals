/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#define FileToWriteTo "Result_Num1_AND_Num2.txt"

/* Function declarations */

void Hello(void);
void Bye_Message(void);
void CheckFile(FILE*, char[]);
void PrintFile(FILE*, char[]);
void CalculateFile(FILE*, FILE*);


int main(void)
{
	/* Exercice 14.10

	Assignment:

	Use a text editor to create 2 different files that both contain a 
	row of integer numbers, ordered from small to large. Write a program 
	that combines the numbers in both files to create 1 ordered row and 
	writes these numbers in that order to a new file. Again, no arrays can 
	be used.

	*/

	printf("\n\t----\tDit is oefening 14.10 van 'Cprogrammingfundamentals2020' Pg202\t----\n\n\n\n");

	Hello();

	FILE* fs1, * fs2;

	char Filesource1[32], Filesource2[32];

	printf("\nWhat is the name of the file from which you want to read the numbers? => ");
	scanf("%s%*c", Filesource1);
	fs1 = fopen(Filesource1, "r");
	CheckFile(fs1, Filesource1);

	printf("\nWhat is the name of the other file from which you want to read the numbers? => ");
	scanf("%s%*c", Filesource2);
	fs2 = fopen(Filesource2, "r");
	CheckFile(fs2, Filesource2);

	PrintFile(fs1, Filesource1); // Printing original file 1
	PrintFile(fs2, Filesource2); // Printing original file 2

	fclose(fs1);
	fclose(fs2);
	fs1 = fopen(Filesource1, "r");
	fs2 = fopen(Filesource2, "r");

	CalculateFile(fs1, fs2); // Printing merged file (ordered row)

	fclose(fs1);
	fclose(fs2);

	Bye_Message();


	return 0;
}

/* Function definitions */


void CheckFile(FILE* fs, char Filesource[])
{
	while (fs == NULL)
	{
		int Answer;
		printf("\n\n\t\033[31mERROR\033[m\nCouldn't find file : \"%s\"  \nContinue?(Yes = 1 , No = 0)\n=> ", Filesource);
		scanf("%d%*c", &Answer);

		while (Answer != 1 && Answer != 2)
		{
			printf("\n\n\t\033[31mERROR\033[m\nIncorrect Nr.\nChoose again.(Yes = 1 , No = 0)\n=>");
			scanf("%d%*c", &Answer);
		}

		switch (Answer)
		{
		case 1: // Yes

			printf("\nWhat do you want to do?\n\n\t1.Read from file\n\t2.Write to new file \n\t3.read and write from/to file\n\t(Choose a correct Nr.) => ");
			scanf("%d%*c", &Answer);

			while (Answer != 1 && Answer != 2 && Answer != 3)
			{
				printf("\n\n\t\033[31mERROR\033[m\nIncorrect Nr.\nChoose again.(Yes = 1 , No = 0)\n=>");
				scanf("%d%*c", &Answer);
			}

			switch (Answer)
			{
			case 1:
				printf("\n\nGive the name of the file please: ");
				scanf("%s%*c", Filesource);
				fs = fopen(Filesource, "r");
				break;
			case 2:
				printf("\n\nGive a name for the file please: ");
				scanf("%s%*c", Filesource);
				fs = fopen(Filesource, "w");
				break;
			case 3:
				printf("\n\nGive the name of the file please: ");
				scanf("%s%*c", Filesource);
				fs = fopen(Filesource, "r+");
				break;
			default:
				break;
			}

			break;
		case 0: // No

			exit(-1);

			break;

		default:
			break;
		}

	}
}

void PrintFile(FILE* fs, char Filesource[])
{
	printf("\n\n%s: ", Filesource);
	int Num;
	while (fscanf(fs, "%d%*c", &Num) > 0)
	{
		printf("%3d |", Num);
	}
}


void CalculateFile(FILE* fNumbers1, FILE* fNumbers2)
{
	FILE* fd; // File destination
	fd = fopen(FileToWriteTo,"w");

	// Use fscanf(use %d) to scan for the numbers in the files
	int Num1, Num2,ret2,ret1;
	ret2 = fscanf(fNumbers2, "%d%*c", &Num2);
	ret1 = fscanf(fNumbers1, "%d%*c", &Num1);
	while (ret1 > 0 && ret2 > 0) // We are forced to put the "fscanf" into the "while" condition otherwise we risk to end up in a endless loop
	{

		if (Num1 > Num2)
		{
			do
			{
				fprintf(fd,"%d ", Num2);

			} while ((ret2 = fscanf(fNumbers2, "%d%*c", &Num2)) > 0 && Num1 > Num2); // Same here. We are forced again to put the "fscanf" into the "while" condition otherwise we risk to end up in a endless loop
		}

		fprintf(fd,"%d ", Num1);
		ret1 = fscanf(fNumbers1, "%d%*c", &Num1);
	}
	// In case there is not a equal amount of numbers in both files we need to check
	//  if we still need to print some numbers from each file


	if (ret2 > 0)
	{
		do
		{
			printf(fd,"%d ", Num2);
		} while ((ret2 = fscanf(fNumbers2, "%d%*c", &Num2)) > 0);
	}


	if (ret1 > 0)
	{
		do
		{
			printf(fd,"%d ", Num1);
		} while ((ret1 = fscanf(fNumbers1, "%d%*c", &Num1)) > 0);
	}

}


void Hello(void)
{

	printf("\n\n\033[0;32m");

	printf("\n\t\t      \x5F\x5F\x5F\x5F          \x5F\x5F\x5F\x5F           \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F                ");
	printf("\n\t\t     \x2F   \x2F\x5C        \x2F   \x2F\x5C         \x2F   \x2F\x5C      \x2F   \x2F\x5C      \x2F   \x2F\x5C                                       ");
	printf("\n\t\t    \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x3A\x5C       \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x3A\x5C                 ");
	printf("\n\t\t   \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     ");
	printf("\n\t\t  \x2F   \x2F\x3A\x3A\x5C \x5F\x5F\x5F  \x2F   \x2F\x3A\x3A\x5C \x5C\x3A\x5C   \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F  \x5C\x3A\x5C    ");
	printf("\n\t\t \x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C  \x2F\x5C\x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C \x5C\x3A\x5C \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F \x5C\x5F\x5F\x5C\x3A\x5C    ");
	printf("\n\t\t \x5C\x5F\x5F\x5F\x5C\x2F  \x5C\x3A\x5C\x2F\x3A\x2F\x5C   \x5C\x3A\x5C \x5C\x3A\x5C\x5F\x5C\x2F \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C \x2F  \x2F\x3A\x2F  ");
	printf("\n\t\t      \x5C\x5F\x5F\x5F\x5C\x3A\x3A\x2F  \x5C   \x5C\x3A\x5C \x5C\x3A\x5C    \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C  \x2F\x3A\x2F     ");
	printf("\n\t\t      \x2F   \x2F\x3A\x2F    \x5C   \x5C\x3A\x5C\x5F\x5C\x2F     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C\x2F\x3A\x2F       ");
	printf("\n\t\t     \x2F\x5F\x5F\x5F\x2F\x3A\x2F      \x5C   \x5C\x3A\x5C        \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x3A\x2F                   ");
	printf("\n\t\t     \x5C\x5F\x5F\x5F\x5C\x2F        \x5C\x5F\x5F\x5F\x5C\x2F         \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F   ");

	printf("\n\n\n\033[0m");

}


void Bye_Message(void)
{
	for (int c = 6, t = 7, s = 3; c <= 6; c++)
	{
		printf("\033[%d;%d%dm", t, s, c);
		printf("\n\n");

		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDC\xDB\xDB\xDC\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xDC\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDF\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");

		printf("\n\n\n");
		printf("\033[0m");
	}
}