#include<stdio.h>

#define WRITE_MODE "w+"


FILE * openingFile(char *filename){
    FILE *fp;
    fp = fopen(filename,WRITE_MODE);
    return fp;
}



int main(int argc, char *argv[] ){

    FILE *fp = openingFile(argv[1]);

    //imprimo primera linea
    fprintf(fp,"id,first_name,last_name,email,gender\n");
    //imprimo la segunda
    fprintf(fp,"%d, %s, %s, %s\n", 1000, "Justo", "Vargas", "justo@globant.com", "male");
    //cierro el archivo
    fclose(fp);

    return 0;

}




