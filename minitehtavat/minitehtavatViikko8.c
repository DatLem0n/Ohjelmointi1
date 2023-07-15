#include <stdio.h>
#include <string.h>

void tehtava57(void);
void tehtava58(void);

int mainViikko8(){
    //tehtava57();
    tehtava58();
}

int omaStrcmp(const char* str1, const char* str2);
void tehtava57(){
    char str1[100], str2[100];
    printf("Anna ensimmainen merkkijono >");
    fgets(str1, 100 ,stdin);
    str1[strcspn(str1, "\n")] = 0;
    printf("Anna toinen merrkijono >");
    fgets(str2, 100 ,stdin);
    str2[strcspn(str2, "\n")] = 0;

    switch (omaStrcmp(str1, str2)) {
        case -1:{
            printf("%s < %s", str1, str2);
        }break;
        case 0:{
            printf("%s == %s", str1, str2);
        }break;
        case 1:{
            printf("%s > %s", str1, str2);
        }break;
    }
}
int omaStrcmp(const char* str1, const char* str2){
    while (*str1 != '\0' || *str2 != '\0'){
        if(*str1 != *str2){
            if(*str1 > *str2) return 1;
            else return -1;
        }
        str1++; str2++;
    }
    if (*str1 == '\0' && *str2 == '\0'){
        return 0;
    } else if (*str1 == '\0' && *str2 != '\0') return -1;
    else return 1;
}

char* mystrcpy(char* kohde, const char* lahde);
char* mystrcat(char* kohde, char* lahde);
void tehtava58(){
    char str1[100] = "Hello ", str2[] = "world";
    mystrcat(str1, str2);
    puts(str1);
    mystrcpy(str1, str2);
    puts(str1);
}
char* mystrcpy(char* kohde, const char* lahde){
    char* start = kohde;
    while (*lahde != '\0'){
        *kohde = *lahde;
        kohde++; lahde++;
    }
    *kohde = '\0';
    return start;
}
char* mystrcat(char* kohde, char* lahde){
    char* start = kohde;
    while (*kohde != '\0') {
        kohde++;
    }
    while (*lahde != '\0'){
        *kohde = *lahde;
        kohde++; lahde++;
    }
    *kohde = '\0';
    return start;
}