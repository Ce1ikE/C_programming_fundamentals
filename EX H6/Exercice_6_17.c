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

void Empty_square(int);
void Filled_square(int);
void Crossed_square(int);
void Line(void);
void Hello(void);
int Error(int);
void Bye(void);

int main(void)
{
	/* Exercice 6.17

	Assignment:
	Write a program that asks the user to choose between 3 options:
	 1. Draw an empty square
	 2. Draw a filled square
	 3. Stop
	The program repeats itself until the user chooses the option 3 (Stop).
	Use the functions ‘empty_square’ and ‘filled_square’

	*/

	printf("\n\t----\tDit is oefening 6.17 van 'Cprogrammingfundamentals2020' Pg108\t----\n\n\n\n");

	Hello();

	int Option,width;

	printf("What option do you choose?: \n\t\t 1. Draw an empty square \n\t\t 2. Draw a filled square \n\t\t 3. Draw a crossed square \n\t\t 4. Stop \n\t\t => ");
	scanf("%d%*c",&Option);


	while (Option != 4)
	{
		while (Option < 0 || Option > 4)
		{
			printf("\n\n\t THIS OPTION IS INVALID!! \n\n\t Enter a valid option: 1, 2, 3 or 4 \n\t\t\t =>  ");
			scanf("%d%*c", &Option);
		}

		switch (Option)
		{
		case 1:
		{

			printf("\n What should the width of the square be?:\t => ");
			scanf("%d%*c", &width);
			width = Error(width);
			printf("\n\n");
			Empty_square(width);

			break;
		}

		case 2:
		{
			printf("\n What should the width of the square be?:\t => ");
			scanf("%d%*c", &width);
			width = Error(width);
			printf("\n\n");
			Filled_square(width);

			break;
		}

		case 3:
		{
			printf("\n What should the width of the square be?:\t => ");
			scanf("%d%*c", &width);
			width = Error(width);
			printf("\n\n");
			Crossed_square(width);

			break;
		}

		default:

		break;
		}
		if (Option == 1 || Option == 2 || Option == 3)
		{
			printf("\n\n What option do you choose?: \n\t\t 1. Draw an empty square \n\t\t 2. Draw a filled square \n\t\t 3. Draw a crossed square  \n\t\t 4. Stop \n\t\t => ");
			scanf("%d%*c", &Option);
		}
		
	}
	
	Line();
	printf("\n\t------ THANK YOU !! for playing with us ------\n");
	Line();
	Bye();
	printf("\n\n\n");


	return 0;

}

/* Functions definition */

// we use the same integers for the 'for' loops since these are local variables that have no effect on the main or other functions 

void Empty_square(int width)
{
	// Full line (Upper side)
	printf("\n\n");
	for (int s = 0; s < width; s++)
	{
	printf("\xDB");
	}

	printf("\n");

	// Middle section (Left side and Right side)
	for (int i = 0; i < ((width-2)*0.55); i++)
	{
	printf("\xDB");
		for (int t = 0; t < width-2; t++) // Reducing the width by 2 since we already have a upper side and bottom side.
		{								//	Not doing so will cause our square to look too much like a rectangle which we don't want.
		printf(" ");
		}
	printf("\xDB\n");
	}

	// Full line (Bottom side)
	for (int m = 0; m < width; m++)
	{
	printf("\xDB");
	}

}


void Filled_square(int width)
{
	// Height of the square = width * (amount in %) => because the ASCII character 219 (hex DB) is a black rectangle so we reduce the height to create a better looking square 
	printf("\n\n");
	for (int i = 0; i < (width*0.55); i++)
	{
		for (int t = 0; t < width; t++)
		{
		printf("\xDB");
		}

	printf("\n");
	}

}


// Just a line for better esthetic end results
void Line(void)
{
	
	for (int i = 0; i < 60; i++)
	{
		printf("-");
	}

}

// A way to restrain the user to a certain 'width' range [5;30]
int Error(int width)
{
	
	while (width < 5 || width > 30)
	{
		if (width < 5)
		{
		printf("\n Too small please restrain your width to the interval [5;30]");
		}
		if (width > 30)
		{
		printf("\n\n Too much for me to handle. Choose a other width please between the interval [5;30]");
		}
		
	printf("\n What should the width of the square be?:\t => ");
	scanf("%d%*c", &width);

	}

	return width;
}

// The extra challenge
void Crossed_square(int width)
{
	int schaakelaar;
	float x;
	x = 0.55;
	schaakelaar = 0;
	if (width % 2 == 1)
	{
		width = width + 1;
	}

	// Full line (Upper side)
	printf("\n\n");
	for (int s = 0; s < width; s++)
	{
		printf("\xDB");
	}
	printf("\n");

	// Middle section (Left and Right side and cross)
	for (int i = 0; i < width - 3; i++)
	{
		printf("\xDB");// Left block

		for (int s = 0; s < i && s < (width - (4 + i)); s++) // The gap between the Left block and the 1st block of the cross on a line 
		{
			printf(" ");
		}
		printf("\xDB"); // 1st block of the cross
		if (i < width / 2) // From here we calculate the distance from the 1st block to the 2nd block of the cross
		{

			for (int t = 0; t < (width - (4 + i * 2)); t++)
			{
				printf(" ");
			}
			schaakelaar++;
		}
		if (schaakelaar >= width / 2)
		{
			for (int c = 0; c < ((4 + i * 2) - width); c++)
			{
				printf(" ");
			}

		}
		printf("\xDB"); // 2nd block of the cross
		for (int a = 0; a < i && a < (width - (4 + i)); a++) // Finally the gap between the 2nd block of the cross and the Right block
		{
			printf(" ");
		}

		printf("\xDB\n"); // Right block
	}


	// Full line (Bottom side)
	for (int m = 0; m < width; m++)
	{
		printf("\xDB");
	}
}



// Hello message with "hello" in 3D perspective
void Hello(void)
{

	printf("\n\n");
	printf("\n      \x5F\x5F\x5F\x5F          \x5F\x5F\x5F\x5F           \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F                         ");
	printf("\n     \x2F   \x2F\x5C        \x2F   \x2F\x5C         \x2F   \x2F\x5C      \x2F   \x2F\x5C      \x2F   \x2F\x5C                                       ");
	printf("\n    \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x3A\x5C       \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x3A\x5C                 ");
	printf("\n   \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     ");
	printf("\n  \x2F   \x2F\x3A\x3A\x5C \x5F\x5F\x5F  \x2F   \x2F\x3A\x3A\x5C \x5C\x3A\x5C   \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F  \x5C\x3A\x5C    ");
	printf("\n \x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C  \x2F\x5C\x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C \x5C\x3A\x5C \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F \x5C\x5F\x5F\x5C\x3A\x5C    ");
	printf("\n \x5C\x5F\x5F\x5F\x5C\x2F  \x5C\x3A\x5C\x2F\x3A\x2F\x5C   \x5C\x3A\x5C \x5C\x3A\x5C\x5F\x5C\x2F \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C \x2F  \x2F\x3A\x2F  ");
	printf("\n      \x5C\x5F\x5F\x5F\x5C\x3A\x3A\x2F  \x5C   \x5C\x3A\x5C \x5C\x3A\x5C    \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C  \x2F\x3A\x2F     ");
	printf("\n      \x2F   \x2F\x3A\x2F    \x5C   \x5C\x3A\x5C\x5F\x5C\x2F     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C\x2F\x3A\x2F       ");
	printf("\n     \x2F\x5F\x5F\x5F\x2F\x3A\x2F      \x5C   \x5C\x3A\x5C        \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x3A\x2F                   ");
	printf("\n     \x5C\x5F\x5F\x5F\x5C\x2F        \x5C\x5F\x5F\x5F\x5C\x2F         \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F   ");
	printf("\n\n\n");


}

void Bye(void)
{
	printf("\n\n\n");

	printf("\n \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDF\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n \xDB\xDB\xDB\xDB\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n \xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDB");
	printf("\n \xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDC\xDB\xDB\xDC\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB");
	printf("\n \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xDC\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB");
	printf("\n \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n \xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB");
	printf("\n \xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDF\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

	printf("\n\n\n");


}