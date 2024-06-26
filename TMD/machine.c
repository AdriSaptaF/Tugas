/*
Saya Adri Sapta F [2205361] mengerjakan TMD dalam mata kuliah Algoritma dan Pemrograman 2 
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"


void ReadFile()
{
    // File pointers for reading data from files
    FILE *fdesa;
    FILE *fbansos;
    FILE *fpj;

    // Initialize counters for each type of data
    count_desa = 0;
    count_bansos = 0;
    count_pj = 0;

    // Open the file containing location data in read mode
    fdesa = fopen("../TMD/tdesa.dat", "r");
    // Read the first line of data into the lokasi array
    fscanf(fdesa, "%s %s %s %s %s", lokasi[count_desa].idlocation, lokasi[count_desa].namelocation, lokasi[count_desa].idsembako,
           lokasi[count_desa].idname, lokasi[count_desa].status);
    // Loop to read until the end marker "####" is encountered
    while (strcmp(lokasi[count_desa].idlocation, "####") != 0)
    {
        count_desa++; // Increment the counter for desa
        // Read the next line of data into the lokasi array
        fscanf(fdesa, "%s %s %s %s %s", lokasi[count_desa].idlocation, lokasi[count_desa].namelocation, lokasi[count_desa].idsembako,
               lokasi[count_desa].idname, lokasi[count_desa].status);
    }
    fclose(fdesa); // Close the location data file

    // Open the file containing bansos data in read mode
    fbansos = fopen("../TMD/tbansos.dat", "r");
    // Read the first line of data into the jenis_sembako array
    fscanf(fbansos, "%s %s", jenis_sembako[count_bansos].id, jenis_sembako[count_bansos].value);
    // Loop to read until the end marker "####" is encountered
    while (strcmp(jenis_sembako[count_bansos].id, "####") != 0)
    {
        count_bansos++; // Increment the counter for bansos
        // Read the next line of data into the jenis_sembako array
        fscanf(fbansos, "%s %s", jenis_sembako[count_bansos].id, jenis_sembako[count_bansos].value);
    }
    fclose(fbansos); // Close the bansos data file
    
    // Open the file containing penanggung jawab data in read mode
    fpj = fopen("../TMD/tpenanggungjawab.dat", "r");
    // Read the first line of data into the penanggung_jawab array
    fscanf(fpj, "%s %s", penanggung_jawab[count_pj].id, penanggung_jawab[count_pj].value);
    // Loop to read until the end marker "####" is encountered
    while (strcmp(penanggung_jawab[count_pj].id, "####") != 0)
    {
        count_pj++; // Increment the counter for penanggung jawab
        // Read the next line of data into the penanggung_jawab array
        fscanf(fpj, "%s %s", penanggung_jawab[count_pj].id, penanggung_jawab[count_pj].value);
    }
    fclose(fpj); // Close the penanggung jawab data file
}

void SearchFile(char filename[], char id_search[])
{
    // Temporary array to hold data read from the file
    data_support arr[100];
    int count_arr = 0; // Counter for the array
    FILE *fsearch; // File pointer for the search file

    // Open the file in read mode
    fsearch = fopen(filename, "r");

    // Read the first line of data into the array
    fscanf(fsearch, "%s %s", arr[count_arr].id, arr[count_arr].value);

    // Loop to read until the end marker "####" is encountered
    while (strcmp(arr[count_arr].id, "####") != 0)
    {
        // If the current id matches the search id, print the corresponding value
        if (strcmp(arr[count_arr].id, id_search) == 0)
        {
            printf("%-20s ", arr[count_arr].value);
        }
        count_arr++; // Increment the counter
        // Read the next line of data into the array
        fscanf(fsearch, "%s %s", arr[count_arr].id, arr[count_arr].value);
    }

    // Close the file after reading all data
    fclose(fsearch);
}


void WriteToFile()
{
    FILE *fdesa;   // File pointer for desa data
    FILE *fbansos; // File pointer for bansos data
    FILE *fpj;     // File pointer for penanggung jawab data

    // Open the file containing location data in write mode
    fdesa = fopen("../TMD/tdesa.dat", "w");
    // Loop through each entry in the lokasi array and write it to the file
    for (int count_data = 0; count_data < count_desa; count_data++)
    {
        fprintf(fdesa, "%s %s %s %s %s\n", lokasi[count_data].idlocation, lokasi[count_data].namelocation, lokasi[count_data].idsembako,
                lokasi[count_data].idname, lokasi[count_data].status);
    }
    // Write the end marker to indicate the end of the data
    fprintf(fdesa, "%s %s %s %s %s\n", "####", "####", "####", "####", "####");
    // Close the location data file
    fclose(fdesa);

    // Open the file containing bansos data in write mode
    fbansos = fopen("../TMD/tbansos.dat", "w");
    // Loop through each entry in the jenis_sembako array and write it to the file
    for (int count_data = 0; count_data < count_bansos; count_data++)
    {
        fprintf(fbansos, "%s %s\n", jenis_sembako[count_data].id, jenis_sembako[count_data].value);
    }
    // Write the end marker to indicate the end of the data
    fprintf(fbansos, "%s %s\n", "####", "####");
    // Close the bansos data file
    fclose(fbansos);

    // Open the file containing penanggung jawab data in write mode
    fpj = fopen("../TMD/tpenanggungjawab.dat", "w");
    // Loop through each entry in the penanggung_jawab array and write it to the file
    for (int count_data = 0; count_data < count_pj; count_data++)
    {
        fprintf(fpj, "%s %s\n", penanggung_jawab[count_data].id, penanggung_jawab[count_data].value);
    }
    // Write the end marker to indicate the end of the data
    fprintf(fpj, "%s %s\n", "####", "####");
    // Close the penanggung jawab data file
    fclose(fpj);
}


void NewFileData(int num, char tape[])
{
    char input[100];
    char update[100];
    char delete[100];

    ReadFile();  // Read the existing data from the files

    // Copy the current word from the tape to the input string and increment the tape position
    strcpy(input, getcurrentwords());
    incrementwords(tape);

    int valid_check = 1;  // Flag to check if the input is valid

    if (strcmp(getcurrentwords(), "UPDATE") == 0)
    {
        strcpy(update, getcurrentwords());  // Copy the current word to the update string
        incrementwords(tape);
        
        if (valid_check == 1)
        {
            // Handle updating desa data
            if ((strcmp(getcurrentwords(), "desa") == 0) && (num == 8))
            {
                incrementwords(tape);

                int check_key = SearchKey(count_desa, getcurrentwords(), 'd');  // Search for existing key in desa data
                if (check_key == 0)
                {
                    // Key not found, add new entry
                    strcpy(lokasi[count_desa].idlocation, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[count_desa].namelocation, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[count_desa].idsembako, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[count_desa].idname, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[count_desa].status, getcurrentwords());

                    int check_bansoscode = SearchKey(count_bansos, lokasi[count_desa].idsembako, 'b');
                    int check_pjcode = SearchKey(count_pj, lokasi[count_desa].idname, 'p');
                    if ((check_bansoscode == 0) && (check_pjcode == 0))
                    {
                        printf("DataValue.Errors : Some Value Is Not Exist.\n");
                        printf("Recommend : Please Check Again Your Input.\n");
                    }
                    else
                    {
                        printf("1 Queries Executed, Success with No Errors.\n");
                        printf("Query Executed : %s\n", input);
                        printf("Data Has Been Updated!!\n");

                        count_desa++;
                    }
                }
                else
                {
                    // Key found, update existing entry
                    strcpy(lokasi[pin_desa].idlocation, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[pin_desa].namelocation, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[pin_desa].idsembako, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[pin_desa].idname, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[pin_desa].status, getcurrentwords());

                    printf("1 Queries Executed, Success with No Errors.\n");
                    printf("Query Executed : %s\n", update);
                    printf("Data Has Been Updated!!\n");
                }
            }
            else if((strcmp(getcurrentwords(), "bansos") == 0) && (num == 5))  // Handle updating bansos data
            {
                incrementwords(tape);

                int check_key = SearchKey(count_bansos, getcurrentwords(), 'b');  // Search for existing key in bansos data
                if (check_key == 0)
                {
                    // Key not found, add new entry
                    strcpy(jenis_sembako[count_bansos].id, getcurrentwords());
                    incrementwords(tape);
                    strcpy(jenis_sembako[count_bansos].value, getcurrentwords());

                    printf("1 Queries Executed, Success with No Errors.\n");
                    printf("Query Executed : %s\n", input);
                    printf("Data Has Been Updated!!\n");

                    count_bansos++;
                }
                else
                {
                    // Key found, update existing entry
                    strcpy(jenis_sembako[pin_bansos].id, getcurrentwords());
                    incrementwords(tape);
                    strcpy(jenis_sembako[pin_bansos].value, getcurrentwords());

                    printf("1 Queries Executed, Success with No Errors.\n");
                    printf("Query Executed : %s\n", update);
                    printf("Data Has Been Updated!!\n");
                }
            }
            else if((strcmp(getcurrentwords(), "pj") == 0) && (num == 5))  // Handle updating penanggung jawab data
            {
                incrementwords(tape);

                int check_key = SearchKey(count_pj, getcurrentwords(), 'p');  // Search for existing key in pj data
                if (check_key == 0)
                {
                    // Key not found, add new entry
                    strcpy(penanggung_jawab[count_pj].id, getcurrentwords());
                    incrementwords(tape);
                    strcpy(penanggung_jawab[count_pj].value, getcurrentwords());

                    printf("1 Queries Executed, Success with No Errors.\n");
                    printf("Query Executed : %s\n", input);
                    printf("Data Has Been Updated!!\n");

                    count_pj++;
                }
                else
                {
                    // Key found, update existing entry
                    incrementwords(tape);
                    strcpy(penanggung_jawab[pin_pj].id, getcurrentwords());
                    incrementwords(tape);
                    strcpy(penanggung_jawab[pin_pj].value, getcurrentwords());

                    printf("1 Queries Executed, Success with No Errors.\n");
                    printf("Query Executed : %s\n", update);
                    printf("Data Has Been Updated!!\n");
                }
            }
            else
            {
                printf("DataFormat.Errors : Table Was Not Found.\n");
                printf("ExpressionQuery.Error : We Couldn't Scan Your Input\n");
                printf("Recommend : Maybe You Mean Is INPUT UPDATE [table_name] xxx xxx xxx xxx;\n");
            }
        }
        
    }
    else if (strcmp(getcurrentwords(), "DELETE") == 0)
    {
        strcpy(delete, getcurrentwords());
        incrementwords(tape);

        if (valid_check == 1)
        {
            if((strcmp(getcurrentwords(), "desa") == 0) && (num == 8))
            {
                incrementwords(tape);

                int check_key = SearchKey(count_desa, getcurrentwords(), 'd');  // Search for existing key in desa data
                if (check_key == 0)
                {
                    // Key not found, display error
                    strcpy(lokasi[count_desa].idlocation, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[count_desa].namelocation, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[count_desa].idsembako, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[count_desa].idname, getcurrentwords());
                    incrementwords(tape);
                    strcpy(lokasi[count_desa].status, getcurrentwords());

                    int check_bansoscode = SearchKey(count_bansos, lokasi[count_desa].idsembako, 'b');
                    int check_pjcode = SearchKey(count_pj, lokasi[count_desa].idname, 'p');

                    if ((check_bansoscode == 0) && (check_pjcode == 0))
                    {
                        printf("DataValue.Errors : Some Value Is Not Exist.\n");
                        printf("Recommend : Please Check Again Your Input.\n");
                    }
                    else
                    {
                        printf("1 Queries Executed, Success with No Errors.\n");
                        printf("Query Executed : %s\n", input);
                        printf("Data Has Been Updated!!\n");

                        count_desa++;
                    }
                }
                else
                {
                    // Key found, delete the entry
                    printf("1 Queries Executed, Success with No Errors.\n");
                    printf("Query Executed : %s\n", delete);
                    printf("Data Has Been Deleted!!\n");

                    for (int delete_index = pin_desa; delete_index < count_desa; delete_index++)
                    {
                        strcpy(lokasi[delete_index].idlocation, lokasi[delete_index + 1].idlocation);
                        strcpy(lokasi[delete_index].namelocation,lokasi[delete_index + 1].namelocation);
                        strcpy(lokasi[delete_index].idsembako, lokasi[delete_index + 1].idsembako);
                        strcpy(lokasi[delete_index].idname, lokasi[delete_index + 1].idname);
                        strcpy(lokasi[delete_index].status, lokasi[delete_index + 1].status);
                    }
                    count_desa--;
                }   
            }
            else if((strcmp(getcurrentwords(), "bansos") == 0) && (num == 5))
            {
                incrementwords(tape);

                int check_key = SearchKey(count_bansos, getcurrentwords(), 'b');  // Search for existing key in bansos data
                if (check_key == 0)
                {
                    // Key not found, display error
                    strcpy(jenis_sembako[count_bansos].id, getcurrentwords());
                    incrementwords(tape);
                    strcpy(jenis_sembako[count_bansos].value, getcurrentwords());

                    printf("1 Queries Executed, Success with No Errors.\n");
                    printf("Query Executed : %s\n", input);
                    printf("Data Has Been Updated!!\n");

                    count_bansos++;
                }
                else
                {
                    // Key found, delete the entry
                    printf("1 Queries Executed, Success with No Errors.\n");
                    printf("Query Executed : %s\n", delete);
                    printf("Data Has Been Deleted!!\n");

                    for (int delete_index = pin_bansos; delete_index < count_bansos; delete_index++)
                    {
                        strcpy(jenis_sembako[delete_index].id, jenis_sembako[delete_index + 1].id);
                        strcpy(jenis_sembako[delete_index].value, jenis_sembako[delete_index + 1].value);
                    }
                    count_bansos--;
                }
            }
            else if((strcmp(getcurrentwords(), "pj") == 0) && (num == 5))
            {
                incrementwords(tape);

                int check_key = SearchKey(count_pj, getcurrentwords(), 'p');  // Search for existing key in pj data
                if (check_key == 0)
                {
                    // Key not found, display error
                    strcpy(penanggung_jawab[count_pj].id, getcurrentwords());
                    incrementwords(tape);
                    strcpy(penanggung_jawab[count_pj].value, getcurrentwords());

                    printf("1 Queries Executed, Success with No Errors.\n");
                    printf("Query Executed : %s\n", input);
                    printf("Data Has Been Updated!!\n");

                    count_pj++;
                }
                else
                {
                    // Key found, delete the entry
                    printf("1 Queries Executed, Success with No Errors.\n");
                    printf("Query Executed : %s\n", delete);
                    printf("Data Has Been Deleted!!\n");

                    for (int delete_index = pin_pj; delete_index < count_pj; delete_index++)
                    {
                        strcpy(penanggung_jawab[delete_index].id, penanggung_jawab[delete_index + 1].id);
                        strcpy(penanggung_jawab[delete_index].value, penanggung_jawab[delete_index + 1].value);
                    }
                    count_pj--;
                }
            }
            else
            {
                printf("DataFormat.Errors : Table Was Not Found.\n");
                printf("ExpressionQuery.Error : We Couldn't Scan Your Input\n");
                printf("Recommend : Maybe You Mean Is INPUT UPDATE xxx xxx xxx xxx xxx;\n");
                valid_check = 0; 
            }   
        } 
    }
    else
    {
        // Handle other operations
        if (valid_check == 1)
        {
            if(num == 7)
            {
                if(strcmp(getcurrentwords(), "desa") == 0)
                {
                    incrementwords(tape);

                    int check_key = SearchKey(count_desa, getcurrentwords(), 'd');  // Search for existing key in desa data
                    if (check_key == 0)
                    {
                        // Key not found, add new entry
                        strcpy(lokasi[count_desa].idlocation, getcurrentwords());
                        incrementwords(tape);
                        strcpy(lokasi[count_desa].namelocation, getcurrentwords());
                        incrementwords(tape);
                        strcpy(lokasi[count_desa].idsembako, getcurrentwords());
                        incrementwords(tape);
                        strcpy(lokasi[count_desa].idname, getcurrentwords());
                        incrementwords(tape);
                        strcpy(lokasi[count_desa].status, getcurrentwords());
                        
                        int check_bansoscode = SearchKey(count_bansos, lokasi[count_desa].idsembako, 'b');
                        int check_pjcode = SearchKey(count_pj, lokasi[count_desa].idname, 'p');
                        if ((check_bansoscode == 0) && (check_pjcode == 0))
                        {
                            printf("DataValue.Errors : Some Value Is Not Exist.\n");
                            printf("Recommend : Please Check Again Your Input.\n");
                        }
                        else
                        {
                            printf("1 Queries Executed, Success with No Errors.\n");
                            printf("Query Executed : %s\n", input);
                            printf("Data Has Been Updated!!\n");

                            count_desa++;
                        }
                    }
                    else
                    {
                        printf("DataFormat.Errors : Data Already Exist.\n");
                        printf("Recommend : Check Your Input.\n");
                    }
                }
                else
                {
                    printf("DataFormat.Errors : Table Was Not Found.\n");
                } 
            }
            else if(num == 4)
            {
                if(strcmp(getcurrentwords(), "bansos") == 0)
                {
                    incrementwords(tape);

                    int check_key = SearchKey(count_bansos, getcurrentwords(), 'b');  // Search for existing key in bansos data
                    if (check_key == 0)
                    {
                        // Key not found, add new entry
                        strcpy(jenis_sembako[count_bansos].id, getcurrentwords());
                        incrementwords(tape);
                        strcpy(jenis_sembako[count_bansos].value, getcurrentwords());

                        printf("1 Queries Executed, Success with No Errors.\n");
                        printf("Query Executed : %s\n", input);
                        printf("Data Has Been Updated!!\n");

                        count_bansos++;
                    }
                    else
                    {
                        printf("DataFormat.Errors : Data Already Exist.\n");
                        printf("Recommend : Check Your Input.\n");
                    }
                }
                else if(strcmp(getcurrentwords(), "pj") == 0)
                {
                    incrementwords(tape);

                    int check_key = SearchKey(count_pj, getcurrentwords(), 'p');  // Search for existing key in pj data
                    if (check_key == 0)
                    {
                        // Key not found, add new entry
                        strcpy(penanggung_jawab[count_pj].id, getcurrentwords());
                        incrementwords(tape);
                        strcpy(penanggung_jawab[count_pj].value, getcurrentwords());

                        printf("1 Queries Executed, Success with No Errors.\n");
                        printf("Query Executed : %s\n", input);
                        printf("Data Has Been Updated!!\n");

                        count_pj++;
                    }
                    else
                    {
                        printf("DataFormat.Errors : Data Already Exist.\n");
                        printf("Recommend : Check Your Input.\n");
                    }
                }
                else
                {
                    printf("DataFormat.Errors : Table Was Not Found.\n");
                }        
            }
            else
            {
                printf("ExpressionQuery.Error : We Couldn't Scan Your Input\n");
                printf("Recommend : Maybe You Mean Is INPUT [table_name] xxx xxx xxx xxx;\n");
            }
        }
    }

    WriteToFile();  // Write the updated data to the files
}

void UpdateFileData(int num, char tape[])
{
    ReadFile();  // Read the existing data from the files
    incrementwords(tape);  // Move to the next word in the tape

    int valid_check = 1;  // Flag to check if the input is valid
    
    if (valid_check == 1)
    {
        // Handle updating desa data
        if ((strcmp(getcurrentwords(), "desa") == 0) && (num == 7))
        {
            incrementwords(tape);

            int check_key = SearchKey(count_desa, getcurrentwords(), 'd');  // Search for existing key in desa data

            if (check_key == 0)
            {
                // Key not found, display error
                printf("DataValue.Errors : Some Value Is Not Exist.\n");
                printf("Reccomend : Please Check Again Your Input.\n");
            }
            else
            {
                // Key found, update existing entry
                strcpy(lokasi[pin_desa].idlocation, getcurrentwords());
                incrementwords(tape);
                strcpy(lokasi[pin_desa].namelocation, getcurrentwords());
                incrementwords(tape);
                strcpy(lokasi[pin_desa].idsembako, getcurrentwords());
                incrementwords(tape);
                strcpy(lokasi[pin_desa].idname, getcurrentwords());
                incrementwords(tape);
                strcpy(lokasi[pin_desa].status, getcurrentwords());

                printf("1 Queries Executed, Success with No Errors.\n");
                printf("Query Executed : UPDATE\n");
                printf("Data Has Been Updated!!\n");
            }
        }
        // Handle updating bansos data
        else if ((strcmp(getcurrentwords(), "bansos") == 0) && (num == 4))
        {
            incrementwords(tape);

            int check_key = SearchKey(count_bansos, getcurrentwords(), 'b');  // Search for existing key in bansos data

            if (check_key == 0)
            {
                // Key not found, display error
                printf("DataValue.Errors : Some Value Is Not Exist.\n");
                printf("Reccomend : Please Check Again Your Input.\n");
            }
            else
            {
                // Key found, update existing entry
                strcpy(jenis_sembako[pin_bansos].id, getcurrentwords());
                incrementwords(tape);
                strcpy(jenis_sembako[pin_bansos].value, getcurrentwords());
    
                printf("1 Queries Executed, Success with No Errors.\n");
                printf("Query Executed : UPDATE\n");
                printf("Data Has Been Updated!!\n");
            }
        }
        // Handle updating penanggung jawab (pj) data
        else if ((strcmp(getcurrentwords(), "pj") == 0) && (num == 4))
        {
            incrementwords(tape);

            int check_key = SearchKey(count_pj, getcurrentwords(), 'p');  // Search for existing key in pj data

            if (check_key == 0)
            {
                // Key not found, display error
                printf("DataValue.Errors : Some Value Is Not Exist.\n");
                printf("Reccomend : Please Check Again Your Input.\n");
            }
            else
            {
                // Key found, update existing entry
                strcpy(penanggung_jawab[pin_pj].id, getcurrentwords());
                incrementwords(tape);
                strcpy(penanggung_jawab[pin_pj].value, getcurrentwords());
    
                printf("1 Queries Executed, Success with No Errors.\n");
                printf("Query Executed : UPDATE\n");
                printf("Data Has Been Updated!!\n");
            }
        } 
        else
        {
            // Handle case where table is not found
            printf("DataFormat.Errors : Table Was Not Found.\n");
        } 
    }

    WriteToFile();  // Write the updated data to the files
}


void DeleteFileData(int num, char tape[])
{
    ReadFile();  // Read the existing data from the files
    incrementwords(tape);  // Move to the next word in the tape

    int valid_check = 1;  // Flag to check if the input is valid
    
    if (valid_check == 1)
    {
        // Handle deleting desa data
        if ((strcmp(getcurrentwords(), "desa") == 0) && (num == 3))
        {
            incrementwords(tape);

            int check_key = SearchKey(count_desa, getcurrentwords(), 'd');  // Search for existing key in desa data
            if (check_key == 0)
            {
                // Key not found, display error
                printf("DataValue.Errors : Some Value Is Not Exist.\n");
                printf("Reccomend : Please Check Again Your Input.\n");
            }
            else
            {
                // Key found, delete existing entry
                printf("1 Queries Executed, Success with No Errors.\n");
                printf("Query Executed : DELETE\n");
                printf("Data Has Been Deleted!!\n");

                // Shift remaining entries to fill the gap
                for (int delete_index = pin_desa; delete_index < count_desa; delete_index++)
                {
                    strcpy(lokasi[delete_index].idlocation, lokasi[delete_index + 1].idlocation);
                    strcpy(lokasi[delete_index].namelocation, lokasi[delete_index + 1].namelocation);
                    strcpy(lokasi[delete_index].idsembako, lokasi[delete_index + 1].idsembako);
                    strcpy(lokasi[delete_index].idname, lokasi[delete_index + 1].idname);
                    strcpy(lokasi[delete_index].status, lokasi[delete_index + 1].status);
                }
                count_desa--;  // Decrease the count of desa entries
            }
        }
        // Handle deleting bansos data
        else if ((strcmp(getcurrentwords(), "bansos") == 0) && (num == 3))
        {
            incrementwords(tape);

            int check_key = SearchKey(count_bansos, getcurrentwords(), 'b');  // Search for existing key in bansos data
            if (check_key == 0)
            {
                // Key not found, display error
                printf("DataValue.Errors : Some Value Is Not Exist.\n");
                printf("Reccomend : Please Check Again Your Input.\n");
            }
            else
            {
                // Key found, delete existing entry
                printf("1 Queries Executed, Success with No Errors.\n");
                printf("Query Executed : DELETE\n");
                printf("Data Has Been Deleted!!\n");

                // Shift remaining entries to fill the gap
                for (int delete_index = pin_bansos; delete_index < count_bansos; delete_index++)
                {
                    strcpy(jenis_sembako[delete_index].id, jenis_sembako[delete_index + 1].id);
                    strcpy(jenis_sembako[delete_index].value, jenis_sembako[delete_index + 1].value);
                }
                count_bansos--;  // Decrease the count of bansos entries
            }
        }
        // Handle deleting penanggung jawab (pj) data
        else if ((strcmp(getcurrentwords(), "pj") == 0) && (num == 3))
        {
            incrementwords(tape);

            int check_key = SearchKey(count_pj, getcurrentwords(), 'p');  // Search for existing key in pj data
            if (check_key == 0)
            {
                // Key not found, display error
                printf("DataValue.Errors : Some Value Is Not Exist.\n");
                printf("Reccomend : Please Check Again Your Input.\n");
            }
            else
            {
                // Key found, delete existing entry
                printf("1 Queries Executed, Success with No Errors.\n");
                printf("Query Executed : DELETE\n");
                printf("Data Has Been Deleted!!\n");

                // Shift remaining entries to fill the gap
                for (int delete_index = pin_pj; delete_index < count_pj; delete_index++)
                {
                    strcpy(penanggung_jawab[delete_index].id, penanggung_jawab[delete_index + 1].id);
                    strcpy(penanggung_jawab[delete_index].value, penanggung_jawab[delete_index + 1].value);
                }
                count_pj--;  // Decrease the count of pj entries
            }
        }
        else
        {
            // Handle case where table is not found
            printf("DataFormat.Errors : Table Was Not Found.\n");
        }
    }
    
    WriteToFile();  // Write the updated data to the files
}


void ShowFileData(int num, char tape[])
{
    ReadFile();  // Read the existing data from the files
    incrementwords(tape);  // Move to the next word in the tape

    int valid_check = 1;  // Flag to check if the input is valid

    // Check if the number of arguments is within the valid range
    if (num < 2 || num > 4)
    {
        printf("ExpressionQuery.Error : We Couldn't Scan Your Input\n");
        printf("Reccomend : Maybe You Mean Is SHOW [table_name] or SHOW [table_name] [table_name] ...;\n");
        valid_check = 0;  // Set the valid_check flag to 0 (invalid input)
    }

    if (valid_check == 1)
    {
        // Case when only one table is requested to be shown
        if (num == 2)
        {
            if (strcmp(getcurrentwords(), "desa") == 0)
            {
                printf("%-10s %-20s %-20s\n", "ID_Desa", "Nama_Lokasi", "Status");
                printf("----------------------------------------------------\n");
                for (int index_show = 0; index_show < count_desa; index_show++)
                {
                    printf("%-10s %-20s %-20s\n", lokasi[index_show].idlocation, lokasi[index_show].namelocation, lokasi[index_show].status);
                }
            }
            else if (strcmp(getcurrentwords(), "bansos") == 0)
            {
                printf("%-10s %-20s\n", "ID_Bansos", "Jenis_Bansos");
                printf("-----------------------------\n");
                for (int index_show = 0; index_show < count_bansos; index_show++)
                {
                    printf("%-10s %-20s\n", jenis_sembako[index_show].id, jenis_sembako[index_show].value);
                }
            }
            else if (strcmp(getcurrentwords(), "pj") == 0)
            {
                printf("%-10s %-20s\n", "ID_PJ", "Nama_Penanggung_Jawab");
                printf("-----------------------------\n");
                for (int index_show = 0; index_show < count_pj; index_show++)
                {
                    printf("%-10s %-20s\n", penanggung_jawab[index_show].id, penanggung_jawab[index_show].value);
                }
            }
        }
        // Case when two tables are requested to be shown with a join
        else if (num == 3)
        {
            if (strcmp(getcurrentwords(), "desa") == 0)
            {
                incrementwords(tape);
                if (strcmp(getcurrentwords(), "bansos") == 0)
                {
                    printf("%-10s %-20s %-20s %-20s\n", "ID_Desa", "Nama_Lokasi", "Jenis_Bansos", "Status");
                    printf("--------------------------------------------------------------------------\n");
                    for (int index_show = 0; index_show < count_desa; index_show++)
                    {
                        printf("%-10s %-20s ", lokasi[index_show].idlocation, lokasi[index_show].namelocation);
                        SearchFile("../TMD/tbansos.dat", lokasi[index_show].idsembako);  // Search for bansos data by ID
                        printf("%-20s\n", lokasi[index_show].status);
                    }
                }
                else if (strcmp(getcurrentwords(), "pj") == 0)
                {
                    printf("%-10s %-20s %-20s %-20s\n", "ID_Desa", "Nama_Lokasi", "Nama_PJ", "Status");
                    printf("--------------------------------------------------------------------------\n");
                    for (int index_show = 0; index_show < count_desa; index_show++)
                    {
                        printf("%-10s %-20s ", lokasi[index_show].idlocation, lokasi[index_show].namelocation);
                        SearchFile("../TMD/tpenanggungjawab.dat", lokasi[index_show].idname);  // Search for pj data by ID
                        printf("%-20s\n", lokasi[index_show].status);
                    }
                } 
            }
            else
            {
                printf("ExpressionFormat.Error : Can't Join The Table Foreign Key Not Found\n");
                printf("Reccomend : Check The Table\n");
            }
        }
        // Case when three tables are requested to be shown with a join
        else
        {
            if (strcmp(getcurrentwords(), "desa") == 0)
            {
                printf("%-10s %-20s %-20s %-20s %-20s\n", "ID_Lokasi", "Nama_Lokasi", "Jenis_Bansos", "Nama_PJ", "Status");
                printf("---------------------------------------------------------------------------------------------------\n");
                for (int index_show = 0; index_show < count_desa; index_show++)
                {
                    printf("%-10s %-20s ", lokasi[index_show].idlocation, lokasi[index_show].namelocation);
                    SearchFile("../TMD/tbansos.dat", lokasi[index_show].idsembako);  // Search for bansos data by ID
                    SearchFile("../TMD/tpenanggungjawab.dat", lokasi[index_show].idname);  // Search for pj data by ID
                    printf("%-10s\n", lokasi[index_show].status);
                }
            }
            else
            {
                printf("ExpressionFormat.Error : Can't Join The Table Foreign Key Not Found\n");
                printf("Reccomend : Check The Table\n");
            }
        }
    }
}

void startwords(char pita[])
{
    // Initialize index and length of current word
    indeks = 0;
    lenwords = 0;

    // Skip leading spaces
    while (pita[indeks] == ' ')
    {
        indeks++;
    }

    // Extract the first word until a space or semicolon is encountered
    while ((pita[indeks] != ' ') && (pita[indeks] !=  ';'))
    {
        // Store the current character in the current word array
        cwords[lenwords] = pita[indeks];
        indeks++;
        lenwords++;
    }
    // Null-terminate the current word string
    cwords[lenwords] = '\0';
}


void resetwords()
{
    // Reset the length of the current word to 0
    lenwords = 0;
    
    // Null-terminate the current word string to effectively "clear" it
    cwords[lenwords] = '\0';
}


void incrementwords(char pita[])
{
    // Reset the length of the current word to 0
    lenwords = 0;

    // Skip any leading spaces
    while (pita[indeks] == ' ')
    {
        indeks++;
    }

    // Read the next word until a space or semicolon is encountered
    while ((pita[indeks] != ' ') && (pita[indeks] != ';'))
    {
        cwords[lenwords] = pita[indeks];  // Store the character in cwords
        indeks++;                         // Move to the next character
        lenwords++;                       // Increase the length of the word
    }

    // Null-terminate the current word string
    cwords[lenwords] = '\0';
}

// Function to get the current word stored in the cwords array
char *getcurrentwords()
{
    return cwords;  // Return the pointer to the current word
}


// Function to get the length of the current word stored in the lenwords variable
int getlenwords()
{
    return lenwords;  // Return the length of the current word
}


// Function to check and count the number of words in the given tape (string)
int CheckTape(char tape[])
{
    int len_tape = 0;  // Initialize a counter for the number of words in the tape
    startwords(tape);  // Start parsing the first word from the tape

    // Loop until the end of the tape is reached
    while (EOP(tape) == 0)
    {
        len_tape++;          // Increment the word counter
        incrementwords(tape); // Move to the next word in the tape
    }
    
    // If there is a remaining word that has not been counted, increment the counter
    if (getlenwords() > 0)
    {
        len_tape++;
    }
    return len_tape;  // Return the total number of words in the tape
}


// Function to check if the end of the tape (string) has been reached
int EOP(char pita[])
{
    // Check if the current character in the tape is the end-of-tape marker (';')
    if (pita[indeks] == ';')
    {
        return 1; // Return 1 to indicate the end of the tape has been reached
    }
    else
    {
        return 0; // Return 0 to indicate that the end of the tape has not been reached
    }
}


void QRECORD(int num, char tape[])
{
    // Memeriksa kata kunci pertama pada perintah
    if (strcmp(getcurrentwords(), "INPUT") == 0)
    {
        // Memanggil fungsi untuk menangani perintah INPUT
        NewFileData(num, tape);
    }
    else if (strcmp(getcurrentwords(), "UPDATE") == 0)
    {
        // Memanggil fungsi untuk menangani perintah UPDATE
        UpdateFileData(num, tape);
    }
    else if (strcmp(getcurrentwords(), "DELETE") == 0)
    {
        // Memanggil fungsi untuk menangani perintah DELETE
        DeleteFileData(num, tape);
    }
    else if (strcmp(getcurrentwords(), "SHOW") == 0)
    {
        // Memanggil fungsi untuk menangani perintah SHOW
        ShowFileData(num, tape);
    }
    else
    {
        // Menampilkan pesan error jika perintah tidak valid
        printf("DataFormat.Error : invalid Query\n");
        printf("Reccomend : Use INPUT, UPDATE, DELETE, or SHOW Command.\n");
    }
}


int SearchKey(int num, char search[], char datacode)
{
    int index = 0;
    int found = 0;

    // Memeriksa datacode untuk menentukan jenis data yang dicari ('d' untuk lokasi, 'b' untuk bansos, 'p' untuk penanggung jawab)
    if (datacode == 'd')
    {
        // Mencari ID lokasi di array lokasi
        while ((index < num) && (found == 0))
        {
            if (strcmp(lokasi[index].idlocation, search) == 0)
            {
                found = 1;
                pin_desa = index; // Menyimpan indeks lokasi yang ditemukan
            }
            else
            {
                index++;
            }
        }
    }
    else if (datacode == 'b')
    {
        // Mencari ID bansos di array jenis_sembako
        while ((index < num) && (found == 0))
        {
            if (strcmp(jenis_sembako[index].id, search) == 0)
            {
                found = 1;
                pin_bansos = index; // Menyimpan indeks bansos yang ditemukan
            }
            else
            {
                index++;
            }
        }
    }
    else if (datacode == 'p')
    {
        // Mencari ID penanggung jawab di array penanggung_jawab
        while ((index < num) && (found == 0))
        {
            if (strcmp(penanggung_jawab[index].id, search) == 0)
            {
                found = 1;
                pin_pj = index; // Menyimpan indeks penanggung jawab yang ditemukan
            }
            else
            {
                index++;
            }
        }
    }
    
    // Mengembalikan nilai 1 jika data ditemukan, atau 0 jika tidak ditemukan
    if (found == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void wait(float x)
{
    time_t start; 
    time_t current; 
    time (&start);//making the start time 
    do
    { 
        time (&current);//making the current time 
        //doing checking while the different time under x and //meet the ending if the different time is x 
    } while (difftime(current, start) < x);
}

int TotalWords(char tape[])
{
    int temp_idx = indeks; // Simpan nilai indeks saat ini untuk penggunaan sementara
    int totalwords = 0; // Inisialisasi jumlah kata
    int stop_looping = 0; // Variabel untuk menghentikan looping

    // Looping sampai bertemu dengan ';' atau kondisi berhenti lainnya
    while ((stop_looping == 0))
    {
        // Memeriksa jika karakter saat ini adalah spasi
        if (tape[temp_idx] == ' ')
        {
            totalwords++; // Jika ya, tambahkan ke jumlah kata
        }
        
        // Memeriksa jika karakter saat ini adalah ';'
        if (tape[temp_idx] == ';')
        {
            stop_looping = 1; // Jika ya, atur variabel stop_looping menjadi 1 untuk menghentikan looping
        }

        temp_idx++; // Pindah ke karakter berikutnya di dalam string tape
    }
    
    return (totalwords + 1); // Mengembalikan jumlah kata, ditambah 1 untuk menghitung kata terakhir setelah ';'
}
