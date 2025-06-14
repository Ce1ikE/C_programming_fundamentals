/*

			+---------+----------+--------+--------+
			|	Name  |	Firstname|  Game		   |
			+---------+----------+--------+--------+
			|  Celik  | Ennis    |  Deadly pointer |
			+---------+----------+--------+--------+

*/
/*
	The objective of this game is to guess the values of 
	*p all the way through *(p + 10) and such for each level.
	
	Additionally you need to keep track of the adres of the pointer 'm'
	as a bonus objective.

	As third objective you must discover the sum of the final values in level 7

	Good luck!
	
*/

#include <stdio.h>
#include <stdlib.h>

int* Honderd(int*);
void VijfHonderd(int*);
int* Duizend(int*);
void Print_Current_Result(int*,int*,int*);
void Print_Sum_Level7(int*);

int main(void)
{
	int Counter = 1;
	

	/* Start */
	int * m = (int*)malloc(11 * sizeof(int));
	int * p = m;
	int Vijf = 3;
	int Drie = 6;
	int Zes = 4;
	int Vier = 2;

	/* Start of simple */
	/* Level 1 */

	*m = 4;
	*(m) = Vier;
	*(m + 1) = 1;
	*(m + 2) = 2;
	*(m + 3) = 2;
	*(m + 4) = 4;
	*(m + 5) = 10;
	*(m + 6) = Zes;
	*(m + 7) = 10;
	*(m + 8) = Vijf;
	*(m + 9) = Vijf;
	*(m + 10) = 2*Vijf;

	//Print_Current_Result(p, &Counter, m); /* Uncomment to see the result of level 1 */// ===============================
	/* Let's make it a little bit more complicated */
	/* Level 2 */
	*(m + 3) = Drie;
	*(m + 6) = Vijf;
	*(m + Zes) = 6;
	*(m + Vier) = Vijf;
	m++;
	*(m + Vier) = Vijf;

	//Print_Current_Result(p, &Counter, m); /* Uncomment to see the result of level 2 */// ===============================
	/* Next level please ... */
	/* Level 3 */
	
	m += Zes;
	m = Honderd(m);
	*m += Zes;
	VijfHonderd(m);
	*m -= Vier;
	m++;
	m -= *(m + 2);
	*m = *(m + 2);
	
	//Print_Current_Result(p, &Counter, m); /* Uncomment to see the result of level 3 */// ===============================
	/* And next level ... */
	/* Level 4 */

	m[-2] = Vijf*Vier;
	m[1] = 4;
	m[2] = 5;
	++m;
	m--;
	*(m + (Vier * m[-1])) /= Vier;
	m += *(m + 1);
	*(m + 1) += Drie;
	m[2] = 10;
	m[-(*m)] = Vijf;
	
	//Print_Current_Result(p, &Counter, m); /* Uncomment to see the result of level 4 */// ===============================
	/* And next level ... */
	/* Level 5 */

	m -= m[3];
	*(m + (m[-1] * Zes) + (m[3] - m[5] * 2)) += *(m + Vijf * Drie - m[7] * 2);
	m = m++ + (*m);
	m = Duizend(m);
	VijfHonderd(m);
	m[1] += 5;

	//Print_Current_Result(p, &Counter, m); /* Uncomment to see the result of level 5 */// ===============================
	/* Almost there ... */
	/* Level 6 */

	m[-(*(m - 1) - m[0])] = 0;
	m = m-- + 0 - (*(m - 3));
	VijfHonderd(m);
	m = Honderd(m);
	m[m[Zes] - m[Vijf]] = 0;
	*(m + (*m * 3)) /= Zes;

	//Print_Current_Result(p, &Counter, m); /* Uncomment to see the result of level 6 */// ===============================
	/* BOSS level */
	/* Level 7 */

	m = m + ((*(m - (m[6] - m[8]))) - ((*m) * (m[1] * (m[2] + 1))));
	*m *= (m[-3] + m[(*m - m[-2]) - (*(m - 4))]);
	*(m - m[-Zes] - (*(m - m[-Zes]))) *= Drie * Vier * Vijf * Zes;
	*(m - 10) *= *m;

	//Print_Current_Result(p, &Counter, m); /* Uncomment to see the final result */// ===============================
	printf("\n\n");
	//Print_Sum_Level7(p); /* Uncomment to see the final sum */
	return 0;
}

int* Honderd(int * m)
{
	*m = 1;
	*(m + *m) = 2;
	return m;
}

void VijfHonderd(int * q)
{
	*q += 3;
	*(q - (*q - 5)) = 2;
	q += 2; /* Sneaky ... */
}

int* Duizend(int * m)
{
	*m += *m;
	*(m + 2) += *m;
	m -= (*m / 6) ;

	return m;
}

void Print_Current_Result(int * p ,int * Counter ,int * m) 
{	
	printf("\n\nLevel %d: \n-------\n",(*Counter)++);
	for (int i = 0; i < 11; i++)
	{
		if ((p+i) == m)
		{
			printf("\033[31m");
			printf("(%d)=%2d ", i, *(p + i));
			printf("\033[m");
		}
		else
		{
			printf("\033[32m");
			printf("(%d)=%2d ", i, *(p + i));
			printf("\033[m");
		}		
	}
}

void Print_Sum_Level7(int * p)
{
	int SUM = 0;

	for (int i = 0; i < 11; i++)
	{
		SUM += *(p + i);
	}

	printf("=> The final sum is equal to : %d\n\n", SUM);
}