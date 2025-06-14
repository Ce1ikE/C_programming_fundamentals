/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Function declarations */

float Factor_calculator(float,float,float);

int main(void)
{
	/* Exercice 6.15

	Assignment:
	Write a function with as parameters 3 integer numbers that 
	represent a day, month and year. This function calculates and returns a 
	factor according to following formula:
	𝑓𝑎𝑐𝑡𝑜𝑟 = 365 ∗ 𝑦𝑒𝑎𝑟 + 𝑑𝑎𝑦 + 31 ∗ (𝑚𝑜𝑛𝑡ℎ − 1)+ [(𝑦𝑒𝑎𝑟 − 1)/4]− [[(𝑦𝑒𝑎𝑟 − 1)/100 + 1] ∗ 3/4]

	for the months January and February with [x] being the integer part of x

	𝑓𝑎𝑐𝑡𝑜𝑟 = 365 ∗ 𝑦𝑒𝑎𝑟 + 𝑑𝑎𝑦 + 31 ∗ (𝑚𝑜𝑛𝑡ℎ − 1)− [0,4 ∗ 𝑚𝑜𝑛𝑡ℎ + 2,3] +[𝑦𝑒𝑎𝑟/4]− [[𝑦𝑒𝑎𝑟/100 +1] ∗ 3/4]

	for the months March till December.
	Write a main function that reads 2 dates, calculates the number of days 
	in between these 2 dates by calculating the difference between the 2 
	factors of the corresponding dates

	*/

	printf("\n\t----\tDit is oefening 6.15 van 'Cprogrammingfundamentals2020' Pg107\t----\n\n\n\n");


	float Factor, Factor_difference;
	Factor_difference = 0;
	int Year, Month, Day;

	for (int i = 0; i < 2; i++)
	{


		printf("\n Please input a date please (YYYY M D) : => ");
		scanf("%d%d%d%*c", &Year, &Month, &Day);


		while (Year < 0 || Month > 12 || Month < 0 || Day > 366 || Day < 0)
		{
			printf("\n Please input a correct date please (YYYY M D) : => ");
			scanf("%d%d%d%*c", &Year, &Month, &Day);
		}

		Factor = Factor_calculator(Year, Month, Day);
		Factor_difference = Factor_difference - Factor;
		if (Factor_difference < 0)
		{
			Factor_difference = -Factor_difference;
		}
	}
	
	
	printf("\n\n The number of days between your dates is %.0f", Factor_difference);

	return 0;

}





float Factor_calculator(float Y ,float M ,float D)
{

	float Factor;

	if (M <= 2)
	{
		Factor = 365 * Y + D + 31 * (M - 1) + ((Y - 1) / 4) - (((Y - 1) / 100) * 3 / 4);
	}
	else
	{
		Factor = 365 * Y + D + 31 * (M - 1) - ((0.4 * M) + 2.3) + (Y / 4) - (((Y / 100) + 1) * 3 / 4);
	}




	return Factor;
}