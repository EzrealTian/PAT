//
//main.cpp
//B1002-写出这个数
//
//Created by Ezreal on 2019/09/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
int main(){
    char pinyin[10][5] = {  // 字典数组
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

    string str;
    cin >> str;
    int number = 0;
    for (auto it : str) number += (it - '0');   // 计算各位和

    str = to_string(number);
    for (int i = 0; i < str.length(); i++)
        printf("%s%s", i == 0 ? "" : " ", pinyin[str[i] - '0']);
    return 0;
}