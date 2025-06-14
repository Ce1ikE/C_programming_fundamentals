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

/* Function declaration */

void Print_Equation(float, float, float);

int main(void)
{
	/* Exercice 5.2.18

	Assignment:

	Write a program that asks the user to enter 
	the coefficients a,	b and c of a quadratic equation with general form 
	ax^2 + bx + c = 0
	and prints all real roots of this equation. Make sure the program
	does not crash for certain values of the coefficients!

	*/

	printf("\n\t----\tDit is oefening 5.2.18 van 'Cprogrammingfundamentals2020' Pg69\t----\n\n\n\n");

	float a, b, c,x1,x2; // x1 & x2 are our roots of the quadratic equation
	printf("Enter the coefficients of the quadratic equation: ");

	printf("\nEnter \"a\" : ");
	scanf("%f%*c", &a);

	printf("\nEnter \"b\" : ");
	scanf("%f%*c", &b);

	printf("\nEnter \"c\" : ");
	scanf("%f%*c", &c);


	float Delta = b * b - 4 * a * c; // Delta = b^2 - 4ac  // Delta == D

	if (a != 0) // Equation of type ax^2 + bx + c = 0
	{
		Print_Equation(a, b, c);
		// D is either D > 0 or D < 0 or D = 0

		if (Delta < 0) // No roots
		{
			printf("\n\n\tNo roots for the equation");
		}
		else // 1 or 2 roots
		{

			// General formula 
			/*
			
			x1 ; x2 ==   (-b (+/-) sqrt(delta)) / (2 * a)
			
			*/

			if (Delta == 0) // 1 root // x1 == x2
			{
				x1 = (-b) / (2 * a);
				printf("\n\n\t1 Root:  x1 = %.2f", x1);
			}
			else // 2 roots // x1 != x2
			{
				x1 = (-b + sqrt(Delta)) / (2 * a);
				x2 = (-b - sqrt(Delta)) / (2 * a);
				printf("\n\n\t2 Roots:  x1 = %.2f  x2 = %.2f", x1, x2);
			}
		}
	}
	else 
	{
		if (b != 0) // Equation of type bx + c = 0 => Solution x = -c / b
		{
			Print_Equation(a, b, c);
			x1 = (-c) / b;
			printf("\n\n\t1 Root:  x1 = %.2f", x1);
		}
		else // Equation of type c = 0
		{
			if (c != 0) // Inconsistent because if c != 0 but in the equation c = 0 => impossible 
			{
				Print_Equation(a, b, c);
				printf("\n\n\tInconsistent Equation");
			}
			else
			{
				Print_Equation(a, b, c);
				printf("\n\n\tNo roots for the equation");
			}

		}
	}



	printf("\n\n\n");
	return 0; 
}

/* Function definition */


void Print_Equation(float a, float b, float c)
{

	// Each coeffecient can either be equal to zero or not zero this will give us 8 possible equations

	/*
	
	a = 0 || a != 0 => 2 possibilities
	b = 0 || b != 0 => 2 possibilities
	c = 0 || c != 0 => 2 possibilities
	
	2 * 2 * 2 = 2^3 = 8 possibilities
	
	*/

	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("\nEquation: 0 = 0"); // 0 = 0
			}
			else
			{
				printf("\nEquation: %.2f = 0",c); // c = 0
			}
		}
		else // b != 0
		{
			if (c == 0)
			{
				printf("\nEquation: %.2f x = 0", b); // b*x = 0
			}
			else
			{
				printf("\nEquation: %.2f x + %.2f = 0", b, c); // b*x + c = 0
			}
		}
	}
	else // a != 0
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("\nEquation: %.2f x^2 = 0", a); // a*x^2 = 0
			}
			else
			{
				printf("\nEquation: %.2f x^2 + %.2f = 0", a, c); // a*x^2 + c = 0
			}
		}
		else // b != 0
		{
			if (c == 0)
			{
				printf("\nEquation: %.2f x^2 + %.2f x = 0", a, b); // a*x^2 + b*x = 0
			}
			else
			{
				printf("\nEquation: %.2f x^2 + %.2f x + %.2f = 0", a, b, c); // a*x^2 + b*x + c = 0
			}
		}
	}



}