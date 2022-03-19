#include <stdio.h>
#include <string.h>
#include "Rents.h"

/*
  De esta forma solo tengo la logica principal aqui
  y toda la definicion de las estructuras esta
  en otros archivos.
*/

int main( ) {

    // Esto me permite crear cualquier tipo de
    // estructuras con mi nuevo tipo de dato
    Book books[2];

    /* book 1 specification */
    strcpy(books[0].title, "C Programming");
    strcpy(books[0].author, "Nuha Ali");
    strcpy(books[0].subject, "C Programming Tutorial");
    books[0].book_id = 6495407;

    /* book 2 specification */
    strcpy(books[1].title, "Telecom Billing");
    strcpy(books[1].author, "Zara Ali");
    strcpy(books[1].subject, "Telecom Billing Tutorial");
    books[1].book_id = 6495700;

    /* print Book1 info */

    //si imprimimos la estructura sola solo
    // me muestra una representacion binaria
    printf("Book 1 : %s\n",  books[0]);
    //por lo que para imprimir debo ir directo miembro a miembro
    printf("Book 1 title : %s\n",  books[0].title);
    printf("Book 1 author : %s\n",  books[0].author);
    printf("Book 1 subject : %s\n",  books[0].subject);
    printf("Book 1 book_id : %d\n",  books[0].book_id);

    /* print Book2 info */
    printBook(books[1]);

    //puedo crear estructuras mas complejas incluso
    // como un alquiler que contiene un libro
    //creamos el libro
    Book book = {"La Vuelta al mundo en 80 Dias",
                 "Julio Verne",
                 "Obra maestra de  ciencia ficcion",
                 864864};

    Rent rent = {book, "Justo Vargas"};

    printRent(rent);

    return 0;
}


