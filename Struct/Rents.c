#include "Rents.h"
#include <stdio.h>

void printRent(Rent rent ) {

   printf( "Rent title : %s\n", rent.book.title);
   printf( "Rent author : %s\n", rent.book.author);
   printf( "Rent subject : %s\n", rent.book.subject);
   printf( "Rent book_id : %d\n", rent.book.book_id);
     printf( "Rent User : %s\n", rent.user);

}