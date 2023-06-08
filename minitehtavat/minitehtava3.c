#include <stdio.h>

double palkka = 0;
double tunnit = 0;
double brutto = 0;
double veroprosentti = 0;
double netto = 0;
double verottajanOsuus = 0;
int minitehtava3(void){
    printf("Anna tuntipalkka ");
    scanf("%lf", &palkka);
    printf("Tehdyt tunnit ");
    scanf("%lf", &tunnit);
    printf("Anna veroprosentti ");
    scanf("%lf", &veroprosentti);
    brutto = palkka * tunnit;
    verottajanOsuus = (veroprosentti / 100.0) * brutto;
    netto = brutto - verottajanOsuus;
    printf("Nettopalkkasi on %.02lf euroa josta veron osuus on %.02lf euroa", netto, verottajanOsuus);
    return 0;
}