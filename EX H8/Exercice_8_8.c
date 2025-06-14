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

/* Function declarations */

void Hello(void);
void Symbol_Filter(char[]);
void Alphabetical_order(char[], char[], char[]);
void Upper_2_Lower_Converter(char[]);

int main(void)
{
	/* Exercice 8.8

	Assignment:
	Repeat exercise 8.7 but now with 3 names

	*/

	printf("\n\t----\tDit is oefening 8.8 van 'Cprogrammingfundamentals2020' Pg129\t----\n\n\n\n");

	Hello();

	char Name_1[32], Name_2[32], Name_3[32];

	printf("Please enter a name : ");
	gets(Name_1);
	Symbol_Filter(Name_1);
	Upper_2_Lower_Converter(Name_1);

	printf("Please enter a name : ");
	gets(Name_2);
	Symbol_Filter(Name_2);
	Upper_2_Lower_Converter(Name_2);

	printf("Please enter a name : ");
	gets(Name_3);
	Symbol_Filter(Name_3);
	Upper_2_Lower_Converter(Name_3);

	Alphabetical_order(Name_1, Name_2, Name_3);

	return 0;



}


void Symbol_Filter(char S[])
{
	int Length;


	int i;
	i = 0;

	do
	{
		Length = strlen(S);
		if ('!' <= S[i] && S[i] <= '@') // ASCII characters with decimal value [32 ; 64]
		{
			for (int t = 0; t + i < Length; t++)
			{
				S[i + t] = S[i + 1 + t];
			}


		}
		else
		{
			i++;
		}


	} while (S[i] != '\0');


}

void Upper_2_Lower_Converter(char S[])
{

	int Sentence_length;
	Sentence_length = strlen(S);

	for (int i = 0; i < Sentence_length; i++)
	{
		if ('A' <= S[i] && S[i] <= 'Z')
		{
			S[i] = S[i] + 32;
		}

	}

}

void Alphabetical_order(char N1[], char N2[], char N3[])
{
	int compare_1,compare_2,compare_3;

	compare_1 = strcmp(N1, N2);
	compare_2 = strcmp(N1, N3);
	compare_3 = strcmp(N2, N3);

	// With 3 names there are 6 combinations possible: 
	/*
		1 | 1 2 3
		2 | 1 3 2
		3 | 2 1 3
		4 | 2 3 1
		5 | 3 1 2
		6 | 3 2 1

		or mathematically 3*2*1 = 6
	*/ 

	if (compare_1 < 0)
	{
		if (compare_2 < 0)
		{
			if (compare_3 < 0)
			{
				printf("\n %s , %s , %s \n\n ", N1, N2, N3); // 1
			}
			else
			{
				printf("\n %s , %s , %s \n\n ", N1, N3, N2); // 2
			}
		}
		else
		{
			if (compare_3 < 0)
			{
				printf("\n %s , %s , %s \n\n ", N2, N3, N1); // 3
			}
			else
			{
				printf("\n %s , %s , %s \n\n ", N3, N1, N2); // 4
			}
		}


	}
	else (compare_1 > 0);
	{
		if (compare_2 < 0)
		{
			if (compare_3 < 0)
			{
				printf("\n %s , %s , %s \n\n ", N2, N1, N3); // 5
			}
		}
		else
		{
			if (compare_3 > 0)
			{
				printf("\n %s , %s , %s \n\n ", N3, N2, N1); // 6
			}
			
		}
		
	}

	
}



void Hello(void)
{

	printf("\n\n");

	printf("\n      \x5F\x5F\x5F\x5F          \x5F\x5F\x5F\x5F           \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F                         ");
	printf("\n     \x2F   \x2F\x5C        \x2F   \x2F\x5C         \x2F   \x2F\x5C      \x2F   \x2F\x5C      \x2F   \x2F\x5C                                       ");
	printf("\n    \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x3A\x5C       \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x3A\x5C                 ");
	printf("\n   \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     ");
	printf("\n  \x2F   \x2F\x3A\x3A\x5C \x5F\x5F\x5F  \x2F   \x2F\x3A\x3A\x5C \x5C\x3A\x5C   \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F  \x5C\x3A\x5C    ");
	printf("\n \x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C  \x2F\x5C\x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C \x5C\x3A\x5C \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F \x5C\x5F\x5F\x5C\x3A\x5C    ");
	printf("\n \x5C\x5F\x5F\x5F\x5C\x2F  \x5C\x3A\x5C\x2F\x3A\x2F\x5C   \x5C\x3A\x5C \x5C\x3A\x5C\x5F\x5C\x2F \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C \x2F  \x2F\x3A\x2F  ");
	printf("\n      \x5C\x5F\x5F\x5F\x5C\x3A\x3A\x2F  \x5C   \x5C\x3A\x5C \x5C\x3A\x5C    \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C  \x2F\x3A\x2F     ");
	printf("\n      \x2F   \x2F\x3A\x2F    \x5C   \x5C\x3A\x5C\x5F\x5C\x2F     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C\x2F\x3A\x2F       ");
	printf("\n     \x2F\x5F\x5F\x5F\x2F\x3A\x2F      \x5C   \x5C\x3A\x5C        \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x3A\x2F                   ");
	printf("\n     \x5C\x5F\x5F\x5F\x5C\x2F        \x5C\x5F\x5F\x5F\x5C\x2F         \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F   ");

	printf("\n\n\n");


}