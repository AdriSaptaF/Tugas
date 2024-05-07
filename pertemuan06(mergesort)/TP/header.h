#include <stdio.h>
#include <string.h>

typedef struct 
{
    /* data */
    char ArtistSong[50];
    float DurationSong;
    char NameSong[50];
    char Codename[50];

}tracklist_data;

void InputYourTrackList(int total, tracklist_data arr[], int code);
void sorting(int total, tracklist_data song[total], int sort_option);
void MergeData(int total1, int total2, tracklist_data arr1[], tracklist_data arr2[], tracklist_data arr3[], int sort_type, int sort_status);
void display(int total, tracklist_data song[total], float time, char currentplay[]);