#include "header.h"

int main()
{
    int TotalListAbdulSong;
    scanf("%d", &TotalListAbdulSong);
    tracklist_data ListAbdulSong[TotalListAbdulSong];
    InputYourTrackList(TotalListAbdulSong, ListAbdulSong, 0);
    
    int TotalListJasonSong;
    scanf("%d", &TotalListJasonSong);
    tracklist_data ListJasonSong[TotalListJasonSong];
    InputYourTrackList(TotalListJasonSong, ListJasonSong, 1);

    int TotalListRakhaSong;
    scanf("%d", &TotalListRakhaSong);
    tracklist_data ListRakhaSong[TotalListRakhaSong];
    InputYourTrackList(TotalListRakhaSong, ListRakhaSong, 2);

    int TotalListTatthaSong;
    scanf("%d", &TotalListTatthaSong);
    tracklist_data ListTatthaSong[TotalListTatthaSong];
    InputYourTrackList(TotalListTatthaSong, ListTatthaSong, 3);

    int TotalListTaufiqSong;
    scanf("%d", &TotalListTaufiqSong);
    tracklist_data ListTaufiqSong[TotalListTaufiqSong];
    InputYourTrackList(TotalListTaufiqSong, ListTaufiqSong, 4);

    float TravelTime;
    char NowPlayingTheTrackList[50];
    char SortBy[50];
    scanf("%f %s %s", &TravelTime, NowPlayingTheTrackList, SortBy);

    int num12 = TotalListAbdulSong + TotalListJasonSong;
    int num123 = TotalListAbdulSong + TotalListJasonSong + TotalListRakhaSong;
    int num1234 = TotalListAbdulSong + TotalListJasonSong + TotalListRakhaSong + TotalListTatthaSong;
    int AllNum = TotalListAbdulSong + TotalListJasonSong + TotalListRakhaSong + TotalListTatthaSong + TotalListTaufiqSong;

    tracklist_data data12[num12];
    tracklist_data data123[num123];
    tracklist_data data1234[num1234];
    tracklist_data AllData[AllNum];
    if (strcmp(SortBy, "Band") == 0)
    {
        /* code */
        sorting(TotalListAbdulSong, ListAbdulSong, 0);
        sorting(TotalListJasonSong, ListJasonSong, 0);
        sorting(TotalListRakhaSong, ListRakhaSong, 0);
        sorting(TotalListTatthaSong, ListTatthaSong, 0);
        sorting(TotalListTaufiqSong, ListTaufiqSong, 0);

        MergeData(TotalListAbdulSong, TotalListJasonSong, ListAbdulSong, ListJasonSong, data12, 0, 0);
        MergeData(num12, TotalListRakhaSong, data12, ListRakhaSong, data123, 0, 0);
        MergeData(num123, TotalListTatthaSong, data123, ListTatthaSong, data1234, 0, 0);
        MergeData(num1234, TotalListTaufiqSong, data1234, ListTaufiqSong, AllData, 0, 0);

    }
    else if (strcmp(SortBy, "Durasi") == 0)
    {
        /* code */
        sorting(TotalListAbdulSong, ListAbdulSong, 1);
        sorting(TotalListJasonSong, ListJasonSong, 1);
        sorting(TotalListRakhaSong, ListRakhaSong, 1);
        sorting(TotalListTatthaSong, ListTatthaSong, 1);
        sorting(TotalListTaufiqSong, ListTaufiqSong, 1);

        MergeData(TotalListAbdulSong, TotalListJasonSong, ListAbdulSong, ListJasonSong, data12, 0, 1);
        MergeData(num12, TotalListRakhaSong, data12, ListRakhaSong, data123, 0, 1);
        MergeData(num123, TotalListTatthaSong, data123, ListTatthaSong, data1234, 0, 1);
        MergeData(num1234, TotalListTaufiqSong, data1234, ListTaufiqSong, AllData, 0, 1);
    }
    else
    {
        /* code */
        sorting(TotalListAbdulSong, ListAbdulSong, 2);
        sorting(TotalListJasonSong, ListJasonSong, 2);
        sorting(TotalListRakhaSong, ListRakhaSong, 2);
        sorting(TotalListTatthaSong, ListTatthaSong, 2);
        sorting(TotalListTaufiqSong, ListTaufiqSong, 2);

        MergeData(TotalListAbdulSong, TotalListJasonSong, ListAbdulSong, ListJasonSong, data12, 1, 0);
        MergeData(num12, TotalListRakhaSong, data12, ListRakhaSong, data123, 1, 0);
        MergeData(num123, TotalListTatthaSong, data123, ListTatthaSong, data1234, 1, 0);
        MergeData(num1234, TotalListTaufiqSong, data1234, ListTaufiqSong, AllData, 1, 0);
    }
    
    
    if (strcmp(NowPlayingTheTrackList, "Abdul") == 0)
    {
        /* code */
        display(AllNum, AllData, TravelTime, "Abdul");
    }
    else if (strcmp(NowPlayingTheTrackList, "Jason") == 0)
    {
        /* code */
        display(AllNum, AllData, TravelTime, "Jason");
    }
    else if (strcmp(NowPlayingTheTrackList, "Rakha") == 0)
    {
        /* code */
        display(AllNum, AllData, TravelTime, "Rakha");
    }
    else if (strcmp(NowPlayingTheTrackList, "Tattha") == 0)
    {
        /* code */
        display(AllNum, AllData, TravelTime, "Tattha");
    }
    else
    {
        /* code */
        display(AllNum, AllData, TravelTime, "Taufiq");
    } 
    

    return 0;
}