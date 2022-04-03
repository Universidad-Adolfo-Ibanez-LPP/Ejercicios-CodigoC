//
// Created by Justo Vargas on 15-03-22.
//
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "Personas.h"
#include "Utils.h"

#define MAXCHAR 1000

int registryCount = 0;

Persona *getPersonas(FILE *fp) {
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

            //seteo borrar por defecto en 0
            persona->borrar = 0;

            personas[cont] = *persona;
            cont++;
        }
    }
    //guardo la cantidad de registros que lei
    registryCount = cont;
    return personas;
}

void writePersonas(Persona *personas, FILE *fp){
    //Escribo la primer linea
    fprintf(fp,"id,first_name,last_name,email,gender\n");
    //escribo las siguientes
    for (int i = 0; i < registryCount; ++i) {
        //solo escribo sino puse para borrar a esa persona
        if (personas[i].borrar == 0){
            fprintf(fp,"%d,%s,%s,%s,%s", personas[i].id, personas[i].name, personas[i].surname, personas[i].email, personas[i].gender);
        }
    }
}

void agregarPersona() {
    //genero espacio para crear una persona
    Persona  *persona = (Persona *) malloc(sizeof(Persona));
    //comienzo a pedir los datos
    printf("Ingrese el id \n");
    int id;
    scanf("%d", &id);
    persona->id = id;

    char token = (char*)malloc( 50 * sizeof(char));
    printf("Ingrese el nombre \n");
    scanf("%s", &token);
    //genero memoria para el nombre en nuestra estructura persona
    persona->name = (char*)malloc(strlen(token)* sizeof(char));
    //recien ahora tengo lugar para copiar el nombre
    strcpy(persona->name, token);

    printf("Ingrese el apellido \n");
    scanf("%s", &token);
    //genero memoria para el nombre en nuestra estructura persona
    persona->surname = (char*)malloc( strlen(token) * sizeof(char));
    //recien ahora tengo lugar para copiar el nombre
    strcpy(persona->surname, token);

    printf("Ingrese el mail \n");
    scanf("%s", &token);
    //genero memoria para el nombre en nuestra estructura persona
    persona->email = (char*)malloc( strlen(token) * sizeof(char));
    //recien ahora tengo lugar para copiar el nombre
    strcpy(persona->email, token);

    printf("Ingrese el genero \n");
    scanf("%s", &token);
    //genero memoria para el nombre en nuestra estructura persona
    persona->gender = (char*)malloc( strlen(token) * sizeof(char));
    //recien ahora tengo lugar para copiar el nombre
    strcpy(persona->gender, token);

    //pongo en 0 el borrado, por que por defecto no esta para borrarse
    persona->borrar = 0;

    //el ultimo sexo a veces no trae el salto de linea asi que si no lo tiene lo verifico
    char *lastGender = personas[registryCount-1].gender;
    if (!strstr(lastGender, "\n")){
        strcat(lastGender, "\n");
    }
    //ahora lo puedo agregar al final de mi array, por lo que
    //actualizo mi contador de registros
    //lo tiro al final del arreglo
    personas = (Persona*) realloc(personas, (registryCount+1)*sizeof(Persona));
    personas[registryCount] = *persona;
    registryCount++;
    printf("Agregado con exito! \n");
}


void buscarPersona() {
    char *name = (char*)malloc( strlen(name) * sizeof(char));
    printf("Ingrese el nombre o parte del nombre de la persona a buscar \n");
    scanf("%s", name);
    //Hago una busqueda linea
    int i = 0;
    int encontre = 0;
    while (i<registryCount && encontre == 0){
        char *nameConverted = toLowerC(personas[i].name);
        char *nameToLook = toLowerC(name);
        char *ret = strstr(nameConverted, nameToLook);
        //valido que la encuentro y que no la borre antes
        if(ret && personas[i].borrar == 0){
            encontre = 1;
        } else {
            i++;
        }
    }
    //verifico que sali por que encontre
    if (encontre == 1){
        printf("La persona Existe, estos son los datos \n");
        printf("%s,%s. \n", personas[i].name, personas[i].surname);
    } else {
        printf("La persona no existe! \n");
    }

}


void eliminarPersona() {
    char *name = (char*)malloc( 50 * sizeof(char));;
    printf("Ingrese el nombre o parte del nombre de la persona a eliminar \n");
    scanf("%s", name);
    //Hago una busqueda linea
    int i = 0;
    int encontre = 0;
    while (i<registryCount && encontre == 0){
        char *nameConverted = toLowerC(personas[i].name);
        char *nameToLook = toLowerC(name);
        char *ret = strstr(nameConverted, nameToLook);
        //valido que la encuentro y que no la borre antes
        if(ret && personas[i].borrar == 0){
            encontre = 1;
        } else {
            i++;
        }
    }
    //verifico que sali por que encontre
    if (encontre == 1){
        printf("La persona Existe, Se muestran sus datos: \n");
        printf(" Nombre: %s, Apellido: %s, e-mail: %s. \n", personas[i].name, personas[i].surname, personas[i].email);
        //verifico que el usuario quiera seguir o salir
        printf("Seguro la elimina? S para confirmar, cualquier otra tecla para salir.");
        char *rta = (char*)malloc(1 * sizeof(char));
        scanf("%s", rta);
        //solo si esta seguro de borrarlo lo hago
        if (strcmp(toLowerC(rta), "s") == 0){
            //la dejo marcada para borrar
            personas[i].borrar = 1;
            printf("Borrado con Exito! \n");
        }
    } else {
        printf("La persona no existe! \n");
    }
}

void mostrarPersonas() {
    //accedo a la cantidad de registro que lei
    for (int i = 0; i < registryCount; ++i) {
        //puedo solo imprimir su mail por ejemplo
        printf("%s,%s. \n", personas[i].name, personas[i].surname);
    }

}




