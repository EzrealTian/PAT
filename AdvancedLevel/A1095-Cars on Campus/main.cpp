//
//main.cpp
//A1095-Cars on Campus
//
//Created by Ezreal on 2019/09/18.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <algorithm>
#include <cstring>

struct record {
    char carID[8];
    char state[4];
    int hour;
    int minute;
    int second;
};
bool compare(record r1, record r2) { return r1.carID < r2.carID;}
using namespace std;
int main(){
    int recordCount, queryCount;
    scanf("%d%d", &recordCount, &queryCount);
    record *list = new record[recordCount];
    for (int i = 0; i < recordCount; i++) scanf("%s%d:%d:%d%s", list[i].carID, &list[i].hour, &list[i].minute, &list[i].second, list[i].state);
    sort(list, list + recordCount, compare);
    printf("---\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%s %d:%d:%d %s\n", list[i].carID, list[i].hour, list[i].minute, list[i].second, list[i].state);
    }

    return 0;
}