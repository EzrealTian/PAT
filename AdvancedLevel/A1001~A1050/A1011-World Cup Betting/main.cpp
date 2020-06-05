//
//main.cpp
//A1011-World Cup Betting
//
//Created by Ezreal on 2019/09/04.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    double number[9];
    for (int i = 0; i < 9; i++)
    {
        scanf("%lf", &number[i]);
    }
    char set[3] = {'W', 'T', 'L'};
    char result[3];
    double income = 1;
    double max = 0.0;
    int index;
    for(int i = 0; i < 9; i += 3) {
        max = 0;
        for(int j = i; j < i + 3; j++) {
            if(max < number[j]) {
                max = number[j];
                index = j;
            }
        }
        result[i/3] = set[index%3];
        income *= max;
    }
    income = (income * 0.65 - 1) * 2;
    printf("%c %c %c %.2lf",result[0], result[1], result[2], income);
    
    return 0;
}