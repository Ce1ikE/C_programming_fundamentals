/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Function declarations */

void Draw_bar(int, char);

int main(void)
{
	/* Exercice 6.12

	Assignment:
	Write a program that reads a number of scores. The scores are all 
	positive integer numbers. A negative number is entered to indicate that 
	all scores were entered.
	For each score, a bar with a length equal to the score is drawn. To this 
	end, a predefined symbol needs to be printed as many times as the 
	score. (for loop).
	Write a function draw_bar that takes a score as input and draws a bar 
	with corresponding length. The scores and the wanted symbol are read 
	in the main function

	*/

	printf("\n\t----\tDit is oefening 6.12 van 'Cprogrammingfundamentals2020' Pg106\t----\n\n\n\n");

	int score,number_of_scores;
	char symbol;
	number_of_scores = 0;

	printf("What symbol would you like to use? :\t");
	scanf("%c%*c",&symbol);
	printf("\n\n Enter scores please, finish with a negative number:\t");
	scanf("%d", &score);

	while (score > 0)
	{
		
	

		if (score > 0)
		{
		number_of_scores++;
		}

		if (number_of_scores > 0)
		{

		printf("\n Score = %4d\t", score);
		Draw_bar(score, symbol);
		}
		
	scanf("%d%*c", &score);

	}

	if (number_of_scores == 0)
	{
		printf("\n\n\t NO SCORES ENTERED\n\n");
	}




	return 0;
}



// Function to draw a line with a predefined length and a predefined symbol 
void Draw_bar(score, symbol)
{

	for (int i = 0; i < score; i++)
	{
	printf("%c", symbol);
	}
	printf("\n\n");
	
}
