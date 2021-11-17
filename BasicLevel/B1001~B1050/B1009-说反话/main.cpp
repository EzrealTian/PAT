//
//main.cpp
//B1009-说反话
//
//Created by Ezreal on 2019/09/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    char words[81];
    cin.getline(words, 81);
    //printf("%d", strlen(words));
    int end = strlen(words) - 1;
    bool isFirst = true;
    for (int i = end; i >= 0; i--) {
        if (i > 0 && words[i - 1] != ' ') continue;
        if (isFirst) isFirst = false;
        else printf(" ");
        for (int j = i; j <= end; j++) {
            printf("%c", words[j]);
        }
        i--;
        end = i - 1;
    }
    return 0;
}