//
//main.cpp
//B1001-3n+1猜想
//
//Created by Ezreal on 2019/07/24.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>

int main(){
    unsigned int n;
    scanf("%d", &n);
    int count = 0;
    while (n != 1) {
        if (n & 1)
            n = (3 * n + 1) / 2;
        else 
            n /= 2;
        count++;
    }
    printf("%d\n", count);
    return 0;
}