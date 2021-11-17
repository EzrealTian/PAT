//
//main.cpp
//B1007-素数对猜想
//
//Created by Ezreal on 2019/12/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <stdio.h>
#include <cmath>
int main(){
    int count = 0;
    int number;
    scanf("%d", &number);
    int preNum = 2;
    int nextNum;
    for (int i = 2; i <= number; i++) {
        int sqrtNum = sqrt(i);
        bool flag = false;
        for (int j = 2; j <= sqrtNum; j++) {
            if (i % j == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            nextNum = i;
            if (nextNum - preNum == 2) count++;
            preNum = i;
        }
    }
    printf("%d\n", count);
    return 0;
}