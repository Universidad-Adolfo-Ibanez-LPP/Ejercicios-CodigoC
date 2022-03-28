//
// Created by Justo Vargas on 15-03-22.
//
#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>
#include "Personas.h"

#define MAXCHAR 1000

Persona* getPersonas(FILE *fp) {
    //genero un array dinamico de personas
    Persona *personas = (Persona*) malloc(sizeof(Persona));;

    char row[MAXCHAR];
    char *token;
    int cont = 0;
    //saco la primer linea
    fgets(row, MAXCHAR, fp);
    while (feof(fp) != true){
        //obtiene la linea siguiente
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        //print id first
        Persona  persona;
        //convierto el id en entero
        int id = atoi(token);
        //lo paso a la persona
        persona.id = id;
        strcpy( persona.name, strtok(NULL, ","));
        strcpy( persona.surname, strtok(NULL, ","));
        strcpy( persona.email, strtok(NULL, ","));
        strcpy( persona.gender, strtok(NULL, ","));
        personas[cont] = persona;
        cont++;
    }
    return personas;
}
