//
//main.cpp
//B1005-继续(3n+1)猜想
//
//Created by Ezreal on 2019/12/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <stdio.h>
int main(){
    int numberSet[101] = {0};
    int count;
    scanf("%d", &count);
    int *numbers = new int[count];
    for (int i = 0; i < count; i++) {
        scanf("%d", &numbers[i]);
        numberSet[numbers[i]] = 1;
    }
    for (int i = 0; i < count; i++) {
        while (numbers[i] != 1) {
            numbers[i] = numbers[i] % 2 == 0 ? numbers[i] / 2 : (3 * numbers[i] + 1) / 2;
            if (numbers[i] < 101) numberSet[numbers[i]] = 0;
        }
    }
    bool isFirst = true;
    for(int i = 100; i >= 0; i--) {
        if (numberSet[i] == 1) {
            if (isFirst) {
                printf("%d", i);
                isFirst = false;
            } else {
                printf(" %d", i);
            }
        }
    }
    return 0;
}