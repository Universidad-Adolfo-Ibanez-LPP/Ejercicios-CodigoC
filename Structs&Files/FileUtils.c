//
// Created by Justo Vargas on 03-04-22.
//

#include <stdio.h>
#include "FileUtils.h"

#define READ_ONLY "r"
#define WRITE "w+"

FILE * openFileToRead(char *filename){
    FILE *fp;
    fp = fopen(filename,READ_ONLY);
    return fp;
}

FILE * openFileToWrite(char *filename){
    FILE *fp;
    fp = fopen(filename,WRITE);
    return fp;
}

void closeFile(FILE *fp){
    fclose(fp);
}
