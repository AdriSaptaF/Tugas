#include "header.h"

int check_and_compare_IP(char *str1, char *str2)
{
    int num1 = 0, num2 = 0; // Untuk menyimpan nilai angka sementara
    int i = 0, j = 0; // Index untuk iterasi pada string

    while (str1[i] != '\0' && str2[j] != '\0') 
    {
        // Ambil angka pertama dari setiap string
        while (str1[i] != '.' && str1[i] != '\0') 
        {
            num1 = num1 * 10 + (str1[i] - '0');
            i++;
        }

        while (str2[j] != '.' && str2[j] != '\0') 
        {
            num2 = num2 * 10 + (str2[j] - '0');
            j++;
        }

        // Bandingkan nilai numerik
        if (num1 > num2) 
        {
            return 1;
        } 
        else if (num2 > num1) 
        {
            return 0;
        }

        // Reset nilai angka sementara untuk bagian selanjutnya
        num1 = 0;
        num2 = 0;

        // Lewati titik (.) untuk iterasi selanjutnya
        if (str1[i] == '.') 
        {
            i++;
        }
        if (str2[j] == '.') 
        {
            j++;
        }
    }
}


void BubbleSort(int total, lab_data data[total], int status)
{
    int count_sort;
    int temp_number;
    char temp_string[50];
    int swap;

    if (status == 0)
    {
        do
        {
            swap = 0;
            for (count_sort = 0; count_sort < (total - 1); count_sort++)
            {
                if (data[count_sort].AccessLevel_Person > data[count_sort + 1].AccessLevel_Person)
                {
                    strcpy(temp_string, data[count_sort].Lab_Person);
                    strcpy(data[count_sort].Lab_Person, data[count_sort + 1].Lab_Person);
                    strcpy(data[count_sort + 1].Lab_Person, temp_string);

                    strcpy(temp_string, data[count_sort].Ip_Person);
                    strcpy(data[count_sort].Ip_Person, data[count_sort + 1].Ip_Person);
                    strcpy(data[count_sort + 1].Ip_Person, temp_string);
                    
                    temp_number = data[count_sort].AccessLevel_Person;
                    data[count_sort].AccessLevel_Person = data[count_sort + 1].AccessLevel_Person;
                    data[count_sort + 1].AccessLevel_Person = temp_number;

                    swap = 1;
                }
                else if (data[count_sort].AccessLevel_Person == data[count_sort + 1].AccessLevel_Person)
                {
                    if (check_and_compare_IP(data[count_sort].Ip_Person, data[count_sort + 1].Ip_Person) == 1)
                    {
                        strcpy(temp_string, data[count_sort].Lab_Person);
                        strcpy(data[count_sort].Lab_Person, data[count_sort + 1].Lab_Person);
                        strcpy(data[count_sort + 1].Lab_Person, temp_string);

                        strcpy(temp_string, data[count_sort].Ip_Person);
                        strcpy(data[count_sort].Ip_Person, data[count_sort + 1].Ip_Person);
                        strcpy(data[count_sort + 1].Ip_Person, temp_string);
                        
                        temp_number = data[count_sort].AccessLevel_Person;
                        data[count_sort].AccessLevel_Person = data[count_sort + 1].AccessLevel_Person;
                        data[count_sort + 1].AccessLevel_Person = temp_number;

                        swap = 1;
                    }
                    
                }
                
                
            }
            
        } while (swap == 1);
    }
    else
    {
        do
        {
            swap = 0;
            for (count_sort = 0; count_sort < (total - 1); count_sort++)
            {
                if (data[count_sort].AccessLevel_Person < data[count_sort + 1].AccessLevel_Person)
                {
                    strcpy(temp_string, data[count_sort].Lab_Person);
                    strcpy(data[count_sort].Lab_Person, data[count_sort + 1].Lab_Person);
                    strcpy(data[count_sort + 1].Lab_Person, temp_string);

                    strcpy(temp_string, data[count_sort].Ip_Person);
                    strcpy(data[count_sort].Ip_Person, data[count_sort + 1].Ip_Person);
                    strcpy(data[count_sort + 1].Ip_Person, temp_string);
                    
                    temp_number = data[count_sort].AccessLevel_Person;
                    data[count_sort].AccessLevel_Person = data[count_sort + 1].AccessLevel_Person;
                    data[count_sort + 1].AccessLevel_Person = temp_number;

                    swap = 1;
                }
                else if (data[count_sort].AccessLevel_Person == data[count_sort + 1].AccessLevel_Person)
                {
                    if (check_and_compare_IP(data[count_sort].Ip_Person, data[count_sort + 1].Ip_Person) == 0)
                    {
                        strcpy(temp_string, data[count_sort].Lab_Person);
                        strcpy(data[count_sort].Lab_Person, data[count_sort + 1].Lab_Person);
                        strcpy(data[count_sort + 1].Lab_Person, temp_string);

                        strcpy(temp_string, data[count_sort].Ip_Person);
                        strcpy(data[count_sort].Ip_Person, data[count_sort + 1].Ip_Person);
                        strcpy(data[count_sort + 1].Ip_Person, temp_string);
                        
                        temp_number = data[count_sort].AccessLevel_Person;
                        data[count_sort].AccessLevel_Person = data[count_sort + 1].AccessLevel_Person;
                        data[count_sort + 1].AccessLevel_Person = temp_number;

                        swap = 1;
                    }
                    
                }
                
                
            }
            
        } while (swap == 1);
    }
}


/*void QuickSortUjung(int total, lab_data data[total], int status, int left, int right)
{
    int count01, count02;
    char temp_string[50];
    int temp_number;
    count01 = left;
    count02 = right;

   if (status == 0)
    {
        do
        {
            printf("awal : %d %d\n", count01, count02);
            while (((data[count01].AccessLevel_Person < data[right].AccessLevel_Person) || ((data[count01].AccessLevel_Person == data[right].AccessLevel_Person) && (check_and_compare_IP(data[count01].Ip_Person, data[right].Ip_Person) == 1) && count01 != right)) && (count01 <= count02))
            {
                printf("%d\n", check_and_compare_IP(data[count01].Ip_Person, data[right].Ip_Person));
                count01++;
            }
            
            while (((data[count02].AccessLevel_Person > data[left].AccessLevel_Person) || ((data[count02].AccessLevel_Person == data[left].AccessLevel_Person) && (check_and_compare_IP(data[count02].Ip_Person, data[left].Ip_Person) == 1) && count02 != left)) && (count01 <= count02))
            {
                count02--;
            }
            printf("akhir : %d %d\n", count01, count02);
            if (count01 < count02)
            {
                strcpy(temp_string, data[count01].Lab_Person);
                strcpy(data[count01].Lab_Person, data[count02].Lab_Person);
                strcpy(data[count02].Lab_Person, temp_string);

                strcpy(temp_string, data[count01].Ip_Person);
                strcpy(data[count01].Ip_Person, data[count02].Ip_Person);
                strcpy(data[count02].Ip_Person, temp_string);
                
                temp_number = data[count01].AccessLevel_Person;
                data[count01].AccessLevel_Person = data[count02].AccessLevel_Person;
                data[count02].AccessLevel_Person = temp_number;

                count01++;
                count02--;
            }
        } while (count01 < count02);
        
        if ((left < count02) && (count02 < right))
        {
            QuickSortUjung(total, data, status, left, count02);
        }

        if ((count01 < right) && (count01 > left))
        {
            QuickSortUjung(total, data, status, count01, right);
        }
    }
    else
    {
        do
        {
            while (((data[count01].AccessLevel_Person > data[right].AccessLevel_Person) || ((data[count01].AccessLevel_Person == data[right].AccessLevel_Person) && (check_and_compare_IP(data[count01].Ip_Person, data[right].Ip_Person) == 0))) && (count01 <= count02))
            {
                count01++;
            }
            
            while (((data[count02].AccessLevel_Person < data[left].AccessLevel_Person) || ((data[count02].AccessLevel_Person == data[left].AccessLevel_Person) && (check_and_compare_IP(data[count02].Ip_Person, data[left].Ip_Person) == 0))) && (count01 <= count02))
            {
                count02--;
            }
    
            if (count01 < count02)
            {
                strcpy(temp_string, data[count01].Lab_Person);
                strcpy(data[count01].Lab_Person, data[count02].Lab_Person);
                strcpy(data[count02].Lab_Person, temp_string);

                strcpy(temp_string, data[count01].Ip_Person);
                strcpy(data[count01].Ip_Person, data[count02].Ip_Person);
                strcpy(data[count02].Ip_Person, temp_string);
                
                temp_number = data[count01].AccessLevel_Person;
                data[count01].AccessLevel_Person = data[count02].AccessLevel_Person;
                data[count02].AccessLevel_Person = temp_number;

                count01++;
                count02--;
            }
        } while (count01 < count02);
        
        if ((left < count02) && (count02 < right))
        {
           QuickSortUjung(total, data, status, left, count02);
        }

        if ((count01 < right) && (count01 > left))
        {
            QuickSortUjung(total, data, status, count01, right);
        }
    }
    
}*/
void QuickSortMidPivot(int total, lab_data data[total], int status, int left, int right)
{
    int count01, count02;
    char temp_string[50];
    int temp_number;
    count01 = left;
    count02 = right;

    int pivot = data[(left + right + 1) / 2].AccessLevel_Person;
    char pivot02[50];
    strcpy(pivot02, data[(left + right + 1) / 2].Ip_Person);
    if (status == 0)
    {
        do
        {
            while (((data[count01].AccessLevel_Person < pivot) || ((data[count01].AccessLevel_Person == pivot) && (check_and_compare_IP(data[count01].Ip_Person, pivot02) == 1) && count01 != ((left + right) / 2))) && (count01 <= count02))
            {
                count01++;
            }
            
            while (((data[count02].AccessLevel_Person > pivot) || ((data[count02].AccessLevel_Person == pivot) && (check_and_compare_IP(data[count02].Ip_Person, pivot02) == 1) && count02 != ((left + right) / 2))) && (count01 <= count02))
            {
                count02--;
            }
            
            if (count01 < count02)
            {
                strcpy(temp_string, data[count01].Lab_Person);
                strcpy(data[count01].Lab_Person, data[count02].Lab_Person);
                strcpy(data[count02].Lab_Person, temp_string);

                strcpy(temp_string, data[count01].Ip_Person);
                strcpy(data[count01].Ip_Person, data[count02].Ip_Person);
                strcpy(data[count02].Ip_Person, temp_string);
                
                temp_number = data[count01].AccessLevel_Person;
                data[count01].AccessLevel_Person = data[count02].AccessLevel_Person;
                data[count02].AccessLevel_Person = temp_number;

                count01++;
                count02--;
            }
        } while (count01 < count02);
        
        if ((left < count02) && (count02 < right))
        {
            
            QuickSortMidPivot(total, data, status, left, count02);
        }

        if ((count01 < right) && (count01 > left))
        {
            QuickSortMidPivot(total, data, status, count01, right);
        }
    }
    else
    {
        do
        {
            while (((data[count01].AccessLevel_Person > pivot) || ((data[count01].AccessLevel_Person == pivot) && (check_and_compare_IP(data[count01].Ip_Person, pivot02) == 0) && count01 != ((left + right) / 2))) && (count01 <= count02))
            {
                count01++;
            }
            
            while (((data[count02].AccessLevel_Person < pivot) || ((data[count02].AccessLevel_Person == pivot) && (check_and_compare_IP(data[count02].Ip_Person, pivot02) == 0) && count02 != ((left + right) / 2))) && (count01 <= count02))
            {
                count02--;
            }   
            if (count01 < count02)
            {
                strcpy(temp_string, data[count01].Lab_Person);
                strcpy(data[count01].Lab_Person, data[count02].Lab_Person);
                strcpy(data[count02].Lab_Person, temp_string);

                strcpy(temp_string, data[count01].Ip_Person);
                strcpy(data[count01].Ip_Person, data[count02].Ip_Person);
                strcpy(data[count02].Ip_Person, temp_string);
                
                temp_number = data[count01].AccessLevel_Person;
                data[count01].AccessLevel_Person = data[count02].AccessLevel_Person;
                data[count02].AccessLevel_Person = temp_number;

                count01++;
                count02--;
            }
        } while (count01 < count02);
        
        if ((left < count02) && (count02 < right))
        {
           QuickSortMidPivot(total, data, status, left, count02);
        }

        if ((count01 < right) && (count01 > left))
        {
            QuickSortMidPivot(total, data, status, count01, right);
        }
    }
}

void Display(int total, lab_data data[total])
{
    int length_string01 = 0;
    for (int count_data = 0; count_data < total; count_data++)
    {
       if (length_string01 < strlen(data[count_data].Lab_Person))
       {
            length_string01 = strlen(data[count_data].Lab_Person);
       }
       
    }

    int length_string02 = 0;
    for (int count_data = 0; count_data < total; count_data++)
    {
       if (length_string02 < strlen(data[count_data].Ip_Person))
       {
            length_string02 = strlen(data[count_data].Ip_Person);
       }
       
    }

    for (int print_data = 0; print_data < total; print_data++)
    {
        printf("%s ", data[print_data].Lab_Person);
        for (int space = 0; space < (length_string01 - strlen(data[print_data].Lab_Person)); space++)
        {
            printf(" ");
        }
        printf("%s ", data[print_data].Ip_Person);
        for (int space = 0; space < (length_string02 - strlen(data[print_data].Ip_Person)); space++)
        {
            printf(" ");
        }
        printf("%d\n", data[print_data].AccessLevel_Person);
    }
}