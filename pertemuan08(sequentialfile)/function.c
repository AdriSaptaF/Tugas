#include "header.h"


// PROSEDUR READ DATA MAKANAN
void readFileName(int *n, dataName source[], char fileName[])
{
    FILE *fTemp;
    fTemp = fopen(fileName, "r"); //  r untuk operator read file
   
    int returnVal = fscanf(fTemp, "%s %d %s", source[*n].nama, &source[*n].harga, source[*n].jenis); // untuk scan 3 data pada baris pertama dari isi file

    // cek apakah data yang discan di atas dummy atau tidak              
    if (strcmp(source[*n].nama, "####") == 0 || returnVal == EOF) 
    {
        printf("File Kosong\n");
    }
    else // jika buka dummy/eof
    {
        while (strcmp(source[*n].nama, "####") != 0) // selama buka data dummy/eof
        {
            *n = *n + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %d %s", source[*n].nama, &source[*n].harga, source[*n].jenis); // scan data berikutnya
        }
    }
 
    fclose(fTemp); // tutup file
}
