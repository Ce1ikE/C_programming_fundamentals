/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Macro's */


/* Headers */

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>


/* Function declarations */

void Donut(void);

int main(void)
{

	Donut();

	return 0;
}

/* Function definitions */


void Donut(void) 
{
	int k;
	float A = 0, B = 0, i, j, z[1760];
	char b[1760];
	printf("\x1b[2J"); // ANSI CSI code to erase the content of the screen
	printf("\x1b[?25l");
	for (; ;) 
	{
		
		memset(b, 32, 1760);
		memset(z, 0, 7040);
		for (j = 0; 6.28 > j; j += 0.02) 
		{
			for (i = 0; 6.28 > i; i += 0.02) 
			{
				float sini = sin(i);
				float cosi = cos(i);
				float cosj = cos(j);
				float sinj = sin(j);
				float sinA = sin(A);
				float cosA = cos(A);
				float cosB = cos(B);
				float sinB = sin(B);
				float cosj2 = cosj + 2;
				float mess = 1 / (sini * cosj2 * sinA + sinj * cosA + 5);
				float t = sini * cosj2 * cosA - sinj * sinA;

				int	x = 40 + 25 * mess * (cosi * cosj2 * cosB - t * sinB); // Added constants K1 and K2
				int	y = 12 + 13 * mess * (cosi * cosj2 * sinB + t * cosB); // 1760 / 80 = 22
				int	o = x + 80 * y;
				int	N = 8 * ((sinj * sinA - sini * cosj * cosA) * cosB - sini * cosj * sinA - sinj * cosA - cosi * cosj * sinB);

				if (0 < y < 22 && 0 < x < 80 && mess > z[o]) 
				{
					z[o] = mess;
					b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
				}
			}
		}
		printf("\x1b[H"); // ANSI CSI code to put the cursor back to home (0;0)(top left corner)
		for (k = 0; 1761 > k; k++) 
		{
			putchar(k % 80 ? b[k] : 10);
		}
			
		A += 0.04;
		B += 0.1;
	}
}





