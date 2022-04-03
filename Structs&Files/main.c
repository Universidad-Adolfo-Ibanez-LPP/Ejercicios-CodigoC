#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "Personas.h"
#include "FileUtils.h"
#include "Utils.h"

enum OPTIONS { BUSCAR = 1, ELIMINAR = 2, MOSTRAR = 3, SALIR = 5, AGREGAR = 4};

//contratos
void closeProgram();
void showMenu();
void keepGoing();

//Variables
//Defino la estructura que usare para guardar los contenidos en memoria
char *filename;

//metodo principal
int main(int argc, char *argv[] ){

    //Abro el archivo
    filename = argv[1];
    FILE *fp = openFileToRead(filename);
    //paso el contenido del file a un array de personas
    personas = getPersonas(fp);
    //cierro el archivo.
    closeFile(fp);
    //Cargo la estructura
    showMenu();
    return 0;

}

void showTitles(){
    printf("********************************** \n");
    printf("***** Bienvenido a Personas ****** \n");
    printf("********************************** \n");
    printf("Ingrese la opción \n");
    printf("1. - Buscar Persona \n");
    printf("2. - Borrar Persona \n");
    printf("3. - Mostrar Personas \n");
    printf("4. - Agregar Persona \n");
    printf("5. - Salir \n");

}
void showMenu(){
    int option = 0;
    showTitles();
    scanf("%d", &option);
    //esto hace que el menu vuelva a mostrarse hasta que me ingrese una opcion valida
    while (option <= 0 || option >= 6) {
        printf("Opción Invalida! \n");
        showTitles();
        scanf("%d", &option);
    } ;
    //Solo salgo con una opcion valida
    switch (option) {
        case AGREGAR:
            agregarPersona();
            //al terminar muestro el menu de nuevo;
            keepGoing();
            break;
        case BUSCAR:
            buscarPersona();
            //al terminar muestro el menu de nuevo;
            keepGoing();
            break;
        case ELIMINAR:
            eliminarPersona();
            //al terminar muestro el menu de nuevo;
            keepGoing();
            break;
        case MOSTRAR:
            mostrarPersonas();
            //al terminar muestro el menu de nuevo;
            keepGoing();
            break;
        case SALIR:
            closeProgram();
            break;
    }
}

void keepGoing() {
    //verifico que el usuario quiera seguir o closeProgram
    printf("Desea realizar una nueva acción? Presione S o cualquier otra tecla para cerarr el programa.");
    char *rta = (char*)malloc(1 * sizeof(char));
    scanf("%s", rta);
    //Verifico que pueda closeProgram.
    if (strcmp(toLowerC(rta), "s") == 0){
        //muestro menu
        showMenu();
    } else {
        closeProgram();
    }
}



void closeProgram() {
    printf("Gracias por usar el programa \n");
    //ahora hago el proceso inverso y finalmente copio todo de nuevo al archivo
    FILE *fp = openFileToWrite(filename);
    writePersonas(personas, fp);
    closeFile(fp);
}

