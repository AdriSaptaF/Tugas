//coba tp 6

#include <stdio.h>
#include <string.h>

    typedef struct {
        char band[100];
        float durasi; 
        char judul_lagu[100]; 
    }lagu;


    void shorting(lagu arr[], int n, char*metode){
        if(strcmp(metode,"Band")==0)
        {
            //insertion sort
            for(int i = 1; i < n; i++)
            {
                lagu temp = arr[i];
                int j = i-1;
                while(j >= 0 && (strcmp(temp.band,arr[j].band)) < 0)
                {
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = temp;
            }

        }else if(strcmp(metode,"Durasi")==0)
        { 
            for(int i = 1; i < n; i++){
                lagu temp = arr[i];
                int j = i-1;
                while(j >= 0 && temp.durasi < arr[j].durasi){
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = temp;
            }
  
        }else if(strcmp(metode,"Judul")==0){ 
            //insertion sort
            for(int i = 1; i < n; i++){
                lagu temp = arr[i];
                int j = i-1;
                while(j >= 0 && (strcmp(temp.judul_lagu,arr[j].judul_lagu)) < 0){
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = temp;
            }

        }

    }

    void merge(lagu arr1[], int n, lagu arr2[], int m, lagu arr3[], char*metode){
        if(strcmp(metode,"Band")==0){
            int i1 = 0, i2 = 0;
            int i3 = 0;
            while(i1 < n && i2 < m){
                if(strcmp(arr1[i1].band,arr2[i2].band) < 0) {
                    arr3[i3] = arr1[i1];
                    i1++;
                }else{
                    arr3[i3] = arr2[i2];
                    i2++;
                }
                i3++;
            }

            while(i1 < n){
                arr3[i3] = arr1[i1];
                i1++;
                i3++;
            }

            while(i2 < m){
                arr3[i3] = arr2[i2];
                i2++;
                i3++;
            }

            }else if(strcmp(metode,"Durasi")==0){ 
                int i1 = 0, i2 = 0;
                int i3 = 0;
                while(i1 < n && i2 < m){
                    if(arr1[i1].durasi < arr2[i2].durasi) {
                        arr3[i3] = arr1[i1];
                        i1++;
                    }else{
                        arr3[i3] = arr2[i2];
                        i2++;
                    }
                    i3++;
                }

                while(i1 < n){
                    arr3[i3] = arr1[i1];
                    i1++;
                    i3++;
                }

                while(i2 < m){
                    arr3[i3] = arr2[i2];
                    i2++;
                    i3++;
                }
  
        }else if(strcmp(metode,"Judul")==0){ 
            int i1 = 0, i2 = 0;
            int i3 = 0;
            while(i1 < n && i2 < m){
                if(strcmp(arr1[i1].judul_lagu,arr2[i2].judul_lagu) < 0) {
                    arr3[i3] = arr1[i1];
                    i1++;
                }else{
                    arr3[i3] = arr2[i2];
                    i2++;
                }
                i3++;
            }

            while(i1 < n){
                arr3[i3] = arr1[i1];
                i1++;
                i3++;
            }

            while(i2 < m){
                arr3[i3] = arr2[i2];
                i2++;
                i3++;
            }
        }
    }

    int main()
    {
        // Meminta masukan user untuk mengisi lagu fav abdul
        int nA;
        scanf("%d", &nA);
        lagu abdul[nA];
        for (int i = 0; i < nA; i++) 
        {
            scanf("%s %f %s", abdul[i].band, &abdul[i].durasi, abdul[i].judul_lagu);
        }

        // Meminta masukan user untuk mengisi lagu fav jason
        int nJ;
        scanf("%d", &nJ);
        lagu jason[nJ];
        for (int i = 0; i < nJ; i++) 
        {
            scanf("%s %f %s", jason[i].band, &jason[i].durasi, jason[i].judul_lagu);
        }

        // Meminta masukan user untuk mengisi lagu fav rakha
        int nR;
        scanf("%d", &nR);
        lagu rakha[nR];
        for (int i = 0; i < nR; i++) {
            scanf("%s %f %s", rakha[i].band, &rakha[i].durasi, rakha[i].judul_lagu);
        }

        // Meminta masukan user untuk mengisi lagu fav tattha
        int nTh;
        scanf("%d", &nTh);
        lagu tattha[nTh];
        for (int i = 0; i < nTh; i++) 
        {
            scanf("%s %f %s", tattha[i].band, &tattha[i].durasi, tattha[i].judul_lagu);
        }

        // Meminta masukan user untuk mengisi lagu fav taufiq
        int nTa;
        scanf("%d", &nTa);
        lagu taufiq[nTa];
        for (int i = 0; i < nTa; i++) 
        {
            scanf("%s %f %s", taufiq[i].band, &taufiq[i].durasi, taufiq[i].judul_lagu);
        }

        // Meminta masukan user untuk mengisi detik
        int detik;
        scanf("%d", &detik);

        // Meminta masukan user untuk mengisi nama asprak 
        char nasprak[20];
        scanf("%s", nasprak);

        // Meminta masukan user untuk mengisi apa yang di shorting
        char shrt[20];
        scanf("%s", shrt);
        
        shorting(abdul, nJ, shrt);
        shorting(jason, nJ, shrt);
        shorting(rakha, nR, shrt);
        shorting(tattha, nTh, shrt);
        shorting(taufiq, nTa, shrt);

        lagu abson[nA + nJ];
        lagu absonra[nA + nJ + nR];
        lagu absonratha[nA + nJ + nR + nTh];
        lagu absonrathatu[nA + nJ + nR + nTh + nTa];


        merge(abdul, nA, jason, nJ, abson, shrt);
        merge(abson, (nA + nJ), rakha, nR, absonra, shrt);
        merge(absonra, (nA + nJ + nR), tattha, nTh, absonratha, shrt);
        merge(absonratha, (nA + nJ + nR + nTh), taufiq, nTa, absonrathatu, shrt);


        int find= 0;
        
        // Mencari nama band paling panjang
        for(int i = 0; i < (nA + nJ + nR + nTh + nTa); i++)
        {
            if(strlen(absonrathatu[i].band) > find)
            {
                find = strlen(absonrathatu[i].band);
            }
        }
        
        // Menampilkan output kepala (3 baris pertama)
        printf("---------------------------------------------------\n");
        printf("Daftar lagu yang telah dikumpulkan:\n");
        printf("---------------------------------------------------\n");
        
        // Menampilkan output dari inptan setelah di shorting
        for(int i = 0; i < (nA + nJ + nR + nTh + nTa); i++)
        {
            printf("%s ", absonrathatu[i].band);
                for(int src =0; src < (find - (strlen(absonrathatu[i].band))); src++)
                {
                    printf(" ");
                }
                
            printf("%.2f %s\n", absonrathatu[i].durasi, absonrathatu[i].judul_lagu);
        }
        
        // Menampilkan output kepala (3 baris pertama)
        printf("---------------------------------------------------\n");
        printf("Daftar lagu %s yang disetel dalam perjalanan:\n", nasprak);
        printf("---------------------------------------------------\n");

        return 0;

    }