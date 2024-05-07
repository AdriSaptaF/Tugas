#include "header.h"

int main()
{
    int total_data;
    scanf("%d", &total_data);

    data_of_books resource_of_books[total_data];
    inputdata(total_data, resource_of_books);

    char keywords_name[50];
    int keywords_page;

    scanf("%s", keywords_name);
    scanf("%d", &keywords_page);

    return 0;
}