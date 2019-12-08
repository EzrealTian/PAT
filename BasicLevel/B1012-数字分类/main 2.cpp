//
//main.cpp
//B1012-数字分类
//
//Created by Ezreal on 2019/07/28.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    int count;
    int number;
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
    double A4 = 0.0;
    int A4Count = 0;
    scanf("%d",&count);
    int A2Flag = 0;
    int A2Count = 0;
    for (int i = 0; i < count; i++) {
        scanf("%d",&number);
        if (number % 5 == 0 && number % 2 == 0) {
            A1 += number;
        }
        if (number % 5 == 1) {
            A2 = A2Flag % 2 == 0 ? A2 + number : A2 - number;
            A2Flag++;
            A2Count++;
        }
        if (number % 5 == 2) {
            A3++;
        }
        if (number % 5 == 3) {
            A4 += number;
            A4Count++;
        }
        if (number % 5 == 4 && number > A5) {
            A5 = number;
        }
    }
    A4 = A4Count == 0 ? 0 : A4 / A4Count;
    cout << fixed << setprecision(1);
    A1 == 0 ? printf("N ") : printf("%d ",A1);
    A2Count == 0 ? printf("N ") : printf("%d ",A2);
    A3 == 0 ? printf("N ") : printf("%d ",A3);
    A4 == 0 ? printf("N ") : printf("%.1f ",A4);
    A5 == 0 ? printf("N\n") : printf("%d\n",A5);
    return 0;
}