#include "header.h"

int main()
{
    int m = 0;
    dataName listMenu[50]; // Alokasi data menu

    readFileName(&m, listMenu, "Menu.dat"); // panggil fungsi read file untuk scanning data file

    // MENAMPILKAN DATA MENU
    printf("Menu:\n");
    for(int i = 0; i < m; i++)
    {
        printf("%s %d %s\n", listMenu[i].nama, listMenu[i].harga, listMenu[i].jenis);
    }

    return 0;
}
