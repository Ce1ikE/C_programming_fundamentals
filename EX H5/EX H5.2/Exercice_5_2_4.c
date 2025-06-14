/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	/* Exercice 5.2.4.

	Assignment:
	Write a program that asks the user to enter a real number and prints 
	whether for that number, each one of the following conditions is met or not:

	condition A: 3 ≤ x < 8.5
	condition B: x < 3 OR 5.4 < x ≤ 7.3 OR x > 13
	condition C: x ≠ 3 AND x < 9.75

	*/

	printf("\n\t----\tDit is oefening 5.2.4. van 'Cprogrammingfundamentals2020' Pg66\t----\n\n\n\n");

	float Number;
	const char* Cond_A=' ',* Cond_B=' ',* Cond_C=' ';

	printf("Please enter a real number :\t");
	scanf("%f%*c",&Number);

	// 1st Condition (A)
	if (3 <= Number && Number < 8.5)
	{
		Cond_A = "A";
	}
	else
	{
		Cond_A = "NOT A";
	}

	// 2nd Condition (B)
	if (Number < 3 || 5.4 < Number && Number <= 7.3 || Number > 13)
	{
		Cond_B = "B";
	}
	else
	{
		Cond_B = "NOT B";
	}

	// 3rd Condition (C)
	if (Number != 3 && Number < 9.75)
	{
		Cond_C = "C";
	}
	else
	{
		Cond_C = "NOT C";
	}


	printf("\n\n %.1f matches conditions: %s, %s, %s \n\n\n", Number, Cond_A, Cond_B, Cond_C);


	return 0;
}