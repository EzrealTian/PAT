//
//main.cpp
//A1001-A+B Format
//
//Created by Ezreal on 2019/09/11.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cmath>
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    int sum = a + b;
    if (sum < 0) printf("-");
    sum = fabs(sum);
    if (sum == 0) printf("0\n");
    //printf("%d", sum);
    char result[7];
    int count = 0;
    while (sum > 0) {
        result[count] = sum % 10 + '0';
        sum /= 10;
        count++;
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%c", result[i]);
        if (i % 3 == 0 && i != 0) printf(",");
    }
    return 0;
}