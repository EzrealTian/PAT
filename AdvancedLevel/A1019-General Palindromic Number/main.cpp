//
//main.cpp
//A1019-General Palindromic Number
//
//Created by Ezreal on 2019/09/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    int number, base;
    scanf("%d%d", &number, &base);
    int result[32] = {0};
    int count;
    //求出进制数
    for (count = 0; count < 32; count++) {
        result[count] = number % base;
        if (number / base == 0 ) break;
        else number /= base; 
    }
    //判断回文
    bool isPalin = true;
    for (int i = 0; i <= count/2; i++) {
        if (result[i] != result[count - i]) {
            isPalin = false;
            break;
        }
    }
    //输出
    isPalin == true ? printf("Yes\n") : printf("No\n");
    for (int i = count; i >= 0; i--) {
        if (i == count) printf("%d", result[i]);
        else printf(" %d", result[i]);
    }
    return 0;
}