
/* Headers */

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Macro's */

#define StringLength	(32)
#define COLOR_ON(c)		(printf("\033[3"#c"m"))
#define COLOR_OFF()		(printf("\033[m"))

/* Struct's */

typedef struct Datum_t {

	int Dag;
	char Maand[StringLength];
	int Jaar;

} datum;

typedef struct Film_t {

	char Titel[StringLength];
	float Prijs;
	datum Uitgavedatum;
	char Genre[StringLength];

} film;

/* Function definitions */

void Check_Arg(int);
void Check_file(FILE*);
void lees(FILE*,film*,int*,int,int);
void menu(int*);
void statistieken(film*,int);
void genre(film*, int);

int main(int argc,char ** argv)
{
	/* argv & argc */
	/*
	
	argv[0] => Prog.exe
	argv[1] => FileName
	argv[2] => Jaartal
	argv[3] => Max_Aantal
	
	argc == 4

	*/

	/* Check voor aantal argumenten */
	Check_Arg(argc);

	int Jaartal = atoi(argv[2]);
	int Max_Aantal = atoi(argv[3]);
	int Aantal_in_Lijst = 0;
	int keuze = 0;

	FILE * FilePointer;
	char FileName[StringLength];
	strcpy(FileName, argv[1]);
	FilePointer = fopen(FileName, "r");

	/* Check voor file */
	Check_file(FilePointer);

	/* Create dynamic struct array for films */
	film* Lijst = (film*)malloc(Max_Aantal * sizeof(film));

	/* Lees file inhoud */
	lees(FilePointer, Lijst, &Aantal_in_Lijst, Max_Aantal, Jaartal);

	if (Aantal_in_Lijst != 0)
	{
		while (keuze != 3)
		{
			menu(&keuze);

			switch (keuze)
			{
			case 1: statistieken(Lijst, Aantal_in_Lijst); break;
			case 2: genre(Lijst, Aantal_in_Lijst); break;
			case 3: printf("\n\n\tProgramma verlaten...");
			default:
				break;
			}
		}
	}
	else
	{
		printf("\nGeen films gevonden met uitgavejaar %d", Jaartal);
	}


	printf("\n\n");
	free(Lijst);
	fclose(FilePointer);
	return 0;
}

/* Function declarations */

void Check_Arg(int arg_N)
{
	if (arg_N != 4)
	{
		printf("\n\nFout aantal argumenten meegegeven aan het programma!");
		exit(-1);
	}
}


void Check_file(FILE * FileSource)
{
	if (FileSource == NULL)
	{
		printf("\n\nFile niet gevonden/geopend");
		exit(-2);
	}
}


void lees(FILE* FileSource, film* Lijst, int * Aantal_in_Lijst, int Max_Aantal, int Jaartal)
{
	/* File format
	<string>				=> fgets
	<int> <string> <int>	=> fscanf
	<float> <string>		=> fscanf
	*/

	film Een_Film;

	while (fgets(Een_Film.Titel,StringLength,FileSource) != NULL && *Aantal_in_Lijst < Max_Aantal)
	{
		// 2nd line
		fscanf(FileSource, "%d%*c",&(Een_Film.Uitgavedatum.Dag));
		fscanf(FileSource, "%s%*c", Een_Film.Uitgavedatum.Maand);
		fscanf(FileSource, "%d%*c",&(Een_Film.Uitgavedatum.Jaar));
		// 3rd line
		fscanf(FileSource, "%f%*c",&(Een_Film.Prijs));
		fscanf(FileSource, "%s%*c",Een_Film.Genre);

		if (Een_Film.Uitgavedatum.Jaar == Jaartal)
		{
			*(Lijst + (*Aantal_in_Lijst)) = Een_Film; // Kopieer de inhoud van "Een_Film" naar "Lijst"
			(*Aantal_in_Lijst)++;
		}
	}
}


void menu(int * Keuze)
{
	printf("\n\nMaak een keuze:\n\t1) Statistieken \n\t2) Genre  \n\t3) Stop \n\t> ");
	scanf("%d%*c", Keuze);
	while (*Keuze < 1 || 3 < *Keuze)
	{
		printf("\n\nMaak een keuze:\n\t1) Statistieken \n\t2) Genre  \n\t3) Stop \n\t> ");
		scanf("%d%*c", Keuze);
	}
}


void statistieken(film * Lijst, int Aantal_in_Lijst)
{
	film Goedkoopste_Film, Duurste_Film;
	Goedkoopste_Film = *Lijst;
	Duurste_Film = *Lijst;

	float Gemmiddelde_Prijs = 0;

	for (int i = 0; i < Aantal_in_Lijst; i++)
	{
		if (Goedkoopste_Film.Prijs > (Lijst + i)->Prijs)
		{
			Goedkoopste_Film = *(Lijst + i);
		}

		if (Duurste_Film.Prijs < (Lijst + i)->Prijs)
		{
			Duurste_Film = *(Lijst + i);
		}

		Gemmiddelde_Prijs += (Lijst + i)->Prijs;
	}

	Gemmiddelde_Prijs /= Aantal_in_Lijst;

	// =============== Print ====================

	printf("\n\nGoedkoopste film\n-------------");
	printf("\nTitel : %s", Goedkoopste_Film.Titel);
	printf("Uitgavedatum : %d %s %d", Goedkoopste_Film.Uitgavedatum.Dag, Goedkoopste_Film.Uitgavedatum.Maand ,Goedkoopste_Film.Uitgavedatum.Jaar);
	printf("\nPrijs : %.2f", Goedkoopste_Film.Prijs);

	printf("\n\nDuurste film\n-------------");
	printf("\nTitel : %s", Duurste_Film.Titel);
	printf("Uitgavedatum : %d %s %d", Duurste_Film.Uitgavedatum.Dag, Duurste_Film.Uitgavedatum.Maand, Duurste_Film.Uitgavedatum.Jaar);
	printf("\nPrijs : %.2f", Duurste_Film.Prijs);

	printf("\n\nGemiddelde prijs : %.2f", Gemmiddelde_Prijs);

}


void genre(film * Lijst, int Aantal_in_Lijst)
{
	char Genre_Keuze[StringLength];
	printf("\n\nNaar welke genre wil je zoeken?: ");
	scanf("%s%*c", Genre_Keuze);

	int Aantal_Gevonden = 0;

	// =============== Print ====================

	for (int i = 0; i < Aantal_in_Lijst; i++)
	{
		if ((strcmp((Lijst + i)->Genre,Genre_Keuze)) == 0)
		{
			printf("\n\nFilm Nr %d\n-------------", i + 1); // Print nummer in de lijst
			printf("\nTitel : %s",(Lijst + i)->Titel);
			printf("Uitgavedatum : %d %s %d", (Lijst + i)->Uitgavedatum.Dag, (Lijst + i)->Uitgavedatum.Maand, (Lijst + i)->Uitgavedatum.Jaar);
			printf("\nPrijs : %.2f", (Lijst + i)->Prijs);
			Aantal_Gevonden++;
		}
	}

	printf("\n\nAantal films met van genre : %s\n------------------------------\n", Genre_Keuze);
	printf("%d", Aantal_Gevonden);
}




