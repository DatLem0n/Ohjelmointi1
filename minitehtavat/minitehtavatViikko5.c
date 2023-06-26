#include <stdio.h>
#include <math.h>

void tehtava22(void);
void tehtava23(void);
void tehtava24(void);
void tehtava26(void);
void tehtava27(void);
void tehtava28(void);

int mainViikko5(){
    //tehtava22();
    //tehtava23();
    //tehtava24();
    //tehtava26();
    //tehtava27();
    tehtava28();
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