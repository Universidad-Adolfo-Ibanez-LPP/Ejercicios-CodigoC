//
// Created by Justo Vargas on 15-03-22.
//

/*
 * Y aqui estan las implementaciones
 */
#include "impresion.h"

void print( char *c ) {
    for (int i = 0; i < MAX; ++i) {
        printf("*");
    }
    printf("\n Imprimiendo desde el Modulo impresion \n");
    for (int i = 0; i < MAX; ++i) {
        printf("*");
    }
    printf("\n Salida: %s", c);
}


