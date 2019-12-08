//
//main.cpp
//A1065-A+B and C
//
//Created by Ezreal on 2019/07/31.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    long long a, b, c;
    long long sum;
    bool flag;
    int count;
    scanf("%d",&count);
    for (int i = 0; i < count; i++)
    {
        scanf("%lld %lld %lld",&a, &b, &c);
        printf("%lld",a+b);
        sum = a + b;    //计算结果不能再if中进行比较，因为会造成范围错误
        if (a > 0 && b > 0 && sum < 0) printf("Case #%d: true\n",i + 1);
        else if(a < 0 && b < 0 && sum >= 0) printf("Case #%d: false\n",i + 1);
        else if(sum > c) printf("Case #%d: true\n",i + 1);
        else printf("Case #%d: false\n",i + 1);
    }
    return 0;
}