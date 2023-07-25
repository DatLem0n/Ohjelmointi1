#include <stdio.h>

void lueKortti(int);
int kysyPin(void);
int menu(void);

int main(void) {
    int korttiValinta = 0;

    while (1){
        puts("\nTervetuloa!\n");
        puts("Syota kortti, ole hyva (1, 2 tai 3)");

        do {
            printf("> ");
            scanf("%i", &korttiValinta);
            fflush(stdin);
            if(korttiValinta < 1 || korttiValinta > 3){
                printf("Vaara valinta, Yrita uudelleen ");
            }
        } while (korttiValinta < 1 || korttiValinta > 3);
        lueKortti(korttiValinta);

        if(!kysyPin()){
            break;
        }
        while (1){
            if (menu() == 4) {
                break;
            }
        }

    }
    return 0;
}
/**
 * Lukee valitun kortin tiedot muistiin
 * @param korttiValinta (int) kortin numero, jonka tiedot luetaan.
 */
void lueKortti(int korttiValinta){
    printf("Luettu kortti %i \n", korttiValinta);
}

/**
 * Kysyy käyttäjältä kortin pin:ä, ja tarkistaa sen oikeaksi
 * @return palauttaa 1, jos oikein ja 0 jos väärin 4 kertaa
 */
int kysyPin(){
    int syotto = 0, tunnusluku = 1234, sallitutKerrat = 4;
    for (int i = 0; i < sallitutKerrat; ++i) {
        printf("Nappaile tunnusluku (%i) > ", tunnusluku);
        scanf("%i", &syotto);
        fflush(stdin);
        if(syotto == tunnusluku){
            return 1;
        }
        else if(i != 3) printf("Vaara tunnusluku, yrita uudelleen (yritys %i) \n", i + 2);
    }
    printf("Pin vaarin %i kertaa, ota yhteys pankkiin", sallitutKerrat);
    return 0;
}

/**
 * tulostaa päävalikon ja toimii käyttäjän valitseman vaihtoehdon mukaan
 * @return palauttaa toiminnon numeron
 */
int menu(){
    int valinta = 0;

    printf("\n");
    puts("Valitse toiminto:");
    puts("(1) Otto");
    puts("(2) Saldo");
    puts("(3) Tapahtumat");
    puts("(4) Lopeta\n");

    do {
        printf("Tee valinta > ");
        scanf("%i", &valinta);
        fflush(stdin);
        if(valinta > 4 || valinta < 1){
            printf("Vaara valinta \n");
        }
    }while(valinta > 4 || valinta < 1);
    switch (valinta) {
        case 1:{
            puts("Otto valittu");
            return 1;
        }break;
        case 2:{
            puts("Saldo valittu");
            return 2;
        }break;
        case 3:{
            puts("Tapahtumat valittu");
            return 3;
        }break;
        case 4:{
            puts("Lopeta valittu");
            return 4;
        }
        default:{
            puts("Tapahtui virhe");
            return 0;
        }
    }
}