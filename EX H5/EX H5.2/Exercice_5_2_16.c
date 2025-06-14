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
	/* Exercice 5.2.15.

	Assignment:
	Write a program that calculates the length of the third side of 
	a right-angled triangle based upon the lengths of the 2 other sides
	and prints it to the screen. To this end, ask the user to enter the 
	length of all 3 sides in the order: side1 side2 hypotenuse. A zero is to 
	be entered for the side for which you wish to calculate the length.
	(ℎ𝑦𝑝𝑜𝑡𝑒𝑛𝑢𝑠𝑒)^2 = 𝑠𝑖𝑑𝑒1^2 + 𝑠𝑖𝑑𝑒2^2

	*/
	
	printf("\n\t----\tDit is oefening 5.2.15. van 'Cprogrammingfundamentals2020' Pg68\t----\n\n\n\n");

	float S1, S2, H;
	printf("Please enter the value of the sides of the triangle in order (side1 side2 hypo)\n !!! represent the unknown by a zero:");
	scanf("%f%f%f%*c",&S1,&S2,&H);

	if (S1 == 0)
	{
	S1 = sqrt((S2 * S2) + (H * H));
	printf("\n\n The unknown side equals to %f",S1);
	}
	else
	{
		if (S2 == 0)
		{
		S2 = sqrt((S1 * S1) + (H * H));
		printf("\n\n The unknown side equals to %f", S2);
		}
		else
		{
			if (H == 0)
			{
			H = sqrt((S2 * S2) + (S1 * S1));
			printf("\n\n The unknown hypotenuse equals to %f", H);
			}
		}
	}
	
	

	return 0;

}