//
// Created by Justo Vargas on 15-03-22.
//
struct Personas {
    int  id;
    char  *name;
    char  *surname;
    char  *email;
    char   *gender;
} ;

typedef struct Personas Persona;

extern int registryCount;

Persona* getPersonas(FILE *fp);

FILE * openFile(char *filename);
void closeFile(FILE *pFile);
