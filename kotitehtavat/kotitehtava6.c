#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char nimi[100];
    double summa;
}Maksu;

typedef struct {
    int tiliNumero;
    double saldo;
    int kayttoraja;
    int pin;
    Maksu tapahtumat[100];
    int tapahtumaMaara;
}Kortti;

int lueKortti(int, Kortti*);
int kysyPin(Kortti*);
int menu(Kortti*);
int otto(Kortti*);
void saldo(Kortti*);
void tapahtumat(Kortti*);
int kysyValinnat(int, int);
void suljeIstunto(Kortti*);



int main() {
    Kortti kortti;
    int valinta, quitFlag = 0;
    char input;

    while (1){
        puts("\nTervetuloa!\n");
        puts("Syota tilinumero, ole hyva (valmiita tileja 1, 2 ja 3) (Q lopettaa)");

        while (1) {
            if (scanf("%d", &valinta) != 1) {
                scanf("%c", &input);
                fflush(stdin);
                if (input == 'q' || input == 'Q') {
                    quitFlag = 1;
                    break;
                } else {
                    printf("Vain numeroita tilinumeroon, yrita uudelleen (valmiita tileja 1, 2 ja 3) (Q lopettaa)\n");
                }
            }
            else break;
        }
        if (quitFlag){
            break;
        }
        if(lueKortti(valinta, &kortti)){
            while (1){
                if (menu(&kortti) == 4) {
                    suljeIstunto(&kortti);
                    break;
                }
            }
        }
    }
}
/**
 * Lukee valitun kortin tiedot muistiin, kutsuu kysyPin funktion, jolla tarkistaa luvan lukea loput tilin tiedot.
 * Tilin tiedot tulisi olla .tili päätteisessä tiedostossa riveittäin seuraavassa järjestyksessä:
 * PIN(int) -> Saldo(double) -> Kortin käyttöraja(int) -> Tapahtumamäärä(int) -> Tapahtumat [nimi(str);summa(double)]
 * Jos tilin tiedostossa on vain PIN ja Saldo, funktio luo tilille loput.
 *
 * @param tiliNumero (int) tilin numero, jonka tiedot luetaan (1 - 3)
 * @param kortti (Kortti) kortti, jonne tiedot luetaan
 *
 * @return palauttaa 1, jos lukeminen onnistuu, muuten 0
 */
int lueKortti(int tiliNumero, Kortti* kortti){
    FILE * tiliFile;
    char filename[100], pin[10], kayttoraja[100], saldo[100], tapahtumaMaara[10], tapahtumat[200];
    snprintf(filename, 100, "%i", tiliNumero);
    strcat(filename, ".tili");

    tiliFile = fopen(filename, "r");
    if (tiliFile == NULL){
        puts("Tilinumeroa ei tunnistettu \n");
        return 0;
    }
    kortti->tiliNumero = tiliNumero;
    fgets(pin, 10, tiliFile);
    kortti->pin = atoi(pin);

    if(kysyPin(kortti) == 0){
        fclose(tiliFile);
        return 0;
    }

    fgets(saldo, 100, tiliFile);
    kortti->saldo = strtod(saldo, NULL);
    if(feof(tiliFile)){
        kortti->tapahtumaMaara = 0;
        kortti->kayttoraja = 400;
        return 1;
    }
    fgets(kayttoraja, 100, tiliFile);
    kortti->kayttoraja = atoi(kayttoraja);
    fgets(tapahtumaMaara, 100, tiliFile);
    kortti->tapahtumaMaara = atoi(tapahtumaMaara);

    char * tapahtumaToken;
    for (int i = 0; i < kortti->tapahtumaMaara; ++i) {
        fgets(tapahtumat, 200, tiliFile);

        tapahtumaToken = strtok(tapahtumat, ";");
        strcpy(kortti->tapahtumat[i].nimi, tapahtumaToken);
        tapahtumaToken = strtok(NULL, ";");
        kortti->tapahtumat[i].summa = strtod(tapahtumaToken, NULL);
    }
    fclose(tiliFile);
    return 1;
}

/**
 * Tallentaa kortin tiedot tilinumero.tili tiedostoon.
 * @param kortti Tili, jonka tiedot tallennetaan.
 */
void suljeIstunto(Kortti* kortti){
    FILE * tiliFile;
    char filename[100], tempStr[200];

    snprintf(filename, 200, "%i", kortti->tiliNumero);
    strcat(filename, ".tili");
    tiliFile = fopen(filename, "w");

    fprintf(tiliFile,"%i\n", kortti->pin);
    fprintf(tiliFile,"%.02lf\n", kortti->saldo);
    fprintf(tiliFile,"%i\n", kortti->kayttoraja);
    fprintf(tiliFile,"%i\n", kortti->tapahtumaMaara);
    for (int i = 0; i < kortti->tapahtumaMaara; ++i) {
        snprintf(tempStr, 200, "%s;%.02lf\n", kortti->tapahtumat[i].nimi, kortti->tapahtumat[i].summa);
        fputs(tempStr, tiliFile);
    }
    fclose(tiliFile);
}

/**
 * Kysyy käyttäjältä kortin pin:ä, ja tarkistaa sen oikeaksi
 * @return palauttaa 1, jos oikein ja 0 jos väärin 4 kertaa
 */
int kysyPin(Kortti* kortti){
    int syotto = 0, tunnusluku = kortti->pin, sallitutKerrat = 4;
    for (int i = 0; i < sallitutKerrat; ++i) {
        printf("\nNappaile tunnusluku (%i) > ", tunnusluku);
        scanf("%i", &syotto);
        fflush(stdin);
        if(syotto == tunnusluku){
            return 1;
        }
        else if(i != 3) printf("Vaara tunnusluku, yrita uudelleen (%i. yritys) \n", i + 2);
    }
    printf("Pin vaarin %i kertaa, ota yhteys pankkiin", sallitutKerrat);
    return 0;
}

/**
 * tulostaa päävalikon ja toimii käyttäjän valitseman vaihtoehdon mukaan
 * @return palauttaa toiminnon numeron (lopetusta varten)
 */
int menu(Kortti* kortti){
    int valinta = 0;

    printf("\n");
    puts("Valitse toiminto:");
    puts("(1) Otto");
    puts("(2) Saldo");
    puts("(3) Tapahtumat");
    puts("(4) Lopeta\n");

    valinta = kysyValinnat(1, 4);
    switch (valinta) {
        case 1:{
            puts("Otto valittu");
            otto(kortti);
            return 1;
        }
        case 2:{
            puts("Saldo valittu");
            saldo(kortti);
            return 2;
        }
        case 3:{
            puts("Tapahtumat valittu");
            tapahtumat(kortti);
            return 3;
        }
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

/**
 * Suorittaa kortilta käteisennoston, tarkistaa kortin saldon ja lisää tapahtuman tilin tapahtumiin
 * Laskee pyydettävien setelien määrän ja tulostaa sen.
 * @param kortti
 * @return 0, jos nosto epäonnistuu, 1 jos nosto onnistuu
 */
int otto(Kortti* kortti){
    int valinta, valinta2, ottoSumma = 0, voiNostaa, rahayksMaara = 3;
    int rahat[] = {50, 20, 1};
    int seteliMaara[rahayksMaara];

    puts("\nOTTO: ");
    puts("(1) 20 euroa");
    puts("(2) 40 euroa");
    puts("(3) 60 euroa");
    puts("(4) 90 euroa");
    puts("(5) 140 euroa");
    puts("(6) 240 euroa");
    puts("(7) Muu summa");
    puts("(8) Takaisin");

    valinta = kysyValinnat(1, 8);

    switch (valinta) {
        case 1:{
            ottoSumma = 20;
        }break;
        case 2:{
            ottoSumma = 40;
        }break;
        case 3:{
            ottoSumma = 60;
        }break;
        case 4:{
            ottoSumma = 90;
        }break;
        case 5:{
            ottoSumma = 140;
        }break;
        case 6:{
            ottoSumma = 240;
        }break;
        case 7:{
            printf("\nPaljonko haluat nostaa (max 1000 euroa) \n");
            do {
                voiNostaa = 1;
                printf("> ");
                scanf("%i", &ottoSumma);
                fflush(stdin);
                if (ottoSumma <= 0){
                    printf("Syota kunnollinen luku ");
                    voiNostaa = 0;
                }
                if (ottoSumma > 1000){
                    puts("Et voi nostaa yli 1000 euroa tasta automaatista \n");
                    voiNostaa = 0;
                }
            } while (!voiNostaa);
        }break;
        case 8:{
            return 0;
        }
        default:
    }
    if (ottoSumma > kortti->saldo){
        printf("Tilin kate ei riita nostoon \n");
        return 0;
    }
    else if (ottoSumma > kortti->kayttoraja){
        printf("Et voi nostaa yli %i euroa (kortin kayttoraja) \n", kortti->kayttoraja);
        return 0;
    }
    else{
        puts("\nHaluatko tiedot?");
        puts("(1) Naytolle");
        puts("(2) Ei kiitos");
        valinta2 = kysyValinnat(1, 2);

        int tempSumma = ottoSumma;
        for (int i = 0; i < rahayksMaara; ++i) {
            if(tempSumma >= rahat[i]){
                seteliMaara[i] = tempSumma / rahat[i];
                tempSumma = tempSumma % rahat[i];
            } else seteliMaara[i] = 0;
        }
        if (seteliMaara[rahayksMaara - 1] != 0){
            printf("\nAutomaatti ei voi antaa 20 euroa pienempia seteleita, joten %i euron pyynnosta %i euroa jaa tilillesi", ottoSumma, seteliMaara[rahayksMaara - 1]);
            ottoSumma -= seteliMaara[rahayksMaara - 1];

        }

        kortti->saldo -= ottoSumma;
        strcpy(kortti->tapahtumat[kortti->tapahtumaMaara].nimi, "Otto-automaatti");
        kortti->tapahtumat[kortti->tapahtumaMaara].summa = -ottoSumma;
        kortti->tapahtumaMaara ++;

        if(valinta2 == 1){
            printf("\n***KUITTI****\n"
                   "Nostettu \t %i euroa\n"
                   "Nostettavissa \t %.02lf euroa \n"
                   "*************\n",ottoSumma, kortti->saldo);
        }
        printf("\nAutomaatti antaa %i 50 euron setelia ja %i 20 euron setelia, yht %i euroa\n", seteliMaara[0], seteliMaara[1], ottoSumma);
    }
    return 1;
}
/**
 * Tulostaa tilin saldon näytölle
 * @param kortti
 */
void saldo(Kortti * kortti){
    puts("\nTilin tilanne");
    printf("Tilin saldo \t\t %.02lf euroa\n", kortti->saldo);
    printf("Kortin kateisnostovara \t %i euroa ", kortti->kayttoraja);
    printf("\n (1) Lopeta");
    kysyValinnat(1, 1);
}
/**
 * Tulostaa tilin menneet tapahtumat näytölle
 * @param kortti
 */
void tapahtumat(Kortti * kortti){
    puts("Minne haluat tiedot");
    puts("(1) Naytolle");
    kysyValinnat(1, 1);

    for (int i = 0; i < kortti->tapahtumaMaara; ++i) {
        printf("%-20s ------ %.02lf euroa \n", kortti->tapahtumat[i].nimi, kortti->tapahtumat[i].summa);
    }
    puts("-------------------------------------------");
    printf("%-20s ------ %.02lf euroa\n", "nykyinen saldo: ", kortti->saldo);
}
/**
 * Ottaa käyttäjältä numeroita valikoissa
 * @param alaraja alin hyväksytty numero
 * @param ylaraja korkein hyväksytty numero
 * @return palauttaa hyväksytyn syötön käyttäjältä
 */
int kysyValinnat(int alaraja, int ylaraja){
    int valinta = 0;
    do {
        printf("> ");
        scanf("%i", &valinta);
        fflush(stdin);
        if(valinta > ylaraja || valinta < alaraja){
            printf("Vaara valinta, yrita uudelleen ");
        }
    }while(valinta > ylaraja || valinta < alaraja);
    return valinta;
}
