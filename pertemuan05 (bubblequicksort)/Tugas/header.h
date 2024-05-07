/*Library Declaration*/
#include <stdio.h>
#include <string.h>

/*Struct Data input Lab Person*/
typedef struct 
{
    char Lab_Person[50];
    char Ip_Person[20];
    int AccessLevel_Person;
} lab_data;

/*Declaration Of Procedure*/
int check_and_compare_IP(char *str1, char *str2);
void BubbleSort(int total, lab_data data[total], int status);
//void QuickSortUjung(int total, lab_data data[total], int status, int left, int right);
void QuickSortMidPivot(int total, lab_data data[total], int status, int left, int right);
void Display(int total, lab_data data[total]);
