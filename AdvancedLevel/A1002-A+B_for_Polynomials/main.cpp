//
//main.cpp
//A1002-A+B for Polynomials
//
//Created by Ezreal on 2019-08-03.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>

int main(){
    int count = 0;
    int K;
    double arr[1001] = {0.0};  //注意系数取值范围
    int exp;    // 次数
    double coe; // 系数
    for (int j = 0; j < 2; j++) {
        scanf("%d", &K);
        for (int i = 0; i < K; i++) {
            scanf("%d%lf", &exp, &coe);
            arr[exp] += coe;
        }
    }
    for (int i = 0; i < 1001; i++) if (arr[i] != 0) count++;
    printf("%d", count);
    for (int i = 1000; i>= 0; i--) if (arr[i] != 0.0) printf(" %d %.1f", i, arr[i]);
    return 0;
}