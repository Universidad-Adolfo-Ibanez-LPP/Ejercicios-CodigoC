#include <stdio.h>

/*
 * trabajaremos con estos tres metodos
 * para entender como funciona el scope de las variables
 * y ver cuando camabian y cuando no
 */

void no_cambia( int d );
void cambia( int* d );
void tampoco(int* d);

//paso por valor por lo que no cambia
void no_cambia( int d ) {
    d = 19;
}

// si bien la *d se pasa por referencia
// esta se copia en la variable i, por lo que
// i es una variable completamente independiente
void tampoco(int *d) {
    int i = *d;
    i  = 20;
}

//aca si es un paso por referencia completo
void cambia(int* d) {
    *d = 21;
}

/*
 * en el cuerpo del main vemos como numero va cambiando acorde a como se pasa.
 */
int main( ) {
    int numero ;
    scanf("%d", &numero);
    printf("%d\n", numero);
    no_cambia(numero);
    printf("%d\n", numero);
    tampoco(&numero);
    printf("%d\n", numero);
    cambia(&numero);
    printf("%d\n", numero);
}