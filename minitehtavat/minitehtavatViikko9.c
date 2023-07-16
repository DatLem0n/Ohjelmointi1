#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void tehtava59();
void tehtava60();
void tehtava61();
void tehtava62();

int mainViikko9(void){
    //tehtava59();
    //tehtava60();
    tehtava61();
    //tehtava62();
}


typedef struct{
    char nimi[100];
    int voitot;
    int tappiot;
}Joukkue;

int joukkueComparer(const void* a, const void* b) {
    const Joukkue* team1 = (const Joukkue*)a;
    const Joukkue* team2 = (const Joukkue*)b;

    int scoreA = team1->voitot - team1->tappiot;
    int scoreB = team2->voitot - team2->tappiot;

    return scoreB - scoreA;
}


void flush();
void tehtava59(){
    int joukkueMaara;
    printf("montako joukkuetta > ");
    scanf(" %i", &joukkueMaara);
    flush();
    Joukkue joukkueet[joukkueMaara];

    for (int i = 0; i < joukkueMaara; ++i) {
        printf("Anna joukkueen nimi >");
        fgets(joukkueet[i].nimi, 100, stdin);
        joukkueet[i].nimi[strcspn(joukkueet[i].nimi, "\n")] = 0;
        printf("Anna joukkueen voittojen maara >");
        scanf(" %i", &joukkueet[i].voitot);
        flush();
        printf("Anna joukkueen tappioiden maara >");
        scanf(" %i", &joukkueet[i].tappiot);
        flush();
    }

    printf("****************************************\n"
           "         TULOSLISTA\n"
           "**************************************** \n");
    qsort(joukkueet, joukkueMaara, sizeof(Joukkue), joukkueComparer);
    for (int i = 0; i < joukkueMaara; ++i) {
        printf("%i. joukkue: \t %s tilanne: %i voittoa ja %i tappiota \n", i + 1, joukkueet[i].nimi, joukkueet[i].voitot, joukkueet[i].tappiot);
    }
}


typedef struct{
    int x, y;
}piste;

double laskeEtaisyys(piste, piste);

void tehtava60(){
    int pisteidenMaara = 5;
    piste pisteet[pisteidenMaara];
    double totalDistance = 0, directDistance = 0;

    for (int i = 0; i < pisteidenMaara; ++i) {
        printf("anna pisteen x koordinaatti");
        scanf("%i", &pisteet[i].x);
        printf("anna pisteen y koordinaatti");
        scanf("%i", &pisteet[i].y);
    }

    for (int i = 0; i < pisteidenMaara - 1; ++i) {
        totalDistance += laskeEtaisyys(pisteet[i], pisteet[i + 1]);
    }
    directDistance = laskeEtaisyys(pisteet[0], pisteet[pisteidenMaara - 1]);

    printf("Etaisyys mutkitellen on %.03lf \n", totalDistance);
    printf("Alku ja loppupisteiden valinen etaisyys on %.03lf", directDistance);
}
double laskeEtaisyys(piste piste1, piste piste2){
    return sqrt(pow(piste1.x - piste2.x, 2) + pow(piste1.y - piste2.y, 2));
}






#define JASENMAARA 100
typedef struct {
    char etunimi[100];
    char sukunimi[100];
    int jasennumero;
    int liittymisvuosi;
    int jasenmaksut[5];
}Jasen;
void flush();
void printUser(const Jasen *jasenLista, int index);
int menu(int *selection);

void tehtava61() {
    int selection, jasenLkm = 0, kaytetytJasenNrot[JASENMAARA] = {0}, poistetutJasenNrot[JASENMAARA], poistettujenMaara = 0;
    Jasen jasenet[JASENMAARA];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentYear = tm.tm_year + 1900;

    do {
        selection = menu(&selection);
        switch (selection) {
            case 1: {
                char tempStr[100], splitter[2] = " ", *nimi;
                printf("Anna jasenen Etu- ja Sukunimi > ");
                fgets(tempStr, 100, stdin);
                tempStr[strcspn(tempStr, "\n")] = 0;
                nimi = strtok(tempStr, splitter);
                strcpy(jasenet[jasenLkm].etunimi, nimi);
                nimi = strtok(NULL, splitter);
                strcpy(jasenet[jasenLkm].sukunimi, nimi);

                int jasennumero;
                int used;
                do {
                    printf("Anna jasennumero > ");
                    scanf("%i", &jasennumero);
                    flush();
                    used = 0;
                    for (int i = 0; i < JASENMAARA; ++i) {
                        if(kaytetytJasenNrot[i] == jasennumero){
                            used = 1;
                        }
                    }
                    if(used == 0){
                        jasenet[jasenLkm].jasennumero = jasennumero;
                        kaytetytJasenNrot[jasenLkm] = jasennumero;
                    }
                }while(used);


                int liittymisvuosi;
                printf("Anna liittymisvuosi > ");
                scanf("%i", &liittymisvuosi);
                flush();
                jasenet[jasenLkm].liittymisvuosi = liittymisvuosi;
                int jasenvuodet = currentYear - liittymisvuosi;
                if (jasenvuodet < 5) {
                    for (int i = 0; i < jasenvuodet; ++i) {
                        printf("Anna vuoden %i jasenmaksu > ", currentYear - jasenvuodet + i);
                        scanf("%i", &jasenet[jasenLkm].jasenmaksut[i]);
                        flush();
                    }
                } else {
                    for (int i = 0; i < 5; ++i) {
                        printf("Anna vuoden %i jasenmaksu > ", currentYear - 5 + i);
                        scanf("%i", &jasenet[jasenLkm].jasenmaksut[i]);
                        flush();
                    }
                }

                jasenLkm++;
            }break;
            case 2: {
                int valinta;
                printf("Anna poistettavan jasenen jasennumero > ");
                scanf("%i", &valinta);
                for (int i = 0; i < JASENMAARA; ++i) {
                    if (kaytetytJasenNrot[i] == valinta) {
                        strcpy(jasenet[i].etunimi, "NULL");
                        strcpy(jasenet[i].sukunimi, "NULL");
                        jasenet[i].jasennumero = 0;
                        jasenet[i].liittymisvuosi = 0;
                        for (int j = 0; j < 5; ++j) {
                            jasenet[i].jasenmaksut[j] = 0;
                        }
                        kaytetytJasenNrot[i] = 0;
                        poistettujenMaara ++;
                        poistetutJasenNrot[poistettujenMaara] = valinta;

                    }
                }

            }break;
            case 3: {
                int valinta;
                printf("Anna muutettavan jasenen jasennumero > ");
                scanf("%i", &valinta);
                flush();
                for (int i = 0; i <JASENMAARA; ++i) {
                    if (kaytetytJasenNrot[i] == valinta) {
                        int valinta2;
                        printf("1 Muuta etunimi\n"
                               "2 Muuta sukunimi\n"
                               "3 Muuta jasennumero\n"
                               "4 Muuta liittymisvuosi\n"
                               "5 Muuta jasenmaksutietoja\n");

                        do {
                            printf("Valintasi > ");
                            scanf("%i", &valinta2);
                            flush();
                        }while(valinta2 > 5 || valinta2 < 1);
                        switch (valinta2) {
                            case 1:{
                                printf("Anna uusi etunimi > ");
                                fgets(jasenet[i].etunimi, 100, stdin);
                                jasenet[i].etunimi[strcspn(jasenet[i].etunimi, "\n")] = 0;
                            }break;
                            case 2:{
                                printf("Anna uusi sukunimi > ");
                                fgets(jasenet[i].sukunimi, 100, stdin);
                                jasenet[i].sukunimi[strcspn(jasenet[i].sukunimi, "\n")] = 0;
                            }break;
                            case 3:{
                                int jasennumero;
                                int used;
                                do {
                                    printf("Anna jasennumero > ");
                                    scanf("%i", &jasennumero);
                                    flush();
                                    used = 0;
                                    for (int i = 0; i < JASENMAARA; ++i) {
                                        if(kaytetytJasenNrot[i] == jasennumero){
                                            used = 1;
                                        }
                                    }
                                    if(used == 0){
                                        jasenet[jasenLkm].jasennumero = jasennumero;
                                        kaytetytJasenNrot[jasenLkm] = jasennumero;
                                    }
                                }while(used);
                            }break;
                            case 4:{
                                printf("Anna uusi liittymisvuosi > ");
                                scanf("%i", &jasenet[i].liittymisvuosi);
                                flush();
                            }break;
                            case 5: {
                                printf("Anna uusi etunimi");
                                int jasenvuodet = currentYear - jasenet[i].liittymisvuosi;
                                if (jasenvuodet < 5) {
                                    for (int j = 0; j < jasenvuodet; ++j) {
                                        printf("Anna vuoden %i jasenmaksu > ", currentYear - jasenvuodet + i);
                                        scanf("%i", &jasenet[i].jasenmaksut[j]);
                                        flush();
                                    }
                                } else {
                                    for (int j = 0; j < 5; ++j) {
                                        printf("Anna vuoden %i jasenmaksu > ", currentYear - 5 + i);
                                        scanf("%i", &jasenet[i].jasenmaksut[j]);
                                        flush();
                                    }
                                }
                            }break;
                        }
                    }
                }
            }break;
            case 4:{
                int valinta;
                printf("Anna tulostettavan jasenen jasennumero > ");
                scanf("%i", &valinta);
                for (int i = 0; i < JASENMAARA; ++i) {
                    if(kaytetytJasenNrot[i] == valinta){
                        printUser(jasenet, i);
                    }
                }
            }break;
            case 5:{
                int poistettu;
                for (int i = 0; i < jasenLkm; ++i) {
                    poistettu = 0;
                    for (int j = 0; j < poistettujenMaara; ++j) {
                        if(jasenet[i].jasennumero == poistetutJasenNrot[j]){
                            poistettu = 1;
                        }
                    }
                    if (poistettu == 0){
                        printUser(jasenet, i);
                    }
                }
            }break;
            case 6:{
                int valinta;
                printf("1 Haku etunimella\n"
                       "2 Haku sukunimella\n"
                       "3 Haku jasennumerolla\n"
                       "4 Haku liittymisvuodella\n"
                       "5 Haku jasenmaksurastien perusteella");
                printf("Valintasi > ");
                scanf("%i", &valinta);
                flush();
                switch (valinta) {
                    case 1:{
                        char valinta2[100];
                        printf("Anna etunimi > ");
                        fgets(valinta2, 100, stdin);
                        valinta2[strcspn(valinta2, "\n")] = 0;
                        flush();
                        for (int i = 0; i < jasenLkm; ++i) {
                            if(jasenet[i].etunimi == valinta2){
                                printUser(jasenet, i);
                            }
                        }
                    }break;
                    case 2:{
                        char valinta2[100];
                        printf("Anna sukunimi > ");
                        fgets(valinta2, 100, stdin);
                        valinta2[strcspn(valinta2, "\n")] = 0;
                        flush();
                        for (int i = 0; i < jasenLkm; ++i) {
                            if(jasenet[i].sukunimi == valinta2){
                                printUser(jasenet, i);
                            }
                        }
                    }break;
                    case 3:{
                        int valinta2;
                        printf("Anna jasennumero > ");
                        scanf("%i", &valinta2);
                        flush();
                        for (int i = 0; i < jasenLkm; ++i) {
                            if(jasenet[i].jasennumero == valinta2){
                                printUser(jasenet, i);
                            }
                        }
                    }break;
                    case 4:{
                        int valinta2;
                        printf("Anna liittymisvuosi > ");
                        scanf("%i", &valinta2);
                        flush();
                        for (int i = 0; i < jasenLkm; ++i) {
                            if(jasenet[i].liittymisvuosi == valinta2){
                                printUser(jasenet, i);
                            }
                        }
                    }break;
                    case 5:{
                        int valinta2;
                        printf("Anna jasenmaksu > ");
                        scanf("%i", &valinta2);
                        flush();
                        for (int i = 0; i < jasenLkm; ++i) {
                            for (int j = 0; j < 5; ++j) {
                                if(jasenet[i].jasenmaksut[j] == valinta2){
                                    printUser(jasenet, i);
                                }
                            }
                        }
                    }break;
                }
            }

        }
    } while (selection != 7);
}

void printUser(const Jasen *jasenLista, int index) {
    printf("\n   ETUNIMI: %s\n", jasenLista[index].etunimi);
    printf("  SUKUNIMI: %s\n", jasenLista[index].sukunimi);
    printf("  JASENNRO: %i\n", jasenLista[index].jasennumero);
    printf("LIITTVUOSI: %i\n", jasenLista[index].liittymisvuosi);
}


int menu(int *selection) {
    printf("\n");
    printf("1 Uuden jasenen lisaaminen\n");
    printf("2 Jasenen tietojen poisto\n");
    printf("3 Jasenen tietojen muuttaminen\n");
    printf("4 Tulosta jasen\n");
    printf("5 Tulosta rekisteri\n");
    printf("6 Haku\n");
    printf("7 Lopetus\n\n");
    do {
        printf("Valintasi > ");
        scanf("%i", selection);
        flush();
        if ((*selection) < 1 || (*selection) > 7){
            printf("Vaara valinta");
        }
    }while((*selection) < 1 || (*selection) > 7);
    return (*selection);
}



void flush(){
    while(getc(stdin) != '\n');
}
