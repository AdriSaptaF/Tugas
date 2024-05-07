#include <stdio.h>
#include <string.h>

typedef struct 
{
    /* data */
    char BooksName[50];
    int BooksPage;
}data_of_books;

void inputdata(int total, data_of_books resource[total]);
