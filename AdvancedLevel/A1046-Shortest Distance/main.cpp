//
//main.cpp
//A1046-Shortest Distance
//
//Created by Ezreal on 2019/07/30.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    int count;
    int *distance = new int[count];
    scanf("%d", &count);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        scanf("%d",&distance[i]);
        sum += distance[i];
        distance[i] = sum;  //预处理防止超时，不预处理下面会循环遍历
    } 
    int cycle;
    scanf("%d", &cycle);
    int start, end;
    for (int i = 0; i < cycle; i++)
    {
        scanf("%d %d",&start, &end);
        if(start > end) {
            int temp = start;
            start = end;
            end = temp;
        }
        int sum2 = distance[end -2] - distance[start - 2];
        if(sum2 < sum - sum2) printf("%d\n",sum2);
        else printf("%d\n",sum - sum2);
    }
    return 0;
}