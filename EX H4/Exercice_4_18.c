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
	/* Exercice 4.18

	   Write a program that asks the user to enter name, first name,
	   street, number, zip code and town name. Afterwards, the program
	   outputs this data in the format:
	 -  first name name  -
	 -  street number    -
	 -  zip code town	 -


	*/


	printf("\n\t----\tDit is oefening 4.18 van 'Cprogrammingfundamentals2020' Pg52\t----\n\n\n\n");

	char FS[32], N[32], S[32], TN[32], answer;
	int SN, ZC;
	printf("Please enter your Firstname:\n");
	gets(FS);
	printf("\nPlease enter your Name:\n");
	gets(N);
	printf("\nPlease enter your Streetname:\n");
	gets(S);
	printf("\nPlease enter your Street number:\n");
	scanf("%d%*c", &SN);
	printf("\nPlease enter your town's Zip code:\n");
	scanf("%d%*c", &ZC);
	printf("\nPlease enter your town's name:\n");
	gets(TN);

	printf("\n\n Are these informations correct(yes = y ; no = n)?\n\n\t %s\t%s\n\t %s\t %d\n\t %d\t %s\n\n> ", FS, N, S, SN, ZC, TN);
	scanf("%c%*c", &answer);

	switch (answer)
	{
	case 'y':printf("We will proceed at once to create your profile\n\n"); break;
	case 'n':printf("We are sorry about the inconvenience\n\n"); break;
	default:printf("Invalid option\n\n");break;
	}



	return 0;
}