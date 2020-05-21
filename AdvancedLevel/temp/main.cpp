//
//main.cpp
//test-file
//
//Created by Ezreal on 2019/00/00.
//Copyright © 2019年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main(){
    bool notPrime[105000] = {};	//质数位示图，标记质数
    int prime[105000] = {0};	//质数数组栈
    int primeCount = 0;	//当前质数个数

    notPrime[0] = true;	//0和1均不是质数
    notPrime[1] = true;

    for (int i = 2; i < 105000; i++) {
        if(!notPrime[i]) prime[primeCount++] = i;	//质数入栈
        for (int j = 0; j < primeCount && i * prime[j] < 105000; j++) {
            notPrime[i * prime[j]] = true;	//标记为不是质数
            if(i % prime[j] == 0) break;	//欧拉筛法的核心：如果这个数能被素数栈里面的素数整除，那么之前一定被处理过，所以直接跳过
        }
    }
    int begin, end;
    scanf("%d%d", &begin, &end);
    int count = 0;
    for (int i = begin - 1; i < end; i++) {
        if (count % 10 == 0) printf("%d", prime[i]);
        else printf(" %d", prime[i]);
        if (count % 10 == 9) printf("\n");
        count++;
    }
    return 0;
}
