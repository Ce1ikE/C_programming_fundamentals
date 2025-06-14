/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

/* Headers */

#include "MyHeaderEC.h"

/* Function declarations */

void Get_NbrOfP_M(int*, int*);
void CreateList(int, PeopleOJ**);
void CalculateOrder(int,int, PeopleOJ**);

int main(void)
{
	/* Exercice 18.8

	Assignment:

	The problem of Josephus.
	Suppose N people decide to commit suicide together. To do so, they 
	stand in a circle and every M people, 1 person is eliminated. What is the 
	order of elimination?

	*/

	TITLE_EX(18.8,243);

	Hello(2);

	PeopleOJ* AnyPerson = (PeopleOJ*)malloc(sizeof(PeopleOJ)); // PeopleOJ == people of Josephus
	AnyPerson->Next = NULL; // Making sure it doesn't point anywhere we don't want to
	int M, NumberOfPeople;

	Get_NbrOfP_M(&NumberOfPeople,&M);

	CreateList(NumberOfPeople, &AnyPerson);

	if (NumberOfPeople != 0)
	{
		printf("\n\nThe order of elimination is: \n\n");
		COLOR_ON(2);
		CalculateOrder(NumberOfPeople,M,&AnyPerson);
		COLOR_OFF();
	}


	Bye_Message(6,3,7);


	return 0;
}

/* Function definitions */

void Get_NbrOfP_M(int * N, int * M)
{
	printf("\nEnter the number of people in the circle: ");
	scanf("%d%*c", N);

	while (*N <= 0)
	{
		printf("\n\n\tINVALID INPUT number of people must be positive\n\nEnter the number of people in the circle: ");
		scanf("%d%*c", N);
	}

	printf("\nEnter the number M: ");
	scanf("%d%*c", M);

	while (*M < 1)
	{
		printf("\n\n\tINVALID INPUT number M must be positive\n\nEnter the number M: ");
		scanf("%d%*c", M);
	}
}

void CreateList(int Nbr, PeopleOJ** Head)
{

	/*	Schema
	
	1) Create single-linked circular list but keep the head and tail pointer

	Head => Ap => Bp => Cp => ... => Tail

	Note: While creating the list we will atribute a number to each node.
	2) Link the tail pointer to the head pointer

	Tail->next = Head;
	
	*/

	(*Head)->Next = NULL;
	(*Head)->Number = 1; // Number 1 will always be attributed to the head pointer 
	PeopleOJ* PrevPointer = *Head, * NewPointer;

	for (int i = 1; i < Nbr; i++) // Create the circular list
	{	
		NewPointer = (PeopleOJ*)malloc(sizeof(PeopleOJ)); // Alocate memory for the new pointer (structure)
		NewPointer->Number = i + 1; // Attribute a new number to the new structure // The Numbers that follow will always be incremented by 1
		NewPointer->Next = NULL; // Set the address of the new pointer to make sure it doens't point to anywhere we don't want to
		PrevPointer->Next = NewPointer; // Link the previous pointer to the new pointer
		PrevPointer = NewPointer; // Advance the previous structure to the new structure 
		
	}
	PrevPointer->Next = *Head; // Close the circle with reference pointer "Head"
	printf("\n\nThe circle contains: \n");

	for (int i = 0; i < Nbr; i++)
	{
		COLOR_ON(4);
		printf("%d ", (*Head)->Number);
		COLOR_OFF();
		*Head = (*Head)->Next;
	}

}

void CalculateOrder(int Nbr,int M, PeopleOJ** AnyPerson)
{
	PeopleOJ * Help, * Prev = AnyPerson;

	for(int t = 0;t < Nbr ;t++)
	{

		for (int i = 0; i < M - 1; i++)
		{
			Prev = *AnyPerson;
			*AnyPerson = (*AnyPerson)->Next;
		}
		printf("%2d ", (*AnyPerson)->Number);
		Help = *AnyPerson;
		*AnyPerson = (*AnyPerson)->Next;
		Prev->Next = *AnyPerson;
		free(Help);
	}
}