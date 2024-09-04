///Library includes
#include<stdio.h>
#include<stdlib.h>
#include "time.h"
#include "string.h"

///Global variables
char playername[30];
int bordbakht[2] = { 0 , 0 };
int flag8 = 10;
int flag16 = 40;


void inputEROR() {//This function was created to display any user's input errors.
    system("cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\ \033[1;31m WRONG INPUTE!!!!TRY AGAIN\033[0m");
    _sleep(1500);
    system("cls||clear");
}

///user account
void changename() {
    system("cls||clear");
    printf("Please enter your new username:");
    gets(playername);
    system("cls||clear");
}
void newplayer() {
    system("cls||clear");
    printf("\033[1;35m%Who are YOU??  :| \033[0m\n");
    gets(playername);
    bordbakht[0] = 0;
    bordbakht[1] = 0;
    system("cls||clear");
}
void account() {
    system("cls||clear");
    printf("Please enter your username:");
    gets(playername);
    system("cls||clear");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

/// 8*8 Mode
void printtable8(char display[8][8], int khooneh[8][8], int flag) {
    printf("\t\033[1;31m%[Flag remaining]:\033[0m  %d \n\n", flag);
    printf("       1   2   3   4   5   6   7   8\n\n");
    printf("      -------------------------------\n");
    for (int i = 0; i < 8; i++) {
        printf(" %d-  ", ++i);
        i--;
        for (int j = 0; j < 8; j++) {
            printf("|");
            if (display[i][j] == '0') {

                printf("   ");
                continue;
            }
            if (display[i][j] == '1') {
                printf(" \033[1;34m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '2') {
                printf(" \033[1;32m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '3') {
                printf(" \033[1;31m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '4') {
                printf(" \033[1;33m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '5') {
                printf(" \033[1;36m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '6') {
                printf(" \033[1;35m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '7') {
                printf(" \033[1;37m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == 64) {
                printf(" \033[1;31m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == 'F') {
                printf(" \033[1;35m$\033[0m ");
                continue;
            }
            else {
                printf(" \033[1;33m%c\033[0m ", display[i][j]);

            }


        }
        printf("|");
        printf("\n");
        printf("      -------------------------------");
        printf("\n");
    }
    printf("\n\n");

    printf("       1   2   3   4   5   6   7   8\n\n");
    printf("      -------------------------------\n");
    for (int i = 0; i < 8; i++) {
        printf(" %d-  ", ++i);
        i--;
        for (int j = 0; j < 8; j++) {
            printf("|");
            if (khooneh[i][j] == 0) {
                printf("   ");
                continue;
            }
            if (khooneh[i][j] == 1) {
                printf(" \033[1;34m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 2) {
                printf(" \033[1;32m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 3) {
                printf(" \033[1;31m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 4) {
                printf(" \033[1;33m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 5) {
                printf(" \033[1;36m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 6) {
                printf(" \033[1;35m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 7) {
                printf(" \033[1;37m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            else {
                printf(" \033[1;35m@\033[0m ");
                continue;
            }
        }
        printf("|");
        printf("\n");
        printf("      -------------------------------");
        printf("\n");

    }

}

void game8() {
    int khooneh[8][8] = { 0 };
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

/// 16*16 Mode
void printtable16(char display[16][16], int khooneh[16][16]) {
    printf("\t\033[1;31m%[Flag remaining]:\033[0m  %d \n\n", flag16);
    printf("       1   2   3   4   5   6   7   8   9   10  11  12  13  14 15  16\n\n");
    printf("      ---------------------------------------------------------------\n");
    for (int i = 0; i < 16; i++) {
        if (i < 9) {
            printf(" %d-  ", ++i);
        }
        else {
            printf(" %d- ", ++i);
        }
        i--;
        for (int j = 0; j < 16; j++) {
            printf("|");
            if (display[i][j] == '0') {

                printf("   ");
                continue;
            }
            if (display[i][j] == '1') {
                printf(" \033[1;34m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '2') {
                printf(" \033[1;32m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '3') {
                printf(" \033[1;31m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '4') {
                printf(" \033[1;33m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '5') {
                printf(" \033[1;36m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '6') {
                printf(" \033[1;35m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == '7') {
                printf(" \033[1;37m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == 64) {
                printf(" \033[1;31m%c\033[0m ", display[i][j]);
                continue;
            }
            if (display[i][j] == 'F') {
                printf(" \033[1;35m$\033[0m ");
                continue;
            }
            else {
                printf(" \033[1;33m%c\033[0m ", display[i][j]);

            }


        }
        printf("|");
        printf("\n");
        printf("      ---------------------------------------------------------------");
        printf("\n");
    }
    printf("\n\n");

    printf("       1   2   3   4   5   6   7   8   9   10  11  12  13  14 15  16\n\n");
    printf("      ---------------------------------------------------------------\n");
    for (int i = 0; i < 16; i++) {
        if (i < 9) {
            printf(" %d-  ", ++i);
        }
        else {
            printf(" %d- ", ++i);
        }
        i--;
        for (int j = 0; j < 16; j++) {
            printf("|");
            if (khooneh[i][j] == 0) {
                printf("   ");
                continue;
            }
            if (khooneh[i][j] == 1) {
                printf(" \033[1;34m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 2) {
                printf(" \033[1;32m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 3) {
                printf(" \033[1;31m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 4) {
                printf(" \033[1;33m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 5) {
                printf(" \033[1;36m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 6) {
                printf(" \033[1;35m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            if (khooneh[i][j] == 7) {
                printf(" \033[1;37m%d\033[0m ", khooneh[i][j]);
                continue;
            }
            else {
                printf(" \033[1;35m@\033[0m ");
                continue;
            }
        }
        printf("|");
        printf("\n");
        printf("      ---------------------------------------------------------------");
        printf("\n");

    }

}

void game16() {
    int khooneh[16][16] = { 0 };
}


int selectmode() {
    for (;;) {
        system("cls||clear");
        printf("\n\n\n\n\033[1;32m%WHICH MODE YOU WANNA PLAY?\033[0m");
        printf("\n\033[1;32m%(1)-8*8\033[0m");
        printf("\n\033[1;32m%(2)-16*16\033[0m\n");
        char choose[50];
        gets(choose);
        if (strlen(choose) > 2) {
            int i = 0;
            while (1) {

                char t = choose[i];
                if (t == '\0')break;
                i++;
            }
            inputEROR();
            continue;
        }
        else if (choose[0] == '1' || choose[0] == '2') {
            return (int)choose[0] - 48;
        }
        else {
            inputEROR();
            continue;
        }
    }

}
int Menu() {
    for (;;) {
        printf("\033[1;33m User:%s       \033[0m\n", playername);
        _sleep(250);
        printf("\033[1;35m [Total game played]=%d       \033[0m\n", (bordbakht[1] + bordbakht[0]));
        printf("\t\033[1;32m [Win]=%d       \033[0m", bordbakht[1]);
        printf("\033[1;31m [lose]=%d       \033[0m", bordbakht[0]);
        _sleep(250);
        printf("\n\n\033[1;34m Menu:\033[0m");
        printf("\n\n\n\033[1;34m (1)-Play\033[0m");
        printf("\n\033[1;34m (2)-Change username\033[0m");
        printf("\n\033[1;34m (3)-New player\033[0m");
        printf("\n\033[1;34m (4)-EXIT:(\033[0m\n");
        char choose[50];
        gets(choose);
        if (strlen(choose) > 2) {
            int i = 0;
            while (1) {

                char t = choose[i];
                if (t == '\0')break;
                i++;
            }
            inputEROR();
            continue;
        }
        else if (choose[0] == '1' || choose[0] == '2' || choose[0] == '3' || choose[0] == '4') {
            return (int)choose[0] - 48;
        }
        else {
            inputEROR();
            continue;
        }
    }
}

int main() {
    account();
    for(;;){
        system("cls||clear");
        int choose = Menu();
        if (choose == 2) {
            changename();
            printf("\033[1;33m%User name changed to:  %s\033[0m", playername);
            _sleep(3000);
            system("cls||clear");
            continue;
        }
        if (choose == 3) {
            newplayer();
            printf("\033[1;33m%Hi  %s\033[0m", playername);
            _sleep(3000);
            system("cls||clear");
            continue;
        }
        if (choose == 4) {
            break;
        }
        if (choose == 1) {
            int selectedmode = selectmode();
            system("cls||clear");
            if (selectedmode == 1) {
                flag8 = 10;
                game8();
            }
            else {
                flag16 = 40;
                game16();
            }
            system("cls||clear");
            continue;
        }
        else {
            inputEROR();
        }
    }
}