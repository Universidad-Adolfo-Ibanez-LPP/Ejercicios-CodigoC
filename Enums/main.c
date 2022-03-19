#include <stdio.h>

//creo una enumeracion
enum MESES {Jan = 1, Feb, Mar, Apr=26, May, Jun, Jul,
    Aug, Sep, Oct , Nov, Dec};

enum DIAS {Lunes, Martes, Miercoles, Jueves, Viernes};

int main()
{
    //puedo recorrerla usando un for
    int i;
    for (i=Jan; i<=Dec; i++)
        printf("%d ", i);

    //o bien puedo instanciar un Mes de la siguiente forma
    enum MESES mes;
    mes = Jan;
    printf("\n %d \n",mes);

    //me permite realizar cosas como
    int opcion = 0;
    printf("Ingrese un numero del 1 al 5 \n");
    //recuerden que debo pasar el puntero
    scanf("%d", &opcion);

    switch (opcion) {
        case Lunes:
            printf("Ha elegido el dia Lunes");
            break;
        case Martes:
            printf("Ha elegido el dia Martes");
            break;
        case Miercoles:
            printf("Ha elegido el dia Miercoles");
            break;
        case Jueves:
            printf("Ha elegido el dia Jueves");
            break;
        case Viernes:
            printf("Ha elegido el dia Viernes");
            break;
        default:
            printf("No ha elegido ningun dia");
    }

    return 0;

}
