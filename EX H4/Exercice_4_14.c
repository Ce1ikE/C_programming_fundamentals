/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis

*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	/* Exercice 4.14
	 
	Assignment:

	Consider an electrical circuit consisting of two series resistors R1 and R2. 
	If a voltage U is applied to this circuit, the current flowing in this 
	circuit will be I = U/ R1+R2 according to Ohm’s law. 
	The voltage (V2) across the resistor R2 will then be defined by V2 = I . R2.
	Write a program that asks the user to enter the values for U, R1 and R2 and prints the values of I and V2 to the screen.


	*/

	printf("--\tDit is oefening 4.14 van 'Cprogrammingfundamentals2020' Pg51\t--\n\n\n");

	int R1, R2, U;
	float I, V2;

	printf("Please enter the values of the voltage en resistance 1 and 2\n\n");
	printf("Value of the voltage:\n> ");
	scanf("%d%*c",&U);
	printf("Value of resistance 1:\n> ");
	scanf("%d%*c", &R1);
	printf("Value of resistance 2:\n> ");
	scanf("%d%*c", &R2);

	I = (float)U / (float)(R1 + R2);
	V2 = I * (float)R2;

	printf("\n\n The voltage across the resistor 2 equals: %.2f ohm\n\n The current flowing through the circuit equals: %.2f ampere\n\n\n", V2, I);

	return 0;
}