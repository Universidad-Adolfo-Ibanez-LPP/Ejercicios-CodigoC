#include "Books.h"
#include <stdio.h>

/*
  
  Creo una estructura de libros
  Y en este archivo coloco todos los 
  metodos relacionados a libro
  
*/

void printBook(Book book ) {

   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
}