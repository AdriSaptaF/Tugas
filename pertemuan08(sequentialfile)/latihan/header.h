#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[50]; 
    char kode_kategori[50];
    char kode_brand[50];
    int harga;
}dataSkincare;

typedef struct{
    char kode[50];
    char nama[50];
}dataOther;

void readskincare(int *n, dataSkincare source[], char file[]);
void readother(int *m, dataOther source[], char file[]);
// void printall(int n, dataSkincare source1[], int m, dataOther source2[], int o, dataOther source3[]);
