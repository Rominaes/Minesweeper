#include<stdio.h>
#include<stdlib.h>
#include "time.h"
#include "string.h"

char playername[30];
int bordbakht[2] = { 0 , 0 };

void inputEROR() {//This function was created to display any user's input errors.
    system("cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\ \033[1;31m WRONG INPUTE!!!!TRY AGAIN\033[0m");
    _sleep(1500);
    system("cls||clear");
}


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


        }
        else {
            inputEROR();
        }
    }
}