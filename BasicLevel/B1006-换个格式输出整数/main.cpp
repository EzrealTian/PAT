//
//main.cpp
//B1006-换个格式输出整数
//
//Created by Ezreal on 2019/--/--.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    int number;
    scanf("%d",&number);
    int A = number / 100;
    number %= 100;
    int B = number / 10;
    int C = number % 10;
    for (int i = 0; i < A; i++) {
        printf("B");
    }
    for (int i = 0; i < B; i++) {
        printf("S");
    }
    for (int i = 0; i < C; i++) {
        printf("%d", i + 1);
    }
    
    return 0;
}