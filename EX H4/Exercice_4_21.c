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
	/* Exercice 4.21

	Assignment:
	Write a program that prints the date of Easter for a year entered by the user.
	Easter is held on the first Sunday after the first full moon of the spring. 
	Easter is delayed by 1 week if the full moon is on Sunday. 
	According to Jean Meeus, Spencer Jones and Butcher, the Easter date in year J can be calculated as follows 
	(all divisions are integer divisions):

	𝑎 = 𝑟𝑒𝑚𝑎𝑖𝑛𝑑𝑒𝑟 𝑜𝑓 𝑡ℎ𝑒 𝑑𝑖𝑣𝑖𝑠𝑖𝑜𝑛 𝑜𝑓 𝐽 𝑏𝑦 19
	𝑏 = 𝐽 / 100
	𝑐 = 𝑟𝑒𝑚𝑎𝑖𝑛𝑑𝑒𝑟 𝑜𝑓 𝑡ℎ𝑒 𝑑𝑖𝑣𝑖𝑠𝑖𝑜𝑛 𝑜𝑓 𝐽 𝑏𝑦 100
	𝑑 = 𝑏 / 4
	𝑒 = 𝑟𝑒𝑚𝑎𝑖𝑛𝑑𝑒𝑟 𝑜𝑓 𝑡ℎ𝑒 𝑑𝑖𝑣𝑖𝑠𝑖𝑜𝑛 𝑜𝑓 𝑏 𝑏𝑦 4
	𝑓 = (𝑏 + 8) / 25
	𝑔 = (𝑏 − 𝑓 + 1) / 3
	ℎ = 𝑡ℎ𝑒 𝑟𝑒𝑚𝑎𝑖𝑛𝑑𝑒𝑟 𝑜𝑓 𝑡ℎ𝑒 𝑑𝑖𝑣𝑖𝑠𝑖𝑜𝑛 𝑜𝑓 (19 ∗ 𝑎 + 𝑏 − 𝑑 − 𝑔 +15) 𝑏𝑦 30
	𝑖 = 𝑐 / 4
	𝑘 = 𝑡ℎ𝑒 𝑟𝑒𝑚𝑎𝑖𝑛𝑑𝑒𝑟 𝑜𝑓 𝑡ℎ𝑒 𝑑𝑖𝑣𝑖𝑠𝑖𝑜𝑛 𝑜𝑓 𝑐 𝑏𝑦 4
	𝑙 = 𝑡ℎ𝑒 𝑟𝑒𝑚𝑎𝑖𝑛𝑑𝑒𝑟 𝑜𝑓 𝑡ℎ𝑒 𝑑𝑖𝑣𝑖𝑠𝑖𝑜𝑛 𝑜𝑓 (32 + 2 ∗ 𝑒 + 2 ∗ 𝑖 − ℎ – 𝑘) 𝑏𝑦 7
	𝑚 = (𝑎 + 11 ∗ ℎ + 22 ∗ 𝑙) / 451
	𝑚𝑜𝑛𝑡ℎ = (ℎ + 𝑙 − 7 ∗ 𝑚 + 114) /31
	𝑑𝑎𝑦 = 1 + 𝑡ℎ𝑒 𝑟𝑒𝑚𝑎𝑖𝑛𝑑𝑒𝑟 𝑜𝑓 𝑡ℎ𝑒 𝑑𝑖𝑣𝑖𝑠𝑖𝑜𝑛 𝑜𝑓 (ℎ + 𝑙 − 7 ∗ 𝑚 + 114) 𝑏𝑦 31

	!!!!This formula is valid for the Gregorian calendar and as such only after 
	1582.
	*/

	printf("\n\t----\tDit is oefening 4.21 van 'Cprogrammingfundamentals2020' Pg53\t----\n\n\n\n");

	int Year, Month, Day, a, b, c, d, e, f, g, h, i, k, l, m;
	const char* Month_name =' ';

	printf("Please enter the year of choice to see on what date Easter was held:\t");
	scanf("%d%*c",&Year);

	while (Year < 0)
	{
		printf("\n %d is not a valid year \nPlease enter the year of choice to see on what date Easter was or will be held:\t",Year);
		scanf("%d%*c",&Year);
	}

	// Calculation Zone --------------------------- OFF LIMITS --------------------------- OFF LIMITS --------------------------- OFF LIMITS 
	// -------------------------------------------- OFF LIMITS --------------------------- OFF LIMITS --------------------------- OFF LIMITS 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	a = Year % 31;
	b = Year / 100;
	c = Year % 100;
	d = b / 4;
	e = c / 4;
	f = (b + 8) / 25;
	g = (b - (f + 1)) / 3;
	h = ((19 * a) + b - d - g + 15) % 30;
	i = c / 4;
	k = c % 4;
	l = (32 + (2 * e) + (2 * i) - h - k) % 7;
	m = (a + (11 * h) + (22 * l)) / 451;
	Month = (h + l - (7 * m) + 114) / 31;
	Day = 1 + ((h + l - 7 * m + 114) % 31);

	switch (Month)
	{
	case 1 :
		Month_name = "January";
		break;

	case 2 :
		Month_name = "February";
		break;

	case 3 :
		Month_name = "Mars";
		break;

	case 4 :
		Month_name = "April";
		break;

	case 5 :
		Month_name = "May";
		break;

	case 6 :
		Month_name = "June";
		break;

	case 7 :
		Month_name = "July";
		break;

	case 8 :
		Month_name = "August";
		break;

	case 9 :
		Month_name = "September";
		break;

	case 10 :
		Month_name = "October";
		break;

	case 11 :
		Month_name = "November";
		break;

	case 12 :
		Month_name = "December";
		break;

	default:
		printf("\n\t----Oops something went wrong----\n\n");
		break;
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// -------------------------------------------- OFF LIMITS --------------------------- OFF LIMITS --------------------------- OFF LIMITS 
	// Calculation Zone --------------------------- OFF LIMITS --------------------------- OFF LIMITS --------------------------- OFF LIMITS 

	printf("\n\n in the year %d Easter was held on %s %d\n\n\n\n",Year,Month_name,Day);

	return 0;
}