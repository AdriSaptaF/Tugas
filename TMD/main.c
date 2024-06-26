/*
Saya Adri Sapta F [2205361] mengerjakan TMD dalam mata kuliah Algoritma dan Pemrograman 2 
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main()
{
    system("cls"); // Clear the screen
    char tape[201]; // Buffer to hold the input command
    int finish_state = 0; // Variable to control the main loop

    // Display welcome messages with delays
    wait(1);
    printf("Wilujeng Sumping di DBMS Bermanfaat bagi Negeri Indonesia\n");
    wait(1);
    printf("Versi 1.0\n\n");
    wait(1);
    printf("00000000000000000000000000000000000000000000000000000000\n");
    wait(1);
    printf("   0000000000000000000000000000000000000000000000000\n");
    wait(1);
    printf("                    Semangat Pagi\n");
    wait(1);
    printf("   0000000000000000000000000000000000000000000000000\n");
    wait(1);
    printf("00000000000000000000000000000000000000000000000000000000\n");
    wait(1);

    // Main loop that runs until finish_state is set to 1
    while (finish_state == 0)
    {
        printf("\ndbms [Adri] > "); // Prompt for user input
        scanf(" %200[^\n]s", tape); // Read user input into tape

        startwords(tape); // Initialize word processing with the input tape
        int total_cwords = TotalWords(tape); // Get total words in the input tape

        // Check if the command is "BYE"
        if (strcmp(getcurrentwords(), "BYE") == 0)
        {
            system("cls"); // Clear the screen
            printf("\nTerima Kasih Telah Menggunakan Program ini.\n");
            printf("Sampai Takdir Mempertemukan Kita Kembali :)\n");
            finish_state = 1; // Set finish_state to 1 to exit the loop
        }
        else
        {
            QRECORD(total_cwords, tape); // Process the input command
        }
        
        // Clear the tape buffer for the next input
        for (int i = 0; i < indeks; i++)
        {
            tape[i] = '\0';
        }
    }
    
    return 0; // Exit the program
}
