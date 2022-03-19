#include "Books.h"


struct Rents {
  Book book;
  char user[50];
};

typedef struct Rents Rent;

void printRent(Rent rent );