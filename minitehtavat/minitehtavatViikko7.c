#include <stdio.h>
#include <string.h>
#include <ctype.h>



void tehtava48(void);
void tehtava49(void);
void tehtava50(void);
void tehtava51(void);
void tehtava52(void);
void tehtava53(void);
void tehtava54(void);
void tehtava55(void);
void tehtava56(void);

int mainViikko7(void){
    //tehtava48();
    //tehtava49();
    //tehtava50();
    //tehtava51();
    //tehtava52();
    //tehtava53();
    tehtava54();
    //tehtava55();
    //tehtava56();
}

void tehtava48(){
    char string[100];
    fgets(string, 100, stdin);
    for (int i = 0; i < strlen(string); ++i) {
        string[i] = tolower(string[i]);
    }
    printf("%s", string);
    for (int i = 0; i < strlen(string); ++i) {
        string[i] = toupper(string[i]);
    }
    printf("%s", string);
}


void tehtava49(){
    char strings[5][100];

    for (int i = 0; i < 5; ++i) {
        fgets(strings[i], 100, stdin);
    }
    for (int i = 0; i < 5; ++i) {
        if(tolower(strings[i][0]) == 'a'){
            printf("a-merkilla alkava merkkijono %s", strings[i]);
        }
    }
}

void tehtava50(){
    char strings[5][100];

    for (int i = 0; i < 5; ++i) {
        fgets(strings[i], 100, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0';
    }
    for (int i = 0; i < 5; ++i) {
        if (tolower(strings[i][strlen(strings[i]) - 1]) == 'n' && tolower(strings[i][strlen(strings[i]) - 2]) == 'e') {
            printf("en-merkkijonoon paattyva merkkijono %s \n", strings[i]);
        }
    }
}

void tehtava51(){
    char aakkoset[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g' , 'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'o' ,'p' ,'q', 'r', 's', 't', 'u' ,'v', 'w', 'x' ,'y' , 'z'};
    int aakkosMaara[26] = {0};
    char strings[3][100];

    for (int i = 0; i < 3; ++i) {
        fgets(strings[i], 100, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0';
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < strlen(strings[i]); ++j) {
            for (int k = 0; k < 26; ++k) {
                if (strings[i][j] == aakkoset[k]){
                    aakkosMaara[k] ++;
                }
            }
        }
    }

    printf("Aakkoset \t Kpl \n");
    for (int i = 0; i < 26; ++i) {
        printf("%-8c \t %i \n", aakkoset[i], aakkosMaara[i]);
    }
}
void poistaValilyonnit(char input[], char output[]);
void tehtava52(){
    char strings[3][100], noSpaces[3][100];

    for (int i = 0; i < 3; ++i) {
        fgets(strings[i], 100, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0';
    }
    for (int i = 0; i < 3; ++i) {
        poistaValilyonnit(strings[i], noSpaces[i]);
        printf("%s \n", noSpaces[i]);
    }
}
void poistaValilyonnit(char input[], char output[]){
    int valilyontimaara = 0;
    for (int i = 0; i < strlen(input); ++i) {
        if (input[i] != ' '){
            output[i - valilyontimaara] = input[i];
        }
        else valilyontimaara ++;
    }
    output[strlen(input) - valilyontimaara + 1] = '\0';
}

void etsiMerkkijonoAlusta(char word1[] , char word2[] , char output[]);
void tehtava53(){

    char mjono1[100];
    char mjono2[100];
    char loydetty[10]={'\0'};
    fgets(mjono1, 100, stdin);
    mjono1[strcspn(mjono1, "\n")] = '\0';
    fgets(mjono2, 100, stdin);
    mjono2[strcspn(mjono2, "\n")] = '\0';


    etsiMerkkijonoAlusta(mjono1, mjono2, loydetty);
    printf("%s", loydetty);
}

void etsiMerkkijonoAlusta(char word1[] , char word2[] , char output[]) {
    int shortest, matchFlag = 1, matches = 0;
    if(strlen(word1) > strlen(word2)) shortest = strlen(word2);
    else shortest = strlen(word1);

    for (int i = 0; i < shortest; ++i) {
        if(matchFlag && word1[i] == word2[i]){
            output[i] = word1[i];
            matches ++;
        }
        else matchFlag = 0;
    }
    output[matches] = '\0';
}

void tehtava54(){
    char luvut[2][100];
    int luku1, luku2, summa;
    for (int i = 0; i < 2; ++i) {
        printf("Anna %i. luku >", i + 1);
        fgets(luvut[i], 100, stdin);
        luvut[i][strcspn(luvut[i], "\n")] = '\0';
    }
    sscanf(luvut[0], "%i", &luku1);
    sscanf(luvut[1], "%i", &luku2);
    summa = luku1 + luku2;

    printf("Lukujen %i ja %i summa on %i", luku1, luku2, summa);
}