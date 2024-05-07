#include <stdio.h>
#include <string.h>
typedef struct 
{
    /* data */
    char Name[50];
    char Id_Brand[10];
    char Id_Category[10];
    int Price;
}skincare_data;

typedef struct 
{
    /* data */
    char Id_Product[10];
    char Codename[50];
}skincare_sub_data;


void ReadFile(int *num, skincare_data src[], char file[]);
void ReadSubFile(int *num, skincare_sub_data src[], char file[]);
void WriteFile(int num, skincare_data src[], char file[]);
void DisplayFile(int num, skincare_data src[], char file[]);