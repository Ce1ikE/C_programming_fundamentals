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
	struct node* next;

} Node;

/* Function declarations */

void showHelp(void);
void add(char*, Node**);
int removeElement(char*, Node**);
int isItem(char*, Node*);
int countItems(Node*);
void removeList(Node**);
void showList(Node*);
char* trim(char*);

int main(void)
{
	/* Exercice 18.1
	
	Assignment:
	Write a program that allows to build and adapt an alphabetically 
	ordered single-linked list with a command interpreter. Part of the code is 
	written below. Only the missing functions need to be programmed.

	Remark: the function trim is not absolutely needed for this exercise. It
	removes extra spaces at the beginning of an instruction or string.

	Missing functions => 
	
	int countItems(Node*);
	int isItem(char*, Node*);
	void removeElement(char*, Node**);
	void add(char*, Node**);
	
	*/



	char instruction[STRLEN];
	Node* head = NULL;
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
		case 'i': 
				add(trim(pi + 1), &head);
				break;
		case 'd': 	;
				if (removeElement(trim(pi + 1), &head))
					printf("\"%s\" is removed from the list.\n", trim(pi + 1));
				else
					printf("\"%s\" is NOT in the list.\n", trim(pi + 1));
				break;
		case 'f': 
				if (isItem(trim(pi + 1), head))
					printf("\"%s\" is in the list.\n",trim(pi + 1));
				else
					printf("\"%s\" is NOT in the list.\n",trim(pi + 1));
				break;
		case 'l': 
				showList(head);
				break;
		case 'n': 
				printf(" Number of list items: %d\n",countItems(head));
				break;
		case 'r': 
				removeList(&head);
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
	removeList(&head);
	return 0;
}

/* Function definitions */

void showHelp(void)
{
	printf("i <string> : inserts the element in <string> alphabetically into the list\n");
	printf("d <string> : removes the element in <string> from the list\n");
	printf("f <string> : searches the list and returns if the string is in the list or not.\n");
	printf("l : shows the full list\n");
	printf("n : returns the number of items in the list\n");
	printf("r : removes the full list\n");
	printf("h : shows the help menu (this list).\n");
	printf("q : end of the program (first remove the list)\n");
}

void add(char* s, Node** b)
{
	printf("This function inserts \"%s\" (alphabetically) into the list\n", s);
	
	/* 
	In the function "add" we need to do a few things in order to correctly insert a new struct of the type "Node":

	1) Create new available space for our new struct and place the name into it => use functions "malloc" and "strcpy"
	2) Check if our list is empty or not (First node) by checking if our head pointer(*b) is equal to NULL or not => use a "if" statement
	3) If it is not our first "Node" we need to check if the new node needs to become the new head "Node" or if it needs to be placed further down the list => use a "if" statement
	4) If the new "Node" needs to be placed further down the list we must go through the list and adjust the pointers accordingly
	
	*/ 

	// 1)
	Node* New = (Node*)malloc(sizeof(Node));
	New->next = NULL; // To make sure it doesn't point to a new structure // little bit like making sure the circuit is closed off
	strcpy(New->name, s);

	// 2)
	if (*b == NULL) // Check the first element
	{
		*b = New;
	}
	else
	{
		// 3)
		if (strcmp(s,(*b)->name) < 0)
		{
			/*
			b => c => NULL
			a => NULL

			after 

			NULL of 'a' becomes 'b'
			and 

			a => b => c => NULL
			*/
			New->next = *b;
			*b = New;
		}
		else
		{
			// 4)

			Node* prev = *b;
			Node* temp = prev;

			while (temp != NULL && strcmp(s,temp->name) >= 0)
			{
				prev = temp;
				temp = temp->next;
			}
			New->next = temp;
			prev->next = New;
		}		
	}
}

int removeElement(char* s, Node** b)
{
	printf("This function removes \"%s\" from the list\n", s);

	int Found = 0;

	if (*b == NULL && strcmp(s,(*b)->name) == 0) // Check first element
	{
		Found == 1;
		free(*b);
	}
	else
	{
		Node* Prev = *b;
		Node* temp = Prev;
		
		while (temp->next != NULL && strcmp(s,temp->name) != 0) // Loop through the DDS until you found the name
		{
			Prev = temp;
			temp = temp->next;
		}
		/* 
		
		temp "Node" needs to be removed
		Check for different cases:
	
		1) "temp" is in the middle of the chain which means we need "Prev->next" to point to "temp->next"
		2) "temp" is the last "Node" of the chain which means "Prev->next" needs to be NULL

		*/
		if (temp->next != NULL && strcmp(s, temp->name) == 0)
		{
			Found = 1;
			Prev->next = temp->next; // Readjust the "Node" accordingly // little bit like rewiring
			free(temp);
		}

		if (temp->next == NULL && strcmp(s, temp->name) == 0)
		{
			Found = 1;
			Prev->next = NULL;
			free(temp);
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

void removeList(Node** b)
{
	Node* p = *b;
	while (p != NULL)
	{
		*b = p->next;
		free(p);
		p = *b;
	}
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
			
			printf("%2d  %s ",Counter++,b->name);
			b = b->next;
		}
	}
	printf("\n\n");
}

char* trim(char* s)
{
	while (*s == ' ') s++;
	return s;
}