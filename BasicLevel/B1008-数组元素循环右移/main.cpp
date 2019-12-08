//
//main.cpp
//B1008-数组元素循环右移
//
//Created by Ezreal on 2019/07/28.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    int count, offset;
    scanf("%d %d", &count, &offset);
    int *numbers = new int[count];
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &numbers[i]);
    }
    offset %= count;
    int isLast = 0;
    for (int i = count - offset; i < count; i++)
    {   
        printf("%d",numbers[i]);
        isLast++;
        if (isLast < count)printf(" ");
    }
    for (int i = 0; i < count - offset; i++)
    {
        printf("%d",numbers[i]);
        isLast++;
        if (isLast < count)printf(" ");
    }
    printf("\n");
    return 0;
}