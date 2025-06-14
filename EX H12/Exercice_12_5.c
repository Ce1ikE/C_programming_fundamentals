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

/* Function declarations */

void Hello(void);
void Bye_Message(void);
short int Input(void);
void Output(short int);

int main(void)
{
	/* Exercice 12.5

	Assignment:
	Write a function that prints the binary representation of a short int
	using bit operations. Write a program that uses this function.

	*/

	printf("\n\t----\tDit is oefening 12.5 van 'Cprogrammingfundamentals2020' Pg177\t----\n\n\n\n");

	Hello();

	short int Number;

	Number = Input();

	Output(Number);

	Bye_Message();
	

	return 0;
}



short int Input(void)
{
	short int Number;
	int Count = 0;


	printf("Number INPUT : ");

	scanf("%hd%*c",&Number);

	
	return Number;
}



void Output(short int Number)
{
	// 1st Method ====================================================================================================================================================
	// Schema
	/*
		                  BIN(0b)	   DEC    HEX(0x) => In hex notation each number [0-F] defines the value of 4 bits since 2^0 + 2^1 + 2^2 + 2^3 = 1111 = 16 = F
	short int i = 0000 0000 0000 0001 = 1 =    0001 
	
		i << 15 => "i"'s bits are all shifted 15 bits to the left

				          BIN(0b)		  DEC      HEX(0x)
	short int i = 1000 0000 0000 0000 = -32 768 =   8000 => As we can see we would have a negative value using a "short int" that is why we use a "int" type which has more bits available thus not having a negative value
														 => A other problem that will occur if we had used a "short int" is that our MSB (most left bit) would equal "1" and every time we shift to the right the leading "1" creates a trailing "1" 
														 => 1000 0000 0000 0000 >> 1100 0000 0000 0000 etc.. >> 1111 1111 1111 1111 != 1 but = -1

	int i = ...00 1000 0000 0000 0000 = 32 768 = 0x...8000 => Positive => since our number N is a short integer we don't have to worry about the bits that are placed in front of 16th bit of "i"

						                      BIN(0b)		DEC   HEX(0x)
	say our number is a short int N = 0000 0000 0010 1101 = 45 =   002D

		1st iteration	          2nd iteration                 16th iteration 
	+--+-------------------+  +--+-------------------+      +--+-------------------+
	|i |1000 0000 0000 0000|  |i |0100 0000 0000 0000| ...  |i |0000 0000 0000 0001|
	+--+-------------------+  +--+-------------------+      +--+-------------------+
	|N |0000 0000 0010 1101|  |N |0000 0000 0010 1101| ...  |N |0000 0000 0010 1101|
	+--+-------------------+  +--+-------------------+      +--+-------------------+
	|& |0000 0000 0000 0000|  |& |0000 0000 0000 0000|      |& |0000 0000 0000 0001|
	+--+-------------------+  +--+-------------------+      +--+-------------------+

	=> Evaluates 0 , false    => Evaluates 0 , false   ...  => Evaluates 1 , true
	=> Prints "0"			  => Prints "0"            ...  => Prints "1"

	*/
	int Count = 0;
	printf("\n\n(binary representation) OUPUT (1st method): ");
	for (int i = 1 << 15; i > 0; i >>= 1) // we are starting with the MSB in order to work our way down to the LSB. The reason behind it is because we are printing from left to right.
	{


		if (Number & i)   // 0 != true and 0 = false so simply putting 'Number & i ? printf("1") : printf("0");' would also statisfy => ternary operators might be incompatibele so avoid using them 
		{
			printf("1");
		}
		else
		{
			printf("0");
		}

		Count++;

		if (Count == 4)
		{
			printf(" ");
			Count = 0;
		}
	}
	
	// 2nd Method ====================================================================================================================================================
	// With masking
	// Schema
	/*
		
							                   BIN(0b)		DEC   HEX(0x)
	say our number is a short int N = 0000 0000 0110 1100 = 108 =   006C

	and 0x8000 = 1000 0000 0000 0000 = 32768


		     1st iteration	                10nd iteration                     16th iteration
	+-------+-------------------+  +-------+-------------------+      +-------+-------------------+
	|N      |0000 0000 0110 1100|  |N      |1101 1000 0000 0000| ...  |N      |0000 0000 0000 0000|
	+-------+-------------------+  +-------+-------------------+      +-------+-------------------+
	|0x8000 |1000 0000 0000 0000|  |0x8000 |1000 0000 0000 0000| ...  |0x8000 |1000 0000 0000 0000|
	+-------+-------------------+  +-------+-------------------+      +-------+-------------------+
	|       |0000 0000 0000 0000|  |       |1000 0000 0000 0000| ...  |       |0000 0000 0000 0000|
	+-------+-------------------+  +-------+-------------------+      +-------+-------------------+
	|>> 15  |                   |  |>> 15  |                   | ...  |>> 15  |                   |
	+-------+-------------------+  +-------+-------------------+      +-------+-------------------+
	|Bit    |0000 0000 0000 0000|  |Bit    |0000 0000 0000 0001|      |Bit    |0000 0000 0000 0000|
	+-------+-------------------+  +-------+-------------------+      +-------+-------------------+

	=> Bit = 0					   => Bit = 1						  => Bit = 0
	=> Prints "0"			       => Prints "1"                 ...  => Prints "0"
	
	*/
	Count = 0;
	printf("\n\n(binary representation) OUTPUT(2nd method with masking) : ");
	for (int i = 0; i < 16; i++) 
	{
		short int Bit = (Number & 0x8000) >> 15; // 0x8000 == 1000 0000 0000 0000
		printf("%hd",Bit);

		Number <<= 1; // Shift all bits to the left in "Number" by 1
		Count++;

		if (Count == 4)
		{
			printf(" ");
			Count = 0;
		}
	}
	
}



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

	printf("\n\n");

	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDF\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDC\xDB\xDB\xDC\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xDC\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDF\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

	printf("\n\n\n");

}