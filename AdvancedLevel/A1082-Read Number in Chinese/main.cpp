//
//main.cpp
//A1082-Read Number in Chinese
//
//Created by Ezreal on 2019/09/11.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cmath>

int main(){
    char arr2[10][5] = {
        {"ling"},
        {"yi"},
        {"er"},
        {"san"},
        {"si"},
        {"wu"},
        {"liu"},
        {"qi"},
        {"ba"},
        {"jiu"}
    };
    int number;
    scanf("%d", &number);
    if (number < 0) printf("Fu ");
    number = fabs(number);

    int part[3];
    part[0] = number / 100000000;
    part[1] = number % 100000000 / 10000;
    part[2] = number % 100000000 % 10000;
    bool needZero = false;
    bool needPre = false;
    if (number == 0) printf("ling");
    for (int i = 0; i < 3; i++) {
        int number = part[i];
        for (int j = 1000; j > 0; j /= 10) {
            if (number / j != 0) {
                if (needPre) printf(" ");
                printf("%s", arr2[number / j]);
                needPre = true;
                if (j == 1000) printf(" Qian");
                else if (j == 100) printf(" Bai");
                else if (j == 10) printf(" Shi");
                number %= j;
                needZero = true;
            } else if (number / j == 0 && number % j != 0) {
                if (needZero) {
                    printf(" ling");
                    needPre = true;
                    needZero = false;
                } 
            }
        }
        if (part[i] == 0) continue;
        else {
            if (i == 0) printf(" Yi");
            else if (i == 1) printf(" Wan");
        }
    }
    return 0;
}