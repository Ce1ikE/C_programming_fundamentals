#ifndef _PHONE_H
#define	 PHONE_H

#define FILENAME "phone.dat"
#define NLEN 25
#define PLEN 20
#define MENU_SIZE 5

typedef struct
{
	int ID;
	char name[NLEN];
	char phoneNr[PLEN];
	char StreetName[StrLength];
	int HouseNumber;
	int PostalCode;
	char TownName[StrLength];
} Phone;

char* menutext[] [2] = { {"a","add"},{"l","list"},{"s","search"},{"r","remove"},{"e","end"} };

#endif

