//
// Created by Justo Vargas on 15-03-22.
//
#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>
#include "Personas.h"

#define MAXCHAR 1000

int registryCount = 0;

Persona* getPersonas(FILE *fp) {
    //genero un array dinamico de personas
    Persona *personas = (Persona*) malloc(5000*sizeof(Persona));;

    char row[MAXCHAR];
    char *token;
    int cont = 0;
    //saco la primer linea
    fgets(row, MAXCHAR, fp);
    while (!feof(fp)){
        if (!feof(fp)){
            //obtiene la linea siguiente
            fgets(row, MAXCHAR, fp);
            token = strtok(row, ",");
            //print id first
            Persona  *persona = (Persona *) malloc(sizeof(Persona));;
            //convierto el id en entero
            int id = atoi(token);
            //lo paso a la persona
            persona->id = id;

            //obtengo el siguiente campo
            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            persona->name = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( persona->name, token);

            //obtengo el siguiente campo
            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            persona->surname = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( persona->surname, token);

            //obtengo el siguiente campo
            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            persona->email = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( persona->email, token);

            //obtengo el siguiente campo
            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            persona->gender = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( persona->gender, token);

            personas[cont] = *persona;
            cont++;
        }
    }
    //guardo la cantidad de registros que lei
    registryCount = cont;
    return personas;
}



