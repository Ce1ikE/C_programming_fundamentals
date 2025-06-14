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
void Alphabetical_order(char[], char[]);
void Upper_2_Lower_Converter(char[]);

int main(void)
{
	/* Exercice 8.7

	Assignment:
	Write a program that reads 2 names and prints them alphabetically.

	*/

	printf("\n\t----\tDit is oefening 8.7 van 'Cprogrammingfundamentals2020' Pg129\t----\n\n\n\n");

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

	Alphabetical_order(Name_1, Name_2);

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

void Alphabetical_order(char N1[], char N2[])
{
	int compare;
	compare = strcmp(N1, N2);

	if (compare < 0)
	{
		printf("\n %s , %s \n\n ", N1, N2);

	}
	else
	{
		if (compare > 0)
		{
			printf("\n %s , %s \n\n ", N2, N1);
		}
		else
		{
			printf("\n %s , %s \n\n ", N1, N2);
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