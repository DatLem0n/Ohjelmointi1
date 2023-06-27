#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void tehtava22(void);
void tehtava23(void);
void tehtava24(void);
void tehtava26(void);
void tehtava27(void);
void tehtava28(void);
void tehtava29(void);
void tehtava30(void);
void tehtava31(void);
void tehtava32(void);
void tehtava33(void);
void tehtava34(void);
void tehtava35(void);
void tehtava36(void);

int mainViikko5(){
    //tehtava22();
    //tehtava23();
    //tehtava24();
    //tehtava26();
    //tehtava27();
    //tehtava28();
    //tehtava29();
    //tehtava30();
    //tehtava31();
    //tehtava32();
    //tehtava33();
    //tehtava34();
    //tehtava35();
    tehtava36();
}

void tehtava22(){
    int num, decimal = 0, rem, base = 1;
    printf("Anna viisinumeroinen binääriluku: ");
    scanf("%d", &num);
    while (num > 0)
    {
        rem = num % 10;
        decimal = decimal + rem * base;
        num = num / 10;
        base = base * 2;
    }
    printf("%i", decimal);
}


double laskeParkkiMaksu(double);
void tehtava23(){
    double hours[3], total[3];
    printf("Anna ensimmaisen asiakkaan tunnit: ");
    scanf("%lf", &hours[0]);
    printf("Anna toisen asiakkaan tunnit: ");
    scanf("%lf", &hours[1]);
    printf("Anna kolmannen asiakkaan tunnit: ");
    scanf("%lf", &hours[2]);
    total[0] = laskeParkkiMaksu(hours[0]);
    total[1] = laskeParkkiMaksu(hours[1]);
    total[2] = laskeParkkiMaksu(hours[2]);

    printf(" Asiakas \t Tunnit \t Veloitus \n");
    for (int i = 0; i < 3; i++){
        printf("%8i \t %6.02lf \t %8.02lf \n",i+1, hours[i], total[i]);
    }
    printf("YHTEENSA \t %6.02lf \t %8.02lf \n", hours[0] + hours[1] + hours[2], total[0] + total[1] + total[2]);

}
double laskeParkkiMaksu(double hours){
    double total = 0;
    int minimum = 2;
    int days = 0;
    if (hours <= 3){
        return minimum;
    }
    while (hours >= 24)
    {
        hours -= 24;
        days += 1;
    }
    if (days == 0){
        hours -= 3;
        total += minimum;
    }
    total += 10 * days + 0.5 * hours;
    return total;
}


void rounder(int);
void tehtava24(){
    rounder(5);
}
void rounder(int amountOfNumbers){
    double original[amountOfNumbers], rounded[amountOfNumbers];

    for(int i = 0; i < amountOfNumbers; i++){
        printf("Anna pyoristettava luku: ");
        scanf("%lf", &original[i]);
        rounded[i] = floor(original[i] + 0.50);
    }

    for (int i = 0; i < amountOfNumbers; ++i) {
        printf("%.02lf \t %.02lf \n", original[i], rounded[i]);
    }
}


long korotaKokonaislukuPotenssiin(int luku, int potenssi);
void tehtava26(){
    int luku, potenssi;
    printf("Anna luku: ");
    scanf("%i", &luku);
    printf("Anna potenssi: ");
    scanf("%i", &potenssi);
    printf("luku %i korotettuna potenssiin %i on %li",luku, potenssi, korotaKokonaislukuPotenssiin(luku, potenssi));
}

long korotaKokonaislukuPotenssiin(int luku, int potenssi){
    int original = luku;
    for(int i = 1; i < potenssi; i++){
        luku *= original;
    }
    return luku;
}



int timeToSec(int, int, int);
void tehtava27(){
    int time[2][3];
    for (int i = 0; i < 2; ++i) {
        printf("Anna tunnit: ");
        scanf("%i", &time[i][0]);
        printf("Anna minuutit: ");
        scanf("%i", &time[i][1]);
        printf("Anna sekunnit: ");
        scanf("%i",&time[i][2]);
    }
    int time1Seconds = timeToSec(time[0][0], time[0][1], time[0][2]);
    int time2Seconds = timeToSec(time[1][0], time[1][1], time[1][2]);

    int timeDiffSeconds;
    if (time1Seconds > time2Seconds) {
        timeDiffSeconds = time2Seconds - time1Seconds;
    }
    else{
        timeDiffSeconds = time1Seconds - time2Seconds;
    }
    printf("Aikaero on: %i sekuntia \n", timeDiffSeconds);

    int timeDiff[3];
    timeDiff[0] = timeDiffSeconds / 3600;
    timeDiff[1] = (timeDiffSeconds - timeDiff[0] * 3600) / 60;
    timeDiff[2] = timeDiffSeconds - timeDiff[0] * 3600 - timeDiff[1] * 60;
    printf("Aika on %i tuntia %i minuuttia %i sekuntia \n", timeDiff[0], timeDiff[1], timeDiff[2]);
}
int timeToSec(int hours, int min, int sec){
    long total = hours * 60 * 60 + min * 60 + sec;
    return total;
}


int onkoLukuTaydellinen(int luku);
void tehtava28(){
    for (int i = 1; i <= 10000; ++i) {
        if(onkoLukuTaydellinen(i) == 1){
            printf("\nLuku %d on taydellinen luku", i);
        }
    }
}
int onkoLukuTaydellinen(int luku){
    int tekijaMaara = 0;
    int tekijat[luku];
    for (int i = 1; i <= luku; ++i) {
        if (luku % i == 0 && i != luku){
            tekijat[tekijaMaara] = i;
            tekijaMaara ++;
        }
    }

    int sum = 0;
    for (int j = 0; j < tekijaMaara; ++j) {
        sum += tekijat[j];
    }
    if (luku == sum){
        return 1;
    }
    else return 0;
}
int flipCoin(void);
void tehtava29(){
    srand(time(NULL));
    int kruunua = 0, klaavaa = 0;

    for (int i = 0; i < 100; ++i) {
        if (flipCoin() == 1){
            klaavaa ++;
        }
        else{
            kruunua ++;
        }
    }

    printf("Heittojen tulos: %i kruunua ja %i klaavaa", kruunua, klaavaa);
}
int flipCoin(){
    double randomValue = (double)rand() / (RAND_MAX);
    if(randomValue >= 0.50){
        return 1;
    }
    else return 0;
}


void tehtava30(){
    srand(time(NULL));
    int randNum1, randNum2, answer, response;

    do{
        randNum1 = (rand() % 9) + 1;
        randNum2 = (rand() % 9) + 1;
        answer = randNum1 * randNum2;
        printf("Anna luku -1 lopettaaksesi \n");
        printf("Paljonko on %i kertaa %i? > ", randNum1, randNum2);

        while(1){
            scanf("%i", &response);

            if(response == -1){
                break;
            }
            else if(response == answer){
                printf("Oikein! \n");
                break;
            }
            else{
                printf("Vaarin, yrita uudelleen > ");
            }
        }


    }while(response != -1);
}


int random01(void);
void tehtava31(){
    srand(time(NULL));
    int randNum1, randNum2, answer, response;

    do {
        if (random01() == 1){
            randNum1 = (rand() % 9) + 1;
            randNum2 = (rand() % 9) + 1;
            answer = randNum1 * randNum2;
            printf("Anna luku -1 lopettaaksesi \n");
            printf("Paljonko on %i kertaa %i? > ", randNum1, randNum2);

            while(1){
                scanf("%i", &response);

                if(response == -1){
                    break;
                }
                else if(response == answer){
                    printf("Oikein! \n");
                    break;
                }
                else{
                    printf("Vaarin, yrita uudelleen > ");
                }
            }
        }
        else{
            randNum1 = (rand() % 9) + 1;
            randNum2 = (rand() % 9) + 1;
            answer = randNum1 * randNum2;
            printf("Anna luku -1 lopettaaksesi \n");
            printf("Paljonko on %i jaettuna %i? > ", answer, randNum1);

            while(1){
                scanf("%i", &response);

                if(response == -1){
                    break;
                }
                else if(response == randNum2){
                    printf("Oikein! \n");
                    break;
                }
                else{
                    printf("Vaarin, yrita uudelleen > ");
                }
            }
        }
    }while(response != -1);
}
int random01(){
    double randomValue = (double)rand() / (RAND_MAX);
    if(randomValue >= 0.50){
        return 1;
    }
    else return 0;
}

double factorial(int);
void tehtava32(){
    double num= 0;
    for (int i = 0; i < 10; ++i) {
        num += 1 / factorial(i);
        printf("%lf \n", num);
    }
}
double factorial(int number){
    int num = 1;
    for (int i = 1; i <= number ; ++i) {
        num = num*i;
    }
    return num;
}

double pyoristaKokonaisluvuksi(double);
double pyoristaKymmenesosat(double);
double pyoristaSadasosat(double);
double pyoristaTuhannesosat(double);
void tehtava33(){
    int amountOfValues = 1;
    double arvot[amountOfValues];
    for (int i = 0; i < amountOfValues; ++i) {
        printf("Anna pyoristettava luku: ");
        scanf("%lf", &arvot[i]);
    }
    for (int i = 0; i < amountOfValues; ++i) {
        printf("%lf %lf \n", arvot[i], pyoristaKokonaisluvuksi(arvot[i]));
        printf("%lf %lf \n", arvot[i], pyoristaKymmenesosat(arvot[i]));
        printf("%lf %lf \n", arvot[i], pyoristaSadasosat(arvot[i]));
        printf("%lf %lf \n", arvot[i], pyoristaTuhannesosat(arvot[i]));
        printf("\n");
    }
}
double pyoristaKokonaisluvuksi(double luku){
    return floor(luku + 0.5);
}
double pyoristaKymmenesosat(double luku){
    return floor(luku * 10 + 0.5) / 10;
}
double pyoristaSadasosat(double luku){
    return floor(luku * 100 + 0.5) / 100;
}
double pyoristaTuhannesosat(double luku){
    return floor(luku * 1000 + 0.5) / 1000;
}


void tehtava34(){
    int flipped = 0, num, original;

    printf("Anna kokonaisluku: ");
    scanf("%i", &num);
    original = num;

    while (num != 0) {
        flipped = flipped * 10 + num % 10;
        num /= 10;
    }
    printf("Luku %i kaannettyna on %i", original, flipped);
}


void tehtava35(){
    srand(time(NULL));
    int randNum1, randNum2, answer, response, right = 0, wrong = 0;

    do {
        if (random01() == 1){
            randNum1 = (rand() % 9) + 1;
            randNum2 = (rand() % 9) + 1;
            answer = randNum1 * randNum2;
            printf("Anna luku -1 lopettaaksesi \n");
            printf("Paljonko on %i kertaa %i? > ", randNum1, randNum2);

            while(1){
                scanf("%i", &response);

                if(response == -1){
                    break;
                }
                else if(response == answer){
                    printf("Oikein! \n");
                    right++;
                    break;
                }
                else{
                    printf("Vaarin, yrita uudelleen > ");
                    wrong ++;
                }
            }
        }
        else{
            randNum1 = (rand() % 9) + 1;
            randNum2 = (rand() % 9) + 1;
            answer = randNum1 * randNum2;
            printf("Anna luku -1 lopettaaksesi \n");
            printf("Paljonko on %i jaettuna %i? > ", answer, randNum1);

            while(1){
                scanf("%i", &response);

                if(response == -1){
                    break;
                }
                else if(response == randNum2){
                    printf("Oikein! \n");
                    right++;
                    break;
                }
                else{
                    printf("Vaarin, yrita uudelleen > ");
                    wrong ++;
                }
            }
        }
    }while(response != -1);
    printf("Sait %i vastausta oikein, ja %i meni pikkuisen pieleen \n", right, wrong);
    if(right >= wrong){
        printf("Arvosanasi on : \"Hyvaksytty\"");
    }
    else{
        printf("Arvosanasi on : \"Hylatty\"");
    }
}

int randomValue(int, int);
void clearInputBuffer(void);
void tehtava36(){
    srand(time(NULL));
    int random, input;
    char inputChar;
    do {
        random = randomValue(1, 100);
        while(1){
            printf("Arvaa luku valilta 1 - 100: ");
            scanf("%i", &input);
            if (input < random){
                printf("Liian pieni luku, yrita uudelleen. \n");
            }
            else if(input != random){
                printf("Liian suuri luku, yrita uudelleen. \n");
            }
            else{
                printf("OIKEIN! \n");
                do {
                    printf("Haluatko yrittaa uudelleen (vastaa k, jos haluat jatkaa ja e jos et halua jatkaa pelia)?");
                    clearInputBuffer();
                    scanf("%c", &inputChar);
                }while(inputChar != 'e' && inputChar != 'k');
                break;
            }
        }
    }while(inputChar == 'k');

}
int randomValue(int min, int max){
    return (rand() % max) + min;
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
