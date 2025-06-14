
/*

	Class: 1EICT
	Name: Celik
	Firstname: Ennis

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#define Aantal_trekkingen 6 // Hiermee pas je het aantal trekkingen aan dat in de Lottotrekking van vandaag worden weergegeven
#define Aantal_Nummers 42 // Hiermee pas je de mogelijke getrokken nummers aan

/* Functie declaraties*/

void Lotto_Trekking(short[]); // Trekking is verplicht 'short'
short Keuze(void); // "Keuze" mag 'long (int)' of 'short (int)' zijn 
void Print(short[], short);

int main(void)
{
	short Trekking[Aantal_trekkingen], Keuze_Print_methode;

	Lotto_Trekking(Trekking);

	Keuze_Print_methode = Keuze();

	Print(Trekking,Keuze_Print_methode);
	printf("\n\n\n");
	return 0;
}

/* Functie definities */

void Lotto_Trekking(short Trekking[])
{
	srand(time(NULL));

	for (int i = 0; i < Aantal_trekkingen; i++)
	{
		int Dubbele;
		do 
		{
			Dubbele = 0;
			Trekking[i] = rand() % Aantal_Nummers + 1; // Hier wordt een random waarde gegenereerd in [1 ; Aantal_Nummers] (Normaal == 42) en daarna '+ 1' omdat we geen '0' willen hebben in de trekking
			for (int t = 0; t < i; t++) // Hier moet een 'for' loop geïmplementeerd worden omdat er een check moet gedaan voor dubbele waarden van het begin t.e.m. waar we al waarden hebben gegenereerd 
			{
				if (Trekking[t] == Trekking[i])
				{
					Dubbele = 1;
				}
			}
		} while (Dubbele);
	}



}

short Keuze(void) // "Keuze" mag 'int' of 'short' zijn 
{
	short Keuze_Print;

	printf("\n\nHoe wil je de trekking weergeven? Kies een methode(1 of 2)\n\t\t1.Tekenen\n\t\t2.Binair\n\t\t=> ");
	scanf("%hd%*c", &Keuze_Print);
	while (Keuze_Print != 1 && Keuze_Print != 2)
	{
		printf("\n\nDit is niet een geldige keuze! Kies Opnieuw: => ");
		scanf("%hd%*c", &Keuze_Print);
	}

	return Keuze_Print;
}

void Print(short Trekking[], short Keuze_Print)
{

	if (Keuze_Print == 1)
	{
		char Teken;
		printf("\nMet welk symbool wil je de trekking voorstellen? : ");
		scanf("%c%*c", &Teken);
		printf("\nDit is de Lottotrekking van vandaag:\n");

		for (int i = 0; i < Aantal_trekkingen; i++)
		{
			printf("\n%2hd |\t", Trekking[i]);
			for (int t = 0; t < Trekking[i]; t++)
			{
				printf("\033[0;32m%c\033[0m", Teken);
			}

		}

	}
	else // Keuze_Print == 2
	{
		printf("\nDit is de Lottotrekking van vandaag:\n");
		for (int t = 0; t < Aantal_trekkingen; t++) 
		{
			printf("\n%2hd |\t", Trekking[t]);
			int Count = 0;
			for (int i = 1 << 15; i >= 1; i = i >> 1) // Begin the werken van de MSB tot de LSB voor de binaire vorm
			{
				printf("\033[0;32m");
				(Trekking[t] & i) ? printf("1") : printf("0");
				printf("\033[0m");

				/* Is het zelfde als dit :
				if (Trekking & i)   // 1 = Juist and 0 = Fout 
				{
					printf("1");
				}
				else
				{
					printf("0");
				}
				*/


				Count++;

				if (Count == 4)
				{
					printf(" ");
					Count = 0;
				}
			}


		}

	}





}








