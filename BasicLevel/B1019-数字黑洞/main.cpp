//
//main.cpp
//B1019-数字黑洞
//
//Created by Ezreal on 2019/12/08.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <stdio.h>
#include <algorithm>
bool compare1(int c1, int c2) {
    return c1 > c2;
}
bool compare2(int c1, int c2) {
    return c1 < c2;
}

using namespace std;
int main(){
    int number1[4], number2[4];
    int input;
    scanf("%d", &input);
    do {
        for (int i = 0; i < 4; i++) {
            number1[i] = input % 10;
            number2[3 - i] = input % 10;
            input /= 10;
        }
        sort(number1, number1 + 4, compare1);
        sort(number2, number2 + 4, compare2);
        int temp1 = number1[0] * 1000 + number1[1] * 100 + number1[2] * 10 + number1[3];
        int temp2 = number2[0] * 1000 + number2[1] * 100 + number2[2] * 10 + number2[3];
        printf("%04d - %04d = %04d\n", temp1, temp2, temp1 - temp2);
        input = temp1 - temp2;
        if (input == 0) break;
    } while(input != 6174);
    return 0;
}