//
//main.cpp
//A1042-Shuffling Machine
//
//Created by Ezreal on 2019/07/30.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    //初始序列
    int start[54] = {0};
    for (int i = 0; i < 54; i++) start[i] = i;
    int index[54] = {0};
    //变换次数
    int count = 0;
    scanf("%d",&count);
    //变换规则
    for (int i = 0; i < 54; i++) scanf("%d", &index[i]);
    //结束序列
    int end[54] = {0};
    //开始变换
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 54; j++) end[index[j] - 1] = start[j];
        for (int k = 0; k < 54; k++) start[k] = end[k];
    }
    for (int i = 0; i < 54; i++)
    {
        if (end[i] / 13 == 0) printf("S%d",end[i]%13 + 1);
        else if (end[i] / 13 == 1) printf("H%d",end[i]%13 + 1);
        else if (end[i] / 13 == 2) printf("C%d",end[i]%13 + 1);
        else if (end[i] / 13 == 3) printf("D%d",end[i]%13 + 1);
        else printf("J%d",end[i]%13 + 1);
        if (i != 53) printf(" ");      
    }
    return 0;
}