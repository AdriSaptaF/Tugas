#include <stdio.h>

int n = 10;
int arr[] = {4, 8, 0, 2, 6, 2, 8, 9, 10, 15};
int targetvalue = 9;


int seqsearch(int n, int arr[], int target)
{
    int found = 0;
    int i = 0;

    while ((i < n) && (found == 0))
    {
        /* code */
        if (arr[i] == target)
        {
            found = 1;
        }
        else
        {
            i++;
        }
    }

    return found;
    
}

int main()
{
    if (seqsearch(n, arr, targetvalue) == 0)
    {
        /* code */
        printf("Tidak ada\n");
    }
    else
    {
        printf("Ada\n");
    }
    
}