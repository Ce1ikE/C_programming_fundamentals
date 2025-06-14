/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/* Function declarations */

void Draw_bar(void);
double Sin_cal(int);

int main(void)
{
	/* Exercice 6.2

	Assignment:
	Write a program that prints a table with 2 columns. The first column 
	contains all angles from 0 till 360 degrees with steps of 30 degrees. The 
	second column contains the corresponding sine values.

	*/

	printf("\n\t----\tDit is oefening 6.2 van 'Cprogrammingfundamentals2020' Pg104\t----\n\n\n\n");


	int Angle;
	double Answer;
	Angle = 0;

	printf(" Angles  |   Sin Value \n");
	Draw_bar();
	
	for (int i = 0; i < 13; i++)
	{
		Answer = Sin_cal(Angle);

		
		printf(" %6d  |  %6.3lf \n", Angle,Answer);

		Angle = Angle + 30;
	}


	printf("\n\n");



	return 0;
}


void Draw_bar(void)
{
	for (int i = 0; i < 30; i++)
	{
		printf("-");
	}

	printf("\n");

}



double Sin_cal(int Angle)
{

	double result;


	result = sin((double)((Angle * M_PI) / 180));


	return result;
}
