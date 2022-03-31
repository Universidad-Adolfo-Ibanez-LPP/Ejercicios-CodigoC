#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"


void printValues(libro dato[]){
    for (int i=0; i<1000; i++){
        printf("\n%s; %s, %d, %d, %s, %d, %s, %s", dato[i].titulo, dato[i].autor, dato[i].ano, dato[i].estante_numero, dato[i].estante_seccion, dato[i].piso, dato[i].edificio, dato[i].sede);
    }
}

FILE * openingFile(char *filename){
    printf("ENtrando a abrir el archivo de nombre %s", filename);
    FILE *fp;
    fp = fopen(filename,"r");
    printf("Archivo cargado");
    return fp;
}

void showContentAsStruct(FILE *the_file){

    char line[1000];
    char *sp;

    int row_count = 0;
    int field_count;

    libro dato[1001];
    int i = 0;

    while ( fgets(line, 1000, the_file) != NULL)
    {
        //printf("%s\n", line);

        int a = 0;
        field_count = 0;
        row_count++;

        if (row_count == 1){
            continue;
        }

        //printf("\n%c", line[0]);

        if (line[0] == '"'){
            sp = strtok(line, "\"");
            //printf("%s\n", sp);
            //sp = strtok(NULL, "\"");
            //printf("%s\n", sp);
            a++;
        }

        if (a == 0){
            sp = strtok(line, ",");
        }
        strcpy(dato[i].titulo, sp);
        sp = strtok(NULL, ",");

        //printf("%s", sp)

        while(strlen(sp) != 0){

            if (field_count == 0){

            }

            if (field_count == 1){
                strcpy(dato[i].autor, sp);
            }

            if (field_count == 2){
                dato[i].ano = atoi(sp);
            }

            if (field_count == 3){
                dato[i].estante_numero = atoi(sp);
            }

            if (field_count == 4){
                strcpy(dato[i].estante_seccion, sp);
            }

            if (field_count == 5){
                dato[i].piso = atoi(sp);
            }

            if (field_count == 6){
                strcpy(dato[i].edificio, sp);
            }

            if (field_count == 7){
                strcpy(dato[i].sede, sp);
            }

            sp = strtok(NULL, ",");
            field_count++;
        }
        i++;
    }


    fclose(the_file);

    printValues(dato);
}


int main() {
    printf("Comenzando el main");
    FILE *the_file = openingFile("../inventario.csv");

    showContentAsStruct(the_file);

    return 0;
}