//
//main.cpp
//B1021-个位数统计
//
//Created by Ezreal on 2019/09/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>
int main(){
    char number[1001];
    memset(number,'A',sizeof(char)*1001);
    scanf("%s", number);
    int result[10];
    memset(result, 0, sizeof(int)*10);
    for (int i = 0; i < 1001; i++) {
        if (number[i] == 'A') break;
        result[number[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (result[i] != 0) printf("%d:%d\n",i, result[i]);
    }
    return 0;
}