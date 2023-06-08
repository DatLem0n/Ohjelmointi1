#include <stdio.h>

int minitehtava4 (void){
    double summa = 0;
    double korko = 0;
    long paivat = 0;
    double kokonaiskorko;

    scanf("%lf", &summa);
    scanf("%lf", &korko);
    scanf("%li", &paivat);

    kokonaiskorko = summa * korko/100 * paivat / 365;
    printf("Lainapaaoman %.02lf euroa korko %li paivalta korkoprosentilla %.02lf on yhteensa %.02lf euroa",
           summa, paivat, korko, kokonaiskorko);
}