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
	/* Exercice 5.2.8.

	Assignment:
	Write a BMI (Body Mass Index) calculator. BMI is a measure of body 
	fat based on height and weight that applies to adult men and 
	women. It can be calculated with the following formula:
	𝐵𝑀𝐼 = 𝑤𝑒𝑖𝑔𝑡ℎ 𝑖𝑛 𝑘𝑔 / ((ℎ𝑒𝑖𝑔𝑡ℎ 𝑖𝑛 𝑚) ∗ (ℎ𝑒𝑖𝑔𝑡ℎ 𝑖𝑛 𝑚))
	
	The BMI is divided into different categories:
	− underweight < 18.5
	- normal weight 18.5 – 24.9
	- overweight 25 – 29.9
	- obesity ≥ 30
	Ask the height and weight of the user, calculate his/her BMI and 
	print the category the user belongs to.


	*/

	printf("\n\t----\tDit is oefening 5.2.8. van 'Cprogrammingfundamentals2020' Pg67\t----\n\n\n\n");


	float weight, height, BMI;

	printf("Can you please enter your body weight in 'Kg' Please:");
	scanf("%f%*c",&weight);

	printf("\n\nCan you please enter your body height in 'm' Please:");
	scanf("%f%*c", &height);

	BMI = (weight / (height * height));

	if (BMI < 18.5)
	{
		printf("\n\nYou are underweight\n\n");
	}
	else
	{
		if (18.5 <= BMI <= 25)
		{
			printf("\n\nYou are normal weight\n\n");
		}
		else
		{
			if (25 <= BMI <= 30)
			{
				printf("\n\nYou are overweight\n\n");
			}
			else (30 < BMI);
			{
				printf("\n\nYou are obese\n\n");
			}
		}
	}


	return 0;
}