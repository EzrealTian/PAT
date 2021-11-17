//
//main.cpp
//B1032-挖掘机技术哪家强
//
//Created by Ezreal on 2019/07/28.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    const int n = 100001;
    int totalScore[n] = {0};
    int count;
    scanf("%d",&count);
    int index, score;
    for (int i = 0; i < count; i++)
    {
        scanf("%d%d",&index,&score);
        totalScore[index] += score;
    }
    score = 0;
    for (int i = 1; i <= count; i++)
    {
        if (totalScore[i] > score)
        {   
            score = totalScore[i];
            index = i;
        }
    }
    printf("%d %d\n",index,score);
    
    return 0;
}