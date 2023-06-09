#include <stdio.h>
#include <stdlib.h>

void tehtava5(void);
void tehtava6(void);
void tehtava7(void);
void tehtava8(void);
void tehtava9(void);
void tehtava10(void);
void tehtava11(void);
void tehtava12(void);
void tehtava13(void);
void tehtava14(void);
void tehtava15(void);
void tehtava16(void);
void tehtava17(void);


int mainViikko3 (){
    //tehtava5();
    //tehtava6();
    //tehtava7();
    //tehtava8();
    //tehtava9();
    //tehtava10;
    //tehtava11();
    //tehtava12();
    //tehtava13();
    //tehtava14();
    //tehtava15();
    //tehtava16();
    tehtava17();
}


void tehtava5(){
    double tuntipalkka;
    double tunnit;
    double veropros;
    double netto = 0;
    double brutto = 0;
    double veromaara = 0;

    printf("Anna tuntipalkka: ");
    scanf("%lf", &tuntipalkka);
    printf("Anna tuntien maara: ");
    scanf("%lf", &tunnit);
    printf("Anna veroprosentti: ");
    scanf("%lf", &veropros);

    netto = tunnit * tuntipalkka;
    if (tunnit > 40){
        netto += (tunnit - 40) * (tuntipalkka * 0.5);
    }
    veromaara = netto * veropros / 100;
    brutto = netto - veromaara;

    printf("Nettopalkkasi on %.02lf euroa ja verottajan osuus on %.02lf euroa", brutto, veromaara);
}

void tehtava6(){
    long luku1;
    long luku2;

    printf("Anna ensimmainen luku: ");
    scanf("%li", &luku1);
    printf("Anna toinen luku: ");
    scanf("%li", &luku2);

    while (1){
        if (luku1 == 0){
            printf("Ei voi jakaa nollalla");
            break;
        }

        if (luku2 % luku1 == 0){
            printf("Luku %li on luvun %li monikerta", luku2, luku1);
            break;
        }
        else{
            printf("Luku %li ei ole luvun %li monikerta", luku2, luku1);
            break;
        }
    }
}

void tehtava7(){
    long pistemaara = 0;
    printf("Anna pistemaara: ");
    scanf("%li", &pistemaara);

    if (pistemaara >= 0 && pistemaara <= 11){
        printf("Hylatty");
    }
    else if (pistemaara >= 12 && pistemaara <= 13){
        printf("1");
    }
    else if (pistemaara >= 14 && pistemaara <= 16){
        printf("2");
    }
    else if (pistemaara >= 17 && pistemaara <= 19){
        printf("3");
    }
    else if (pistemaara >= 20 && pistemaara <= 22){
        printf("4");
    }
    else if (pistemaara >= 23 && pistemaara <= 24){
        printf("5");
    }
    else{
        printf("Virheellinen pistemaara");
    }
}

void tehtava8(){
    long pistemaara = 0;
    printf("Anna pistemaara: ");
    scanf("%li", &pistemaara);

    switch (pistemaara) {
        case 0 ... 11:
            printf("Hylatty");
            break;
        case 12 ... 13:
            printf("1");
            break;
        case 14 ... 16:
            printf("2");
            break;
        case 17 ... 19:
            printf("3");
            break;
        case 20 ... 22:
            printf("4");
            break;
        case 23 ... 24:
            printf("5");
            break;
        default:
            printf("Virheellinen pistemaara");
            break;
    }
}

void tehtava9(){
    long numero = 0;
    for (int i = 0; i < 10; i++){
        long input;
        printf("Anna numero: ");
        scanf("%li", &input);
        if (input > numero){
            numero = input;
        }
    }
    printf("Suurin syottamasi luku oli %li", numero);
}

void tehtava10(){
    printf("N \t 10*N \t 100*N \t 1000*N \n");
    for(int i = 1; i <= 10; i++){
        printf("%i \t %i \t %i \t %i \n", i, i * 10, i * 100, i * 1000);
    }
}

void tehtava11(){
    long original, reversed = 0;
    printf("Anna numero: ");
    scanf("%li", &original);
    long number = original;
    if (original >= 10000 && original <= 99999){
            while(number != 0)
            {
                int i = number % 10;
                reversed = reversed * 10 + i;
                number = number / 10;
            }
            if (original == reversed){
                printf("Luku %li on palindromi", original);
            }
            else{
                printf("Luku %li ei ole palindromi", original);
            }
        }
    else {
        printf("Syote ei ole viisinumeroinen positiivinen kokonaisluku");
    }
}

void tehtava12(){
    printf("%7s%12s", "Celsius", "Fahrenheit");
    for (long asteC = -100; asteC <= 100; asteC += 10){
        double asteF = 1.8 * asteC + 32;
        printf("\n%5ld%12.02lf", asteC, asteF);
    }
}

void tehtava13(){
    for (int i = 1; i <= 8; i++){
        int j = 0;
        do{
            printf("a");
            j++;
        }
        while(j < i);
        printf("\n");
    }
}

void tehtava14(){
    for(int i = 0; i < 8; i++){
        int j = 8 - i;
        for (int k = 0; k < j; k++){
            printf(" ");
        }
        for (j; j <= 8; j++){
            printf("a");
        }
        printf("\n");
    }
}

void tehtava15(){
    printf("Anna viisinumeroinen kokonaisluku: ");
    char input[6];
    scanf("%s", input);
    printf("Luku %i eroteltuna: ", atoi(input));
    if (input[0] == '-'){
        for(int i = 1; i < sizeof(input) / sizeof(input[0]); i++){
            printf("-%c ", input[i]);
        }
    }
    else{
        for(int i = 0; i < (sizeof(input) / sizeof(input[0]) - 1); i++){
            printf("%c ", input[i]);
        }
    }
}

void tehtava16(){
    double kokoKulutus = 0;
    double kokoBensa = 0;
    double kokoKm = 0;
    double inputBensa;
    double inputKm;
    double tempKulutus;
    int endFlag = 0;

    do{
        tempKulutus = 0;
        inputBensa = 0;
        inputKm = 0;
        printf("Anna tankatun bensiinin maara ( -1 lopettaa ) > ");
        scanf("%lf", &inputBensa);
        if (inputBensa == -1){
            endFlag = 1;
        }
        else{
            kokoBensa += inputBensa;
            printf("Ajetut kilometrit > ");
            scanf("%lf", &inputKm);
            kokoKm += inputKm;

            tempKulutus = (inputBensa / inputKm) * 100;
            printf("Keskikulutus talla tankkauksella on %.03lf litraa satasella\n", tempKulutus);
        }
    }
    while (endFlag == 0);
    kokoKulutus = (kokoBensa / kokoKm) * 100;
    printf("kokonaiskeskikulutus on %.03lf litraa satasella", kokoKulutus);
}

void tehtava17(){
    int printNum = 1;

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10 - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%d", printNum % 10);
            printNum++;
        }
        for (int j = 1; j <= i - 1; j++) {
            printf("%d", (printNum - 2 ) % 10);
            printNum--;
        }
        printf("\n");
    }
}