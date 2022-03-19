#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Veremos como manejar strings
 */
int main() {
    //podemos instanciar un string con un puntero
    char *s;
    //o bien con un array de caracteres
    char word[20];
    char *hi = "hello";
    char bye[] = "goodbye";

    //cuando lo hacemos con un puntero para crear un string
    // debemos usar la funcion malloc pasando la logitud del string
    s = (char*)malloc(20*sizeof(char));

    // podemos darle un valor usando la funcion strcpy
    strcpy( s, "good morning dear");
    // podemos imprimir la longitud del string
    printf( "%lu\n", strlen( s ) );

    //tambien podemos realizar directo
    s = "good morning";

    printf("%s \n", s);

    strcpy( word, "how are you?" );

    printf( "%lu\n", strlen( word ) );

    printf( "%c\n", s[4] );
    //se posiciona en la segunda letra
    s++;
    //e imprime solo esa por el formato
    printf( "%c\n", *s );
    //dado que corrimos un lugar verificar que imprime ahora
    printf( "%s\n", s );
    printf( "Longitud s: %lu\n", strlen( s ) );
}




