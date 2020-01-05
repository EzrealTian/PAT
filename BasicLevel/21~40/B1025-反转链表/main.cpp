//
//main.cpp
//B1025-反转链表
//
//Created by Ezreal on 2019/12/08.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;
int main(){
    int firstAdd, count, reverseCount;
    scanf("%d%d%d", &firstAdd, &count, &reverseCount);
    int list[100000], data[100000], next[100000];
    int temp;
    for (int  i = 0; i < count; i++) {
        scanf("%d", &temp);
        scanf("%d%d", &data[temp], &next[temp]);
    }

    int sum = 0;
    while(firstAdd != -1) {	//关键步，筛选剔除无效结点
        list[sum++] = firstAdd;
        firstAdd = next[firstAdd];
    }
    for (int i = 0; i <= sum - reverseCount; i += reverseCount) reverse(begin(list) + i, begin(list) + i + reverseCount);	//reverse操作
    for(int i = 0; i < sum - 1; i++) {
        printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
    }
    printf("%05d %d -1\n", list[sum - 1], data[list[sum - 1]]);
    return 0;
}