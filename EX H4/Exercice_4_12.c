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
	/* Exercice 4.12
	
		Assignment:
		Write a program that asks the user to enter an amount of money
		(e.g. 13578) in euro and prints the corresponding number of notes
		(500, 200, 100, 50, 20, 10, 5) and coins (2, 1). Always use the
		minimal number of notes and coins possible.
	*/

	printf("--\tDit is oefening 4.12 van 'Cprogrammingfundamentals2020' Pg51\t--\n\n\n");

	int fivehund_note, twohund_note, hund_note, fifty_note, twenty_note, ten_note, five_note, euro_recal, euro_entered;
	// fivehund = 500 note -- twohund = 200 -- hund = 100 // euro recal = the entered value entered by the user times a 100 
														//	 also stands for recalibration since we're also going to recalibrate this value as our calculations go on
	int two_coin, one_coin;


	printf("Please enter the amount of Euros:\n\n> ");
	scanf("%d%*c", &euro_entered);

	euro_recal = euro_entered * 100; //We recalculate the amount entered by the user in order to be able to use the operator '%' since we also have to deal with the decimal numbers	
	//SB: dit is niet echt nodig voor deze oefening aangezien je een int inleest en dus al een int hebt. Voor oefening 13 moet dit wel. 

	fivehund_note = (euro_recal - (euro_recal % 50000)) / 50000;		//SB: als je in C 2 integers deelt, dan krijg je een integer resultaat => dit kan gewoon als: fivehund_note = euro_recal / 50000;
	twohund_note = ((euro_recal - fivehund_note * 50000) - ((euro_recal - fivehund_note * 50000) % 20000)) / 20000;	//SB: dit kan dan eenvoudiger als twohund_note = (euro_recal % 50000) / 20000; en zo verder voor de andere
	euro_recal = euro_recal - (fivehund_note * 50000 + twohund_note * 20000);
	hund_note = (euro_recal - (euro_recal % 10000)) / 10000;
	fifty_note = ((euro_recal - hund_note * 10000) - ((euro_recal - hund_note * 10000) % 5000)) / 5000;
	euro_recal = euro_recal - (hund_note * 10000 + fifty_note * 5000);
	twenty_note = (euro_recal - (euro_recal % 2000)) / 2000;
	ten_note = ((euro_recal - twenty_note * 2000) - ((euro_recal - twenty_note * 2000) % 1000)) / 1000;
	euro_recal = euro_recal - (twenty_note * 2000 + ten_note * 1000);
	five_note = (euro_recal - (euro_recal % 500)) / 500;
	two_coin = ((euro_recal - five_note * 500) - ((euro_recal - five_note * 500) % 200)) / 200;
	euro_recal = euro_recal - (five_note * 500 + two_coin * 200);
	one_coin = euro_recal / 100;

	printf("The amount of Euros you entered amounts to:\n %d notes of 500\n %d notes of 200\n %d notes of 100\n %d notes of 50\n %d notes of 20\n %d notes of 10\n %d notes of 5\n %d coins of 2 euro\n %d coins of 1 euro\n\n\n"
		, fivehund_note, twohund_note, hund_note, fifty_note, twenty_note, ten_note, five_note, two_coin, one_coin);


	return 0;



}