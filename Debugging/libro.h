struct libros {
    char titulo[1000];
    char autor[1000];
    int ano;
    int estante_numero;
    char estante_seccion[500];
    int piso;
    char edificio[500];
    char sede[500];
};

typedef struct libros libro;


/* Funciones para manejar el archivo directamente */
libro *obtenerlibro(int *n); /* Obtiene un vector dinámico de libros */
char existelibro(int codigolibro, libro *libro); /* Busca si existe el libro en el archivo de libros */
char existelibro2(char descripcionlibro, libro *libro);
char insertarlibro(libro libro); /* Inserta el libro al final del archivo */
char eliminarlibro(int codigolibro); /* Eliminar el libro de código codigolibro del archivo */
char eliminacionFisica(); /* Realiza la eliminación física de registros inválidos del archivo de libros */
char modificarlibro(libro libro); /* Modifica el libro en el archivo */
char guardarReporte(); /* Genera un archivo TXT con el reporte de los libros */
