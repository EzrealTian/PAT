//
//main.cpp
//B1023-组个最小数
//
//Created by Ezreal on 2019/12/08.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <stdio.h>
int main(){
    int numbers[10];
    for (int i = 0; i < 10; i++) scanf("%d", &numbers[i]);
    for (int i = 1; i < 10; i++) {
        if (numbers[i] != 0) {
            printf("%d", i);
            numbers[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++) while(numbers[i] > 0) {
        printf("%d", i);
        numbers[i]--;
    }
    return 0;
}