#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

// Deklarasi fungsi-fungsi yang akan digunakan
void create_directory(const char *dir_name); // Membuat direktori baru
void remove_directory(const char *dir_name); // Menghapus direktori
void list_directory(const char *dir_name); // Menampilkan isi direktori
void create_or_update_file(const char *file_name); // Membuat atau memperbarui file
void remove_file(const char *file_name); // Menghapus file
void clear_screen(); // menghapus layar