#include "header.h"

int main()
{
    int total_data;
    scanf("%d", &total_data);

    lab_data input[total_data];
    /*Scan the input data*/
    int count_input;
    for (count_input = 0; count_input < total_data; count_input++)
    {
        scanf("%s %s %d", input[count_input].Lab_Person, input[count_input].Ip_Person, &input[count_input].AccessLevel_Person);
    }

    /*Scan The Sort Type and How to Sort The Data*/
    char sort_type[50];
    char sort_process[50];

    scanf("%s", sort_type);
    scanf("%s", sort_process);

    /*Do The Sort Process*/
    if ((strcmp(sort_type, "Ascending") == 0))
    {
        if ((strcmp(sort_process, "Bubble") == 0))
        {
            /* Do the bubble sorting with ascending style */
            BubbleSort(total_data, input, 0);
        }
        else if ((strcmp(sort_process, "Quick") == 0))
        {
            /* Do the quick sorting with ascending style */
            QuickSortMidPivot(total_data, input, 0, 0, total_data - 1);
        }
        
    }
    else
    {
        if ((strcmp(sort_process, "Bubble") == 0))
        {
            /* Do the bubble sorting with descending style */
            BubbleSort(total_data, input, 1);
        }
        else if ((strcmp(sort_process, "Quick") == 0))
        {
            /* Do the quick sorting with descending style */
            QuickSortMidPivot(total_data, input, 1, 0, total_data - 1);
        }
    }
    
    Display(total_data, input);
    
    return 0;
}