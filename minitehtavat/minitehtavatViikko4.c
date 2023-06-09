#include <stdio.h>

void tehtava18(void);
void tehtava19(void);
void tehtava20(void);
void tehtava21(void);

int mainViikko4(){
    //tehtava18();
    //tehtava19();
    //tehtava20();
    tehtava21();
}

void tehtava18(){
    double sum = 0;
    int amount = 0;
    double inputNum;
    double average = 0;
    while(1){
        printf("Anna reaaliluku (negatiivinen lopettaa): ");
        scanf("%lf",&inputNum);
        if(inputNum >= 0){
            sum += inputNum;
            amount++;
        }
        else{
            if (amount != 0){
                average = sum / amount;
            }
            printf("Annettujen lukujen keskiarvo on %lf", average);
            break;
        }
    }
}

void tehtava19(){
    double sum = 0;
    int amount = 0;
    double inputNum;
    double average = 0;
    do{
        printf("Anna reaaliluku (negatiivinen lopettaa): ");
        scanf("%lf",&inputNum);
        if(inputNum >= 0){
            sum += inputNum;
            amount++;
        }
        else{
            if (amount != 0){
                average = sum / amount;
            }
            printf("Annettujen lukujen keskiarvo on %.02lf", average);
        }
    }
    while(inputNum >= 0);
}

void tehtava20(){
    double sum = 0;
    int amount = 0;
    double inputNum;
    double average = 0;
    for(;;){

        printf("Anna reaaliluku (negatiivinen lopettaa): ");
        scanf("%lf",&inputNum);
        if(inputNum >= 0){
            sum += inputNum;
            amount++;
        }
        else{
            if (amount != 0){
                average = sum / amount;
            }
            printf("Annettujen lukujen keskiarvo on %.02lf", average);
            break;
        }
    }
}

void tehtava21(){
    double sum = 0;
    int amount = 0;
    double inputNum;
    double average = 0;
    int mistakeAmount = 0;

    printf("Anna reaaliluku (negatiivinen lopettaa) > ");
    while(1){
        if (scanf("%lf", &inputNum) == 1){
            if(inputNum >= 0){
                sum += inputNum;
                amount++;
                printf("\nAnna reaaliluku (negatiivinen lopettaa): ");
            }
            else{
                if (amount != 0){
                    average = sum / amount;
                }
                printf("Annettujen lukujen keskiarvo on %.02lf", average);
                break;
            }
        }
        else{
            printf("Ei ollut reaaliluku \n");
            mistakeAmount ++;
            if (mistakeAmount < 3){
                printf("Virheellinen syote numero %i\n", mistakeAmount);
                while ((inputNum = getchar()) != '\n' && inputNum != EOF) {}
                printf("Ei kelpaa, yrita uudelleen! > ");
            }
            else {
                printf("Virheellinen syote kolme kertaa. Ohjelma lopetetaan");
                break;
            }

        }
    }
}