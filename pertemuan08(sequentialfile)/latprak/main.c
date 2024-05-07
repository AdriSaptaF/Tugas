#include "header.h"

int main()
{
    int totalmaindata, totalsubdata01, totalsubdata02;
    totalmaindata = 0;
    totalsubdata01 = 0;
    totalsubdata02 = 0;

    skincare_data maindata[50];
    skincare_data finaldata[50];
    skincare_sub_data subdata_brand[50];
    skincare_sub_data subdata_category[50];
    ReadFile(&totalmaindata, maindata, "skincare.txt");
    ReadSubFile(&totalsubdata01, subdata_brand, "brand.txt");
    ReadSubFile(&totalsubdata02, subdata_category, "category.txt");

    int count01, count02;
    count01 = 0;
    count02 = 0;

    for (int i = 0; i < totalmaindata; i++)
    {
        strcpy(finaldata[i].Name, maindata[i].Name);

        for (int j = 0; j < totalsubdata01; j++)
        {
            /* code */
            if (strcmp(maindata[i].Id_Brand, subdata_brand[j].Id_Product) == 0)
            {
                /* code */
                strcpy(finaldata[count01].Id_Brand, subdata_brand[j].Codename);
                count01++;
            }
        }

        for (int k = 0; k < totalsubdata02; k++)
        {
            /* code */
            if (strcmp(maindata[i].Id_Category, subdata_category[k].Id_Product) == 0)
            {
                /* code */
                strcpy(finaldata[count02].Id_Category, subdata_category[k].Codename);
                count02++;
            }
        }
        finaldata[i].Price = maindata[i].Price;
    }
    
    WriteFile(count01, finaldata, "list.txt");
    DisplayFile(0, finaldata, "list.txt");
    
    return 0;
}