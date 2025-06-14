/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void)
{
	/* Exercice 5.3.17.

	Assignment:
	Write a program that draws a zigzag line until the user enters 
	‘n’ to stop. The first portion of the line is made out of a number of 
	blocks determined by the user. The next portion is only half that 
	length, … If the user wants to draw several zigzag lines, make sure 
	they are all well positioned and drawn correctly.

	*/

	printf("\n\t----\tDit is oefening 5.3.17. van 'Cprogrammingfundamentals2020' Pg85\t----\n\n\n\n");

	int width, offset,Length;
	char Answer;
	printf("Welcome to ZIGZAG world!!\nHow wide do you want your ZIGZAG line?:\t=> ");
	scanf("%d%*c",&width);
	
	Length = width;
	offset = 0;
	int k = 4;

	do 
	{
		for (int x = 1; x < 14; x++)
		{
			for (int t = 0; t < (width / (k / 4)); t++)
			{
				for (int n = 0; n < t + offset; n++)
				{
				printf(" ");
				}
			printf("\xDB\n");
			}

			for (int m = (width / (k / 4)); m > (width / (k / 2)); m--)
			{
	
				for (int s = 0; s < m + offset; s++)
				{
				printf(" ");
				}
			printf("\xDB\n");
			
			}
					
			offset = offset + (width / (k / 2));
			k *= 4;
		}

		printf("\n\n Do you want to draw another ZIGZAG line? (YES = \"y\" / NO = \"n\")\t=> ");
		scanf("%c%*c",&Answer);	

		while (Answer != 'y' && Answer != 'n')
		{
			printf("\n\n\t\033[41mINCORRECT CHOICE\033[m");
			printf("\n\n Do you want to draw another ZIGZAG line? (YES = \"y\" / NO = \"n\")\t=> ");
			scanf("%c%*c", &Answer);
		}

		if (Answer == 'y')
		{
			printf("\nHow wide do you want your ZIGZAG line?:\t=> ");
			scanf("%d%*c", &width);
			offset = 0;
			k = 4;
		}

	} while (Answer == 'y');  // This loop will continue as long as the user will answer "yes"

	printf("\n\n\t END OF CONSTRUCTION\n\n\n\n");

	return 0;
}
