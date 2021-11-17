//
//main.cpp
//B1046-划拳
//
//Created by Ezreal on 2019/07/28.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    int count;
    scanf("%d",&count);
    int ASaid, ADo, BSaid, BDo;
    int ACount = 0;
    int BCount = 0;
    for (int i = 0; i < count; i++)
    {
        scanf("%d %d %d %d",&ASaid,&ADo,&BSaid,&BDo);
        if (ASaid + BSaid == ADo && ASaid + BSaid != BDo)
        {
            BCount++;
        }
        else if (ASaid + BSaid != ADo && ASaid + BSaid == BDo)
        {
            ACount++;
        }
    }
    printf("%d %d\n",ACount,BCount);
    return 0;
}