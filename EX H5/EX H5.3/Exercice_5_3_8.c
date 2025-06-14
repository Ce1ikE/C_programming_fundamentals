/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

int main(void)
{
	/* Exercice 5.3.8.

	Assignment:
	Write a program that sums 10 numbers entered by the user and 
	computes the mean of those 10 numbers. Try to use only 3 variables 
	in your program. Calculate the sum while reading the numbers.


	*/

	printf("\n\t----\tDit is oefening 5.3.8. van 'Cprogrammingfundamentals2020' Pg83\t----\n\n\n\n");

	int Numbers, Sum = 0;
	float Avg;
	printf("Please enter 10 integers :\n\n");
	
	for (int i = 0; i < 10; i++)
	{
		printf("\n Nr %d is : ",i + 1);
		scanf("%d%*c", &Numbers);
		Sum = Sum + Numbers;
	}
		
	Avg = (float)Sum / 10;


	printf("\n\nThe sum is equal to %d and the average is equal to %.2f \n\n\n ", Sum, Avg);


}