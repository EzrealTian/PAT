//
//main.cpp
//A1002-A+B for Polynomials
//
//Created by Ezreal on 2019/08/03.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    int count = 0;
    int N;
    double arr1[1001] = {0.0};  //注意系数取值范围
    double arr2[1001] = {0.0};
    int exp;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &exp);
        scanf("%lf", &arr1[exp]);
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &exp);
        scanf("%lf", &arr2[exp]);
    }
    for (int i = 1000; i >= 0; i--) {
        arr2[i] += arr1[i];
        if (arr2[i] > 0) count++;   //系数不为零，而不是系数大于零
    }
    printf("%d",count);
    for (int i = 1000; i >= 0; i--) {
        if (arr2[i] != 0) printf(" %d %.1lf",i, arr2[i]);
    }
    return 0;
}