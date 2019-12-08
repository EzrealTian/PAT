//
//main.cpp
//B1016-部分A+B
//
//Created by Ezreal on 2019/07/28.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    char A[11] = "0000000000";
    char B[11] = "0000000000";
    char DA,DB;
    int resultA = 0;
    int resultB = 0;
    scanf("%s %c %s %c",A,&DA,B,&DB);
    for (int i = 0; i < 11; i++)
    {
        if (A[i] == DA)
        {
            resultA *= 10;
            resultA += (A[i] - 48);
        }
        if (B[i] == DB)
        {
            resultB *= 10;
            resultB += (B[i] - 48);
        }
    }
    printf("%d\n",resultA+resultB);
    return 0;
}