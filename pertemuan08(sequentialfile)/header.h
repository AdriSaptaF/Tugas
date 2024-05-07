#include <stdio.h>
#include <string.h>


typedef struct
{
    char nama[50], jenis[50];
    int harga;
}dataName;


void readFileName(int *n, dataName source[], char fileName[]);