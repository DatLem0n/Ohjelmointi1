#include <stdio.h>

void tehtava5(void);
void tehtava6(void);
void tehtava7(void);
void tehtava8(void);
void tehtava9(void);
void tehtava10(void);



int main (){
    //tehtava5();
    //tehtava6();
    //tehtava7();
    // tehtava8();
    //tehtava9();
    tehtava10();
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

}