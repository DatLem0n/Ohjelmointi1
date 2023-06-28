#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tehtava37(void);
void tehtava38(void);
void tehtava39(void);
void tehtava40(void);
void tehtava41(void);
void tehtava42(void);
void tehtava43(void);
void tehtava44(void);
void tehtava45(void);
void tehtava46(void);
void tehtava47(void);
int mainViikko6(){
    //tehtava37();
    //tehtava38();
    //tehtava39();
    //tehtava40();
    //tehtava41();
    //tehtava42();
    //tehtava43();
    tehtava44();
    //tehtava45();
    //tehtava46();
    //tehtava47();
}
int paivienLukumaaraKuukaudessa(int);
void tehtava37(){
    int valinta, paivia;

    printf("Anna kuukausi: ");
    scanf("%i", &valinta);
    paivia = paivienLukumaaraKuukaudessa(valinta);
    if (paivia == -1) printf("Kuukautta %i ei ole olemassa", valinta);
    else printf("Kuukaudessa %i on %i päivää", valinta, paivia);

}
int paivienLukumaaraKuukaudessa(int kk){
    int paiviaKK[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (kk > 12 || kk < 1) return -1;
    else return paiviaKK[kk - 1];
}

int isLeapYear(int);
void tehtava38(){
    int year;
    printf("Anna vuosiluku: ");
    scanf("%i", &year);
    if (isLeapYear(year)) printf("Vuosi %i on karkausvuosi", year);
    else printf("Vuosi %i ei ole karkausvuosi", year);
}
int isLeapYear(int year){
    if((year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0))) return 1;
    else return 0;
}

void tehtava39(){
    int lukuMaara = 20, syote, luvut[lukuMaara];

    for (int i = 0; i < lukuMaara; ++i) {
            printf("Syota %i luku >", i + 1);
            scanf("%i", &syote);
            if (syote > 100 || syote < 10) {
                do {
                printf("Ei kelpaa! \n");
                printf("Yrita uudelleen >");
                scanf("%i", &syote);
                } while (syote > 100 || syote < 10);
            }
            luvut[i] = syote;
    }
    for (int i = 0; i < lukuMaara; ++i) {
        int luku = luvut[i], matches = 0;
        for (int j = 0; j < lukuMaara; ++j) {
            if(j != i){
                if(luvut[i] == luvut[j]){
                    matches++;
                }
            }
        }
        if(matches == 0){
            printf("%i \n",luvut[i]);
        }
    }
}

void tehtava40(){
    int lukuMaara = 5, syote, luvut[lukuMaara], kaanteinen[lukuMaara];

    for (int i = 0; i < lukuMaara; ++i) {
        printf("Syota %i luku >", i + 1);
        scanf("%i", &syote);
        luvut[i] = syote;
    }
    for (int i = 0; i < lukuMaara; ++i) {
        kaanteinen[lukuMaara - 1 - i] = luvut[i];
    }
    for (int i = 0; i < lukuMaara; ++i) {
        printf("%i %i \n", luvut[i], kaanteinen[i]);
    }
}

void tehtava41(){
    int suurinSallittu = 100, pieninSallittu = 0, lukuMaara = 10, syote, luvut[lukuMaara], suurin = 0, indexOfSuurin = 0;
    double keskiarvo, summa;

    for (int i = 0; i < lukuMaara; ++i) {
        printf("Syota %i luku >", i + 1);
        scanf("%i", &syote);
        if (syote > suurinSallittu || syote < pieninSallittu) {
            do {
                printf("Ei kelpaa, anna %i kokonaisluku uudestaan > ", i + 1);
                scanf("%i", &syote);
            } while (syote > suurinSallittu || syote < pieninSallittu);
        }
        luvut[i] = syote;
    }

    for (int i = 0; i < lukuMaara; ++i) {
        printf("%i ", luvut[i]);
        summa += luvut[i];
        if(luvut[i] > suurin){
            suurin = luvut[i];
            indexOfSuurin = i;
        }
    }
    printf("\n");

    keskiarvo = summa / lukuMaara;
    printf("Suurin arvo on %i ja se sijaitsee paikassa %i \n", suurin, indexOfSuurin);
    printf("Taulukon arvojen keskiarvo on %.02lf", keskiarvo);
}

int throw2D6(void);
void tehtava42(){
    int results[12];
    int diceThrows = 3600;
    srand(time(NULL));
    for (int i = 0; i < diceThrows; ++i) {
        results[throw2D6() - 1] ++;
    }
    printf("Summa \t Lukumaara \n");
    for (int i = 0; i < 11; ++i) {
        printf("%8i \t %4i \n", i + 2, results[i + 1]);
    }
    printf("YHTEENSA \t %i", diceThrows);
}

int throw2D6(){
    int dice1, dice2, sumOfDice;
    dice1 = (rand() % 6) + 1;
    dice2 = (rand() % 6) + 1;
    sumOfDice = dice1 + dice2;
    return sumOfDice;
}

int getRandomNumber(int, int);
int hasDuplicates(const int arr[], int sizeOfArr);
void tehtava43(){
    int size = 20, taulukko[20] = {0}, min = 1, max = 20;
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        do{
            taulukko[i] = getRandomNumber(min, max);
        }while(hasDuplicates(taulukko, size) == 1);
    }
    for (int i = 0; i < size; ++i) {
        printf("%i \n", taulukko[i]);
    }
}
int getRandomNumber(int min, int max){
    return((rand() % max) + min);
}
int hasDuplicates(const int arr[], int sizeOfArr){
    for (int i = 0; i < sizeOfArr; ++i) {
        if (arr[i] != 0) {
            for (int j = i + 1; j < sizeOfArr; ++j) {
                if (arr[i] == arr[j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int dateToDays(const int arr[]);
void tehtava44(){

    int dates[2][3], days1, days2, dayDiff;
    for (int i = 0; i < 2; ++i) {
        printf("Anna vuosi: ");
        scanf("%i", &dates[i][0]);
        printf("Anna kuukausi: ");
        scanf("%i", &dates[i][1]);
        printf("Anna paiva: ");
        scanf("%i", &dates[i][2]);
    }
    while(1){
        if (dates[0][0] > dates[1][0]){
            printf("Aloitusvuosi on myohempi kuin lopetusvuosi");
            break;
        }
        else if (dates[0][0] == dates[1][0]){
            //sama vuosi
            if(dates[0][1] > dates[1][1]) {
                printf("Koska aloitusvuosi on sama kuin lopetusvuosi \n");
                printf("niin, aloituskuukausi ei voi olla suurempi kuin lopetuskuukausi! \n");
                break;
            }
            else if (dates[0][1] == dates[1][1]){
                //sama kuukausi
                if (dates[0][2] > dates[1][2]){
                    printf("Koska aloitusvuosi on sama kuin lopetusvuosi \n");
                    printf("ja aloituskuukausikin on sama kuin lopetuskuukausi \n");
                    printf("niin aloituspaiva ei voi olla suurempi kuin lopetuspaiva \n");
                    break;
                }
                else if (dates[0][2] == dates[1][2]) {
                    printf("Paivaykset ovat samat!");
                    break;
                }
            }
        }


        days1 = dateToDays(dates[0]);
        days2 = dateToDays(dates[1]);
        dayDiff = days2 - days1;
        printf("%i.%i.%i ja %i.%i.%i valilla on %i paivaa", dates[0][0], dates[0][1], dates[0][2], dates[1][0], dates[1][1], dates[1][2], dayDiff);
        break;
    }

}
int dateToDays(const int date[]){
    int startYear = 1900;
    int days = 0;
    int paiviaKK[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    for (int i = startYear; i < date[0] - 1; ++i) {
        if (isLeapYear(i)){
            days += 366;
        }
        else days += 365;
    }
    for (int i = 0; i < date[1] - 1; ++i) {
        days += paiviaKK[i];
    }
    if (isLeapYear(date[0]) && date[1] > 2) days ++;
    days += date[2];
    return days;
}