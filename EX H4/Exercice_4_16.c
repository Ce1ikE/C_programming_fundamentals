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
/* Exercice 4.16 

	  Assignment:
	  Rewrite the previous exercise such that lines are placed around the
	  table and in between the numbers:

*/
	int in7, in8, in9, in10, in11, in12;
	char vline[] = "|";
	char hline1[] = "-------------", hline2[] = "-----------";

	//vline = vertical line   =>  |
	//hline = horizontal line =>  -

	printf("\n--\tDit is oefening 4.16 van 'Cprogrammingfundamentals2020' Pg52\t--\n\n\n\n");

	printf("Please enter 6 integers:\n> ");
	scanf("%d%d%d%d%d%d%*c", &in7, &in8, &in9, &in10, &in11, &in12);

	// Crazy Method
	// 
	// printf("\n %s\n %s %3d %s %3d %s\n %s%s%s\n %s %3d %s %3d %s\n %s%s%s\n %s %3d %s %3d %s\n %s\n\n"
	//	, hline1, vline, in7, vline, in8, vline, vline, hline2, vline, vline, in9, vline, in10, vline, vline, hline2, vline, vline, in11, vline, in12, vline, hline1);

	// Easy Method
	printf("---------------\n");
	printf("|%5d |%5d |\n",in7,in8);
	printf("|-------------|\n");
	printf("|%5d |%5d |\n",in9,in10);
	printf("|-------------|\n");
	printf("|%5d |%5d |\n",in11,in12);
	printf("---------------\n\n\n\n");

	return 0;
}