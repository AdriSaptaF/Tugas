#include "header.h"

void ReadFile(int *num, skincare_data src[], char file[])
{
    FILE *ftemp;
    ftemp = fopen(file, "r");
    int returnvalue = fscanf(ftemp, "%s %s %s %d", src[*num].Name, src[*num].Id_Brand, src[*num].Id_Category, &src[*num].Price);

    if ((strcmp(src[*num].Name, "####") == 0))
    {
        /* code */
        printf("File Kosong\n");
    }
    else
    {
        while (strcmp(src[*num].Name, "####") != 0)
        {
            /* code */
            *num = *num + 1;
            fscanf(ftemp, "%s %s %s %d", src[*num].Name, src[*num].Id_Brand, src[*num].Id_Category, &src[*num].Price);
        } 
    }


    fclose(ftemp);
    
}
void ReadSubFile(int *num, skincare_sub_data src[], char file[])
{
    FILE *ftemp;
    ftemp = fopen(file, "r");
    int returnvalue = fscanf(ftemp, "%s %s", src[*num].Id_Product, src[*num].Codename);

    if ((strcmp(src[*num].Id_Product, "####") == 0))
    {
        /* code */
        printf("File Kosong\n");
    }
    else
    {
        while (strcmp(src[*num].Id_Product, "####") !=0)
        {
            /* code */
            *num = *num + 1;
            fscanf(ftemp, "%s %s", src[*num].Id_Product, src[*num].Codename);
        } 
    }

    fclose(ftemp);
}
void WriteFile(int num, skincare_data src[], char file[])
{
    FILE *ftemp;
    ftemp = fopen(file, "w");

    for (int i = 0; i < num; i++)
    {
        /* code */
        fprintf(ftemp, "%s %s %s %d\n", src[i].Name, src[i].Id_Brand, src[i].Id_Category, &src[i].Price);
    }
    
    fprintf(ftemp, "%s %s %s %s\n", "####", "####", "####", "####");

    fclose(ftemp);
}

void DisplayFile(int num, skincare_data src[], char file[])
{
    FILE *ftemp;
    ftemp = fopen(file, "r");
    int returnvalue = fscanf(ftemp, "%s %s %s %d", src[num].Name, src[num].Id_Brand, src[num].Id_Category, &src[num].Price);

    if ((strcmp(src[num].Name, "####") == 0))
    {
        /* code */
        printf("File Kosong\n");
    }
    else
    {
        while (strcmp(src[num].Name, "####") !=0)
        {
            /* code */
            num++;
            fscanf(ftemp, "%s %s %s %d", src[num].Name, src[num].Id_Brand, src[num].Id_Category, &src[num].Price);
        } 
    }

    for (int i = 0; i < num; i++)
    {
        /* code */
        printf("%s %s %s %d\n", src[i].Name, src[i].Id_Brand, src[i].Id_Category, src[i].Price);
    }
    
    fclose(ftemp);
}
