/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/


/* Headers */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#define Room_Rows 5
#define Room_Columns 5
#define Name_Length 32

/* Function declarations */

void Hello(void);
void Bye_Message(void);
void Print_Current_Reservations(char[][Room_Columns][Name_Length]);
void Check_Availability(char[][Room_Columns][Name_Length],char[],int ,int);
void Initialize_Seats(char[][Room_Columns][Name_Length]);
void Print_Line(int);


int main(void)
{
	/* Exercice 9.11

	Assignment:

	Write a program that simulates seat reservations in a theater. Let’s 
	consider a room with 3 rows of 4 seats each. Define a matrix of 3 x 4 
	that represents the room. Every matrix element must be large enough 
	to contain a string of maximal 10 symbols, resulting in a 2D array of 
	strings which is a 3D array of characters! The program repeats itself 
	until the user enters 0 0 0 or until all seats are taken.
	In every program run, a name, row number and seat number are read. 
	If the seat is still available, the name is stored in the corresponding row 
	and column of the matrix. If the seat was already taken, the program 
	prints “occupied”. After every seat reservation, all reservations are
	printed to the screen.

	Use functions to write the program:
	- declare the room in the main program
	- write a function to print the current reservations
	- write a function to initialize the reservations
	- write a function to read the inputs and check the availability of the
	 wanted seat

	*/

	printf("\n\t----\tDit is oefening 9.11 van 'Cprogrammingfundamentals2020' Pg142\t----\n\n\n\n");

	Hello();

	char Seats[Room_Rows][Room_Columns][Name_Length],reservation_Name[Name_Length];
	int Row_seat, SeatNr;

	printf("\nWelcome! The theater has %2d rows of %2d seats each.",Room_Rows,Room_Columns);

	Initialize_Seats(Seats);

	do
	{	
		printf("\nThe current reservations are:\n");
		Print_Current_Reservations(Seats);
		printf("\n\nEnter a new seat reservation(Name + row + seatNr) : ");
		scanf("%s%d%d", &reservation_Name, &Row_seat, &SeatNr);

		Check_Availability(Seats, reservation_Name, Row_seat, SeatNr);

	} while ((Row_seat && SeatNr && strcmp(reservation_Name,"0") )!= 0);

	printf("\n\nThe final seat reservations are:");
	Print_Current_Reservations(Seats);

	Bye_Message();


	return 0;
}

/* Function definitions */

void Initialize_Seats(char S[][Room_Columns][Name_Length])
{

	for (int n = 0; n < Room_Rows; n++)
	{
		for (int i = 0; i < Room_Columns; i++)
		{
			 
			 strcpy(S[n][i], ".\0");
			 
		}
	}


}

void Print_Current_Reservations(char S[][Room_Columns][Name_Length])
{
	printf("\n       |");
	for (int i = 0; i < Room_Columns; i++)
	{
		printf("     SEAT%2d ", i + 1);
	}
	printf("\n---------");
	Print_Line(Room_Columns);
	for (int n = 0; n < Room_Rows; n++)
	{
		printf("\nROW %2d |", n + 1);
		for (int i = 0; i < Room_Columns; i++)
		{
			printf("\033[0;37m %10s \033[0m", S[n][i]);
		}
	}
}


void Check_Availability(char S[][Room_Columns][Name_Length], char Name[], int Row, int SeatNr)
{


	int Seats_available = 0,t,i = 0; // Assume there are no seats available
	while (i < Room_Rows && Seats_available == 0)
	{
		t = 0;
		while (S[i][t] != '.' && t < Room_Columns)
		{

			t++;
		}

		if (t != Room_Columns - 1) // If during the check 't' didn't go till the end then it means there is in fact a seat available 
		{
			Seats_available = 1;
		}
		i++;
	}
	

	if (Seats_available == 1 && (Row != 0 && SeatNr != 0 && strcmp(Name,"0") != 0))
	{
		while (!(0 < Row <= Room_Rows || 0 < SeatNr <= Room_Columns))
		{
			printf("\n\n\t\033[0;31mERROR\033[0m\n\nEnter a new seat reservation(Name + row + seatNr) : ");
			scanf("%s%d%d", Name, &Row, &SeatNr);
		}
		Row -= 1;
		SeatNr -= 1;

		if (strlen(S[Row][SeatNr]) == 1 || strlen(S[Row][SeatNr]) == 2)
		{
			strcpy(S[Row][SeatNr], Name);
		}
		else
		{
			printf("\n\n\t\033[0;31mSEAT OCCUPIED\033[0m\n\n");
		}
	}

	if (Seats_available == 0)
	{
		printf("\n\n\t\033[0;31mALL SEATS OCCUPIED\033[0m\n\n");
	}
	
	

}

void Print_Line(int N)
{

	for (int i = 0; i < N; i++)
	{
		printf("-------------");
	}

}


void Hello(void)
{

	printf("\n\n\033[0;32m");

	printf("\n\t\t      \x5F\x5F\x5F\x5F          \x5F\x5F\x5F\x5F           \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F                ");
	printf("\n\t\t     \x2F   \x2F\x5C        \x2F   \x2F\x5C         \x2F   \x2F\x5C      \x2F   \x2F\x5C      \x2F   \x2F\x5C                                       ");
	printf("\n\t\t    \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x3A\x5C       \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x3A\x5C                 ");
	printf("\n\t\t   \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     ");
	printf("\n\t\t  \x2F   \x2F\x3A\x3A\x5C \x5F\x5F\x5F  \x2F   \x2F\x3A\x3A\x5C \x5C\x3A\x5C   \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F  \x5C\x3A\x5C    ");
	printf("\n\t\t \x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C  \x2F\x5C\x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C \x5C\x3A\x5C \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F \x5C\x5F\x5F\x5C\x3A\x5C    ");
	printf("\n\t\t \x5C\x5F\x5F\x5F\x5C\x2F  \x5C\x3A\x5C\x2F\x3A\x2F\x5C   \x5C\x3A\x5C \x5C\x3A\x5C\x5F\x5C\x2F \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C \x2F  \x2F\x3A\x2F  ");
	printf("\n\t\t      \x5C\x5F\x5F\x5F\x5C\x3A\x3A\x2F  \x5C   \x5C\x3A\x5C \x5C\x3A\x5C    \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C  \x2F\x3A\x2F     ");
	printf("\n\t\t      \x2F   \x2F\x3A\x2F    \x5C   \x5C\x3A\x5C\x5F\x5C\x2F     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C\x2F\x3A\x2F       ");
	printf("\n\t\t     \x2F\x5F\x5F\x5F\x2F\x3A\x2F      \x5C   \x5C\x3A\x5C        \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x3A\x2F                   ");
	printf("\n\t\t     \x5C\x5F\x5F\x5F\x5C\x2F        \x5C\x5F\x5F\x5F\x5C\x2F         \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F   ");

	printf("\n\n\n\033[0m");

}


void Bye_Message(void)
{
	for (int c = 6, t = 7, s = 3; c <= 6; c++)
	{
		printf("\033[%d;%d%dm", t, s, c);
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