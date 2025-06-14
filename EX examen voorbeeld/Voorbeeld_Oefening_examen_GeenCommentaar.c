/*

	C Fundamentals

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>  
#include <string.h>


#define COLOR_ON(c)		(printf("\033[3"#c"m"))
#define COLOR_OFF()		(printf("\033[m")) 
#define StrLength		32 
#define StrBuffer		512 

typedef struct t_Date {

	int Dag;
	int Maand;
	int Jaar;

} date;

typedef struct t_Person {

	char Naam[StrLength];
	date Geboortedatum;
	char Gemeente[StrLength];

} person;



void Lees(FILE*, person*, int, int, int*, int[], int*);
void Kies(int*);
void Bereken(person, int*, int[]);
void Printen(int, person*, int, int[], int);

int main(int argc, char* argv[])
{

	if (argc != 7)
	{
		COLOR_ON(1);
		printf("\n\nGeef het correcte aantal argumenten in: ");
		COLOR_OFF();
		printf("<Naam.exe><FileNaam><Dag><Maand><Jaar><Leeftijdgrens><Max aantal>\n\n");
		exit(-1);
	}

	FILE* fs;
	char Filename[StrLength];

	strcpy(Filename, argv[1]);
	fs = fopen(Filename, "r"); 
	if (fs == NULL)
	{
		COLOR_ON(1);
		printf("\n\n\tHet opgegeven bestand %s kan niet geopend worden.\n\n", Filename);
		COLOR_OFF();
		exit(-1);
	}

	int MaxAantal = atoi(argv[6]);
	int Leeftijdsgrens = atoi(argv[5]);

	person* PersDATA = (person*)malloc(MaxAantal * sizeof(person));
	int Datum[3] = { atoi(argv[2]),atoi(argv[3]), atoi(argv[4]) };
	int Keuze, Teller = 0;
	int min_Leeftijd_Index;

	Lees(fs, PersDATA, MaxAantal, Leeftijdsgrens, &Teller, Datum, &min_Leeftijd_Index);

	if (Teller > 0)
	{
		Kies(&Keuze);

		Printen(Keuze, PersDATA, Teller, Datum, min_Leeftijd_Index);
	}
	else
	{
		printf("\n\nGeen personen gevonden die ouder zijn dan %d jaar", Leeftijdsgrens);
	}

	printf("\n\n\n\n");
	free(PersDATA); 
	fclose(fs);

	return 0;
}

/* Function definitions */

void Lees(FILE* fs, person* PersDATA, int MaxAantal, int Leeftijdsgrens, int* Teller, int Datum[], int* LeeftijdIndex)
{
	person Iemand;
	char BUFFER[StrBuffer];
	int Leeftijd, min_Leeftijd = 0;

	while (fgets(BUFFER, StrBuffer, fs) != NULL && *Teller < MaxAantal)
	{
		strcpy(Iemand.Naam, BUFFER);
		fscanf(fs, "%d%*c", &(Iemand.Geboortedatum.Dag));
		fscanf(fs, "%d%*c", &(Iemand.Geboortedatum.Maand));
		fscanf(fs, "%d%*c", &(Iemand.Geboortedatum.Jaar));
		fscanf(fs, "%s%*c", Iemand.Gemeente);
		Bereken(Iemand, &Leeftijd, Datum);

		if (Leeftijd >= Leeftijdsgrens)
		{
			*(PersDATA + *Teller) = Iemand;

			if (*Teller == 0)
			{
				min_Leeftijd = Leeftijd;
				*LeeftijdIndex = *Teller;
			}
			
			if (min_Leeftijd > Leeftijd)
			{
				*LeeftijdIndex = *Teller;
			}
			(*Teller)++;
		}
	}
}

void Kies(int* Keuze)
{
	printf("\n\nKies een van de volgende opties om te printen: \n\t1) Jongste persoon \n\t2) Zoek met gemeente\n\t=> ");
	scanf("%d%*c", Keuze);

	while (*Keuze != 1 && *Keuze != 2)
	{
		printf("\n\n\tDit is geen geldige keuze\n\nKies een van de volgende opties om te printen: \n\t1) Jongste persoon \n\t2) Zoek met gemeente\n\t=> ");
		scanf("%d%*c", Keuze);
	}
}

void Bereken(person Iemand, int* Leeftijd, int Datum[])
{

	int days = Datum[0] - Iemand.Geboortedatum.Dag;

	int months = Datum[1] - Iemand.Geboortedatum.Maand;
	if (days <= 0)
	{
		months -= 1;
	}

	*Leeftijd = Datum[2] - Iemand.Geboortedatum.Jaar;
	if (months < 0)
	{
		*Leeftijd -= 1;
	}
}


void Printen(int Keuze, person* PersDATA, int Teller, int Datum[], int LeeftijdIndex)
{
	char NaamGemeente[StrLength];
	int Leeftijd;
	int Count = 0;
	int Found = 0;
	
	switch (Keuze)
	{
	case 1:
		COLOR_ON(2);
		Bereken(*(PersDATA + LeeftijdIndex), &Leeftijd, Datum);
		printf("\n\n%s\nLeeftijd: DEC: %d\tHEX: %x\tBIN: ", (PersDATA + LeeftijdIndex)->Naam, Leeftijd, Leeftijd);

		for (int i = 1 << 15; i > 0; i >>= 1)
		{
			if (Leeftijd & i)
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
		COLOR_OFF();
		break;
	case 2:
		printf("\n\nVan welke gemeente wil je de leeftijden kennen? => ");
		scanf("%s%*c", NaamGemeente);
		COLOR_ON(2);
		for (int i = 0; i < Teller; i++)
		{
			if (strcmp((PersDATA + i)->Gemeente, NaamGemeente) == 0)
			{
				Bereken(*(PersDATA + i), &Leeftijd, Datum);
				printf("\n%s\n%d\n", (PersDATA + i)->Naam, Leeftijd);
				Found = 1;
			}
		}
		COLOR_ON(1);
		if (Found == 0)
		{
			printf("\nEr is niemand die in %s woont.", NaamGemeente);
		}
		COLOR_OFF();
		break;
	default:
		break;
	}
	
}
