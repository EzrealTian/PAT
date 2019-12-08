//
//main.cpp
//A1061-dating
//
//Created by Ezreal on 2019/09/08.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    char arr[4][61];
    for (int i = 0; i < 4; i++) scanf("%s", arr[i]);
    char day[7][4] = {
        {"MON"},
        {"TUE"},
        {"WED"},
        {"THU"},
        {"FRI"},
        {"SAT"},
        {"SUN"}
    };
    int index;
    for (int i = 0; i < 60; i++) {
        if (arr[0][i] == arr[1][i] && arr[0][i] >= 'A' && arr[0][i] <= 'Z') {
            printf("%s ", day[arr[0][i] - 'A']);
            index = i + 1;
            break;
        }
    }
    for (int i = index; i < 60; i++) {
        if (arr[0][i] == arr[1][i]) {
            if (arr[0][i] >= '0' && arr[0][i] <= '9') {
                printf("%02d:", arr[0][i] - '0');
                break;
            }
            if (arr[0][i] >= 'A' && arr[0][i] <= 'N') {
                printf("%02d:", arr[0][i] - 'A' + 10);
                break;
            }
        }
    }
    for (int i = 0; i < 60; i++) {
        if (arr[2][i] == arr[3][i]) {
            if (arr[2][i] >= 'a' && arr[2][i] <= 'z') {
                printf("%02d", i);
                break;
            }
            if (arr[2][i] >= 'A' && arr[2][i] <= 'Z') {
                printf("%02d", i);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}