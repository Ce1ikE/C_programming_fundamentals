/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#define Max_Tests 10
#define Max_Parts 20

/* Function declarations */

void Fill_DataMatrix(int[][Max_Tests]);
void Print_DataMatrix(int[][Max_Tests],int,int);
void Hello(void);
void Bye_Message(void);
int Read_Number(int);
void Read_Data(int[][Max_Tests],int,int);
void Print_Data_Results_Parts(int[][Max_Tests],int,int);
void Print_Data_Results_Test(int[][Max_Tests],int,int);

int main(void)
{
	/* Exercice 9.10

	Assignment:
	Write a program to process test results.
	To guarantee the product quality, a company takes a sample of N
	finished parts (0 < N ≤ 20) and submits them to a series of M tests
	(0 < M ≤ 10). If a part fails one or more tests, data is sent to the
	computer in the format:

				PartNumber TestNumber Result
	

	A part is rejected if at least 1 fatal error or at least 3 small errors have occurred.
	The program first reads the amount of parts tested (N) and the number of tests executed per part (M). Then, the test results for all failed parts are read until 0 0 0 is entered.
	The program prints:
	- a table with a line for every tested part (so also the ones that did
	not fail any test) containing information on the test results and a final assessment
	- a second table with a line per test containing the number of parts that did not fail, the number of parts that showed a small error and the number of parts that showed a fatal error.
	The program uses functions:
	- a function ReadNumber that is used twice. Once to read the number
	of parts tested (N) and once to read the number of tests (M).
	Make sure only valid numbers are accepted.
	- a function to read all test data
	- a function to print the results per part
	- a function to print the results per test
	- optional: a function to count the number of occurrences of a certain
	value in a certain column

	*/

	printf("\n\t----\tDit is oefening 9.10 van 'Cprogrammingfundamentals2020' Pg140\t----\n\n\n\n");

	Hello();

	int Data_Matrix[Max_Parts][Max_Tests];
	int Tests, Parts;

	Tests = Read_Number(2);

	Parts = Read_Number(1);

	Read_Data(Data_Matrix, Tests,Parts);

	Fill_DataMatrix(Data_Matrix, Tests, Parts);

	Print_DataMatrix(Data_Matrix,Tests,Parts);

	Print_Data_Results_Parts(Data_Matrix,Tests,Parts);

	Print_Data_Results_Test(Data_Matrix, Tests, Parts);


	Bye_Message();


	return 0;
}






int Read_Number(int N)
{
	int Response;


	if (N == 1)
	{
		printf("\n How many PARTS did you test? => ");
		scanf("%d%*c", &Response);
		while (Response <= 0 || Max_Parts < Response)
		{
			printf("\n\t ERROR : AVAILABLE PARTS [0 ; %2d]",Max_Parts);
			printf("\n How many PARTS did you actually test? => ");
			scanf("%d%*c", &Response);
		}
	}
	else
	{
		printf("\n How many TESTS did you run? => ");
		scanf("%d%*c", &Response);
		while (Response <= 0 || Max_Tests < Response)
		{
			printf("\n\t ERROR : AVAILABLE TESTS [0 ; %2d]",Max_Tests);
			printf("\n How many TESTS did you actually run? => ");
			scanf("%d%*c", &Response);
		}
	}

	return Response;


}

void Fill_DataMatrix(int Data_Matrix[][Max_Tests], int Tests, int Parts)
{
	for (int i = 0; i < Parts; i++)
	{

		for (int t = 0; t < Tests; t++)
		{
			if (Data_Matrix[i][t] != 1 && Data_Matrix[i][t] != 3)
			{
				Data_Matrix[i][t] = 0;
			}
			
		}
	}



}

void Read_Data(int Data[][Max_Tests],int Tests,int Parts)
{

	int i,j,Number_of_Inputs = 0;
	
	printf("\n\n Enter the test results (END = 0 0 0)\n");
	printf("PARTNUMBER TESTNUMBER RESULT\n----------------------------------\n");
	scanf("%d%d%*c",&i,&j); // First Data Entry
	
	
	while (i != 0 && j != 0 && Data[i][j] != 0)
	{
		while (i > Parts || i <= 0 || j > Tests || j <= 0)
		{
			

			if (i > Parts || i <= 0)
			{
				printf("\n INPUT ERROR : Part number incorrect in Column %d", 1);
			}

			if (j > Tests || j <= 0)
			{
				printf("\n INPUT ERROR : Test number incorrect in Column %d", 2);
							
			}

			printf("\n\n Reenter the test result please (END = 0 0 0)\n PARTNUMBER(Max : %2d) TESTNUMBER(Max : %2d) RESULT(1 or 3) \n\n", Parts, Tests);
			scanf("%*d%*c %d%d%*c", &i, &j);
			// I clear the buffer with the remaining number left because we ask the user to reenter a new entry
		}
		

		scanf("%d%*c", &Data[i-1][j-1]); 

		if (Data[i-1][j-1] != 1 && Data[i-1][j-1] != 3)
		{
			printf("\n INPUT ERROR : Result number incorrect in Column %d", 3);
			printf("\n\n Reenter the test result please (END = 0 0 0)\n PARTNUMBER(Max : %2d) TESTNUMBER(Max : %2d) RESULT(1 or 3) \n\n", Parts, Tests);
			
		}
		
		scanf("%d%d%*c",&i,&j); // Next Data Entry
		
		
	}

	

}

// Helper 
void Print_DataMatrix(int Data[][Max_Tests],int Tests, int Parts)
{
	printf("\n\n Here is the full Data Matrix:\n\n");

	for (int i = 0; i < Parts; i++)
	{
		printf("Part %2d \t", i + 1);

		for (int t = 0; t < Tests; t++)
		{
			printf("%2d ", Data[i][t]);
		}
		printf("\n");
	}
	printf("\n\n");
}



void Print_Data_Results_Parts(int Data[][Max_Tests],int Tests,int Parts)
{
	printf("\n\n Results per part:\n\n Part number \t\t\t      Tests   \t\t Assessment");
	

	// Print number of tests
	printf("\n \t\t\t\t ");
	for (int t = 0; t < Tests; t++)
	{
		printf("%2d ", t + 1);
	}
	
	// Print line
	printf("\n");
	for (int m = 0; m < 50; m++)
	{
		printf("--");
	}
	
	
	// Print results
	printf("\n");
	for (int i = 0; i < Parts; i++)
	{
		int Assessment = 0;
		printf("%d \t\t\t\t ", i + 1);

		for (int q = 0; q < Tests; q++)
		{
			
			if (Data[i][q] == 1)
			{
				printf("%2d ", Data[i][q]);
				Assessment++;
			}
			else
			{
				if (Data[i][q] == 3)
				{
					printf("%2d ", Data[i][q]);
					Assessment += 3;
				}
				else
				{
					printf("%2d ", 0);
				}
			}
			
			
		}
		

		if (Assessment >= 3)
		{
			printf("\t Rejected \n");
		}
		else
		{
			printf("\t Accepted \n");
		}




	}

	
	

	// Print line
	printf("\n");
	for (int m = 0; m < 50; m++)
	{
		printf("--");
	} 
	
}

void Print_Data_Results_Test(int Data[][Max_Tests], int Tests, int Parts)
{

	printf("\n\n Results per Test:\n\n Test \t\t\t\tFailures \n \t\t\t None \t Small \t Fatal");
	
	// Print line
	printf("\n");
	for (int m = 0; m < 50; m++)
	{
		printf("--");
	}
	
	int Sum_None_Total = 0, Sum_Small_Total = 0, Sum_Fatal_Total = 0;

	// Print Results
	printf("\n");
	for (int t = 0; t < Tests; t++)
	{
		printf("%2d ", t + 1);

		int Sum_None = 0, Sum_Small = 0, Sum_Fatal = 0;

		for (int i = 0; i < Parts; i++)
		{
			
			if (Data[t][i] == NULL)
			{
				Sum_None++;
				Sum_None_Total++;
			}
			if (Data[t][i] == 1)
			{
				Sum_Small++;
				Sum_Small_Total++;
			}

			if (Data[t][i] == 3)
			{
				Sum_Fatal++;
				Sum_Fatal_Total++;
			}


		}

		printf("\t\t\t %2d \t %2d \t %2d \n", Sum_None, Sum_Small, Sum_Fatal);

	}

	// Print line
	printf("\n");
	for (int m = 0; m < 50; m++)
	{
		printf("--");
	}


	printf("\nTOTAL \t\t\t %2d \t %2d \t %2d \n", Sum_None_Total, Sum_Small_Total, Sum_Fatal_Total);

}



void Hello(void)
{

	printf("\n\n");

	printf("\n\t      \x5F\x5F\x5F\x5F          \x5F\x5F\x5F\x5F           \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F                         ");
	printf("\n\t     \x2F   \x2F\x5C        \x2F   \x2F\x5C         \x2F   \x2F\x5C      \x2F   \x2F\x5C      \x2F   \x2F\x5C                                       ");
	printf("\n\t    \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x3A\x5C       \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x3A\x5C                 ");
	printf("\n\t   \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     ");
	printf("\n\t  \x2F   \x2F\x3A\x3A\x5C \x5F\x5F\x5F  \x2F   \x2F\x3A\x3A\x5C \x5C\x3A\x5C   \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F  \x5C\x3A\x5C    ");
	printf("\n\t \x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C  \x2F\x5C\x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C \x5C\x3A\x5C \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F \x5C\x5F\x5F\x5C\x3A\x5C    ");
	printf("\n\t \x5C\x5F\x5F\x5F\x5C\x2F  \x5C\x3A\x5C\x2F\x3A\x2F\x5C   \x5C\x3A\x5C \x5C\x3A\x5C\x5F\x5C\x2F \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C \x2F  \x2F\x3A\x2F  ");
	printf("\n\t      \x5C\x5F\x5F\x5F\x5C\x3A\x3A\x2F  \x5C   \x5C\x3A\x5C \x5C\x3A\x5C    \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C  \x2F\x3A\x2F     ");
	printf("\n\t      \x2F   \x2F\x3A\x2F    \x5C   \x5C\x3A\x5C\x5F\x5C\x2F     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C\x2F\x3A\x2F       ");
	printf("\n\t     \x2F\x5F\x5F\x5F\x2F\x3A\x2F      \x5C   \x5C\x3A\x5C        \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x3A\x2F                   ");
	printf("\n\t     \x5C\x5F\x5F\x5F\x5C\x2F        \x5C\x5F\x5F\x5F\x5C\x2F         \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F   ");

	printf("\n\n\n");


}



void Bye_Message(void)
{

	printf("\n\n");

	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDF\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDC\xDB\xDB\xDC\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xDC\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDF\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

	printf("\n\n\n");

}