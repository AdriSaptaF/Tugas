/*
Saya Adri Sapta F [2205361] mengerjakan TMD dalam 
mata kuliah Algoritma dan Pemrograman 2 
untuk keberkahanNya maka saya tidak melakukan 
kecurangan seperti yang telah dispesifikasikan. 
Aamiin
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store primary data
typedef struct 
{
    char idlocation[50];   // ID of the location (Primary Key)
    char namelocation[100]; // Name of the location
    char idsembako[100];    // ID of the sembako (Foreign Key)
    char idname[100];       // Name ID
    char status[100];       // Status
} data_utama;

// Structure to store supporting data
typedef struct 
{
    char id[100];   // Generic ID (Primary Key)
    char value[100]; // Value corresponding to the ID
} data_support;

// Global variables
int indeks;         // Index for current processing
int lenwords;       // Length of current word
char cwords[50];    // Current word being processed
int pin_desa;       // Pin The Index from tdesa
int pin_bansos;     // Pin The Index from tbansos
int pin_pj;         // pin The Index from tpj

// Arrays to store data
data_utama lokasi[500];       // Array to store primary data for locations
data_support jenis_sembako[500]; // Array to store support data for sembako
data_support penanggung_jawab[500]; // Array to store support data for responsible persons

// Counters
int count_desa;     // Count of desa (villages)
int count_bansos;   // Count of bansos (social assistance)
int count_pj;       // Count of responsible persons (penanggung jawab)

// Function prototypes
void ReadFile();                    // Function to read data from file
void WriteToFile();                 // Function to write data to file
void NewFileData(int num, char tape[]); // Function to create new file data
void SearchFile(char filename[], char id_search[]); // Function to search in a file
void UpdateFileData(int num, char tape[]); // Function to update file data
void DeleteFileData(int num, char tape[]);
// Word processing functions
void startwords(char pita[]);       // Initialize word processing
void resetwords();                  // Reset current word
void incrementwords(char pita[]);   // Move to next word
char *getcurrentwords();            // Get current word
int getlenwords();                  // Get length of current word
int CheckTape(char tape[]);         // Check the tape for specific conditions
int EOP(char pita[]);               // End of processing check for the tape
void QRECORD(int num, char tape[]); // Function to record query

// Search and processing functions
int SearchKey(int num, char search[], char datacode); // Search for a key in the data
int TotalWords(char tape[]);       // Count total words in the tape
void wait(float x);                // Wait for a specified duration
