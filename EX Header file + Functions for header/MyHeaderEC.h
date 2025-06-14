/*

    "MyHeaderEC.h" by C.E.

    Attachments => "MyFunctionsEC.c"

    TM©2023
    By accessing or using any copyrighted materials owned by C.E., you acknowledge and agree to abide by the terms of this Copyright Disclaimer.
    If you do not agree with any of these terms, please refrain from accessing or using the copyrighted materials.

*///=============================================================================================================================================================================================================================
#ifndef MACRO_EC /* Guard */ 
#define MACRO_EC

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/* All  max macro' s*/

#define MAX2(a,b)		    (a > b ? a : b)
#define MAX3(a,b,c)		    (MAX2(MAX2(a,b),c))
#define MAX4(a,b,c,d)	    (MAX2(MAX3(a,b,c),d))
#define MAX5(a,b,c,d,e)     (MAX2(MAX4(a,b,c,d),e))
// for larger samples use function "Max(int[])"

/* All text printing macro's */

#define COLOR_ON(c)         (printf("\033[3"#c"m"))
#define COLOR_OFF()         (printf("\033[0m"))
#define FONT_ON(f)          (printf("\033[4"#f"m"))
#define FONT_OFF()          (COLOR_OFF())

/* All check macro's */

#define IS_CAPITAL(l)	    (l < 91 && l > 64 ?  1  : 0)
#define IS_SMALL(l)		    (l < 123 && l > 96 ?  1  : 0)
#define IS_LETTER(l)	    (IS_SMALL(l) ? 1 : IS_CAPITAL(l))
#define IS_NUMBER(x)	    (x < 58 && x > 47 ? 1 : 0)

/* All converter macro's */

#define TOUPPER(l)		    (l < 123 && l > 96 ? l = l - 32 : l )
#define TOLOWER(l)		    (l < 91 && l > 64 ? l = l + 32 : l )
// For strings use function "U2l_Converter(char[])" or "l2U_Converter(char[])"

/* All binary macro's */

#define TOBINARY(x)		    (x % 2 ? printf("0") : printf("1"))
#define SHIFT_L_BY(x,n)     (x = x << n)
#define SHIFT_R_BY(x,n)     (x = x >> n)

/* Exercice title macro */

#define TITLE_EX(Oef,Pg)    (printf("\n\t----\tDit is oefening "#Oef" van 'Cprogrammingfundamentals2020' Pg"#Pg"\t----\n\n\n\n"))

/* All constant macro's */

#define STR_BUFFER          512
#define NameLength          15
#define StrLength           32

#endif // MACRO_EC

#ifndef ENUM_EC /* Guard */ // ===========================================================================================================================================================================================================
#define ENUM_EC // =======================================================================================================================================================================================================================

/* All enumerations */

typedef enum t_month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec } month;

typedef enum t_color { Black, Red, Green, Yellow, Blue, Magenta, Cyan, White } Color;


#endif // ENUM_EC


#ifndef STRUC_EC /* Guard */ // ==========================================================================================================================================================================================================
#define STRUC_EC // ======================================================================================================================================================================================================================


typedef struct t_Date {

    int Day;
    int Month_int;
    char Month[StrLength];
    int Year;

} date;

typedef struct t_Person {

    char name[NameLength];
    char firstname[NameLength];
    int Age;
    char HomeTown[StrLength];
    date DayofBirth;
    date EnrollementDate;
    

} person;

typedef struct t_Address {

    char StreetAndNr[StrLength];
    int PostaCode;
    char Town[StrLength];
    char PhoneNr[10]; // Note since a integer range is [2 147 483 647 ; -2 147 483 648] we use a string

} address;

typedef struct t_Student {

    person Personal;
    address HomeAddress;
    address SchoolAddress;

} student;

typedef struct t_Employees {

    person Pers;
    int Salary;

} employee;

typedef struct t_Customers {

    char CustomerNr[StrLength];
    char Name[NameLength];
    char Firstname[NameLength];
    

} customer;

typedef struct t_CustomersINFO {

    char CustomerNr[StrLength];
    char CityAddress[StrLength];

} customerINFO;

typedef struct t_PeopleOfJosephus 
{
    int Number;
    struct PeopleOJ * Next;

} PeopleOJ;

#endif // STRUC_EC


#ifndef FUNCTIONS_EC /* Guard */ // ======================================================================================================================================================================================================
#define FUNCTIONS_EC // ==================================================================================================================================================================================================================

/* My own in build functions */

// Prints a 3D hello message to the terminal
void Hello(int);

// Prints a 2D "Bye" message to the terminal
void Bye_Message(int, int, int);

// Searches for maximum value in a array and returns it's value
int Max_Value(int[],int);

// Prints the prime number up to N as limit or stores them into an array depending on the "mode"
// If the mode equals 'w' :
// ------------------------
// (1) The user must fill in the limit 'N' which defines the limit till where the function searches for prime numbers
// (2) The user must fill in the mode which defines the current working method => writing to a array
// (3) The user must fill in a argument 'arg' which defines the number of additional parameters => 2
// (4) The user must fill in the size of the array in case the size of the array can't hold all prime numbers generated
// (5) The user must fill in the name of the pointer that points to the array which the functions will write to 
// ----------------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------
// If the mode equals 'p':
// -----------------------
// (1) The user must fill in the limit 'N' which defines the limit till where the function search for prime numbers
// (2) The user must fill in the mode which defines the current working method => printing to the terminal
// (3) The user must fill in a argument 'arg' which defines the number of additional parameters => 0
void Prime_up_to(int, char, int,...);

// Prints the Nth first prime numbers or stores them into an array depending on the "mode"
// If the mode equals 'w' :
// ------------------------
// (1) The user must fill in the amount 'N' which defines how many prime numbers will be written to the array
// (2) The user must fill in the mode which defines the current working method => writing to a array
// (3) The user must fill in a argument 'arg' which defines the number of additional parameters => 2
// (4) The user must fill in the size of the array in case the size of the array can't hold all prime numbers generated
// (5) The user must fill in the name of the pointer that points to the array which the functions will write to 
// ----------------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------
// If the mode equals 'p':
// -----------------------
// (1) The user must fill in the amount 'N' which defines how many prime numbers will be printed to the terminal
// (2) The user must fill in the mode which defines the current working method => printing to the terminal
// (3) The user must fill in a argument 'arg' which defines the number of additional parameters => 0
void Prime_Numbers_Generator(int, char, int,...);

// Returns the Nth prime number
int Prime_N(int);

// Filters the ASCII characters with decimal value [32 ; 64]U[91 ; 96]U[123 ; 126] within a string
void Symbol_Filter(char[]);

// Converts the ASCII characters with decimal value [65 ; 90] to ASCII characters with decimal value [97 ; 122]
void U2l_Converter(char[]);

// Converts the ASCII characters with decimal value [97 ; 122] to ASCII characters with decimal value [65 ; 90]
void l2U_Converter(char[]);

// Prints a line with any given length and character
void Print_Line(int, char);

// Sets text color send to the terminal in one of the 8 available colors of the ANSI CSI(more information see below)
void Set_Color(int);

// Sets text font(background) color send to the terminal in one of the 8 available colors of the ANSI CSI(more information see below).However comptability is not garenteed with every terminal
void Set_font(int c);

/*
----Color numbers----

0 Black
1 Red
2 Green
3 Yellow
4 Blue
5 Magenta
6 Cyan
7 White

----Type text----

//Regular text          //Regular bold text         //Regular cursive text      //Regular underline text
ESC[0; 30 m             ESC[1; 30 m                 ESC[2; 30 m                 ESC[4; 30 m
ESC[0; 31 m             ESC[1; 31 m                 ESC[2; 30 m                 ESC[4; 31 m
ESC[0; 32 m             ESC[1; 32 m                 ESC[2; 30 m                 ESC[4; 32 m
ESC[0; 33 m             ESC[1; 33 m                 ESC[2; 30 m                 ESC[4; 33 m
ESC[0; 34 m             ESC[1; 34 m                 ESC[2; 30 m                 ESC[4; 34 m
ESC[0; 35 m             ESC[1; 35 m                 ESC[2; 30 m                 ESC[4; 35 m
ESC[0; 36 m             ESC[1; 36 m                 ESC[2; 30 m                 ESC[4; 36 m
ESC[0; 37 m             ESC[1; 37 m                 ESC[2; 30 m                 ESC[4; 37 m

//Regular blinking text //Regular (swap*) text      //Regular (/) text          //Regular crossed out text
ESC[5; 30 m             ESC[7; 30 m                 ESC[8; 30 m                 ESC[9; 30 m
ESC[5; 31 m             ESC[7; 31 m                 ESC[8; 30 m                 ESC[9; 31 m
ESC[5; 32 m             ESC[7; 32 m                 ESC[8; 30 m                 ESC[9; 32 m
ESC[5; 33 m             ESC[7; 33 m                 ESC[8; 30 m                 ESC[9; 33 m
ESC[5; 34 m             ESC[7; 34 m                 ESC[8; 30 m                 ESC[9; 34 m
ESC[5; 35 m             ESC[7; 35 m                 ESC[8; 30 m                 ESC[9; 35 m
ESC[5; 36 m             ESC[7; 36 m                 ESC[8; 30 m                 ESC[9; 36 m
ESC[5; 37 m             ESC[7; 37 m                 ESC[8; 30 m                 ESC[9; 37 m

//Regular line over text
ESC[53; 30 m

//Regular background*   //High intensty text        //High intensty background
ESC[0; 40 m             ESC[0; 90 m                 ESC[0; 100 m
ESC[0; 41 m             ESC[0; 91 m                 ESC[0; 101 m
ESC[0; 42 m             ESC[0; 92 m                 ESC[0; 102 m
ESC[0; 43 m             ESC[0; 93 m                 ESC[0; 103 m
ESC[0; 44 m             ESC[0; 94 m                 ESC[0; 104 m
ESC[0; 45 m             ESC[0; 95 m                 ESC[0; 105 m
ESC[0; 46 m             ESC[0; 96 m                 ESC[0; 106 m
ESC[0; 47 m             ESC[0; 97 m                 ESC[0; 107 m


----color reset----

ESC[0 m




        ANSI escape sequences are a standard for in-band signaling to control cursor location, color, font styling, and other options on video text terminals and terminal emulators.
        Certain sequences of bytes, most starting with an ASCII escape character and a bracket character, are embedded into text.
        The terminal interprets these sequences as commands, rather than text to display verbatim.
        ANSI sequences were introduced in the 1970s to replace vendor-specific sequences and became widespread in the computer equipment market by the early 1980s.
        They are used in development, scientific, commercial text-based applications as well as bulletin board systems to offer standardized functionality.
        Although hardware text terminals have become increasingly rare in the 21st century, the relevance of the ANSI standard persists because a great majority of terminal emulators and command consoles interpret at least a portion of the ANSI standard.



        escape(ESC) codes:
        ------------------

        Ctrl-key    : ^[
        Octal       : \033
        Unicode     : \u001b
        Hexadecimal : \x1B
        Decimal     : 27

        ANSI escape sequences:
        ---------------------

        Code	C1	    Abbr	    Name

        ESC N	0x8E	SS2	        Single Shift Two

        ESC O	0x8F	SS3	        Single Shift Three

        ESC P	0x90	DCS	        Device Control String

        ESC [	0x9B	CSI	        Control Sequence Introducer

        ESC \	0x9C	ST	        String Terminator

        ESC ]	0x9D	OSC	        Operating System Command

        ESC X	0x98	SOS	        Start of String

        ESC ^	0x9E	PM	        Privacy Message

        ESC _	0x9F	APC	        Application Program Command


        Control sequence introducer(CSI) :
        ----------------------------------

        ESC [ (+Parameter byte) ; (+intermediate byte) ; (+final byte)

                                range(HEX)      range(ASCII)

        Parameter byte      :   0x30-0x3F       0–9:;<=>?

        intermediate byte   :   0x20-0x2F       space !"#$%&'()*+,-./

        final byte          :   0x40-0x7E       @A–Z[\]^_`a–z{|}~

        !!!NOTE:
        A subset of arrangements was declared "private" so that terminal manufacturers could insert their own sequences without conflicting with the standard.
        Sequences containing the parameter bytes <=>? or the final bytes 0x70–0x7E (p–z{|}~) are private.


        ANSI CSI :
        ----------

        Code	        Abbr	    Name

        CSI n A         CUU	        Cursor Up
        CSI n B	        CUD	        Cursor Down
        CSI n C	        CUF	        Cursor Forward
        CSI n D	        CUB	        Cursor Back

        Moves the cursor n (default 1) cells in the given direction.
        If the cursor is already at the edge of the screen, this has no effect.

        CSI n E	        CNL	        Cursor Next Line                    Moves cursor to beginning of the line n (default 1) lines down.
        CSI n F	        CPL	        Cursor Previous Line                Moves cursor to beginning of the line n (default 1) lines up.
        CSI n G	        CHA	        Cursor Horizontal Absolute          Moves the cursor to column n
        CSI n ; m H	    CUP	        Cursor Position                     Moves the cursor to row n, column m. The values are 1-based, and default to 1 (top left corner) if omitted.

        CSI n J	        ED	        Erase in Display

        Clears part of the screen.
        If n is 0 (or missing), clear from cursor to end of screen.
        If n is 1, clear from cursor to beginning of the screen.
        If n is 2, clear entire screen.
        If n is 3, clear entire screen and delete all lines saved in the scrollback buffer.

        CSI n K	        EL	        Erase in Line

        Erases part of the line.
        If n is 0 (or missing), clear from cursor to the end of the line.
        If n is 1, clear from cursor to beginning of the line.
        If n is 2, clear entire line.
        Cursor position does not change.

        CSI n S	        SU	        Scroll Up                           Scroll whole page up by n (default 1) lines.
        CSI n T	        SD	        Scroll Down                         Scroll whole page down by n (default 1) lines.
        CSI n ; m f	    HVP	        Horizontal Vertical Position
        CSI n m	        SGR	        Select Graphic Rendition	        Sets colors and style of the characters following this code

        CSI 5i		                AUX Port On	                        Enable aux serial port usually for local serial printer
        CSI 4i		                AUX Port Off	                    Disable aux serial port usually for local serial printer
        CSI 6n	        DSR	        Device Status Report	            Reports the cursor position (CPR) by transmitting ESC[n;mR, where n is the row and m is the column

        Select Graphic Rendition (SGR) parameters :
        -------------------------------------------

        The control sequence CSI n m, named Select Graphic Rendition (SGR), sets display attributes.
        Several attributes can be set in the same sequence, separated by semicolons.
        Each display attribute remains in effect until a following occurrence of SGR resets it.
        If no codes are given, CSI m is treated as CSI 0 m (reset / normal).

        0	    Reset or normal	All attributes become turned off
        1	    Bold or increased intensity	As with faint, the color change is a PC (SCO / CGA) invention.
        2	    Faint, decreased intensity, or dim	May be implemented as a light font weight like bold.
        3	    Italic	Not widely supported. Sometimes treated as inverse or blink.
        4	    Underline	Style extensions exist for Kitty, VTE, mintty, iTerm2 and Konsole.
        5	    Slow blink	Sets blinking to less than 150 times per minute
        6	    Rapid blink	MS-DOS ANSI.SYS, 150+ per minute; not widely supported
        7	    Reverse video or invert	Swap foreground and background colors; inconsistent emulation
        8	    Conceal or hide	Not widely supported.
        9	    Crossed-out, or strike	Characters legible but marked as if for deletion. Not supported in Terminal.app.
        10	    Primary (default) font
        11–19	Alternative font	Select alternative font n − 10
        20	    Fraktur (Gothic)	Rarely supported
        21	    Doubly underlined; or: not bold	Double-underline per ECMA-48, 8.3.117  but instead disables bold intensity on several terminals, including in the Linux kernel's console before version 4.17.
        22	    Normal intensity	Neither bold nor faint; color changes where intensity is implemented as such.
        23	    Neither italic, nor blackletter
        24	    Not underlined	Neither singly nor doubly underlined
        25	    Not blinking	Turn blinking off
        26	    Proportional spacing	ITU T.61 and T.416, not known to be used on terminals
        27	    Not reversed
        28	    Reveal	Not concealed
        29	    Not crossed out
        30–37	Set foreground color
        38	    Set foreground color	Next arguments are 5;n or 2;r;g;b
        39	    Default foreground color	Implementation defined (according to standard)
        40–47	Set background color
        48	    Set background color	Next arguments are 5;n or 2;r;g;b
        49	    Default background color	Implementation defined (according to standard)
        50	    Disable proportional spacing	T.61 and T.416
        51	    Framed	Implemented as "emoji variation selector" in mintty.
        52	    Encircled
        53	    Overlined	Not supported in Terminal.app
        54	    Neither framed nor encircled
        55	    Not overlined
        58	    Set underline color	Not in standard; implemented in Kitty, VTE, mintty, and iTerm2. Next arguments are 5;n or 2;r;g;b.
        59	    Default underline color	Not in standard; implemented in Kitty, VTE, mintty, and iTerm2.
        60	    Ideogram underline or right side line	Rarely supported
        61	    Ideogram double underline, or double line on the right side
        62	    Ideogram overline or left side line
        63	    Ideogram double overline, or double line on the left side
        64	    Ideogram stress marking
        65	    No ideogram attributes	Reset the effects of all of 60–64
        73	    Superscript	Implemented only in mintty
        74	    Subscript
        75	    Neither superscript nor subscript
        90–97	Set bright foreground color	Not in standard; originally implemented by aixterm
        100–107	Set bright background color


*/

// Prints the content of a existing file to the terminal
void PrintTXTFileContent(FILE*, char[]);

// Prints "Merry christmas and a happy new year"
void PrintHappyHolidays(void);

// Prints the months of the year
void Printmonth(month);

// Controls if the number of given arguments are valid or not
void Control_Arg(int,int,int);

#endif // FUNCTIONS_EC

#ifndef FUNCTIONSSUB_EC /* Guard */ // ===================================================================================================================================================================================================
#define FUNCTIONSSUB_EC // ===============================================================================================================================================================================================================

// These are not functions that have just regular INPUT and OUTPUT but rather different outcomes depending on what the user chooses
// the user has to only answer the questions of the program.

// Checks if a file exists or not and will take additional steps if the file does not exist 
void CheckFile(FILE*, char[]);


#endif // FUNCTIONSSUB_EC

