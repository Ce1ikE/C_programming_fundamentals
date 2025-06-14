/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#include "MyHeaderEC.h"
#define MaxPeople 2

/* Function declarations */

void ReadNames(char[][StrLength]);
void PrintToFile(FILE*,char[][StrLength]);
void PrintData(FILE*);

int main(void)
{
	/* Exercice 15.9

	Assignment:

	Now, we want to add the first name of all people in the file. Ask the 
	first names and save them together with the already existing data in a 
	new file. Print the list of data:

	*/

	TITLE_EX(15.9,216);

	Hello(2);

	char NamesToEnter[MaxPeople][StrLength],Filename[StrLength];
	FILE* fd;

	printf("\nTo which file do you want to write the names? => ");
	scanf("%s%*c", Filename);
	fd = fopen(Filename,"rb+");
	CheckFile(fd, Filename);

	ReadNames(NamesToEnter);

	PrintToFile(fd, NamesToEnter);
	
	Print_Line(100, '=');

	PrintData(fd);

	Bye_Message(6,3,7);

	fclose(fd);

	return 0;
}

/* Function definitions */

void ReadNames(char N[][StrLength])
{
	for (int i = 0; i < MaxPeople; i++)
	{
		printf("\nEnter a name please: ");
		gets(N[i]);
	}
}

void PrintToFile(FILE * fd, char Names[][StrLength])
{
	employee emp;
	int i = 0;
	while (fread(&emp,sizeof(employee),1,fd) > 0)
	{
		fseek(fd, i * sizeof(employee), SEEK_SET); // set the cursor back to the origin position in the file + with a offset of 'i' times the byte size of one employee's data
		strcpy(emp.Pers.firstname,Names[i]);
		fwrite(&emp, sizeof(employee), 1, fd); // Writing the data changed (firstname) in "emp" to the same place in the file which results in overwriting the current data in the file
		i++;
		fseek(fd, i * sizeof(employee), SEEK_SET);
	}
}

void PrintData(FILE * fd)
{
	employee emp;
	fseek(fd, 0, SEEK_SET); // set the cursor back to the origin position in the file

	printf("\n\nFollowing data was entered: \n");
	while (fread(&emp,sizeof(employee),1,fd) > 0)
	{
		COLOR_ON(2);
		printf("\n\tName: %s\n\tFirst name: %s\n\tAge: %d\n\tSalary: %d\n\n",emp.Pers.name,emp.Pers.firstname,emp.Pers.Age,emp.Salary);
		COLOR_OFF();
	}


}