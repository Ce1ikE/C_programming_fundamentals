/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

/* Type Definitions */

typedef enum t_months { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec} Month;

/* Function declarations */

void Hello(void);
void Bye_Message(void);
void Read(int*, Month*);
void NextDay(int*, Month*);
void PrintDay(int, Month);

int main(void)
{
	/* Exercice 12.2

	Assignment:

	Write a program “next-day” with:
	- a function “read” that asks the user to enter a day and a month as
	integers and returns those values to the main function (hint: use pointers) 
	- a function “NextDay” that has the current day and month as 
	arguments, calculates the next day and returns that next day to the
	main function (assume the day is not part of leap year)
	- a function “PrintDay” that takes a day and a month as input and prints them to the screen
	- use an enum type for the months

	*/

	printf("\n\t----\tDit is oefening 12.2 van 'Cprogrammingfundamentals2020' Pg176\t----\n\n\n\n");

	Hello();

	int D_date;
	Month M_date;

	Read(&D_date, &M_date);

	printf("\nThe current day is: ");

	PrintDay(D_date,M_date);

	NextDay(&D_date,&M_date);

	printf("\nThe next day is: ");

	PrintDay(D_date, M_date);

	Bye_Message();


	return 0;
}




// Reads the date entered as integers by the users. Filters also the wrong entered values
void Read(int * D, Month * M)
{

	printf("Enter the current day and month (as integers DD MM ): ");
	int tempMonth;
	scanf("%d%d%*c", D,&tempMonth); // enum type 'Month' has values from 0-11
	*M = (Month)tempMonth;
	*M -= 1;

	while (*M < Jan || *M > Dec)
	{
		printf("\nERROR \nWrong month value.Enter the current day and month (as integers DD MM ):");
		scanf("%d%d%*c", D, &tempMonth);
		*M = (Month)tempMonth;
		*M -= 1;
	}

	if (*M == Jan || *M == Mar || *M == May || *M == Jul || *M == Aug || *M == Oct || *M == Dec)
	{
		while (*D < 0 || *D > 31)
		{
			printf("\n ERROR \n Wrong day value.Enter the current day (as integer DD MM ):");
			scanf("%d%*c", D);
		}
	}
	else
	{
		if (*M == Feb)
		{
			while (*D < 0 || *D > 28)
			{
				printf("\n ERROR \n Wrong day value.Enter the current day (as integer DD MM ):");
				scanf("%d%*c", D);
			}
		}
		else
		{
			while (*D < 0 || *D > 30)
			{
				printf("\n ERROR \n Wrong day value.Enter the current day (as integer DD MM ):");
				scanf("%d%*c", D);
			}
		}
	}

}

// Calculates the next day, if necessary also the next month
void NextDay(int * D, Month * M)
{
	
	if (*M == Jan || *M == Mar || *M == May || *M == Jul || *M == Aug || *M == Oct || *M == Dec) // Months having 31 days
	{
		if (*D < 31)
		{
			*D += 1;
		}
		else
		{
			if (*M == Dec)
			{
				*M = Jan;
				*D = 1;
			}
			else
			{
				*M += 1;
				*D = 1;
			}
			
		}
	}
	else
	{

		if (*M == Feb) // Special month "February" having 28 or 29 days (but we are not in a leap year(See assignment) so we only have to deal with 1 case == 28 days)
		{
			if (*D < 28)
			{
				*D += 1;
			}
			else
			{
				*M += 1;
				*D = 1;
			}
		}
		else // All remaining months having 30 days
		{
			if (*D < 30)
			{
				*D += 1;
			}
			else
			{
				*M += 1;
				*D = 1;
			}
		}
		

	}

	

}

// Print the date of the entered and calculated values
void PrintDay(int D, Month M)
{

	switch (M)
	{
	case Jan: printf("\033[0;34m January \033[0m %3d", D); break;
	case Feb: printf("\033[0;34m February \033[0m %3d", D); break;
	case Mar: printf("\033[0;32m March \033[0m %3d", D); break;
	case Apr: printf("\033[0;32m April \033[0m %3d", D); break;
	case May: printf("\033[0;32m May \033[0m %3d", D); break;
	case Jun: printf("\033[0;31m June \033[0m %3d", D); break;
	case Jul: printf("\033[0;31m July \033[0m %3d", D); break;
	case Aug: printf("\033[0;31m August \033[0m %3d", D); break;
	case Sep: printf("\033[0;33m September \033[0m %3d", D); break;
	case Oct: printf("\033[0;33m October \033[0m %3d", D); break;
	case Nov: printf("\033[0;33m November \033[0m %3d", D); break;
	case Dec: printf("\033[0;36m December \033[0m %3d", D); break;
	default:break;
	}


}




// Prints a hello message
void Hello(void)
{

	printf("\n\n");

	printf("\n\t      \x5F\x5F\x5F\x5F          \x5F\x5F\x5F\x5F           \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F                         ");
	printf("\n\t     \x2F   \x2F\x5C        \x2F   \x2F\x5C         \x2F   \x2F\x5C      \x2F   \x2F\x5C      \x2F   \x2F\x5C                                       ");
	printf("\n\t    \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x3A\x5C       \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x3A\x5C                 ");
	printf("\n\t   \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     ");
	printf("\n\t  \x2F   \x2F\x3A\x3A\x5C \x5F\x5F\x5F  \x2F   \x2F\x3A\x3A\x5C \x5C\x3A\x5C   \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F  \x5C\x3A\x5C    ");
	printf("\n\t \x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C  \x2F\x5C\x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C \x5C\x3A\x5C \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F \x5C\x5F\x5F\x5C\x3A\x5C    ");
	printf("\n\t \x5C\x5F\x5F\x5F\x5C\x2F  \x5C\x3A\x5C\x2F\x3A\x2F\x5C   \x5C\x3A\x5C \x5C\x3A\x5C\x5F\x5C\x2F \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C \x2F  \x2F\x3A\x2F  ");
	printf("\n\t      \x5C\x5F\x5F\x5F\x5C\x3A\x3A\x2F  \x5C   \x5C\x3A\x5C \x5C\x3A\x5C    \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C  \x2F\x3A\x2F     ");
	printf("\n\t      \x2F   \x2F\x3A\x2F    \x5C   \x5C\x3A\x5C\x5F\x5C\x2F     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C\x2F\x3A\x2F       ");
	printf("\n\t     \x2F\x5F\x5F\x5F\x2F\x3A\x2F      \x5C   \x5C\x3A\x5C        \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x3A\x2F                   ");
	printf("\n\t     \x5C\x5F\x5F\x5F\x5C\x2F        \x5C\x5F\x5F\x5F\x5C\x2F         \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F   ");

	printf("\n\n\n");


}



void Bye_Message(void)
{
	for (int c = 6, t = 7,s = 3; c <= 6; c++)
	{
		printf("\033[%d;%d%dm",t,s, c);
		printf("\n\n");

		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDC\xDB\xDB\xDC\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xDC\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDF\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");

		printf("\n\n\n");
		printf("\033[0m");
	}
}