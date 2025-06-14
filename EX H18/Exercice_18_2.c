/*

	C Fundamentals: Labo YT5883
	Exercices from "Cprogrammingfundamentals2020"

	Name: Celik
	Firstname:Ennis
	Class: 1EICT

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // needed for strcpy() and strcmp()
#include <stdlib.h> // needed for malloc(), free()
#define STRLEN 64


typedef struct node
{
	char name[STRLEN];
	struct node * previous;
	struct node* next;

} Node;

/*	Schema

		HEADp => Ap => Bp => Cp => Dp => ... => TAILp => NULL
NULL <= HEADp <= Ap <= Bp <= Cp <= Dp <= ... <= TAILp

*/

/* Function declarations */

void showHelp(void);
void add(char*, Node**,Node**);
int removeElement(char*, Node**,Node**);
int isItem(char*, Node*);
int countItems(Node*);
void removeList(Node**,Node**);
void showList(Node*);
void showListReverse(Node*);
char* trim(char*);

int main(void)
{
	/* Exercice 18.2

	Assignment:
	Modify exercise 18.1 by using a double-linked list. The Node 
	structure is defined as follows:

	typedef struct node
	{
		char name[64];
		struct node * previous;
		struct node * next;
	} Node;

	Use a head pointer and an end pointer that points to the last element of 
	the list. Add also a function that prints the list in reverse order.

	List of everything that needs to be modified =>

	1) The structure "node" needs a other pointer "previous" that points to the previous structure
	2) The function "add" needs to be modified such that the 'rewiring' is correct. => readjust both pointers accordingly 
	3) The function "removeElement" needs to be modified such that the 'rewiring' is correct. => readjust both pointers accordingly 
	4) The function "removeList" needs to be modified such that the list is removed completely in both ways 
	5) The function "showListReverse" needs to be added
	6) The function "main" needs to be modified to fit the new added function and modified functions
	7) The function "showHelp" needs to be modified to fit the new added option

	*/

	char instruction[STRLEN];
	Node* head = NULL;
	Node* tail = NULL;
	char* pi; // pi = pointer to the instruction
	printf("Test program for a single-linked list.\n");
	printf("\nEnter an instruction (h = help)\n");
	printf("\n> ");
	memset(instruction, '\0', STRLEN);
	gets(instruction);
	pi = trim(instruction);
	while (*pi != 'q')
	{
		switch (*pi)
		{
		case 'a':
			add(trim(pi + 1), &head,&tail);
			break;
		case 'd':;
			if (removeElement(trim(pi + 1), &head,&tail))
				printf("\"%s\" is removed from the list.\n", trim(pi + 1));
			else
				printf("\"%s\" is NOT in the list.\n", trim(pi + 1));
			break;
		case 'f':
			if (isItem(trim(pi + 1), head))
				printf("\"%s\" is in the list.\n", trim(pi + 1));
			else
				printf("\"%s\" is NOT in the list.\n", trim(pi + 1));
			break;
		case 'l':
			showList(head);
			break;
		case 'i':
			showListReverse(tail);
			break;
		case 'n':
			printf(" Number of list items: %d\n", countItems(head));
			break;
		case 'r':
			removeList(&head,&tail);
			break;
		case 'h':
			showHelp();
		case 'q':
			break;
		default:
			printf(" Unknown instruction (h = help)\n");
		}
		printf("\n> ");
		memset(instruction, '\0', STRLEN);
		gets(instruction);
		pi = trim(instruction);
	}
	removeList(&head,&tail);
	return 0;
}

/* Function definitions */

void showHelp(void)
{
	printf("a <string> : inserts the element in <string> alphabetically into the list\n");
	printf("d <string> : removes the element in <string> from the list\n");
	printf("f <string> : searches the list and returns if the string is in the list or not.\n");
	printf("l : shows the full list\n");
	printf("i : shows the full list in reverse\n");
	printf("n : returns the number of items in the list\n");
	printf("r : removes the full list\n");
	printf("h : shows the help menu (this list).\n");
	printf("q : end of the program (first remove the list)\n");
}

void add(char* s, Node** b,Node** e)
{
	printf("This function inserts \"%s\" (alphabetically) into the list\n", s);

	Node* New = (Node*)malloc(sizeof(Node));
	New->next = NULL;
	New->previous = NULL;
	strcpy(New->name, s);


	if (*b == NULL) // Check if first element is NULL
	{
		*b = New;
		*e = New;
	}
	else
	{
		if (strcmp(s, (*b)->name) < 0)
		{
			/* Schema
			
			        b => c => NULL
			NULL <= b <= c

				    a => NULL
			NULL <= a

			after

					a => b => c => NULL
			NULL <= a <= b <= c 

			*/
			(*b)->previous = New;
			New->next = *b;
			*b = New;
		}
		else
		{

			Node* prev = *b;
			Node* temp = prev;

			while (temp != NULL && strcmp(s, temp->name) >= 0)
			{
				prev = temp;
				temp = temp->next;
			}

			if (temp == NULL)
			{
				*e = New;
			}

			if (temp != NULL)
			{
				temp->previous = New;
			}

			New->next = temp;
			prev->next = New;
			New->previous = prev;
		}
	}
}

int removeElement(char* s, Node** b,Node** e)
{
	printf("This function removes \"%s\" from the list\n", s);

	int Found = 0;

	if (*b == NULL && strcmp(s, (*b)->name) == 0) // Check if first element is NULL
	{
		Found == 1;
		free(*b);
		free(*e);
	}
	else
	{

		Node* Prev = *b;
		Node* temp = Prev;

		if (strcmp(s, (*b)->name) == 0)
		{
			*b = (*b)->next;
			(*b)->previous = NULL;
			free(Prev);
		}
		else
		{

			while (temp->next != NULL && strcmp(s, temp->name) != 0) // Loop through the DDS until you find the name
			{
				Prev = temp;
				temp = temp->next;
			}
			/*

			temp "Node" needs to be removed
			Check for different cases:

			1) "temp" is in the middle of the chain which means we need "Prev->next" to point to "temp->next" and "(temp->next)->previous" needs to point to "Prev"
			2) "temp" is the last "Node" of the chain which means "Prev->next" needs to be NULL and the tail needs to become "Prev"

			*/
			if (temp->next != NULL && strcmp(s, temp->name) == 0)
			{
				Found = 1;
				/* Schema

				1)

				... => Prev => temp => ...
				... <= Prev <= temp <= ...

				after

				... => Prev => ...
				... <= Prev <= ...

				*/

				temp = temp->next;
				temp->previous = Prev;
				temp = temp->previous; // temp == prev now
				temp = temp->next;
				Prev->next = temp->next; // Readjust the "Node" accordingly // little bit like rewiring

				free(temp);
			}

			if (temp->next == NULL && strcmp(s, temp->name) == 0)
			{
				Found = 1;
				/* Schema

				2)

				... => Prev => temp => NULL
				... <= Prev <= temp

				after

				... => Prev => NULL
				... <= Prev

				*/
				Prev->next = NULL;
				free(temp);
				*e = Prev;
			}
		}
		
	}


	return Found;
}

int isItem(char* s, Node* b)
{
	printf("This function searches \"%s\" in the list\n", s);

	int Count = 0;
	int Found = 0;


	Node* temp = b;

	while ((temp)->next != NULL)
	{
		if (strcmp((temp)->name, s) == 0)
		{
			Found = 1;
		}
		temp = temp->next;
		Count++; // Something we might use later on
	}

	return Found;
}

int countItems(Node* b)
{
	int Count;
	if (b == NULL)
	{
		Count = 0;
	}
	else
	{
		Count = 1;
		Node* Temp = b; // b is the head pointer of the DDS(Dynamic data structure)
		printf("This function returns the number of items in the list\n");
		while ((Temp)->next != NULL)
		{
			Count++;
			Temp = Temp->next;
		}
	}


	return Count;
}

void removeList(Node** b,Node** e)
{
	Node* p = *b;
	while (p != NULL)
	{
		*b = p->next;
		free(p);
		p = *b;
	}
	*e = NULL;
	
}

void showList(Node* b)
{
	int Counter = 0;
	if (b == NULL)
	{
		printf("The list is EMPTY\n");
	}
	else
	{
		printf("The list:\n");
		while (b != NULL)
		{

			printf("%2d  %s ", Counter++, b->name);
			b = b->next;
		}
	}
	printf("\n\n");
}

void showListReverse(Node* e)
{
	int Counter = 0;
	if (e == NULL)
	{
		printf("The list is EMPTY\n");
	}
	else
	{
		printf("The list:\n");
		while (e != NULL)
		{

			printf("%2d  %s ", Counter++, e->name);
			e = e->previous;
		}
	}
	printf("\n\n");
}

char* trim(char* s)
{
	while (*s == ' ') s++;
	return s;
}