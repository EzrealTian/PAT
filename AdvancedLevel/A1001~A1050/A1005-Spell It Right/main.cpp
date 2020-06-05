//
//main.cpp
//A1005-Spell It Right
//
//Created by Ezreal on 2019/09/11.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>

int main(){
    char set[10][6] = {
        {"zero"},
        {"one"},
        {"two"},
        {"three"},
        {"four"},
        {"five"},
        {"six"},
        {"seven"},
        {"eight"},
        {"nine"}
    };
    char arr[101];
    scanf("%s", arr);
    int length = strlen(arr);
    int sum = 0;
    for (int i = 0; i < length; i++) sum += arr[i] - '0';
    if (sum / 100 > 0) printf("%s %s %s\n", set[sum / 100], set[sum % 100 / 10], set[sum % 100 % 10]);
    else if (sum / 10 > 0) printf("%s %s\n", set[sum / 10], set[sum % 10]);
    else printf("%s\n", set[sum]);
    return 0;
}