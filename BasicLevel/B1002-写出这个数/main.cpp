//
//main.cpp
//B1002-写出这个数
//
//Created by Ezreal on 2019/09/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>
int main(){
    char pinyin[10][5] = {
        {"ling"},
        {"yi"},
        {"er"},
        {"san"},
        {"si"},
        {"wu"},
        {"liu"},
        {"qi"},
        {"ba"},
        {"jiu"}
    };
    char number[100];
    memset(number, 'A', sizeof(char) * 100);
    int sum = 0;
    scanf("%s",number);
    for (int i = 0; i < 101; i++) {
        if (number[i] < '0' || number[i] > '9') break;
        sum = sum + number[i] - '0';
    }
    bool moreThan100 = false;
    if (sum / 100 != 0) {
        printf("%s ",pinyin[sum / 100]);
        sum %= 100;
        moreThan100 = true;
    }
    if (sum / 10 != 0 || moreThan100) printf("%s ", pinyin[sum / 10]);
    printf("%s\n", pinyin[sum % 10]);
    return 0;
}