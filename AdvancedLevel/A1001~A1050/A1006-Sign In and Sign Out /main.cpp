//
//main.cpp
//A1006-Sign In and Sign Out
//
//Created by Ezreal on 2019/09/04.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>

int main(){
    int count;
    scanf("%d", &count);
    char number[16];
    //结果
    char theEarly[16];
    char theLate[16];
    int hour, minute, minus;
    int early = 24 * 60 * 60;
    int late = 0;
    for (int i = 0; i < count; i++) {
        scanf("%s", number);
        scanf("%d:%d:%d",&hour, &minute, &minus);
        if(hour * 3600 + minute * 60 + minus < early) {
            early = hour * 3600 + minute * 60 + minus;
            strcpy(theEarly, number);
        }
        scanf("%d:%d:%d",&hour, &minute, &minus);
        if(hour * 3600 + minute * 60 + minus > late) {
            late = hour * 3600 + minute * 60 + minus;
            strcpy(theLate, number);
        }
    }
    printf("%s %s\n",theEarly, theLate);
    return 0;
}