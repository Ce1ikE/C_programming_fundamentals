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
int Test_Palindrome(char[]);
void Symbol_Filter(char[]);
void Upper_2_Lower_Converter(char[]);


int main(void)
{
	/* Exercice 8.5

	Assignment:
	Repeat exercise 8.3 but this time for sentences that form a word 
	based palindrome.
	examples: “He says: it is true, true is it, says he”

	*/

	printf("\n\t----\tDit is oefening 8.5 van 'Cprogrammingfundamentals2020' Pg129\t----\n\n\n\n");

	Hello();

	int Test_result;
	char Sentence[64];

	printf("Write a sentence please (and press enter) : => ");

	Symbol_Filter(Sentence);

	Upper_2_Lower_Converter(Sentence);

	Test_result = Test_Palindrome(Sentence);

	switch (Test_result)
	{
	case 0:
	{

		printf("\n\t THIS IS NOT A PALINDROME SENTENCE");

		break;
	}



	case 1:
	{

		printf("\n\t THIS IS A PALINDROME SENTENCE");

		break;
	}



	default:
		break;
	}



	return 0;

}

void Symbol_Filter(char S[])
{
	int Length;
	gets(S); // Saving the whole sentence in the string "S" alias for sentence

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



int Test_Palindrome(char S[])
{
	int Test_var, Sentence_length;
	Test_var = 1;
	int Old_word;
	Old_word = 0;

	Sentence_length = strlen(S);

	for (int t = 0; t < Sentence_length / 2; t++)
	{
		if (S[t] == ' ')
		{
			
			for (int s = 0; s < t - Old_word; s++)
			{
				if (S[t - s - 1] != S[Sentence_length - s - 1 - Old_word])
				{

					Test_var = 0;

				}
				
				
			}
			Old_word = t + 1;
			
		}


	}




	return Test_var;

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