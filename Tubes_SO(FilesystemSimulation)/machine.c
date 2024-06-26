#include "head.h"

// Fungsi untuk membuat direktori baru
void create_directory(const char *dir_name) 
{
    // Membuat direktori dengan menggunakan fungsi mkdir
    if (mkdir(dir_name) == -1) // Memeriksa apakah pembuatan direktori berhasil
    {
        perror("mkdir"); // Mencetak pesan kesalahan jika mkdir gagal
    } else 
    {
        printf("Directory '%s' created successfully.\n", dir_name); // Menampilkan pesan sukses jika mkdir berhasil
    }
}

// Fungsi untuk menghapus direktori
void remove_directory(const char *dir_name) 
{
    // Menghapus direktori dengan menggunakan fungsi rmdir
    if (rmdir(dir_name) == -1) // Memeriksa apakah penghapusan direktori berhasil
    {
        perror("rmdir"); // Mencetak pesan kesalahan jika rmdir gagal
    } else 
    {
        printf("Directory '%s' removed successfully.\n", dir_name); // Menampilkan pesan sukses jika rmdir berhasil
    }
}

// Fungsi untuk menampilkan isi dari suatu direktori
void list_directory(const char *dir_name) 
{
    DIR *dir; // Pointer untuk direktori
    struct dirent *entry; // Struktur untuk entri direktori

    // Membuka direktori dengan menggunakan fungsi opendir
    if ((dir = opendir(dir_name)) == NULL) // Memeriksa apakah pembukaan direktori berhasil
    {
        perror("opendir"); // Mencetak pesan kesalahan jika opendir gagal
        return;
    }

    // Membaca setiap entri dalam direktori yang dibuka
    while ((entry = readdir(dir)) != NULL) 
    {
        printf("%s\n", entry->d_name); // Menampilkan nama setiap entri
    }

    closedir(dir); // Menutup direktori setelah selesai membaca
}

// Fungsi untuk membuat atau memperbarui file
void create_or_update_file(const char *file_name) 
{
    int fd = open(file_name, O_WRONLY | O_CREAT, 0666); // Membuka file dengan menggunakan fungsi open
    if (fd == -1) // Memeriksa apakah pembuatan atau pembukaan file berhasil
    {
        perror("touch"); // Mencetak pesan kesalahan jika pembuatan atau pembukaan file gagal
    } 
    else 
    {
        close(fd); // Menutup file setelah selesai
        printf("File '%s' touched successfully.\n", file_name); // Menampilkan pesan sukses jika pembuatan atau pembukaan file berhasil
    }
}

// Fungsi untuk menghapus file
void remove_file(const char *file_name) 
{
    // Menghapus file dengan menggunakan fungsi unlink
    if (unlink(file_name) == -1) // Memeriksa apakah penghapusan file berhasil
    {
        perror("rm"); // Mencetak pesan kesalahan jika unlink gagal
    } 
    else 
    {
        printf("File '%s' removed successfully.\n", file_name); // Menampilkan pesan sukses jika unlink berhasil
    }
}

void clear_screen() 
{
   printf("Exiting Program...");
}
