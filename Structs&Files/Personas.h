//
// Created by Justo Vargas on 15-03-22.
//
struct Personas {
    int  id;
    char  name[50];
    char  surname[50];
    char  email[100];
    char   gender[50];
} ;

typedef struct Personas Persona;

Persona* getPersonas(FILE *fp);