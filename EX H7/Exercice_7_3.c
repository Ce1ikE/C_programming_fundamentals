/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Days 7

/* Function declarations */

void Read_Temperature(int[]);
float Mean_Temperature(int[]);



int main(void)
{
	/* Exercice 7.3

	Assignment:
	Repeat exercise 7.1 using 2 functions. Make a function to read the 
	temperatures and a separate function to calculate the mean 
	temperature. Printing the mean must be done in the main program.

	*/

	printf("\n\t----\tDit is oefening 7.3 van 'Cprogrammingfundamentals2020' Pg120\t----\n\n\n\n");



	int Temperature[Days];
	float Mean;
	

	Read_Temperature(Temperature);

	Mean = Mean_Temperature(Temperature);

	printf("\n\n The mean temperature for this week is %.2f\n\n\n", Mean);

	return 0;


}




void Read_Temperature(int Temperature[])
{


	for (int i = 1; i <= Days; i++)
	{
		printf("\n Enter temperature for day %d : => ", i);
		scanf("%d%*c", &Temperature[i - 1]);
	}





}


float Mean_Temperature(int T[])
{
	float Mean;
	Mean = 0;

	for (int t = 0; t < Days; t++)
	{
		Mean = Mean + T[t];
	}
	Mean = Mean / Days;


	return Mean;
}
