/*

	C Fundamentals

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#define _CRT_SECURE_NO_WARNINGS // EEN MUST!!!!
#include <stdlib.h> // Om alle "print" en "scanf" functies te gebruiken
#include <stdio.h>  
#include <string.h> // Om "strcmp" en "strlen" te gebruiken 

/* Macro's */

#define COLOR_ON(c)		(printf("\033[3"#c"m")) // Optioneel
#define COLOR_OFF()		(printf("\033[m")) // Optioneel
#define StrLength		32 // Optioneel
#define StrBuffer		512 // Optioneel

/* Structures */
/* What structures do I need to use?

	Maak een structure “Persoon” met de velden “naam”,
	“geboortedatum” en “gemeente” waarin je de informatie van 1
	persoon kan opslaan.
	
	Hierin is het veld “geboortedatum” zelf een
	structure met de velden “dag”, “maand” en “jaar”. De velden
	“naam” en “regio” zijn strings, de velden “dag”, “maand” en “jaar”
	zijn integers.

*/
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

/* Function declarations */
/* What functions do I need to use?
	
	maak een functie “lees”
	maak een functie “kies”
	maak een functie “printen”
	Maak gebruik van je eerder geschreven functie “bereken”

*/
void Lees(FILE*, person*,int,int,int*,int[],int*);
void Kies(int*); // De kies functie moet maar 1 argument krijgen om te beslissen wat we daarna gaan doen in de "Printen" functie
void Bereken(person, int*,int[]);
void Printen(int, person*,int,int[],int);

// OPGEPAST in 3 functies staat er een pointer van het type "person" als argument maar dit is werkelijk een array van het type "person"
// Uitleg :
/*
	Stel
	als "P" een pointer is van het type "int"
	en "A" een array is van het type "int"

	om te verwijzen naar een waarde waartoe de pointer verwijst moet ik het volgende doen:
	--------------------------------------------------------------------------------------

	*(P) = Waarde1 => P is een adres met de operator "*" kan ik de waarde bemachtigen die achter deze pointer zit
	Als ik "P + 1" doe dan wordt niet "Waarde1" met 1 verhoogd maar verschuift het adres van P met een groote van N bytes (het type "int" kan 4 of 8 bytes groot zijn)
	hierdoor kan ik een nieuw adres lezen namelijk "P + 1". Wat hier achter verschuild zit weet ik niet maar daarom moet je zelf weten hoe ver je mag gaan.

	dus 

	*(P) = Waarde1
	*(P + 1) = Waarde2
	*(P + 2) = Waarde3
	etc...
	*(P + n) = Waarde(n)

	Om te verwijzen naar een waarde waartoe de array verwijst moet ik het volgende doen:
	------------------------------------------------------------------------------------

	A[0] = Waarde1 => *(P + 0) = Waarde1
	A[1] = Waarde2 => *(P + 1) = Waarde2
	etc...

	A[n] = Waarde(n) => deze notatie lijkt heel hard op "*(P + n) = Waarde(n)" simpelweg omdat een array (in dit geval A) ook eigenlijk een pointer is. 

	Conclusie:
	Dus als ik een pointer(P) van het type "Person" zou heb ik eigenlijk een array(A) van het type "Person"

*/

int main(int argc, char* argv[])
{
	// =======================================================================================================================================
	// =======================================================================================================================================
	// ========================================= UITLEG : OPGAVE 16.3 + OPGAVE VOORBEELD EXAMEN ==============================================
	// =======================================================================================================================================
	// =======================================================================================================================================

	// Assignement : Exercice 16.3
	/* 

	Assignment:

	Write a program with command line arguments that calculates the
	age (in number of years) of a number of people based upon their date
	of birth and the current date.

	- make a text file containing a number of names with their
	corresponding dates of birth. Make sure names and dates of birth
	are always written in the same way in the text file.

	- write a function “read_person” to read the data of 1 person from the
	file and save that data into a struct of the type “Person”. This
	struct contains a name field and a field to save the date of birth,
	which is a struct of the type “Date”.

	- call the program from the command line with the current date and
	the text file as arguments

	- write a function “calculate” that calculates the age of a person in
	years, months and days. This function also determines which person
	is the oldest and which person has the longest name.

	- printing the ages is done in the main function. Print also the names
	of the oldest person and of the person with the longest name.

	*/


	// Gedetailleerde opgave
	/*
	
	Maak een structure “Persoon” met de velden “naam”,“geboortedatum” en “gemeente” waarin je de informatie van 1 
	persoon kan opslaan.
	Hierin is het veld “geboortedatum” zelf een structure met de velden “dag”, “maand” en “jaar”.
	De velden “naam” en “regio” zijn strings, de velden “dag”, “maand” en “jaar” zijn integers.

	- de main functie bevat:

	1) controle van de ingegeven argumenten:
			Is het aantal argumenten correct?
			kan de tekst file geopend worden?

	Indien aan 1 van bovenstaande voorwaarden niet voldaan is, moet het programma een gepaste boodschap afdrukken en stoppen.
	(zie voorbeelden 1 en 2)

	2) aanmaken van de lijst = dynamische array van structs waarin 
	de gevonden personen kunnen opgeslagen worden.
	Zorg ervoor dat je array niet groter is dan nodig. Je mag het 
	opgegeven argument max_aantal gebruiken als grootte voor 
	je array.

	3) de nodige functies oproepen

	- maak een functie “lees” waarin je de personen met de juiste leeftijd inleest in een array van structs.
	Maak gebruik van je eerder geschreven functie “bereken” om de leeftijd van een persoon te bereken op basis van de huidige dag en de geboortedag. 
	De functie "bereken" geeft de leeftijd van de persoon in jaren als resultaat.
	Let op dat je niet buiten de grenzen van de array schrijft! 
	Hou ook bij hoeveel personen er uiteindelijk gevonden werden en geef dit door aan het hoofdprogramma.
	Indien er geen personen gevonden werden, moet het programma een gepaste boodschap printen en stoppen (zie voorbeeld 3)

	- maak een functie “kies” waarin je de gebruiker vraagt te kiezen 
	tussen “jongste” of “gemeente”. Zorg ervoor dat de gebruiker enkel 
	een geldige keuze kan ingeven en dat die keuze aan het main
	programma wordt doorgegeven.

	- maak een functie “printen” waarin je de gevraagde output afdrukt.
	1) Indien de gebruiker koos voor jongste zoek je de jongste
	van alle gevonden personen en druk je die af waarbij je de 
	leeftijd van die persoon in decimale, hex en binaire vorm 
	afdrukt. Voor de binaire vorm maak je gebruik van bit operaties.  (zie voorbeeld 4)

	(opm: zorg ervoor dat je eventuele lege plaatsen in de array niet meeneemt in je zoektocht naar de jongste)
	
	2) Indien de gebruiker koos voor gemeente, vraag je de
	gebruiker eerst om een gemeente en daarna print je alle
	gevonden personen af die in die gemeente wonen. (zie voorbeeld 5)

	*/

	// =======================================================================================================================================
	// =======================================================================================================================================
	// ========================================= STAP 1 KIJK DE INPUT NA =====================================================================
	// =======================================================================================================================================
	// =======================================================================================================================================


	// Check voor 7 argumenten => 
	// (1) het executie bestand ("Naam".exe)
	// (2) de naam van het text bestand waarin de data opgeslagen is  
	// (3) de dag van de ingegeven datum
	// (4) de maand van de ingegeven datum met een bereik van van [0-12]
	// (5) het jaartal van de ingegeven datum
	// (6) de leeftijdsgrens
	// (7) het max aantal

	// argv[0-6] = { "Naam.exe" , "Naam text bestand" , "Dag" , "Maand" , "Jaar", "leeftijdsgrens", "max aantal" };
	//					[0]				[1]			     [2]	  [3]      [4]			[5]				[6]
	
	if (argc != 7) // Is het aantal argumenten correct?
	{
		COLOR_ON(1);
		printf("\n\n\tGeef de correcte argumenten in: ");
		COLOR_OFF();
		printf("<Naam.exe><FileNaam><Dag><Maand><Jaar><Leeftijdgrens><Max aantal>\n\n");
		exit(-1);
	}
	
	FILE* fs; // fs == filesource
	char Filename[StrLength];

	strcpy(Filename, argv[1]);
	fs = fopen(Filename, "r"); // => Mode == 'r' de file moet bestaan anders is de return waarde "NULL"
	if (fs == NULL) // kan de tekst file geopend worden?
	{
		COLOR_ON(1);
		printf("\n\n\tHet opgegeven bestand %s kan niet geopend worden.\n\n",Filename);
		COLOR_OFF();
		exit(-1);
	}

	// =======================================================================================================================================
	// =======================================================================================================================================
	// ========================================= STAP 2 : BEGIN PROGRAMMA MAIN ===============================================================
	// =======================================================================================================================================
	// =======================================================================================================================================

	// Eerst moeten we het argument argv[6] omzetten naar een "int"
	int MaxAantal = atoi(argv[6]);
	// Zet ook het argument argv[5] 
	int Leeftijdsgrens = atoi(argv[5]);

	person* PersDATA = (person*)malloc(MaxAantal * sizeof(person));
	// Als je niet begrijpt waarom we een pointer gebruiken in plaats van een array => zie UITLEG lijn [68 ; 103]
	int Datum[3] = { atoi(argv[2]),atoi(argv[3]), atoi(argv[4]) }; 
	// Om niet te veel argumenten door te geven aan mijn functies stockeer ik de ingegeven datum in een array
	int Keuze,Teller = 0;
	int min_Leeftijd_Index;

	Lees(fs,PersDATA,MaxAantal,Leeftijdsgrens,&Teller,Datum, &min_Leeftijd_Index);
	
	if (Teller > 0)
	{
		Kies(&Keuze);

		Printen(Keuze, PersDATA,Teller,Datum, min_Leeftijd_Index);
	}
	else
	{
		printf("\n\nGeen personen gevonden die ouder zijn dan %d jaar", Leeftijdsgrens);
	}

	printf("\n\n\n\n");
	free(PersDATA); // Maak het geheugen blok "PersDATA" vrij
	fclose(fs); // Sluit de file

	return 0;
}

// =======================================================================================================================================
// =======================================================================================================================================
// ========================================= STAP 3 : BEGIN PROGRAMMA FUNCTIES ===========================================================
// =======================================================================================================================================
// =======================================================================================================================================

/* Function definitions */

void Lees(FILE* fs, person* PersDATA,int MaxAantal,int Leeftijdsgrens,int * Teller,int Datum[],int * LeeftijdIndex)
{
	/* !! FORMAT IN FILE:

	Voornaam1 Naam1
	Dag1 Maand1 Jaar1
	Gemeente1
	Voornaam2 Naam2
	Dag2 Maand2 Jaar2
	Gemeente2
	Voornaam3 Naam3
	Dag3 Maand3 Jaar3
	Gemeente3

	etc...

	*/
	person Iemand;
	char BUFFER[StrBuffer];
	int Leeftijd, min_Leeftijd = 0;

	// Scan de volledige naam // Je kan maar een maximum aantal personen opslaan door het feit dat je "malloc" hebt gebruikt
	while (fgets(BUFFER,StrBuffer,fs) != NULL && *Teller < MaxAantal) 
	{
		// Kopieer "BUFFER" naar "Iemand"
		strcpy(Iemand.Naam, BUFFER);
		// Scan dag geboorte datum
		fscanf(fs, "%d%*c", &(Iemand.Geboortedatum.Dag));
		// Scan maand geboorte datum
		fscanf(fs, "%d%*c", &(Iemand.Geboortedatum.Maand));
		// Scan jaar geboorte datum
		fscanf(fs, "%d%*c", &(Iemand.Geboortedatum.Jaar));
		// Scan gemeente naam
		fscanf(fs, "%s%*c", Iemand.Gemeente);
		// Bereken leeftijd
		Bereken(Iemand, &Leeftijd,Datum);

		if (Leeftijd >= Leeftijdsgrens) // Als de berekende leeftijd grooter of gelijk is aan de opgelegde leeftijdgrens dan mag de data opgeslagen worden
		{
			*(PersDATA + *Teller) = Iemand; // We slagen de data op in onze array
			// "PersDATA" is de pointer die het begin van de array aanduid
			// Om aan het volgende "person" adres te komen moet het adres geincrementeerd worden met "Teller"
			// Maar "Teller" is ook een pointer die een adres aanduid om de werkelijke waarden te bemachtigen moet je de "*" operator gebruiken
			// Volgorde: 
			// 1) de werkelijke waarde van "Teller" bemachtigen
			// 2) de pointer "PersDATA" incrementeren
			// 3) de werkelijke waarde van "PersDATA + *Teller" bemachtigen

			if (*Teller == 0)
			{
				min_Leeftijd == Leeftijd;
				*LeeftijdIndex = *Teller;
			}
			
			if (min_Leeftijd > Leeftijd)
			{
				*LeeftijdIndex = *Teller;
			}
			
			(*Teller)++; // "Teller" is een pointer maar we moeten de waarde die achter het adres zit veranderen
			// Volgorde is van de essentie hier : 
			// 1) moeten we de waarde bemachtigen => "*"
			// 2) moeten we de waarde verhogen => "++"
			// !!! Haakjes gebruiken is dan ook zeer belangrijk want (*P)++ != *P++  (Zie "Operator Precedence in C")
		}
	}
}

void Kies(int* Keuze) // Hier maakt de user de keuze over hoe hij wildt printen
{
	printf("\n\nKies een van de volgende opties om te printen: \n\t1) Jongste persoon \n\t2) Zoek met gemeente\n\t=> ");
	scanf("%d%*c", Keuze); // de operator "&" is niet nodig omdat "Keuze" een pointer is
	
	while (*Keuze != 1 && *Keuze != 2) // Zorg ervoor dat de user alleen een juist antwoord kan kiezen 
	// Aangezien de pointer "Keuze" een adres bevat moeten we naar dat adres gaan voor de inhoud te zien daarvoor gebruik je de operator "*"
	{
		printf("\n\n\tDit is geen geldige keuze\n\nKies een van de volgende opties om te printen: \n\t1) Jongste persoon \n\t2) Zoek met gemeente\n\t=> ");
		scanf("%d%*c", Keuze);
	}
}

void Bereken(person Iemand,int * Leeftijd,int Datum[])
{
	// bereken de leeftijd van een persoon
	// Ingevoerde datum - geboorte datum = leeftijd

	// dd - dd
	int days = Datum[0] - Iemand.Geboortedatum.Dag;

	// mm - mm
	int months = Datum[1] - Iemand.Geboortedatum.Maand;
	if (days <= 0)
	{
		months -= 1;
	}

	// yyyy - yyyy
	*Leeftijd = Datum[2] - Iemand.Geboortedatum.Jaar;
	if (months < 0) 
	{
		*Leeftijd -= 1;
	}
}


void Printen(int Keuze, person * PersDATA,int Teller, int Datum[], int LeeftijdIndex)
{
	char NaamGemeente[StrLength];
	int Leeftijd;
	int Count = 0;
	int Found = 0;
	
	switch (Keuze)
	{
	case 1: 
		// Bij keuze "1" zoeken we en printen we de jongste persoon zijn naam af waarbij zijn leeftijd in decimale, hexadecimale en binaire waarde wordt geprint
		COLOR_ON(2);
		Bereken(*(PersDATA + LeeftijdIndex), &Leeftijd, Datum);
		printf("\n\n%s\nLeeftijd: DEC: %d\tHEX: %x\tBIN: ",(PersDATA + LeeftijdIndex)->Naam,Leeftijd,Leeftijd); // decimaal formaat (%d) hexadecimaal formaat (%x)
		
		for (int i = 1 << 15 ;i > 0;i >>= 1) // Print alleen de 16 eerste bits
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

			if (Count == 4) // Om de 4 geprinte bits gaan we een spatie plaatsen zodanig het proper the houden
			{
				printf(" ");
				Count = 0;
			}
		}
		COLOR_OFF();
		break;
	case 2: 
		// Bij keuze "2" zoeken we naar elke persoon waarbij de gemeente gelijk is aan de ingevoerde gemeente en printen we hun namen en hun leeftijd
		printf("\n\nVan welke gemeente wil je de leeftijden kennen? => ");
		scanf("%s%*c", NaamGemeente);
		COLOR_ON(2);
		for (int i = 0; i < Teller; i++)
		{ 
			if (strcmp((PersDATA + i)->Gemeente,NaamGemeente) == 0)
			{
				Bereken(*(PersDATA + i), &Leeftijd, Datum);
				printf("\n%s\n%d\n",(PersDATA + i)->Naam,Leeftijd);
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
