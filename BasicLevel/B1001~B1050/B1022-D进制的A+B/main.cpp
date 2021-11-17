//
//main.cpp
//B1022-D进制的A+B
//
//Created by Ezreal on 2019/09/04.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    int A,B,D;
    scanf("%d%d%d",&A,&B,&D);
    A += B;
    int result[32] = {0};
    int count = 0;
    while (A / D) {
        result[count] = A % D;
        count++;
        A /= D;
        //printf("%d\n",A);
    }
    result[count] = A % D;
    for (int i = count; i >= 0; i--) {
        printf("%d",result[i]);
    }
    printf("\n");
    return 0;
}