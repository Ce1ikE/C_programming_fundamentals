/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Function declarations */

int rand_point_generator(void);

int main(void)
{
	/* Exercice 6.16

	Assignment:
	Consider the first quadrant of a circle in a square with side 1. 
	If you generate a large amount of (x, y) coordinates with x and y belonging to 
	the interval [0, 1], you have a collection of points belonging to the 
	square.
	If you now count all points that belong to the quadrant of the circle with equation x2 + y2 < 1
	and divide this amount by the total amount of points generated, you will find approximately the number pi/4

	Write a program that generates 100 000 points and uses it to calculate 
	the number pi approximately. Run the program several times and 
	compare the results. What if you increase the number of points?


	*/

	printf("\n\t----\tDit is oefening 6.16 van 'Cprogrammingfundamentals2020' Pg108\t----\n\n\n\n");

	double Result;
	int amount_on_in_the_circle;

	printf("	Nr Run time  |	Result \n");
	printf("-------------------------------------\n");
	printf("	pi/4         |   %25.24lf \n",M_PI_4);

	for (int i = 1; i < 31; i++)
	{
		
	amount_on_in_the_circle = rand_point_generator();

	Result = (double)amount_on_in_the_circle / 10000000;

	printf("	%2d           |   %25.24lf \n", i, Result);
	}
	printf("\n\n\n");

	return 0;
}

int rand_point_generator(void)
{
	int amount_on_in_the_circle;
	amount_on_in_the_circle = 0;
	double X, Y,circle;
	srand(time(NULL));
	for (int s = 0; s < 10000000; s++)
	{
		
		X = ((double)rand())/ (double)RAND_MAX;
		Y = ((double)rand())/ (double)RAND_MAX;
		circle = X * X + Y * Y;
		if ( circle < 1)
		{
			amount_on_in_the_circle++;
		}
	}

	return  amount_on_in_the_circle;
}
