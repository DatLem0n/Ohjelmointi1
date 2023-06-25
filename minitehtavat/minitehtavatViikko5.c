#include <stdio.h>

void tehtava22(void);
void tehtava23(void);

int mainViikko5(){
    //tehtava22();
    tehtava23();
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

void tehtava23(){
    double hours1, hours2, hours3, total1, total2, total3;
    scanf("Anna ensimmäisen asiakkaan tunnit: ", &hours1);
    scanf("Anna toisen asiakkaan tunnit: ", &hours2);
    scanf("Anna kolmannen asiakkaan tunnit", &hours3);


}
double laskeParkkiMaksu(double hours){
    double total = 2;
    int days = 0;
    if (hours <= 3){
        return total;
    }
    while (hours >= 24)
    {
        hours -= 24;
        days += 1;
    }
    if (days == 0){
        hours -= 3;
    }
    total += 10 * days + 0.5 * hours;
    return total;
}