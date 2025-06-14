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
	/* Exercice 4.13
		
		Assignment:

		Rewrite the previous program such that cents (50, 20, 10, 5, 2, 1)
		are also included (e.g. 13578,78). Be aware that the % operator can
		only be used with integer operands!

	*/

	printf("--\tDit is oefening 4.13 van 'Cprogrammingfundamentals2020' Pg51\t--\n\n\n");

	int fivehund_note, twohund_note, hund_note, fifty_note, twenty_note, ten_note, five_note, euro_recal;
	// fivehund = 500 note -- twohund = 200 -- hund = 100 // euro recal = the entered value entered by the user times a 100 
														//	 also stands for recalibration since we're also going to recalibrate this value as our calculations go on the recalibration is marked by a **
	int two_coin, one_coin,fifty_cent,twenty_cent,ten_cent,five_cent,two_cent,one_cent;
	float euro_entered;

	printf("Please enter the amount of Euros:\n\n> ");
	scanf("%f%*c", &euro_entered);

	euro_recal = euro_entered * 100; //We recalculate the amount entered by the user in order to be able to use the operator '%' since we also have to deal with the decimal numbers

	fivehund_note = (euro_recal - (euro_recal % 50000)) / 50000;
	twohund_note = ((euro_recal - fivehund_note * 50000) - ((euro_recal - fivehund_note * 50000) % 20000)) / 20000;
	euro_recal = euro_recal - (fivehund_note * 50000 + twohund_note * 20000);//**
	hund_note = (euro_recal - (euro_recal % 10000)) / 10000;
	fifty_note = ((euro_recal - hund_note * 10000) - ((euro_recal - hund_note * 10000) % 5000)) / 5000;
	euro_recal = euro_recal - (hund_note * 10000 + fifty_note * 5000);//**
	twenty_note = (euro_recal - (euro_recal % 2000)) / 2000;
	ten_note = ((euro_recal - twenty_note * 2000) - ((euro_recal - twenty_note * 2000) % 1000)) / 1000;
	euro_recal = euro_recal - (twenty_note * 2000 + ten_note * 1000);//**
	five_note = (euro_recal - (euro_recal % 500)) / 500;
	two_coin = ((euro_recal - five_note * 500) - ((euro_recal - five_note * 500) % 200)) / 200;
	euro_recal = euro_recal - (five_note * 500 + two_coin * 200);//**
	one_coin = (euro_recal - (euro_recal % 100)) / 100;
	fifty_cent = ((euro_recal - one_coin * 100) - ((euro_recal - one_coin * 100) % 50)) / 50;
	euro_recal = euro_recal - (one_coin * 100 + fifty_cent * 50);//**
	twenty_cent = (euro_recal - (euro_recal % 20)) / 20;
	ten_cent = ((euro_recal - twenty_cent * 20) - ((euro_recal - twenty_cent * 20) % 10)) / 10;
	euro_recal = euro_recal - (twenty_cent * 20 + ten_cent * 10);//**
	five_cent = (euro_recal - (euro_recal % 5)) / 5;
	two_cent = ((euro_recal - five_cent * 5) - ((euro_recal - five_cent * 5) % 2)) / 2;
	euro_recal = euro_recal - (five_cent * 5 + two_cent * 2);//**
	one_cent = euro_recal / 1;

	printf("The amount of Euros you entered amounts to:\n %d notes of 500\n %d notes of 200\n %d notes of 100\n %d notes of 50\n %d notes of 20\n %d notes of 10\n %d notes of 5\n %d coins of 2 euro\n %d coins of 1 euro\n %d coins of fifty cent\n %d coins of twenty cents\n %d coins of ten cents\n %d coins of five cents\n %d coins of two cents\n %d coins of one cent\n\n\n"
		, fivehund_note, twohund_note, hund_note, fifty_note, twenty_note, ten_note, five_note, two_coin, one_coin, fifty_cent, twenty_cent, ten_cent, five_cent, two_cent, one_cent);




	return 0;

}