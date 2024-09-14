///Library includes
#include<stdio.h>
#include<stdlib.h>
#include "time.h"
#include "string.h"

///Global variables
char playername[30];
int LooseWin[2] = { 0 , 0 };
int flag8 = 10;
int flag16 = 40;


void inputEROR() {//This function was created to display any user's input errors.
    system("cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\ \033[1;31m WRONG INPUTE!!!!TRY AGAIN\033[0m");
    _sleep(1500);
    system("cls||clear");
}
void winEffect() {
    system("cls||clear");
    for (int i = 1; i < 5; i++) {
        system("cls||clear");
        printf("\033[48;2;20;220;20m");
        _sleep(300);
        system("cls||clear");
        printf("\033[48;2;1;1;1m");
        _sleep(300);
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t \033[1;32mCogratulations!!!\033[0m");
    _sleep(4000);
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
    LooseWin[0] = 0;
    LooseWin[1] = 0;
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
void printtable8(char display[8][8], int map[8][8], int flag) {
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
    printf("Input format : Row Column (R for flag/L for open)=>2 3 R  :");


}


void bomblocation8(int map[8][8], int lower_bound, int upper_bound) {
    //This function randomly distributes bombs in the game cells
    for (int bombcount = 10; bombcount > 0; bombcount--) {
        int numi = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;     // i
        int numj = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;     // j
        int bomb_counter = 0;
        for (int i = 0; i < 8; i++) {
            if (map[i][numj] == 9) {
                bomb_counter++;                       //this variable controls the bomb's count in each column
            }
        }
        if (bomb_counter >= 3) {
            bombcount++;
            continue;
        }
        if (map[numi][numj] != 9) {
            map[numi][numj] = 9;
        }
        else { bombcount++; continue; }
    }

}
void bomb_attached8(int map[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (map[i][j] == 9)continue;
            if (j != 7 && map[i][j + 1] == 9) {
                map[i][j]++;
            }
            if (j != 0 && map[i][j - 1] == 9) {
                map[i][j]++;
            }
            if (i != 7 && map[i + 1][j] == 9) {
                map[i][j]++;
            }
            if (i != 7 && j != 0 && map[i + 1][j - 1] == 9) {
                map[i][j]++;
            }
            if (i != 7 && j != 7 && map[i + 1][j + 1] == 9) {
                map[i][j]++;
            }
            if (i != 0 && map[i - 1][j] == 9) {
                map[i][j]++;
            }
            if (i != 0 && j != 7 && map[i - 1][j + 1] == 9) {
                map[i][j]++;
            }
            if (i != 0 && j != 0 && map[i - 1][j - 1] == 9) {
                map[i][j]++;
            }

        }
    }

}

void numbers_attached_to_zero8(int map[8][8], char display[8][8], int i, int j) {
    display[i][j] = map[i][j] + 48;
    if (j != 7) {
        display[i][j + 1] = map[i][j + 1] + 48;
    }
    if (j != 0) {
        display[i][j - 1] = map[i][j - 1] + 48;
    }
    if (i != 7) {
        display[i + 1][j] = map[i + 1][j] + 48;
    }
    if (i != 7 && j != 0) {
        display[i + 1][j - 1] = map[i + 1][j - 1] + 48;
    }
    if (i != 7 && j != 7) {
        display[i + 1][j + 1] = map[i + 1][j + 1] + 48;
    }
    if (i != 0) {
        display[i - 1][j] = map[i - 1][j] + 48;
    }
    if (i != 0 && j != 7) {
        display[i - 1][j + 1] = map[i - 1][j + 1] + 48;
    }
    if (i != 0 && j != 0) {
        display[i - 1][j - 1] = map[i - 1][j - 1] + 48;
    }
}
void openzero8(int map[8][8], char display[8][8], int trouble[8][8], int i, int j) {
    trouble[i][j] = 1;

    if (map[i][j] == 0) {
        numbers_attached_to_zero8(map, display, (i), (j));
        if (i != 0 && trouble[(i - 1)][(j)] != 1) {
            openzero8(map, display, trouble, (i - 1), (j));

        }
        if (i != 0 && j != 0 && trouble[(i - 1)][(j - 1)] != 1) {
            openzero8(map, display, trouble, (i - 1), (j - 1));

        }
        if (i != 7 && j != 7 && trouble[(i + 1)][(j + 1)] != 1) {

            openzero8(map, display, trouble, (i + 1), (j + 1));

        }
        if (i != 7 && j != 0 && trouble[(i + 1)][(j - 1)] != 1) {

            openzero8(map, display, trouble, (i + 1), (j - 1));

        }
        if (i != 0 && j != 7 && trouble[(i - 1)][(j + 1)] != 1) {

            openzero8(map, display, trouble, (i - 1), (j + 1));

        }
        if (j != 0 && trouble[i][(j - 1)] != 1) {

            openzero8(map, display, trouble, (i), (j - 1));

        }
        if (j != 7 && trouble[i][(j + 1)] != 1) {

            openzero8(map, display, trouble, (i), (j + 1));

        }
        if (i != 7 && trouble[(i + 1)][j] != 1) {

            openzero8(map, display, trouble, (i + 1), (j));
        }

    }
    if (map[i][j] == 0) {
        numbers_attached_to_zero8(map, display, (i), (j));
        if (i != 7 && trouble[(i + 1)][j] != 1) {

            openzero8(map, display, trouble, (i + 1), (j));
        }
        if (i != 0 && j != 0 && trouble[(i - 1)][(j - 1)] != 1) {
            openzero8(map, display, trouble, (i - 1), (j - 1));

        }
        if (i != 7 && j != 7 && trouble[(i + 1)][(j + 1)] != 1) {

            openzero8(map, display, trouble, (i + 1), (j + 1));

        }
        if (i != 7 && j != 0 && trouble[(i + 1)][(j - 1)] != 1) {

            openzero8(map, display, trouble, (i + 1), (j - 1));

        }
        if (i != 0 && j != 7 && trouble[(i - 1)][(j + 1)] != 1) {

            openzero8(map, display, trouble, (i - 1), (j + 1));

        }
        if (j != 0 && trouble[i][(j - 1)] != 1) {

            openzero8(map, display, trouble, (i), (j - 1));

        }
        if (j != 7 && trouble[i][(j + 1)] != 1) {

            openzero8(map, display, trouble, (i), (j + 1));

        }
        if (i != 0 && trouble[(i - 1)][(j)] != 1) {
            openzero8(map, display, trouble, (i - 1), (j));

        }


    }

}

int checkwin8(char display[8][8], int map[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (map[i][j] == 9 && display[i][j] != 'F')
                return 0;
        }

    }
    return 1;
}
void lose8(int map[8][8], char display[8][8]) {
    system("cls||clear");
    for (int i = 0; i < 5; i++) {
        system("cls||clear");
        printf("\033[48;2;205;50;50m");
        _sleep(10);
        system("cls||clear");
        printf("\033[48;2;1;1;1m");
        _sleep(10);
    }
    system("cls||clear");
    for (long int i = 1; i < 101; i++) {
        printf("\033[1;31m%YOU LOST!!!!!!			 \033[0m");
        _sleep(10);
    }
    _sleep(2000);
    system("cls||clear");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (map[i][j] == 9) {
                display[i][j] = '@';
            }

        }

    }
    printtable8(display, map, flag8);
    char trash[20];
    gets(trash);
    system("cls||clear");
}
int user_controler8(int map[8][8], char display[8][8], int trouble[8][8]) {
    int i, j;
    char RL;
    int WL = 0;
    for (;;) {
        char input[50];
        gets(input);
        if (strlen(input) > 6) {
            int i = 0;
            while (1) {
                char t = input[i];
                i++;
                if (t == '\0')break;
            }
            inputEROR();
            printtable8(display, map, flag8);
            continue;
        }
        else {
            i = (int)input[0] - 48;
            j = (int)input[2] - 48;
            RL = input[4];
        }
        if (i > 8 || j > 8 || i < 1 || j < 1) {
            int i = 0;
            while (1) {
                char t = input[i];
                i++;
                if (t == '\0')break;
            }
            inputEROR();
            printtable8(display, map, flag8);
            continue;
        }
        if (RL == 'L' || RL == 'l') {
            if (display[(i - 1)][(j - 1)] == 'F') {

                inputEROR();
                printtable8(display, map, flag8);
                continue;
            }
            if (map[(i - 1)][(j - 1)] == 9) {
                display[(i - 1)][(j - 1)] = '@';
                lose8(map, display);
                WL = 0;
                break;
            }
            else if (map[(i - 1)][(j - 1)] == 0) {
                openzero8(map, display, trouble, (i - 1), (j - 1));
                openzero8(map, display, trouble, (i - 1), (j - 1));

            }
            else { display[(i - 1)][(j - 1)] = map[(i - 1)][(j - 1)] + 48; }
            system("cls||clear");
            printtable8(display, map, flag8);
            continue;
        }
        if (RL == 'R' || RL == 'r') {
            if (display[(i - 1)][(j - 1)] >= '0' && display[(i - 1)][(j - 1)] <= '7') {

                inputEROR();
                system("cls||clear");
                printtable8(display, map, flag8);
                continue;
            }
            else if (display[(i - 1)][(j - 1)] == 'F') {
                display[(i - 1)][(j - 1)] = 254;
                flag8++;
                system("cls||clear");
                printtable8(display, map, flag8);
                continue;
            }
            else {
                if (flag8 == 0) {
                    inputEROR();
                    system("cls||clear");
                    printtable8(display, map, flag8);
                    continue;
                }
                display[(i - 1)][(j - 1)] = 'F';
                flag8--;
                system("cls||clear");
                printtable8(display, map, flag8);
                if (flag8 != 0) {
                    continue;
                }

            }


        }
        if (flag8 == 0) {
            int t = checkwin8(display, map);
            if (t == 1) {
                winEffect();
                WL = 1;
            }
            else {
                continue;
            }

        }
        if (WL == 1) {
            break;
        }
        inputEROR();
        printtable8(display, map, flag8);
        continue;
    }
    return WL;
}
void game8() {
    int map[8][8] = { 0 };
    int lower_bound = 0;
    int upper_bound = 7;
    bomblocation8(map, lower_bound, upper_bound);
    bomb_attached8(map);
    char display[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            display[i][j] = 254;
        }
    }
    printtable8(display, map, flag8);
    int trouble[8][8] = { 0 };
    int wl = user_controler8(map, display, trouble);
    if (wl == 0) {
        LooseWin[0]++;
    }
    else if (wl == 1) {
        LooseWin[1]++;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

/// 16*16 Mode
void printtable16(char display[16][16], int map[16][16]) {
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

    printf("Input format : Row Column (R for flag/L for open)=>2 3 R  :");
}

void bomblocation16(int map[16][16], int lower_bound, int upper_bound) {
    //This function randomly distributes bombs in the game cells
    for (int bombcount = 40; bombcount > 0; bombcount--) {

        int numi = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;     // i
        int numj = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;     // j
        int bomb_counter = 0;
        for (int i = 0; i < 16; i++) {
            if (map[i][numj] == 9) {
                bomb_counter++;                               //this variable controls the bomb's count in each column
            }
        }
        if (bomb_counter >= 3) {
            bombcount++;
            continue;
        }
        if (map[numi][numj] != 9) {
            map[numi][numj] = 9;
        }
        else { bombcount++; continue; }
    }

}
void bomb_attached16(int map[16][16]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (map[i][j] == 9)continue;
            if (j != 15 && map[i][j + 1] == 9) {
                map[i][j]++;
            }
            if (j != 0 && map[i][j - 1] == 9) {
                map[i][j]++;
            }
            if (i != 15 && map[i + 1][j] == 9) {
                map[i][j]++;
            }
            if (i != 15 && j != 0 && map[i + 1][j - 1] == 9) {
                map[i][j]++;
            }
            if (i != 15 && j != 15 && map[i + 1][j + 1] == 9) {
                map[i][j]++;
            }
            if (i != 0 && map[i - 1][j] == 9) {
                map[i][j]++;
            }
            if (i != 0 && j != 15 && map[i - 1][j + 1] == 9) {
                map[i][j]++;
            }
            if (i != 0 && j != 0 && map[i - 1][j - 1] == 9) {
                map[i][j]++;
            }

        }
    }

}

void numbers_attached_to_zero16(int map[16][16], char display[16][16], int i, int j) {
    display[i][j] = map[i][j] + 48;
    if (j != 15) {
        display[i][j + 1] = map[i][j + 1] + 48;
    }
    if (j != 0) {
        display[i][j - 1] = map[i][j - 1] + 48;
    }
    if (i != 15) {
        display[i + 1][j] = map[i + 1][j] + 48;
    }
    if (i != 15 && j != 0) {
        display[i + 1][j - 1] = map[i + 1][j - 1] + 48;
    }
    if (i != 15 && j != 7) {
        display[i + 1][j + 1] = map[i + 1][j + 1] + 48;
    }
    if (i != 0) {
        display[i - 1][j] = map[i - 1][j] + 48;
    }
    if (i != 0 && j != 15) {
        display[i - 1][j + 1] = map[i - 1][j + 1] + 48;
    }
    if (i != 0 && j != 0) {
        display[i - 1][j - 1] = map[i - 1][j - 1] + 48;
    }
}
void openzerot16(int map[16][16], char display[16][16], int trouble[16][16], int i, int j) {
    trouble[i][j] = 1;

    if (map[i][j] == 0) {
        numbers_attached_to_zero16(map, display, (i), (j));
        if (i != 0 && trouble[(i - 1)][(j)] != 1) {
            openzerot16(map, display, trouble, (i - 1), (j));

        }
        if (i != 0 && j != 0 && trouble[(i - 1)][(j - 1)] != 1) {
            openzerot16(map, display, trouble, (i - 1), (j - 1));

        }
        if (i != 15 && j != 15 && trouble[(i + 1)][(j + 1)] != 1) {

            openzerot16(map, display, trouble, (i + 1), (j + 1));

        }
        if (i != 15 && j != 0 && trouble[(i + 1)][(j - 1)] != 1) {

            openzerot16(map, display, trouble, (i + 1), (j - 1));

        }
        if (i != 0 && j != 15 && trouble[(i - 1)][(j + 1)] != 1) {

            openzerot16(map, display, trouble, (i - 1), (j + 1));

        }
        if (j != 0 && trouble[i][(j - 1)] != 1) {

            openzerot16(map, display, trouble, (i), (j - 1));

        }
        if (j != 7 && trouble[i][(j + 1)] != 1) {

            openzerot16(map, display, trouble, (i), (j + 1));

        }
        if (i != 15 && trouble[(i + 1)][j] != 1) {

            openzerot16(map, display, trouble, (i + 1), (j));
        }

    }


}

int checkwin16(char display[16][16], int map[16][16]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (map[i][j] == 9 && display[i][j] != 'F')
                return 0;
        }

    }
    return 1;
}
void lose16(int map[16][16], char display[16][16]) {
    system("cls||clear");
    for (int i = 0; i < 5; i++) {
        system("cls||clear");
        printf("\033[48;2;205;50;50m");
        _sleep(10);
        system("cls||clear");
        printf("\033[48;2;1;1;1m");
        _sleep(10);
    }
    system("cls||clear");
    for (long int i = 1; i < 101; i++) {
        printf("\033[1;31m%YOU LOST!!!!!!			 \033[0m");
        _sleep(10);
    }
    _sleep(2000);
    system("cls||clear");

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (map[i][j] == 9) {
                display[i][j] = '@';
            }

        }

    }
    printtable16(display, map);
    char trash[20];
    gets(trash);
}
int user_controler16(int map[16][16], char display[16][16], int trouble[16][16]) {
    int i, j;
    char RL;
    int WL = 0;
    for (;;) {
        scanf("%d %d %c", &i, &j, &RL);
        char trash[50];
        gets(trash);
        if (strlen(trash) != 0) {
            inputEROR();
            printtable16(display, map);
            continue;
        }
        if (i > 16 || j > 16 || i < 1 || j < 1) {
            inputEROR();
            printtable16(display, map);
            continue;
        }
        if (RL == 'L' || RL == 'l') {
            if (display[(i - 1)][(j - 1)] == 'F') {
                inputEROR();
                printtable16(display, map);
                continue;
            }
            if (map[(i - 1)][(j - 1)] == 9) {
                display[(i - 1)][(j - 1)] = '@';
                lose16(map, display);
                WL = 0;
                break;
            }
            else if (map[(i - 1)][(j - 1)] == 0) {
                openzerot16(map, display, trouble, (i - 1), (j - 1));
                openzerot16(map, display, trouble, (i - 1), (j - 1));
            }
            else { display[(i - 1)][(j - 1)] = map[(i - 1)][(j - 1)] + 48; }
            system("cls||clear");
            printtable16(display, map);
            continue;
        }
        if (RL == 'R' || RL == 'r') {
            if (display[(i - 1)][(j - 1)] >= '0' && display[(i - 1)][(j - 1)] <= '7') {
                inputEROR();
                system("cls||clear");
                printtable16(display, map);
                continue;
            }
            else if (display[(i - 1)][(j - 1)] == 'F') {
                display[(i - 1)][(j - 1)] = 254;
                flag16++;
                system("cls||clear");
                printtable16(display, map);
                continue;
            }
            else {
                if (flag16 == 0) {
                    inputEROR();
                    system("cls||clear");
                    printtable16(display, map);
                    continue;
                }
                display[(i - 1)][(j - 1)] = 'F';
                flag16--;
                system("cls||clear");
                printtable16(display, map);
                if (flag16 != 0) {
                    continue;
                }

            }


        }
        if (flag16 == 0) {
            int t = checkwin16(display, map);
            if (t == 1) {
                winEffect();
                WL = 1;
                break;
            }
            else {
                continue;
            }

        }
        if (WL == 1) {
            break;
        }
        inputEROR();
        printtable16(display, map);
        continue;
    }
    return WL;
}



void game16() {
    int map[16][16] = { 0 };
    int lower_bound = 0;
    int upper_bound = 15;
    bomblocation16(map, lower_bound, upper_bound);
    bomb_attached16(map);
    char display[16][16];
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            display[i][j] = 254;
        }
    }
    printtable16(display, map);
    int trouble[16][16] = { 0 };
    int wl = user_controler16(map, display, trouble);
    if (wl == 0) {
        LooseWin[0]++;
    }
    else if (wl == 1) {
        LooseWin[1]++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
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
        printf("\033[1;35m [Total game played]=%d       \033[0m\n", (LooseWin[1] + LooseWin[0]));
        printf("\t\033[1;32m [Win]=%d       \033[0m", LooseWin[1]);
        printf("\033[1;31m [lose]=%d       \033[0m", LooseWin[0]);
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
void wellcome() {
    system("cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t");
    char wellcome[30] = " WELLCOME TO  MINESWEEPER";
    for (int i = 0; i < 25; i++) {
        printf("\033[1;32m%c\033[0m", wellcome[i]);
        _sleep(85);
    }
    printf("\n\n\t\t\t\t\t\t\t\t");
    char creator[35] = "DEVELOPED BY ALISHA";
    for (int i = 0; i < 19; i++) {
        printf("\033[1;34m%c\033[0m", creator[i]);
        _sleep(200);
    }
    _sleep(4000);
    system("cls||clear");
}
int main() {
    srand(time(NULL));
    printf("\033[48;2;20;20;250m");
    wellcome();
    account();
    printf("\033[1;33m%Hi %s\033[0m", playername);
    _sleep(1000);
    system("cls||clear");
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