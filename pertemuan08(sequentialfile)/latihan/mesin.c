#include "header.h"

//Prosedur "Read" data skincare
void readskincare(int *n, dataSkincare source[], char file[]){
    FILE *fskincare;              
    fskincare = fopen(file, "r"); 
    
    // untuk scan 3 data pada baris pertama dari isi file
    int returnVal = fscanf(fskincare, "%s %s %s %d", source[*n].nama, source[*n].kode_kategori, source[*n].kode_brand, &source[*n].harga);
    // cek apakah data yang discan di atas dummy atau tidak              
    if (strcmp(source[*n].nama, "####") == 0 || returnVal == EOF) printf("File Kosong\n"); 
    else{ // jika buka dummy/eof
    
        while (strcmp(source[*n].nama, "####") != 0){ // selama bukan data dummy/eof
            printf("%s\n", source[*n].nama);
        
            *n = *n + 1; // maju ke indeks penampung berikutnya
            fscanf(fskincare, "%s %s %s %d", source[*n].nama, source[*n].kode_kategori, source[*n].kode_brand, &source[*n].harga);
        }
    }
    fclose(fskincare);
}

//Prosedur "Read" data Category dan Brand
void readother(int *m, dataOther source[], char file[]){
    FILE *fother;              
    fother = fopen(file, "r"); 
    
    // untuk scan 3 data pada baris pertama dari isi file
    int returnVal = fscanf(fother, "%s %s", source[*m].kode, source[*m].nama);

    // cek apakah data yang discan di atas dummy atau tidak              
    if (strcmp(source[*m].kode, "####") == 0 || returnVal == EOF) printf("File Kosong\n");
    else{ // jika buka dummy/eof
    
        while (strcmp(source[*m].kode, "####") != 0){ // selama bukan data dummy/eof
        
            *m = *m + 1; // maju ke indeks penampung berikutnya
            fscanf(fother, "%s %s", source[*m].kode, source[*m].nama); // scan data berikutnya
        }
    }

    fclose(fother);
}

// void printall(int n, dataSkincare source1[], int m, dataOther source2[], int o, dataOther source3[]){
//     int i, bts1, bts2;
//     for (i = 0; i < n; i++){

//         printf("%s ", source1[i].nama);

//         for (bts1 = 0; bts1 < m; bts1++){
//             if (strcmp(source1[i].kode_kategori, source2[bts1].kode) == 0){
//                 printf("%s ", source2[bts1].nama);
//             }
//         }

//         for (bts2 = 0; bts2 < o; bts2++){
//             if (strcmp(source1[i].kode_brand, source3[m].kode) == 0){
//                 printf("%s ", source3[bts2].nama);
//             }
//         }

//         printf("%d\n", source1[i].harga);

//     }
// }


