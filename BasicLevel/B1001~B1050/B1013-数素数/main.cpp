//
//main.cpp
//B1013-数素数
//
//Created by Ezreal on 2019/12/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <stdio.h>
#include <cmath>
int main(){
    bool notPrime[105000] = {true};
    int prime[105000] = {0};
    int primeCount = 0;

    notPrime[0] = true;
    notPrime[1] = true;

    for (int i = 2; i < 105000; i++) {
        if(!notPrime[i]) prime[primeCount++] = i;
        for (int j = 0; j < primeCount && i * prime[j] < 105000; j++) {
            notPrime[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
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
