#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void tehtava63();
void tehtava64();
void tehtava65();
void tehtava66();
void tehtava67();
void tehtava68();




int mainViikko10(){
    tehtava63();
    //tehtava64();
    //tehtava65();
    //tehtava66();
    //tehtava67();
    //tehtava68();
}

void tehtava63(){
    int rows = 1, chars = 0, emptyCounter = 0;
    char ch;
    FILE * inFile;
    inFile = fopen("teksti.txt", "r");

    while ((ch = fgetc(inFile)) != EOF){
        if (ch != '\n'){
            chars++;
            emptyCounter++;
        }
        else {
            if (emptyCounter != 0) {
                rows++;
                emptyCounter = 0;
            }
        }
    }
    printf("Rivit: %i\n", rows);
    printf("Merkit: %i\n", chars);
}

void tehtava64(){
    char filename1[100], filename2[100];
    FILE * file1, * file2;
    fgets(filename1, 100, stdin);
    filename1[strcspn(filename1, "\n")] = 0;
    fgets(filename2, 100, stdin);
    filename2[strcspn(filename2, "\n")] = 0;

    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");

    int match = 1;
    do {
        if(getc(file1) != getc(file2)){
            match = 0;
        }
    } while (!feof(file1) || (!feof(file2)));

    if (match){
        printf("Tiedostot ovat sisällöltään identtiset.");
    }
    else{
        printf("Tiedostot eivät ole sisällöltään identtiset.");
    }
}

void tehtava65(){
    char suomi[100][100], engl[100][100], rivi[100], * sanaSuomi, * sanaEngl;
    int wordCounter = 0;

    FILE * inFile;
    inFile = fopen("sanakirja.txt", "r");

    do {
        fscanf(inFile, "%s", rivi);
        sanaSuomi = strtok(rivi, ";");
        sanaEngl = strtok(NULL, ";");

        strcpy(suomi[wordCounter], sanaSuomi);
        strcpy(engl[wordCounter], sanaEngl);
        wordCounter ++;
    } while (!feof(inFile));


    char kysyttava[100];
    printf("Give word > ");
    fgets(kysyttava, 100, stdin);
    kysyttava[strcspn(kysyttava, "\n")] = 0;

    int wordFound = 0;
    for (int i = 0; i < wordCounter; ++i) {
        if (!wordFound){
            if (strcmp(kysyttava, suomi[i]) == 0){
                printf("sana %s englanniksi on %s", kysyttava, engl[i]);
                wordFound = 1;
            }
            else if(strcmp(kysyttava, engl[i]) == 0){
                printf("sana %s suomeksi on %s", kysyttava, suomi[i]);
                wordFound = 1;
            }
        }

    }
    if (!wordFound) printf("Sanaa %s ei loytynyt sanakirjasta", kysyttava);
    fclose(inFile);
}

void printLines(FILE *inFile, int readLines);
void tehtava66(){
    char filename[100], input[100];
    int readLines = 0;
    FILE * inFile;
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;
    inFile = fopen(filename, "r");

    printLines(inFile, readLines);
    fgets(input, 100, stdin);
    while (input[0] != 'q' && !feof(inFile)){
        readLines += 20;
        printLines(inFile, readLines);
        fgets(input, 100, stdin);
    }
    fclose(inFile);
}

void printLines(FILE *inFile, int readLines) {
    char rivi[1000];
    for (int i = readLines; i < readLines + 20 && !feof(inFile); ++i) {
        fgets(rivi, 1000, inFile);
        printf("%s\n", rivi);
    }
}


void tehtava68()
{
    FILE* inFile;
    char rivi[50], * nimi, * ika;

    if((inFile=fopen("nimet.txt", "r")) == NULL ){
        printf("Tiedoston avaaminen lukemista varten epaonnistui.\n");
    } else {
        do{
            fscanf(inFile, "%s", rivi);
            nimi = strtok(rivi, ";");
            ika = (strtok(NULL, ";"));

            printf("%s %d\n", nimi, atoi(ika));

        }while (!feof(inFile));
        fclose(inFile);
    }
}
