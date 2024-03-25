#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


void Textecolor(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, 
        //and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}


void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void welcome()
{
    int k;
    system("Cls");
    for (k = 0; k < 10; k++)
    {
        if (k % 2 == 0)
            Textecolor(5);
        if (k % 2 == 1)
            Textecolor(3);
        printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t  .----------------.  .----------------.  .----------------.\n");
    printf("\t\t\t\t\t\t | .--------------. || .--------------. || .--------------. |\n");
    printf("\t\t\t\t\t\t | |  _________   | || |    _______   | || |     _____    | |\n");
    printf("\t\t\t\t\t\t | | |_   ___  |  | || |   /  ___  |  | || |    |_   _|   | |\n");
    printf("\t\t\t\t\t\t | |   | |_  \\_|  | || |  |  (__ \\_|  | || |      | |     | |\n");
    printf("\t\t\t\t\t\t | |   |  _|  _   | || |   \'.___`-.   | || |      | |     | |\n");
    printf("\t\t\t\t\t\t | |  _| |___/ |  | || |  |`\\____) |  | || |     _| |_    | |\n");
    printf("\t\t\t\t\t\t | | |_________|  | || |  |_______.\'  | || |    |_____|   | |\n");
    printf("\t\t\t\t\t\t | |              | || |              | || |              | |\n");
    printf("\t\t\t\t\t\t | \'--------------\' || \'--------------\' || \'--------------\' |\n");
    printf("\t\t\t\t\t\t  \'----------------\'  \'----------------\'  \'----------------\'\n");
    Sleep(200);
    system("cls");
    }
    Textecolor(5);
    printf("\t\t\t\t\t\t          R%cpublique Alg%crienne D%cmocratique et Populaire           \n", 130, 130, 130);
    printf("\t\t\t\t\t\tMinist%cre de l'Enseignement Sup%crieur et de la Recherche Scientifique\n\n\n", 130, 130);
    printf("\t\t\t\t\t\t     _______________________________________________________\n");
    printf("\t\t\t\t\t\t    |        _______     _______     _                      |\n");
    printf("\t\t\t\t\t\t    |       |  _____|   |  _____|   | |  %ccole nationale    |\n", 130);
    printf("\t\t\t\t\t\t    |       | |_____    | |_____    | |                     |\n");
    printf("\t\t\t\t\t\t    |       |  _____|   |_____  |   | |  sup%crieure         |\n", 130);
    printf("\t\t\t\t\t\t    |       | |_____     _____| |   | |                     |\n");
    printf("\t\t\t\t\t\t    |       |_______|   |_______|   |_|  d'informatique     |\n");
    printf("\t\t\t\t\t\t    |_______________________________________________________|\n\n\n");
    Textecolor(3);
    printf("\t\t\t\t\t\t\tCPI - 1%cre Ann%ce - Ann%ce Universitaire 2022/2023 \n\n\n", 138, 130, 130);
    printf("\t\t\t\t\t\t ___________________________________________________________________\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t| REALISE PAR :             Your name                               |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|           SECTION : B           GROUPE: 05                        |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|           EXO :        STRING TABLE                               |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|___________________________________________________________________|\n\n\n");
    Sleep(200);
    Sleep(200);
    Textecolor(5);
    printf("\n");
    printf("\t\t\t\t\t\t                             PLease                                         \n");
    printf("\t\t\t\t\t\t                    Press any key to continue..                             ");
    getch();
}




void TP() {
    printf(" .----------------.  .----------------.   .----------------.                                        \n");
    printf("| .--------------. || .--------------. | | .--------------. |                                       \n");
    printf("| |  _________   | || |   ______     | | | |     __       | |                                       \n");
    printf("| | |  _   _  |  | || |  |_   __ \\   | | | |    /  |      | |                                       \n");
    printf("| | |_/ | | \\_|  | || |    | |__) |  | | | |    `| |      | |                                       \n");
    printf("| |     | |      | || |    |  ___/   | | | |     | |      | |                                       \n");
    printf("| |    _| |_     | || |   _| |_      | | | |    _| |_     | |                                       \n");
    printf("| |   |_____|    | || |  |_____|     | | | |   |_____|    | |                                       \n");
    printf("| |              | || |              | | | |              | |                                       \n");
    printf("| '--------------' || '--------------' | | '--------------' |                                       \n");
    printf(" '----------------'  '----------------'   '----------------'                                        \n");
    printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n");
    printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
    printf("| |      __      | || |   _____      | || |    _______   | || |  ________    | || |  ________    | |\n");
    printf("| |     /  \\     | || |  |_   _|     | || |   /  ___  |  | || | |_   ___ `.  | || | |_   ___ `.  | |\n");
    printf("| |    / /\\ \\    | || |    | |       | || |  |  (__ \\_|  | || |   | |   `. \\ | || |   | |   `. \\ | |\n");
    printf("| |   / ____ \\   | || |    | |   _   | || |   '.___`-.   | || |   | |    | | | || |   | |    | | | |\n");
    printf("| | _/ /    \\ \\_ | || |   _| |__/ |  | || |  |`\\____) |  | || |  _| |___.' / | || |  _| |___.' / | |\n");
    printf("| ||____|  |____|| || |  |________|  | || |  |_______.'  | || | |________.'  | || | |________.'  | |\n");
    printf("| |              | || |              | || |              | || |              | || |              | |\n");
    printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
    printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");

    
}


void aff() {
    printf(".----------------.  .----------------.  .-----------------. .----------------.  \n");
    printf("| .--------------. || .--------------. || .--------------. || .--------------. |  \n");
    printf("| |   _____      | || |     _____    | || | ____  _____  | || |  ___  ____   | |  \n");
    printf("| |  |_   _|     | || |    |_   _|   | || ||_   \\|_   _| | || | |_  ||_  _|  | |  \n");
    printf("| |    | |       | || |      | |     | || |  |   \\ | |   | || |   | |_/ /    | |  \n");
    printf("| |    | |   _   | || |      | |     | || |  | |\\ \\| |   | || |   |  __'.    | |  \n");
    printf("| |   _| |__/ |  | || |     _| |_    | || | _| |_\\   |_  | || |  _| |  \\ \\_  | |  \n");
    printf("| |  |________|  | || |    |_____|   | || ||_____\\____| | || | |____||____| | |  \n");
    printf("| |              | || |              | || |              | || |              | |  \n");
    printf("| '--------------' || '--------------' || '--------------' || '--------------' |  \n");
    printf(" '----------------'  '----------------'  '----------------'  '----------------'   \n");
    printf(" .----------------.  .----------------.  .----------------.  .----------------.   \n");
    printf("| .--------------. || .--------------. || .--------------. || .--------------. |  \n");
    printf("| |   _____      | || |     _____    | || |    _______   | || |  _________   | |  \n");
    printf("| |  |_   _|     | || |    |_   _|   | || |   /  ___  |  | || | |  _   _  |  | |  \n");
    printf("| |    | |       | || |      | |     | || |  |  (__ \\_|  | || | |_/ | | \\_|  | |  \n");
    printf("| |    | |   _   | || |      | |     | || |   '.___`-.   | || |     | |      | |  \n");
    printf("| |   _| |__/ |  | || |     _| |_    | || |  |`\\____) |  | || |    _| |_     | |  \n");
    printf("| |  |________|  | || |    |_____|   | || |  |_______.'  | || |   |_____|    | |  \n");
    printf("| |              | || |              | || |              | || |              | |  \n");
    printf("| '--------------' || '--------------' || '--------------' || '--------------' |  \n");
    printf(" '----------------'  '----------------'  '----------------'  '----------------'   \n");
}

