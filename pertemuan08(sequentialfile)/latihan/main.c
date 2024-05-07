#include "header.h"

int main(){
    int n = 0, m = 0, o = 0;

    //Alokasi data skincare, kategori, dan brand 
    dataSkincare skincare[50];
    dataOther category[50];
    dataOther brand[50];

    //Panggil fungsi read file untuk scanning data file
    readskincare(&n, skincare, "skincare.txt");
    printf("%d\n", n);
    readother(&m, category, "category.txt");
    readother(&o, brand, "brand.txt");
    // printall(n, skincare, m, category, o, brand);
    int i, bts1, bts2;
    for (i = 0; i < n; i++){

        printf("%s ", skincare[i].nama);

        for (bts1 = 0; bts1 < m; bts1++){
            if (strcmp(skincare[i].kode_kategori, category[bts1].kode) == 0){
                printf("%s ", category[bts1].nama);
            }
        }

        for (bts2 = 0; bts2 < o; bts2++){
            if (strcmp(skincare[i].kode_brand, brand[m].kode) == 0){
                printf("%s ", brand[bts2].nama);
            }
        }

        printf("%d\n", skincare[i].harga);

    }

    return 0;
}
