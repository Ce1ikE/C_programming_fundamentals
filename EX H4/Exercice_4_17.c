/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020" and 4.17

	Name: Celik 
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	/* Exercice 4.17 

	   Assignment:
	   Rewrite the previous exercise with real numbers. Make sure the
	   decimal points are nicely aligned.

	*/
	printf("\n\t----\tDit is oefening 4.17 van 'Cprogrammingfundamentals2020' Pg52\t----\n\n\n\n");

	float real1, real2, real3, real4, real5, real6;
	
	printf("Please enter 6 real numbers:\n> ");
	scanf("%f%f%f%f%f%f%*c", &real1, &real2, &real3, &real4, &real5, &real6);
	
	// Crazy Method
	// 
	//char vline[] = "|";
	//char hline1[] = "-------------------", hline2[] = "-----------------";
	//vline = vertical line   =>  |
	//hline = horizontal line =>  -
	//printf("\n %s\n %s  %5.2f %s  %5.2f %s\n %s%s%s\n %s  %5.2f %s  %5.2f %s\n %s%s%s\n %s  %5.2f %s  %5.2f %s\n %s\n\n"
	//	,hline1, vline, real1, vline, real2, vline, vline, hline2, vline, vline, real3, vline, real4, vline, vline, hline2, vline, vline, real5, vline, real6, vline, hline1);


	// Easy Method
	printf("-----------------\n");
	printf("|%6.2f |%6.2f |\n", real1, real2);
	printf("|---------------|\n");
	printf("|%6.2f |%6.2f |\n", real3, real4);
	printf("|---------------|\n");
	printf("|%6.2f |%6.2f |\n", real5, real6);
	printf("-----------------\n\n\n\n");

	return 0;
}
