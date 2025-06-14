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

/* Function declarations */

int readnumber(int , int);

int main(void)
{
	/* Exercice 6.9

	Assignment:
	Write a function with header:

	int readnumber(int lower_boundary, int upper_boundary)

	that reads an integer number in the interval [lower_boundary, 
	upper_boundary] and returns that number as function return value. Also 
	in this case, the function can only stop asking an integer number if a 
	correct value was entered.
	Write a main function that calls this function and prints the resulting 
	number.

	*/

	printf("\n\t----\tDit is oefening 6.9 van 'Cprogrammingfundamentals2020' Pg105\t----\n\n\n\n");

	int Upper_boundary, Lower_boundary,Answer;
	Upper_boundary = 15;
	Lower_boundary = -20;
	Answer = readnumber(Lower_boundary, Upper_boundary);

	printf("\n\n\t The number read is %d\n\n\n", Answer);

	return 0;
}



int readnumber(int A,int B)
{
	int X;
	printf("\n Please enter a number between[%d ; %d] :  => ",A,B);
	scanf("%d%*c", &X);

	while (X < A || X > B)
	{
		printf("\n The number you entered is not in the interval [%d ; %d]\n", A, B);
		printf("\n Please enter a number between[%d ; %d] : => ", A, B);
		scanf("%d%*c", &X);

	}

	return X;
}