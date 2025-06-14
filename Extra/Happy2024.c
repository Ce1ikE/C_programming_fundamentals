/*

/////////////////////////////////////////////////////////////////////////////////////////HAPPY
.;;,     .;;,
`  ;;   ;;  '
   ;;   ;; ,  .;;;.   .;;,;;;,  .;;,;;;,  .;;.  .;;.
 ,;;;;;;;;;'  `   ;;  ` ;;   ;; ` ;;   ;; ` ;;  ;; '
 ` ;;   ;;    .;;.;;    ;;   ;;   ;;   ;;   ;;  ;;
   ;;   ;;    ;;  ;; ,  ;;   ;;   ;;   ;;   ;;  ;;
.  ;;    ';;' `;;;';;'  ;;';;'    ;;';;'     `;;';
';;'                    ;;        ;;            ;;
                     .  ;;     .  ;;         .  ;;
                     ';;'      ';;'          ';;'

               .;;, ,;;;,
               `  ;;    ;;
                  ;;    ;;     ,;;,  .;;.      .;;,
                  ;;    ;;    ;;  ;; ` ;;      ;; '
                  ;;    ;;    ;;;;;'   ;;  ;;  ;;
                  ;;    ;;    ;;   .   ;;  ;;  ;;
               .  ;;     ';;'  `;;;'    `;;'`;;'
               ';;'

                              .;;.     .;;.
                              `  ;;   ;;  '
                                 ;;   ;;   .;;,  .;;;.   .;;.;;;,
                                 ;;   ;;  ;;  ;; '   ;;  ` ;;   '
                                 ;;   ;;  ;;;;;' .;;,;;    ;;
                                  `;;;';  ;;   . ;;  ;; ,  ;;
                                      ;;   `;;;'  `;;';;'  ;'
                                      ;;
                                  .'  ;;
                                  ';;;'
*/

/* Headers */////////////////////////////////////////////////////////////////////////////NEW

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>



struct SMALL_RECT {
    SHORT Left;
    SHORT Top;
    SHORT Right;
    SHORT Bottom;
};

/* Function declarations *///////////////////////////////////////////////////////////////YEAR

void Christmas_Tree(void);
void adjustWindowSize(void);

int main(void)
{
   // HANDLE MyOutput;

	srand(time(NULL));
	printf("\033[64r");
	printf("\x1b[2J");
	printf("\033[?3h");
    printf("\x1b[?25l");
    adjustWindowSize();

   
	for (;;)
	{
		printf("\x1b[H"); // == printf("\x1b[f");		
		printf("\033[3%dm",2);
        Christmas_Tree();
	}
    

	return 0;
}

/* Function definitions *////////////////////////////////////////////////////////////////MERRY

void Christmas_Tree(void)
{

    printf("\n\n\n\033[32m");
    short Mod;
    srand(time(NULL));

    if (rand() % 2) {
        if (rand() % 2) {
            Mod = 3;
        }
        else {
            Mod = 2;
        }
    }
    else {
        if (rand() % 2) {
            Mod = 9;
        }
        else {
            Mod = 10;
        }
    } 
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;33m\x2C\033[0;32m                          \033[36m\xC9\xCB\xBB\xC9\xBB\xCB\xBB\xCB\xBB\xBB\xC9\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD\033[0;32m\n");
    printf("\x20\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;33m\x5F\x2F\x5E\x5C\x5F\033[0;32m                        \033[36m\xBA\xBA\xBA\xCC\x20\xBA\xB9\xBA\xB9\xC8\xB9\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD\033[0;32m\n");
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;33m\x3C\x20\x20\x20\x20\x20\x3E\033[0;32m                       \033[36m\xBC\xCA\xC8\xC8\xBC\xCA\xC8\xCA\xC8\xC8\xBC\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD\033[0;32m\n");
    printf("\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;33m\x2F\x2E\x2D\x2E\x5C\033[0;32m\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m              \033[35m\xC9\xBB\xBB\xC9\xCB\xBB\xCB\xC9\xBB\xC9\xCB\xBB\xC9\xCB\xBB\xC9\xBB\xC9\xBB\033[m\033[0;32m\n");
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m\x20\x20\x20\x20\x20\x20\x20\x20\x60\x2F\x26\x5C\x60\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m    \033[35m\xBA\x20\xCC\xB9\xBA\xB9\xBA\xC8\xBB\x20\xBA\x20\xBA\xBA\xBA\xCC\xB9\xC8\xBB\033[m\033[0;32m\n");
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2C\033[0;%d%dm\x40\033[0;32m\x2E\x2A\x3B\033[%d%dm\x40\033[0;32m\x2C                       \033[35m\xC8\xBC\xBC\xC8\xCA\xC8\xCA\xC8\xBC\x20\xCA\x20\xBC\xCA\xC8\xBC\xC8\xC8\xBC\033[m\033[0;32m\n", rand() % 7 + 1, rand() % 7 + 1, rand() % 7 + 1, rand() % 7 + 1);
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2F\033[0;35m\x5F\033[0;32m\033[0;31m\033[0;31m\x6F\033[0;32m\033[0;32m\x2E\x49\x20\x25\033[0;35m\x5F\033[0;32m\x5C\x20\x20\x20\x20\033[0;36m\x2A\033[0;37m                  \xCD\xCD\xCD\xCD \033[34m\xC9\xBB\xC9\xBB\xCB\xCB\xBB \xC9\xBB\033[m \xCD\xCD\xCD\033[0;32m\n");
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;35m\x28\033[0;32m\x60\x27\033[0;35m\x2D\033[0;32m\033[0;35m\x2D\033[0;32m\x3A\033[0;31m\033[0;31m\x6F\033[0;32m\033[0;32m\x28\033[0;35m\x5F\033[0;32m\033[%d%dm\x40\033[0;32m\x3B\033[0;37m                     \xCD\xCD\xCD\xCD \033[34m\xCC\xB9\xBA\xBA\xBA\xBA\xBA \xCC\xB9\033[m \xCD\xCD\xCD\033[0;32m\n", Mod, rand() % 7 + 1);
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2F\x60\x3B\033[0;35m\x2D\033[0;32m\033[0;35m\x2D\033[0;32m\x2E\x2C\033[0;35m\x5F\033[0;32m\033[0;35m\x5F\033[0;32m\x20\x60\x27\033[0;35m\x29\033[0;32m\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;37m      \xCD\xCD\xCD\xCD \033[34m\xBC\xC8\xCA\xC8\xBC\xCA\xBC \xBC\xC8\033[m \xCD\xCD\xCD\033[0;32m\n");
    printf("\x20\x20\x20\033[0;36m\x2A\033[0;32m\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x3B\033[%d%dm\x40\033[0;32m\x60\033[0;31m\x6F\033[0;32m\x20\x25\x20\x4F\x2C\033[0;36m\x2A\033[0;32m\x60\x27\x20\x60\x26\x5C\x20                   \033[31m\xBB\xC9\xC9\xBB\xC9\xBB\xC9\xBB\xBB\xC9\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\033[0;32m\n", Mod, rand() % 7 + 1);
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m\x20\x20\x20\x20\033[0;35m\x28\033[0;32m\x60\x27\033[0;35m\x2D\033[0;32m\033[0;35m\x2D\033[0;32m\x29\033[0;35m\x5F\033[0;32m\033[%d%dm\x40\033[0;32m\x20\x3B\033[0;31m\x6F\033[0;32m\x20\x25\x27\033[0;33m\x28\x29\033[0;32m\x5C\x20\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m            \033[31m\xCC\xB9\xCC\xB9\xCC\xBC\xCC\xBC\xC8\xB9\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\033[0;32m\n", rand() % 7 + 1, rand() % 7 + 1);
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2F\x60\x3B\033[0;35m\x2D\033[0;32m\033[0;35m\x2D\033[0;32m\x2E\033[0;35m\x5F\033[0;32m\x60\x27\x27\033[0;35m\x2D\033[0;32m\033[0;35m\x2D\033[0;32m\x2E\033[0;35m\x5F\033[0;32m\x4F\x27\033[%d%dm\x40\033[0;32m\x3B                 \033[31m\xBC\xC8\xBC\xC8\xCA\x20\xCA\x20\xC8\xBC\033[m \033[32m\xC9\xBB\xCB\xC9\xBB\xBB\xCB\xC9\033[0;32m\n", rand() % 7 + 1, rand() % 7 + 1);
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2F\x26\x3B\x2C\033[0;33m\x28\x29\033[0;32m\x7E\033[0;31m\x6F\033[0;32m\x60\x3B\033[0;35m\x2D\033[0;32m\x2E\x2C\033[0;35m\x5F\033[0;32m\x20\x60\x22\x22\x60\033[0;35m\x29\033[0;37m                \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD \033[32m\xBA\xBA\xBA\xCC\x20\xBA\xBA\xBA\033[0;32m\n");
    printf("\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2F\x60\x2C\033[%d%dm\x40\033[0;32m\x20\x3B\x2B\x26\x20\033[0;33m\x28\x29\033[0;32m\x20\033[0;31m\x6F\033[0;32m\033[0;36m\x2A\033[0;32m\x60\x3B\033[0;35m\x2D\033[0;32m\x27\x3B\x5C                \033[35m\xBB\xC9\xC9\xBB\xC9\xBB\xCB\xBB\x20\033[m\xCD \033[32m\xCA\xC8\xBC\xC8\xBC\xC8\xCA\xBC\033[0:32m\n", rand() % 7 + 1, rand() % 7 + 1);
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;35m\x28\033[0;32m\x60\x22\x22\033[0;35m\x2D\033[0;32m\033[0;35m\x2D\033[0;32m\x2E\x2C\033[0;35m\x5F\033[0;32m\x30\x20\x2B\x25\x20\033[%dm\x40\033[0;32m\x27\x20\x20\x20\x26\033[0;33m\x28\x29\033[0;32m\x5C                \033[35m\xC8\xB9\xCC\x20\xCC\xB9\xBA\xB9\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\033[0;32m\n", rand() % 7 + 1);
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2F\033[0;35m\x2D\033[0;32m\x2E\x2C\033[0;35m\x5F\033[0;32m\x20\x20\x20\x20\x60\x60\x27\x27\033[0;35m\x2D\033[0;32m\033[0;35m\x2D\033[0;32m\x2E\x2E\x2E\x2E\033[0;35m\x2D\033[0;32m\x27\x60\033[0;35m\x29\033[0;32m\x20\x20\033[0;36m\x2A\033[0;32m           \033[35m\xC8\xBC\xC8\xBC\xBC\xC8\xCA\xC8\033[m \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m\x20\x20\x20\x20\x2F\033[%d%dm\x40\033[0;32m\x25\x3B\033[0;31m\x6F\033[0;32m\x60\x3A\x3B\x27\033[0;35m\x2D\033[0;32m\033[0;35m\x2D\033[0;32m\x2C\x2E\033[0;35m\x5F\033[0;32m\033[0;35m\x5F\033[0;32m\x20\x20\x20\033[0;35m\x5F\033[0;32m\033[0;35m\x5F\033[0;32m\x2E\x27\x5C  \n", rand() % 7 + 1, Mod);
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x3B\033[0;36m\x2A\033[0;32m\x2C\x26\033[0;33m\x28\x29\033[0;32m\x3B\x20\033[%dm\x40\033[0;32m\x20\x25\x20\x26\x5E\x3B\x7E\x60\x22\x60\033[0;31m\x6F\033[0;32m\x3B\033[%dm\x40\033[0;32m\033[0;33m\x28\x29\033[0;32m\x3B\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;36m\x2A\033[0;32m  \n", rand() % 7 + 1, rand() % 7 + 1);
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2F\033[0;33m\033[0;33m\x28\x29\033[0;32m\033[0;32m\x3B\x20\033[0;31m\x6F\033[0;32m\x5E\x7E\x3B\x20\x26\x20\033[0;33m\x28\x29\033[0;32m\x2E\033[0;31m\x6F\033[0;32m\033[%d%dm\x40\033[0;32m\033[0;36m\x2A\033[0;32m\x26\x60\x3B\x26\x25\x4F\x5C  \n", Mod, rand() % 7 + 1);
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x60\x22\x3D\x22\x3D\x3D\x22\x22\x3D\x3D\x2C\x2C\x2C\x2E\x2C\x3D\x22\x3D\x3D\x22\x3D\x3D\x3D\x22\x60\n");
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;37m\x5F\x5F\x2E\x2D\x2D\x2D\x2D\x2E\033[0;91m\x28\x5C\033[0;37m\x2D\x27\x27\033[0;32m\x23\x23\x23\x23\x23\033[0;37m\x2D\x2D\x2D\x2E\x2E\x2E\x5F\x5F\x5F\x2E\x2E\x2E\x2D\x2D\x2D\x2D\x2D\x2E\x5F\033[0m\n");
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x60\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;91m\x5C\x29\x5F\033[0;32m\x60\x22\x22\x22\x22\x22\x60  \033[3;37mMay this holiday season leave you with precious memories:\033[0;32m\n");
    printf("\033[0;91m\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2E\x2D\x2D\x27\x20\033[0;37m\x27\033[0;91m\x29  \033[3;37m      A holidays filled with love and light love and joy all around\033[0;32m\n");
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\033[0;37m\x6F\033[0;91m\x28\x20\x20\x29\x5F\x2D\x5C  \033[3;37m       A New Year with continuing blessings friends, family, great fun and delightful surprises\033[0;37m\n");
    printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x60\x22\x22\x22\x60\x20\x60  \033[3;37m      I wish you, your family and friends a happy new year 2024!   --- EC ---\033[0;32m\n");

    printf("\033[m");
}




void adjustWindowSize(void)
{
    struct SMALL_RECT test;

    HANDLE hStdout;
    COORD coord;
    BOOL ok;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = 1000;
    coord.Y = 2000;
    ok = SetConsoleScreenBufferSize(hStdout, coord);

    test.Left = 5;
    test.Top = 5;
    test.Right = coord.X - 1;
    test.Bottom = coord.Y - 1;

    SetConsoleWindowInfo(hStdout, ok, &test);

} //end adjustWindowSize 


/////////////////////////////////////////////////////////////////////////////////////////CHRISTMAS