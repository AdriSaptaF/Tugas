#include "header.h"

void InputYourTrackList(int total, tracklist_data arr[], int code)
{
    for (int count_input = 0; count_input < total; count_input++)
    {
        scanf("%s %f %s", arr[count_input].ArtistSong, &arr[count_input].DurationSong, arr[count_input].NameSong);
        if (code == 0)
        {
            /* code */
            strcpy(arr[count_input].Codename, "Abdul");
        }
        else if (code == 1)
        {
            /* code */
            strcpy(arr[count_input].Codename, "Jason");
        }
        else if (code == 2)
        {
            /* code */
            strcpy(arr[count_input].Codename, "Rakha");
        }
        else if (code == 3)
        {
            /* code */
            strcpy(arr[count_input].Codename, "Tattha");
        }
        else
        {
            /* code */
            strcpy(arr[count_input].Codename, "Taufiq");
        }
    }
}

void sorting(int total, tracklist_data song[total], int sort_option)
{
    if (sort_option == 0)
    {
        /* code */
        for (int i = 0; i < (total - 1); i++)
        {
            int minIndex = i;//set minindex

            for (int j = i + 1; j < total; j++)
            {
                if (strcmp(song[minIndex].ArtistSong, song[j].ArtistSong) > 0)
                {   //sorting kecil ke besar
                    //jika sortvalue dengan indeks minindex lebih dari sorvalue dengan indeks j
                    //maka minindex menjadi sama dengan j
                    minIndex = j;
                }
            }

            //tukar posisi data
            char tempc[50];
            strcpy(tempc, song[i].ArtistSong);
            strcpy(song[i].ArtistSong, song[minIndex].ArtistSong);
            strcpy(song[minIndex].ArtistSong, tempc);

            float temp = song[i].DurationSong;
            song[i].DurationSong = song[minIndex].DurationSong;
            song[minIndex].DurationSong = temp;

            strcpy(tempc, song[i].NameSong);
            strcpy(song[i].NameSong, song[minIndex].NameSong);
            strcpy(song[minIndex].NameSong, tempc);

            strcpy(tempc, song[i].Codename);
            strcpy(song[i].Codename, song[minIndex].Codename);
            strcpy(song[minIndex].Codename, tempc);
        }
    }
    else if (sort_option == 1)
    {
        /* code */
        //algoritma selection sort
        for (int i = 0; i < (total - 1); i++)
        {
            int minIndex = i;//set minindex

            for (int j = i + 1; j < total; j++)
            {
                if (song[minIndex].DurationSong > song[j].DurationSong)
                {   //sorting kecil ke besar
                    //jika sortvalue dengan indeks minindex lebih dari sorvalue dengan indeks j
                    //maka minindex menjadi sama dengan j
                    minIndex = j;
                }
            }

            //tukar posisi data
            char tempc[50];
            strcpy(tempc, song[i].ArtistSong);
            strcpy(song[i].ArtistSong, song[minIndex].ArtistSong);
            strcpy(song[minIndex].ArtistSong, tempc);

            float temp = song[i].DurationSong;
            song[i].DurationSong = song[minIndex].DurationSong;
            song[minIndex].DurationSong = temp;

            strcpy(tempc, song[i].NameSong);
            strcpy(song[i].NameSong, song[minIndex].NameSong);
            strcpy(song[minIndex].NameSong, tempc);

            strcpy(tempc, song[i].Codename);
            strcpy(song[i].Codename, song[minIndex].Codename);
            strcpy(song[minIndex].Codename, tempc);
        }
    }
    else
    {
        for (int i = 0; i < (total - 1); i++)
        {
            int minIndex = i;//set minindex

            for (int j = i + 1; j < total; j++)
            {
                if (strcmp(song[minIndex].NameSong, song[j].NameSong) < 0)
                {   //sorting kecil ke besar
                    //jika sortvalue dengan indeks minindex lebih dari sorvalue dengan indeks j
                    //maka minindex menjadi sama dengan j
                    minIndex = j;
                }
            }

            //tukar posisi data
            char tempc[50];
            strcpy(tempc, song[i].ArtistSong);
            strcpy(song[i].ArtistSong, song[minIndex].ArtistSong);
            strcpy(song[minIndex].ArtistSong, tempc);

            float temp = song[i].DurationSong;
            song[i].DurationSong = song[minIndex].DurationSong;
            song[minIndex].DurationSong = temp;

            strcpy(tempc, song[i].NameSong);
            strcpy(song[i].NameSong, song[minIndex].NameSong);
            strcpy(song[minIndex].NameSong, tempc);

            strcpy(tempc, song[i].Codename);
            strcpy(song[i].Codename, song[minIndex].Codename);
            strcpy(song[minIndex].Codename, tempc);
        }
    }
}

void MergeData(int total1, int total2, tracklist_data arr1[], tracklist_data arr2[], tracklist_data arr3[], int sort_type, int sort_status)
{
    int i1 = 0, i2 = 0, i3 = 0;
    if (sort_type == 0)
    {
       if (sort_status == 0)
       {
            /* code */
            // ulangi hingga arr1 habis atau arr2 habis
            while ((i1 < total1) && (i2 < total2))
            {
                // jika elemen teratas arr1 lebih kecil dari atau sama dengan arr2
                if (strcmp(arr1[i1].ArtistSong, arr2[i2].ArtistSong) < 0)
                {   //sorting dari kecil ke besar
                    // masukkan elemen teratas arr1 ke dalam arr3
                    strcpy(arr3[i3].ArtistSong, arr1[i1].ArtistSong);
                    arr3[i3].DurationSong = arr1[i1].DurationSong;
                    strcpy(arr3[i3].NameSong, arr1[i1].NameSong);
                    strcpy(arr3[i3].Codename, arr1[i1].Codename);
                    i3++;
                    i1++;
                }
                // jika elemen teratas arr2 lebih besar dari arr1
                else
                {
                    // masukkan elemen teratas arr2 ke dalam arr3
                    strcpy(arr3[i3].ArtistSong, arr2[i2].ArtistSong);
                    arr3[i3].DurationSong = arr2[i2].DurationSong;
                    strcpy(arr3[i3].NameSong, arr2[i2].NameSong);
                    strcpy(arr3[i3].Codename, arr2[i2].Codename);
                    i3++;
                    i2++;
                }
            }

            // masukkan sisa arr1 jika ada
            while(i1 < total1)
            {
                strcpy(arr3[i3].ArtistSong, arr1[i1].ArtistSong);
                arr3[i3].DurationSong = arr1[i1].DurationSong;
                strcpy(arr3[i3].NameSong, arr1[i1].NameSong);
                strcpy(arr3[i3].Codename, arr1[i1].Codename);
                i3++;
                i1++;
            }
            // masukkan sisa arr2 jika ada
            while(i2 < total2)
            {
                strcpy(arr3[i3].ArtistSong, arr2[i2].ArtistSong);
                arr3[i3].DurationSong = arr2[i2].DurationSong;
                strcpy(arr3[i3].NameSong, arr2[i2].NameSong);
                strcpy(arr3[i3].Codename, arr2[i2].Codename);
                i3++;
                i2++;
            }
        }
        else
        {
            /* code */
            // ulangi hingga arr1 habis atau arr2 habis
            while ((i1 < total1) && (i2 < total2))
            {
                // jika elemen teratas arr1 lebih kecil dari atau sama dengan arr2
                if (arr1[i1].DurationSong < arr2[i2].DurationSong)
                {   //sorting dari kecil ke besar
                    // masukkan elemen teratas arr1 ke dalam arr3
                    strcpy(arr3[i3].ArtistSong, arr1[i1].ArtistSong);
                    arr3[i3].DurationSong = arr1[i1].DurationSong;
                    strcpy(arr3[i3].NameSong, arr1[i1].NameSong);
                    strcpy(arr3[i3].Codename, arr1[i1].Codename);
                    i3++;
                    i1++;
                }
                // jika elemen teratas arr2 lebih besar dari arr1
                else
                {
                    // masukkan elemen teratas arr2 ke dalam arr3
                    strcpy(arr3[i3].ArtistSong, arr2[i2].ArtistSong);
                    arr3[i3].DurationSong = arr2[i2].DurationSong;
                    strcpy(arr3[i3].NameSong, arr2[i2].NameSong);
                    strcpy(arr3[i3].Codename, arr2[i2].Codename);
                    i3++;
                    i2++;
                }
            }

            // masukkan sisa arr1 jika ada
            while(i1 < total1)
            {
                strcpy(arr3[i3].ArtistSong, arr1[i1].ArtistSong);
                arr3[i3].DurationSong = arr1[i1].DurationSong;
                strcpy(arr3[i3].NameSong, arr1[i1].NameSong);
                strcpy(arr3[i3].Codename, arr1[i1].Codename);
                i3++;
                i1++;
            }
            // masukkan sisa arr2 jika ada
            while(i2 < total2)
            {
                strcpy(arr3[i3].ArtistSong, arr2[i2].ArtistSong);
                arr3[i3].DurationSong = arr2[i2].DurationSong;
                strcpy(arr3[i3].NameSong, arr2[i2].NameSong);
                strcpy(arr3[i3].Codename, arr2[i2].Codename);
                i3++;
                i2++;
            }
        }
    }
    else
    {
        /* code */
        // ulangi hingga arr1 habis atau arr2 habis
        while ((i1 < total1) && (i2 < total2))
        {
            // jika elemen teratas arr1 lebih kecil dari atau sama dengan arr2
            if (strcmp(arr1[i1].NameSong, arr2[i2].NameSong) > 0)
            {   //sorting dari kecil ke besar
                // masukkan elemen teratas arr1 ke dalam arr3
                strcpy(arr3[i3].ArtistSong, arr1[i1].ArtistSong);
                arr3[i3].DurationSong = arr1[i1].DurationSong;
                strcpy(arr3[i3].NameSong, arr1[i1].NameSong);
                strcpy(arr3[i3].Codename, arr1[i1].Codename);
                i3++;
                i1++;
            }
            // jika elemen teratas arr2 lebih besar dari arr1
            else
            {
                // masukkan elemen teratas arr2 ke dalam arr3
                strcpy(arr3[i3].ArtistSong, arr2[i2].ArtistSong);
                arr3[i3].DurationSong = arr2[i2].DurationSong;
                strcpy(arr3[i3].NameSong, arr2[i2].NameSong);
                strcpy(arr3[i3].Codename, arr2[i2].Codename);
                i3++;
                i2++;
            }
        }

        // masukkan sisa arr1 jika ada
        while(i1 < total1)
        {
            strcpy(arr3[i3].ArtistSong, arr1[i1].ArtistSong);
            arr3[i3].DurationSong = arr1[i1].DurationSong;
            strcpy(arr3[i3].NameSong, arr1[i1].NameSong);
            strcpy(arr3[i3].Codename, arr1[i1].Codename);
            i3++;
            i1++;
        }
        // masukkan sisa arr2 jika ada
        while(i2 < total2)
        {
            strcpy(arr3[i3].ArtistSong, arr2[i2].ArtistSong);
            arr3[i3].DurationSong = arr2[i2].DurationSong;
            strcpy(arr3[i3].NameSong, arr2[i2].NameSong);
            strcpy(arr3[i3].Codename, arr2[i2].Codename);
            i3++;
            i2++;
        }
    }
}

void display(int total, tracklist_data song[total], float time, char currentplay[])
{
    printf("---------------------------------------------------\n");
    printf("Daftar lagu yang telah dikumpulkan:\n");
    printf("---------------------------------------------------\n");

    int space_name = 0;
    int space_duration = 0;
    for (int i = 0; i < total; i++)
    {
        if (space_name < strlen(song[i].ArtistSong))
        {
            space_name = strlen(song[i].ArtistSong);
        }

        if ((song[i].DurationSong >= 10) && (space_duration == 0))
        {
            /* code */
            space_duration = 1;
        }
        
    }

    for (int i = 0; i < total; i++)
    {
        printf("%s ", song[i].ArtistSong);
        for (int space = 0; space < (space_name - strlen(song[i].ArtistSong)); space++)
        {
            printf(" ");
        }
        printf("%.2f", song[i].DurationSong);
        if (space_duration == 1)
        {
            if (song[i].DurationSong >= 10)
            {
                printf(" ");
            }
            else
            {
                printf("  ");
            }
        }
        else
        {
            printf(" ");
        }
        
        printf("%s\n", song[i].NameSong);
    }
    
    printf("----------------------------------------------------\n");
    printf("Daftar lagu %s yang disetel dalam perjalanan:\n", currentplay);
    printf("----------------------------------------------------\n");

    int TimePlaying = 0; // Inisialisasi total durasi yang telah diputar
    int count = 0;
    int exit_status = 0; // Inisialisasi variabel exit_status
    int last_space = 0;
    space_duration = 0;
    while (count < total && TimePlaying < time && exit_status == 0)
    {
        int front = song[count].DurationSong;
        int back = (song[count].DurationSong - front) * 100;
        // Hitung durasi lagu yang akan diputar (dalam detik)
        TimePlaying += (front * 60) + back;
        if (strcmp(song[count].Codename, currentplay) == 0)
        {
            /* code */
            if (last_space < strlen(song[count].ArtistSong))
            {
                last_space = strlen(song[count].ArtistSong);
            }

            if ((song[count].DurationSong >= 10) && (space_duration == 0))
            {
                /* code */
                space_duration = 1;
            }
        }
        
        //printf("%d\n", TimePlaying);
        // Cek apakah menambahkan lagu ke dalam playlist akan melebihi batasan waktu
        if (TimePlaying > time)
        {
            exit_status = 1; // Jika melebihi, set exit_status ke 1
        }
        // Tambahkan durasi lagu ke dalam total durasi yang telah diputar
        count++;
        
    }
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(song[i].Codename, currentplay) == 0)
        {
            found = 1;
            printf("%s ", song[i].ArtistSong);
            for (int new_space = 0; new_space < (last_space - strlen(song[i].ArtistSong)); new_space++)
            {
                printf(" ");
            }
            printf("%.2f", song[i].DurationSong);
            if (space_duration == 1)
            {
                if (song[i].DurationSong >= 10)
                {
                    printf(" ");
                }
                else
                {
                    printf("  ");
                }
            }
            else
            {
                printf(" ");
            }
            printf("%s\n", song[i].NameSong);
        }
    }

    // If no songs were found for the requested Codename, display a message
    if (found == 0)
    {
        printf("Gak ada yang disetel~\n");
    }
    
    printf("----------------------------------------------------\n");
}