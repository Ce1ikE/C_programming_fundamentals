/*

	 "MyFunctionsEC.c" by C.E.

	Attachments => "MyHeaderEC.h"

	TM©2023
	By accessing or using any copyrighted materials owned by C.E., you acknowledge and agree to abide by the terms of this Copyright Disclaimer.
	If you do not agree with any of these terms, please refrain from accessing or using the copyrighted materials.

*///=============================================================================================================================================================================================================================

#include "MyHeaderEC.h"


/* My own in build functions */

// Prints a 3D hello message to the terminal
void Hello(int c)
{	
	if (c < 0 || c > 7)
	{
		c = 7;
	}

	printf("\033[3%dm\n\n",c);

	printf("\n\t      \x5F\x5F\x5F\x5F          \x5F\x5F\x5F\x5F           \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F        \x5F\x5F\x5F\x5F                         ");
	printf("\n\t     \x2F   \x2F\x5C        \x2F   \x2F\x5C         \x2F   \x2F\x5C      \x2F   \x2F\x5C      \x2F   \x2F\x5C                                       ");
	printf("\n\t    \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x3A\x5C       \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x3A\x5C                 ");
	printf("\n\t   \x2F   \x2F\x3A\x2F       \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F\x5C\x3A\x5C     ");
	printf("\n\t  \x2F   \x2F\x3A\x3A\x5C \x5F\x5F\x5F  \x2F   \x2F\x3A\x3A\x5C \x5C\x3A\x5C   \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F     \x2F   \x2F\x3A\x2F  \x5C\x3A\x5C    ");
	printf("\n\t \x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C  \x2F\x5C\x2F\x5F\x5F\x5F\x2F\x3A\x2F\x5C\x3A\x5C \x5C\x3A\x5C \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F     \x2F\x5F\x5F\x5F\x2F\x3A\x2F \x5C\x5F\x5F\x5C\x3A\x5C    ");
	printf("\n\t \x5C\x5F\x5F\x5F\x5C\x2F  \x5C\x3A\x5C\x2F\x3A\x2F\x5C   \x5C\x3A\x5C \x5C\x3A\x5C\x5F\x5C\x2F \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C \x2F  \x2F\x3A\x2F  ");
	printf("\n\t      \x5C\x5F\x5F\x5F\x5C\x3A\x3A\x2F  \x5C   \x5C\x3A\x5C \x5C\x3A\x5C    \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C  \x2F\x3A\x2F     ");
	printf("\n\t      \x2F   \x2F\x3A\x2F    \x5C   \x5C\x3A\x5C\x5F\x5C\x2F     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C\x2F\x3A\x2F       ");
	printf("\n\t     \x2F\x5F\x5F\x5F\x2F\x3A\x2F      \x5C   \x5C\x3A\x5C        \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x5C     \x5C   \x5C\x3A\x3A\x2F                   ");
	printf("\n\t     \x5C\x5F\x5F\x5F\x5C\x2F        \x5C\x5F\x5F\x5F\x5C\x2F         \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F      \x5C\x5F\x5F\x5F\x5C\x2F   ");

	printf("\033[m\n\n\n");


}

// Prints a 2D "Bye" message to the terminal
void Bye_Message(int c,int b,int s)
{
	if (b != 3)
	{
		b = 7;
	}

	if (c < 0 || c > 7)
	{
		c = 2;
	}

	if (s != 7)
	{
		s = 7;
	}
		printf("\033[%d;%d%dm", s, b, c);
		printf("\n\n");

		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDC\xDB\xDB\xDC\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xB2\xDC\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xB2\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDF\xB2\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDC\xB2\xDF\xDF\xDF\xB2\xDC\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDF\xDB\xDF\xB2\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");
		printf("\n\t\t\033[40m\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\033[40m");

		printf("\n\n\n");
		printf("\033[0m");

}

// Searches for maximum value in a array
int Max_Value(int N[],int SizeOfArray)
{
	int Max = N[0];
	for (int i = 0; i < SizeOfArray ; i++)
	{
		if (N[i] > Max)
		{
			Max = N[i];
		}
	}


	return Max;
}

// Prints the prime number up to N as limit or stores them into an array
void Prime_up_to(int N,char Mode,int arg,...)
{
	va_list Add_vars;// Calling in the additional parameters if arg = 2
	// va_list types are pointers to the list of arguments
	va_start(Add_vars,arg); // sets arg_ptr Add_vars to the first optional argument in the list of arguments that's passed to the function

	int LengthOfArray = va_arg(Add_vars, int);
	/*
	retrieves a value of any type from the location that's given by arg_ptr Add_vars, and increments arg_ptr Add_vars to point to the next argument in the list
	by using the size of type to determine where the next argument starts.
	
	ATTENTION
	The va_arg() function can retrieve arguments from the list any number of times within the function.
	The var_type argument must be one of int, long, decimal, double, struct, union, or pointer
	*/
	int* temp = va_arg(Add_vars, int*); // accesses the next variadic function argument
	int Start_new_line = 0, IsPrime,m = 0;
	for (int i = 1; i < N; i++) 
	{
		IsPrime = 1;
		for (int t = 2; t <= i / 2; t++)
		{
			if (i % t == 0)
				IsPrime = 0;
		}

		if (IsPrime == 1)
		{
			switch (Mode)
			{
			case 'p':
				printf("%4d ", i);
				Start_new_line++;

				if (Start_new_line == 10)
				{
					printf("\n");
					Start_new_line = 0;
				}
				break;
			case 'w':

				if (m < LengthOfArray) 
				{	
					temp[m] = i;
					m++; 
				}
				break;
			default:
				break;
			}
		}
	}

	va_end(Add_vars);

}

// Prints the Nth first prime numbers or stores them into an array
void Prime_Numbers_Generator(int N,char Mode,int arg,...)
{

	va_list Add_vars;
	va_start(Add_vars, arg);
	int* temp = va_arg(Add_vars, int*);
	int LengthOfArray = va_arg(Add_vars, int);

	int i = 2, Prime_Numbers = 0, Start_new_line = 0, IsNotPrime = 0;
	while (Prime_Numbers < N)
	{
		IsNotPrime = 0;
		for (int t = 2; t <= i / 2; t++)
		{
			if (i % t == 0)
			{
				IsNotPrime = 1;
			}
		}

		if (Mode == 'p' && IsNotPrime == 0)
		{
			printf("%4d ", i);
			Start_new_line++;	
			if (Start_new_line == 10)
			{
				printf("\n");
				Start_new_line = 0;
			}
		}

		if (Mode == 'w' && IsNotPrime == 0)
		{
			if (Prime_Numbers < LengthOfArray)
			{
				temp[Prime_Numbers] = i;
				Prime_Numbers++;
			}
		}
		i++;
	}
	va_end(Add_vars);
}

// Returns the Nth prime number
int Prime_N(int N)
{
	int i = 2, IsNotPrime = 0, Prime_Number = 0, counter = 0; // 0 and 1 are not prime so skip them

	while (counter != N)
	{
		for (int t = 2; t <= i / 2; t++) // for !each! number up till N we control if they are only divible by 1 and themselves
		{
			if (i % t == 0)
			{
				IsNotPrime = 1;
			}
		}

		if (IsNotPrime == 0)
		{
			Prime_Number = i;
			counter++;
		}

		IsNotPrime = 0;

		i++;
	}

	return Prime_Number;
}

// Filters the ASCII characters with decimal value [32 ; 64]U[91 ; 96]U[123 ; 126] within a string
void Symbol_Filter(char S[])
{
	int Length;
	int i;
	i = 0;
	do
	{
		Length = strlen(S);
		if (' ' <= S[i] && S[i] <= '@' || '[' <= S[i] && S[i] <= '`' || '{' <= S[i] && S[i] <= '~')
		{
			for (int t = 0; t + i < Length; t++)
			{
				S[i + t] = S[i + t + 1];
			}
		}
		else
		{
			i++;
		}
	} while (S[i] != '\0');


}

// Converts the ASCII characters with decimal value [65 ; 90] to ASCII characters with decimal value [97 ; 122]
void U2l_Converter(char S[])
{
	int Sentence_length;
	Sentence_length = strlen(S);
	for (int i = 0; i < Sentence_length; i++)
	{
		if ('A' <= S[i] && S[i] <= 'Z')
		{
			S[i] = S[i] + 32;
		}
	}
}

// Converts the ASCII characters with decimal value [97 ; 122] to ASCII characters with decimal value [65 ; 90]
void l2U_Converter(char S[])
{
	int Sentence_length;
	Sentence_length = strlen(S);
	for (int i = 0; i < Sentence_length; i++)
	{
		if ('a' <= S[i] && S[i] <= 'z')
		{
			S[i] = S[i] - 32;
		}
	}
}

// Converts the ASCII characters with decimal value [97 ; 122] to ASCII characters with decimal value [65 ; 90]
void Print_Line(int N, char S)
{
	for (int i = 0; i < N; i++)
	{
		printf("%c", S);
	}
}

// Sets text color send to terminal in one of the 8 available colors of the ANSI CSI
void Set_Color(int c)
{
	if (c < 0 || c > 7)
	{
		c = 7;
	}
	printf("\033[3%dm", c);
}

// Sets text font and color comptability is not garenteed on every terminal
void Set_font(int c)
{
	if (c < 0 || c > 7)
	{
		c = 7;
	}
	printf("\033[4%dm", c);
}

// Checks if a file exists or not and will take additional steps if the file does not exist 
void CheckFile(FILE* fs, char Filesource[])
{
	while (fs == NULL)
	{
		int Answer;
		printf("\n\n\t\033[31mERROR\033[m\nCouldn't find file : \"%s\"  \nContinue?(Yes = 1 , No = 0)\n=> ", Filesource);
		scanf("%d%*c", &Answer);

		while (Answer != 1 && Answer != 0)
		{
			printf("\n\n\t\033[31mERROR\033[m\nIncorrect Nr.\nChoose again.(Yes = 1 , No = 0)\n=>");
			scanf("%d%*c", &Answer);
		}

		switch (Answer)
		{
		case 1: // Answer == Yes

			printf("\nWhat do you want to do?\n\n\t1.Read from file\n\t2.Write to new file \n\t3.read and write from/to file\n\t(Choose a correct Nr.) => ");
			scanf("%d%*c", &Answer);

			while (Answer != 1 && Answer != 2 && Answer != 3)
			{
				printf("\n\n\t\033[31mERROR\033[m\nIncorrect Nr.\nChoose again.\n\n\t1.Read from file\n\t2.Write to new file \n\t3.read and write from/to file\n\t(Choose a correct Nr.) => ");
				scanf("%d%*c", &Answer);
			}

			switch (Answer)
			{
			case 1: // Read from file => File must exist
				printf("\n\nGive the name of the file please: ");
				scanf("%s%*c", Filesource);
				int Length = strlen(Filesource);
				char Extension[4];
				for (int i = 0; i < 4; i++)
				{
					Extension[i] = Filesource[Length - 4 + i];
				}
				if (strcmp(Extension, ".txt"))
				{
					fs = fopen(Filesource, "r");
				}
				if (strcmp(Extension, ".bin"))
				{
					fs = fopen(Filesource, "rb");
				}
				break;
			case 2: // Write to new file => New file is created or contents are erased
				printf("\n\nGive a name for the file please: ");
				scanf("%s%*c", Filesource);
				printf("\nWhat type does the file have to be?\n\n\t1.Binary\n\t2.Text\n\t(Choose a correct Nr.) => ");
				scanf("%d%*c",&Answer);
				while (Answer != 1 && Answer != 2)
				{
					printf("\n\n\t\033[31mERROR\033[m\nIncorrect Nr.\nChoose again.\n\n\t1.Binary\n\t2.Text\n\t(Choose a correct Nr.) => ");
					scanf("%d%*c", &Answer);
				}

				switch (Answer)
				{
				case 1:
					strcat(Filesource, ".bin");
					fs = fopen(Filesource, "wb");
					break;
				case 2:
					strcat(Filesource, ".txt");
					fs = fopen(Filesource, "w");
					break;
				default:
					break;
				}
				COLOR_ON(2);
				printf("\n\n\tNEW FILE CREATED");
				COLOR_OFF();
				break;
			case 3: // Read and write from/to file => File must exist
				printf("\n\nGive the name of the file please: ");
				scanf("%s%*c", Filesource);
				printf("\nOf what type is the file?\n\n\t1.Binary\n\t2.Text\n\t(Choose a correct Nr.) => ");
				scanf("%d%*c",&Answer);
				while (Answer != 1 && Answer != 2)
				{
					printf("\n\n\t\033[31mERROR\033[m\nIncorrect Nr.\nChoose again.\n\n\t1.Binary\n\t2.Text\n\t(Choose a correct Nr.) => ");
					scanf("%d%*c", &Answer);
				}
				switch (Answer)
				{
				case 1: fs = fopen(Filesource, "rb+"); break;
				case 2: fs = fopen(Filesource, "r+"); break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
		case 0: // Answer == No 
			exit(-1); 
			break;

		default: break;
		}

	}
}

// Prints the content of a existing file to the terminal
void PrintTXTFileContent(FILE* fs, char Filesource[])
{
	fs = fopen(Filesource, "r");
	printf("\n\nOUTPUT from file \"%s\": \n", Filesource);
	char line[STR_BUFFER];
	while (fgets(line, STR_BUFFER, fs) != NULL)
	{
		printf("%s", line);
	}

	fclose(fs);
}

// Prints "Merry christmas and a happy new year"
void PrintHappyHolidays(void)
{
	// Merry
	printf("\n\t\033[36m\xC9\xCB\xBB\xC9\xBB\xCB\xBB\xCB\xBB\xBB\xC9\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\t\033[36m\xBA\xBA\xBA\xCC\x20\xBA\xB9\xBA\xB9\xC8\xB9\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\t\033[36m\xBC\xCA\xC8\xC8\xBC\xCA\xC8\xCA\xC8\xC8\xBC\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	// Christmas
	printf("\n\t\033[35m\xC9\xBB\xBB\xC9\xCB\xBB\xCB\xC9\xBB\xC9\xCB\xBB\xC9\xCB\xBB\xC9\xBB\xC9\xBB\033[m ");
	printf("\n\t\033[35m\xBA\x20\xCC\xB9\xBA\xB9\xBA\xC8\xBB\x20\xBA\x20\xBA\xBA\xBA\xCC\xB9\xC8\xBB\033[m ");
	printf("\n\t\033[35m\xC8\xBC\xBC\xC8\xCA\xC8\xCA\xC8\xBC\x20\xCA\x20\xBC\xCA\xC8\xBC\xC8\xC8\xBC\033[m ");

	// And a
	printf("\n\t\xCD\xCD\xCD\xCD \033[34m\xC9\xBB\xC9\xBB\xCB\xCB\xBB \xC9\xBB\033[m \xCD\xCD\xCD");
	printf("\n\t\xCD\xCD\xCD\xCD \033[34m\xCC\xB9\xBA\xBA\xBA\xBA\xBA \xCC\xB9\033[m \xCD\xCD\xCD");
	printf("\n\t\xCD\xCD\xCD\xCD \033[34m\xBC\xC8\xCA\xC8\xBC\xCA\xBC \xBC\xC8\033[m \xCD\xCD\xCD");

	// Happy New Year
	printf("\n\t\033[31m\xBB\xC9\xC9\xBB\xC9\xBB\xC9\xBB\xBB\xC9\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\t\033[31m\xCC\xB9\xCC\xB9\xCC\xBC\xCC\xBC\xC8\xB9\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\t\033[31m\xBC\xC8\xBC\xC8\xCA\x20\xCA\x20\xC8\xBC\033[m \033[32m\xC9\xBB\xCB\xC9\xBB\xBB\xCB\xC9\033[m");
	printf("\n\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD \033[32m\xBA\xBA\xBA\xCC\x20\xBA\xBA\xBA\033[m");
	printf("\n\t\033[35m\xBB\xC9\xC9\xBB\xC9\xBB\xCB\xBB\x20\033[m\xCD \033[32m\xCA\xC8\xBC\xC8\xBC\xC8\xCA\xBC\033[m");
	printf("\n\t\033[35m\xC8\xB9\xCC\x20\xCC\xB9\xBA\xB9\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\t\033[35m\xC8\xBC\xC8\xBC\xBC\xC8\xCA\xC8\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");

}

// Prints the months of the year
void Printmonth(month M)
{
	switch (M)
	{
	case Jan: printf("January  "); break;
	case Feb: printf("February "); break;
	case Mar: printf("March    "); break;
	case Apr: printf("April    "); break;
	case May: printf("May      "); break;
	case Jun: printf("June     "); break;
	case Jul: printf("July     "); break;
	case Aug: printf("August   "); break;
	case Sep: printf("September"); break;
	case Oct: printf("October  "); break;
	case Nov: printf("November "); break;
	case Dec: printf("December "); break;
	default:break;
	}
}

// Controls if the number of given arguments are valid or not
void Control_Arg(int argc,int min,int MAX)
{
	if (argc < min)
	{
		COLOR_ON(1);
		printf("\n\n\tTOO FEW ARGUMENTS GIVEN");
		COLOR_OFF();
		exit(-1);
	}

	if (argc > MAX)
	{
		COLOR_ON(1);
		printf("\n\n\tTOO MANY ARGUMENTS GIVEN");
		COLOR_OFF();
		exit(-1);
	}
}