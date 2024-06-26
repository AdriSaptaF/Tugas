#include "head.h"

int main(int argc, char *argv[]) 
{
    char command[20]; // Variabel untuk menyimpan perintah yang dimasukkan oleh pengguna
    char argument[50]; // Variabel untuk menyimpan argumen tambahan dari perintah

    while (1) { // Loop akan terus berjalan hingga pengguna memasukkan perintah "quit"
        printf("\nEnter command: "); // Meminta pengguna untuk memasukkan perintah
        scanf("%s", command); // Membaca perintah yang dimasukkan oleh pengguna

        if (strcmp(command, "cls") == 0) { // Jika perintah adalah "cls"
            break; // Keluar dari loop dan mengakhiri program
        }

        // Memproses perintah sesuai dengan apa yang dimasukkan oleh pengguna
        if (strcmp(command, "mkdir") == 0) { // Jika perintah adalah "mkdir"
            printf("Enter directory name: "); // Meminta pengguna untuk memasukkan nama direktori
            scanf("%s", argument); // Membaca nama direktori yang dimasukkan oleh pengguna
            create_directory(argument); // Memanggil fungsi create_directory untuk membuat direktori
        } 
        else if (strcmp(command, "rmdir") == 0) { // Jika perintah adalah "rmdir"
            printf("Enter directory name: "); // Meminta pengguna untuk memasukkan nama direktori
            scanf("%s", argument); // Membaca nama direktori yang dimasukkan oleh pengguna
            remove_directory(argument); // Memanggil fungsi remove_directory untuk menghapus direktori
        } 
        else if (strcmp(command, "ls") == 0) { // Jika perintah adalah "ls"
            printf("Enter directory path (press Enter for current directory): "); // Meminta pengguna untuk memasukkan path direktori
            scanf("%s", argument); // Membaca path direktori yang dimasukkan oleh pengguna
            list_directory(argument); // Memanggil fungsi list_directory untuk menampilkan isi direktori
        } 
        else if (strcmp(command, "touch") == 0) { // Jika perintah adalah "touch"
            printf("Enter file name: "); // Meminta pengguna untuk memasukkan nama file
            scanf("%s", argument); // Membaca nama file yang dimasukkan oleh pengguna
            create_or_update_file(argument); // Memanggil fungsi create_or_update_file untuk membuat atau memperbarui file
        } 
        else if (strcmp(command, "rm") == 0) { // Jika perintah adalah "rm"
            printf("Enter file name: "); // Meminta pengguna untuk memasukkan nama file
            scanf("%s", argument); // Membaca nama file yang dimasukkan oleh pengguna
            remove_file(argument); // Memanggil fungsi remove_file untuk menghapus file
        } 
        else { // Jika perintah tidak dikenali
            printf("Unknown command '%s'\n", command); // Cetak pesan kesalahan bahwa perintah tidak dikenali
            printf("Available commands: mkdir, rmdir, ls, touch, rm, quit\n"); // Cetak daftar perintah yang tersedia
        }
    }

    return 0; // Mengembalikan nilai 0, menandakan bahwa program berjalan dengan sukses
}

