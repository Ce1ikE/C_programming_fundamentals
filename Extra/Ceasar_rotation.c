#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char Rotate(char, int);
int main(void)
{
	char Choice;
	printf("\nShift left(l) or shift right(r): "); scanf("%c%*c", &Choice);
	while (Choice != 'l' && Choice != 'r') {
		printf("\nShift left(l) or shift right(r): "); scanf("%c%*c", &Choice);
	}
	int Shift; char Word[32];
	printf("\nShift : "); scanf("%d%*c", &Shift);
	printf("\nWord : "); scanf("%s%*c", Word);
	switch (Choice)
	{
	case 'l':
		printf("\n\nResult: ");
		for (int i = 0; i < strlen(Word); i++) {
			printf("%c ", Rotate(Word[i], -Shift));
		}
		break;
	case 'r':
		printf("\n\nResult: ");
		for (int i = 0; i < strlen(Word); i++) {
			printf("%c ", Rotate(Word[i], Shift));
		}
		break;
	default:
		break;
	}


	printf("\n\n");
	return 0;
}

char Rotate(char Letter, int shift)
{
	if ('a' <= Letter && Letter <= 'z')
	{
		if (Letter + shift > 'z')
		{			
			return Letter += (shift + 'a' - (1 + 'z'));
		}
		else
		{
			return Letter += shift;
		}
	}
}
