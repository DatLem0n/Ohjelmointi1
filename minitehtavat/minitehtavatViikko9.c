#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tehtava59();
void tehtava60();
void tehtava61();
void tehtava62();

int mainViikko9(void){
    tehtava59();
    //tehtava60();
    //tehtava61();
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

void tehtava59(){
    int joukkueMaara;
    printf("montako joukkuetta > ");
    scanf(" %i", &joukkueMaara);
    fflush(stdin);
    Joukkue joukkueet[joukkueMaara];

    for (int i = 0; i < joukkueMaara; ++i) {
        printf("Anna joukkueen nimi >");
        fgets(joukkueet[i].nimi, 100, stdin);
        joukkueet[i].nimi[strcspn(joukkueet[i].nimi, "\n")] = 0;
        printf("Anna joukkueen voittojen maara >");
        scanf(" %i", &joukkueet[i].voitot);
        fflush(stdin);
        printf("Anna joukkueen tappioiden maara >");
        scanf(" %i", &joukkueet[i].tappiot);
        fflush(stdin);
    }

    printf("****************************************\n"
           "         TULOSLISTA\n"
           "**************************************** \n");
    qsort(joukkueet, joukkueMaara, sizeof(Joukkue), joukkueComparer);
    for (int i = 0; i < joukkueMaara; ++i) {
        printf("%i. joukkue: \t %s tilanne: %i voittoa ja %i tappiota \n", i + 1, joukkueet[i].nimi, joukkueet[i].voitot, joukkueet[i].tappiot);
    }
}
