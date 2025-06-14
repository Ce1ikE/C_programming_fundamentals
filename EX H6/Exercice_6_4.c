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
#include <math.h>

/* Function declarations */


int main(void)
{
	/* Exercice 6.4

	Assignment:
	Write a program that reads the lengths of the sides a and b of a 
	right-angled triangle and prints the length of the hypotenuse c and one 
	of the acute angles

	*/

	printf("\n\t----\tDit is oefening 6.4 van 'Cprogrammingfundamentals2020' Pg104\t----\n\n\n\n");


	double side_a, side_b, side_c, angle_alpha; // Angle alpha is the acute angle opposing side 'a' in a right-angled  triangle

	printf("Please enter the value of side 'a' => ");
	scanf("%lf%*c", &side_a);
	while (side_a <= 0)
	{
		printf("Please enter the value of the side, the one you entered is impossible 'a' => ");
		scanf("%lf%*c", &side_a);
	}
	printf("\n Please enter the value of side 'b' => ");
	scanf("%lf%*c", &side_b);
	while (side_b <= 0)
	{
		printf("Please enter the value of the side, the one you entered is impossible 'b' => ");
		scanf("%lf%*c", &side_b);
	}

	side_c = sqrt((side_a*side_a + side_b*side_b));
	angle_alpha = (atan(side_a / side_b)) / M_PI * 180;

	printf("\n\n\t Side a = %.2lf \n\t Side b = %.2lf \n\t Side c = %.2lf \n\t Angle alpha = %.2lf \n\n\n", side_a, side_b, side_c, angle_alpha);





}