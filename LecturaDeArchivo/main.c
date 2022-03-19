#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAXCHAR 1000
#define READ_ONLY "r"

void showContents(FILE *myFile);

FILE * openingFile(char *filename){
    FILE *fp;
    fp = fopen(filename,READ_ONLY);
    return fp;
}


int main(int argc, char *argv[] ){

    FILE *fp = openingFile(argv[1]);

    showContents(fp);

    return 0;

}


void showContents(FILE *myFile) {
    char row[MAXCHAR];
    char *token;
    //muestra el contenido del archivo
    while (feof(myFile) != true){
        //obtiene la linea siguiente
        fgets(row, MAXCHAR, myFile);
        token = strtok(row, ",");
        //print id first
        printf("Row: %s \n", token);
        for (int i = 0; i < 5; ++i) {
            printf("Token %d: %s\n", i, token);
            token = strtok(NULL, ",");
        }

    }
}
