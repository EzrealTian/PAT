//
//main.cpp
//B1017-A除以B
//
//Created by Ezreal on 2019/12/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <stdio.h>
#include <cstring>
int main(){
    char number[1000];
    int subNum;
    scanf("%s%d", number, &subNum);
    int length = strlen(number);

    int restNum = 0;    //余数
    for (int i = 0; i < length; i++) {
        int temp = restNum * 10 + number[i] - '0';
        if (temp / subNum > 0) {
            number[i] = temp / subNum + '0';
            restNum = temp % subNum;
        } else {
            restNum = number[i] - '0';
            number[i] = '0';
        }
    }
    if (!(length > 1 && number[0] == '0')) printf("%c", number[0]);
    
    for (int i = 1; i < length; i++) printf("%c", number[i]);
    printf(" %d\n", restNum);
    return 0;
}