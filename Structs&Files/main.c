#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "Personas.h"
#define MAXCHAR 1000

#define READ_ONLY "r"

void showContentsAsStruct(FILE *pFile);

FILE * openingFile(char *filename){
    FILE *fp;
    fp = fopen(filename,READ_ONLY);
    return fp;
}



int main(int argc, char *argv[] ){

    FILE *fp = openingFile(argv[1]);

    showContentsAsStruct(fp);


    return 0;

}

void showContentsAsStruct(FILE *pFile) {
    Persona *personas;
    //paso el contenido del file a un array de personas
    personas = getPersonas(pFile);

    //COmo no se cuantas personas puede haber leido, uso un pre-test
    int actual = 0;
    //mientras el apellido sea un string valido, esa persona existe
    while (strlen(personas[actual].surname) != 0){
        //puedo solo imprimir su mail por ejemplo
        printf("%s \n", personas[actual].email);
        //paso a la siguiente persona
        actual++;
    }
   
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
