#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "Utils.h"
/*
 *
 * Convierte una cadena de caracteres en la misma pero en minuscula
 * Ejemplos
 *
 * AAA -> aaa
 * baAABb -> baaabb
 *
 */
char *toLowerC(char *name) {
    char *converted =  (char*)malloc( strlen(name) * sizeof(char));
    strcpy(converted,name);
    for(int i = 0; converted[i]; i++){
        converted[i] = tolower(converted[i]);
    }
    return converted;
}
