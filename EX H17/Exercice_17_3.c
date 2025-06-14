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

void ReadDataNames(customer*,int);
void ReadDataINFO(customerINFO*, int);
void PrintData(customer*, customerINFO*, int);


int main(int argc,char * argv[])
{
	/* Exercice 17.3

	Assignment:

	Write a program with name “clients” that:

	- reads customer numbers and corresponding customer names and 
	stores them in an array of structs.

	- reads customer numbers and corresponding customer addresses 
	and stores them in a second array of structs. Use a different struct.

	- can be called from the command line with the size of the arrays as
	argument (ex: clients 3)

	- uses arrays of the correct size (use malloc)

	- prints the customer data

	use a separate function to read the data and one to print the data

	*/

	Control_Arg(argc, 2, 2); // Check of enough or too much arguments are given to the function

	int NbrOfClients = atoi(argv[1]); // "NbrOfClients" == number of clients 

	while (NbrOfClients <= 0) // We can't start the program if the number of clients is zero or negative
	{
		COLOR_ON(1);
		printf("\n\n\tERROR ARGUMENT IS TOO LOW");
		COLOR_OFF();
		char Answer;
		printf("\n\n\tContinue?(Yes = y No = n) => ");
		scanf("%c%*c", &Answer);
		switch (Answer)
		{
		case 'y':
			printf("\n\n\tEnter a other argument number: ");
			scanf("%d%*c", &NbrOfClients);
			break;
		case 'n':
			exit(-1);
			break;
		default:
			break;
		}
	}

	customer * MemPtoC = (customer*)malloc(NbrOfClients * sizeof(customer)); // "MemPtoC" == memory pointer to customers 
	customerINFO * MemPtoINFO = (customerINFO*)malloc(NbrOfClients * sizeof(customerINFO)); // "MemPtoINFO" == memory pointer to customers info

	if (MemPtoC == NULL || MemPtoINFO == NULL) // Check if "malloc" has failed or not
	{
		COLOR_ON(1);
		printf("\n\n\tMEMORY ALLOCATION FAILED");
		COLOR_OFF();
		exit(-1);
	}

	TITLE_EX(17.3,227);

	Hello(2);

	ReadDataNames(MemPtoC,NbrOfClients);
	ReadDataINFO(MemPtoINFO,NbrOfClients);
	PrintData(MemPtoC,MemPtoINFO,NbrOfClients);

	Bye_Message(6,3,7);

	free(MemPtoC);
	free(MemPtoINFO);

	return 0;
}

/* Function definitions */


void ReadDataNames(customer * AllCustomers,int Nbr)
{
	printf("\n\nEnter a list of %d customer numbers and corresponding names: \n", Nbr);

	for (int i = 0; i < Nbr; i++)
	{

		scanf("%s%*c",((AllCustomers + i)->CustomerNr));
		scanf("%s%*c", ((AllCustomers + i)->Firstname));
		scanf("%s%*c", ((AllCustomers + i)->Name));
	}

}

void ReadDataINFO(customerINFO * AllCustomersINFO, int Nbr)
{
	printf("\n\nEnter a list of %d customer numbers and corresponding Addresses(Identical customer ID must be entered): \n",Nbr);

	for (int i = 0; i < Nbr; i++)
	{
		scanf("%s%*c", ((AllCustomersINFO + i )->CustomerNr));
		scanf("%s%*c", ((AllCustomersINFO + i )->CityAddress));
	}
}

void PrintData(customer * PtoNames, customerINFO * PtoINFO,int Nbr)
{
	printf("\n\n");
	Print_Line(100,'=');
	printf("\n\nAll customers data:\n");
	COLOR_ON(2);
	for (int i = 0; i < Nbr; i++)
	{
		for (int t = 0; t < Nbr; t++)
		{
			if (strcmp(((PtoNames + i)->CustomerNr),((PtoINFO + t)->CustomerNr)) == 0) // Check for the right customerID
			{
				printf("\n%4s   %12s %12s   %12s",((PtoNames + i)->CustomerNr), ((PtoNames + i)->Firstname), ((PtoNames + i)->Name), ((PtoINFO + t)->CityAddress));
				
				/* ATTENTION
				
				If a pointer is allocated to a certain address we can add to that pointer a certain value in order to reach a new address in memory.
				If in memory we assign a value 'x' to the address pointer 'p' of type 'int' in order to reach a new value we perform this operation:  p + 1 

				int * p; 
				*p = x;
				*(p + 1) = y;
				*(p + 2) = ...;
				
				General formula => *(p + n) = m;

				* == dereferencing operator | p == Initial address | n == the address we want to access | m == the data we access |

				And so on but with structures we can have , arrays(int[]) , integers(int) , string(char[]) , characters(char) , etc...
				so our next data is located at p + 1 but the specific data we try to access say a integer is not located p + 1 

				Therefore we can use this syntax: (*p).DataName = m;

				But because this gets quite tedious you can use the -> operator.

				(*(p + n)).DN = m; <=> (p + n)->DN = m;

				*/
			}
		}
	}
	COLOR_OFF();
}

