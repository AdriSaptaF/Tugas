#include "header.h"

void inputdata(int total, data_of_books resource[total])
{
    for (int i = 0; i < total; i++)
    {
        /* code */
        scanf("%s %d", resource[i].BooksName, &resource[i].BooksPage);
    }
}

void sequential_search(int total, data_of_books resource[total], char keywords[])
{
    int found = 0;
    int count = 0;

    while ((count < total) && (found == 0))
    {
        /* code */
        if (strcmp(resource[count].BooksName, keywords) == 0)
        {
            /* code */
            found = 1;
        }
        else
        {
            count++;
        }
        
    }

}

void sort_page_data(int total, data_of_books resource[total])
{
    for (int i = 0; i < (total - 1); i++)
        {
            int minIndex = i;//set minindex

            for (int j = i + 1; j < total; j++)
            {
                //if (strcmp(song[minIndex].ArtistSong, song[j].ArtistSong) > 0)
                if (resource[minIndex].BooksPage > resource[j].BooksPage)
                {   //sorting kecil ke besar
                    //jika sortvalue dengan indeks minindex lebih dari sorvalue dengan indeks j
                    //maka minindex menjadi sama dengan j
                    minIndex = j;
                }
            }

            //tukar posisi data
            char tempc[50];
            strcpy(tempc, resource[i].BooksName);
            strcpy(resource[i].BooksName, resource[minIndex].BooksName);
            strcpy(resource[minIndex].BooksName, tempc);

            int temp = resource[i].BooksPage;
            resource[i].BooksPage = resource[minIndex].BooksPage;
            resource[minIndex].BooksPage = temp;
        }
}
void binary_search(int total, data_of_books resource[total], int keys)
{
    int count1, count2, midindex;
    count1 = 0;
    count2 = total - 1;
    int found = 0;

    while ((found == 0) && (count1 <= count2))
    {
        /* code */
        midindex = (count1 + count2) / 2;

        if (resource[midindex].BooksPage == keys)
        {
            /* code */
            found = 1;
        }
        else
        {
            if (resource[midindex].BooksPage >= keys)
            {
                /* code */
                count2 = midindex - 1;
            }
            else
            {
                count1 = midindex + 1;
            }
            
        }
        
    }
}

void display()
{

}