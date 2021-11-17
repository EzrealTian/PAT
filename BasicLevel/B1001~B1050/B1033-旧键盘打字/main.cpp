//
//main.cpp
//B1033-旧键盘打字
//
//Created by Ezreal on 2019/12/03.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    bool charSet[128] = {false};    //散列数组，标记坏键
    char string1[68], string2[100001];
    cin.getline(string1, 68);
    cin.getline(string2, 100001);
    for(int i = 0; i < strlen(string1); i++) {  //将所有坏键置为true
        if (string1[i] >= 'A' && string1[i] <= 'Z') charSet[string1[i] - 'A' + 'a'] = true;
        charSet[string1[i]] = true;
    }
    int length = strlen(string2);
    for (int i = 0; i < length; i++) {  
        if (!charSet[string2[i]]) { //判断键位故障
            if (string2[i] >= 'A' && string2[i] <= 'Z' && charSet['+']) printf(""); //判断shift故障
            else printf("%c", string2[i]);
        }
    }
    printf("\n");
    return 0;
}