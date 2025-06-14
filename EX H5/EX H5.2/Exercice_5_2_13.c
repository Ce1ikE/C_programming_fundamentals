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
	/* Exercice 5.2.13.

	Assignment:
	Write a program that asks the user to enter an instruction in 
	the format:
				'number1' 'operand' 'number2'
	For the operand, the user can choose +, -, * or /. The program 
	calculates the mathematical result and prints it to the screen.
		Tip: 
	read the instruction with scanf("%f%c%f%*c",&getal1,&operand,&getal2);
	and use switch(operand)

	*/

	printf("\n\t----\tDit is oefening 5.2.13. van 'Cprogrammingfundamentals2020' Pg68\t----\n\n\n\n");

	float Number_1, Number_2,Calculator;
	char Operator;

	printf("Enter an expression (without spaces please!):");
	scanf("%f%c%f%*c",&Number_1,&Operator,&Number_2);

	switch (Operator)
	{
	
	case '+':

		
		Calculator = Number_1 + Number_2;
		printf("\n\nThe sum of %.1f and %.1f equals %.1f\n\n\n",Number_1,Number_2, Calculator);

	break;

	case '-':

		Calculator = Number_1 - Number_2;
		printf("\n\nThe difference between %.1f and %.1f equals %.1f\n\n\n",Number_1, Number_2, Calculator);

	break;

	case '*':

		Calculator = Number_1 * Number_2;
		printf("\n\nThe multiplication of %.1f by %.1f equals %.1f\n\n\n",Number_1, Number_2, Calculator);

	break;

	case '/':

		Calculator = Number_1 / Number_2;
		printf("\n\nThe division of %.1f by %.1f equals %.1f\n\n\n",Number_1, Number_2, Calculator);
	

	break;

	default:
		break;

	}

	return 0;


}