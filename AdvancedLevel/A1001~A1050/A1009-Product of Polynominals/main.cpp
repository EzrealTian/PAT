//
//main.cpp
//A1009-Product of Polynimals
//
//Created by Ezreal on 2019/08/30.
//Copyright © 2019年 Ezreal. All rights reserved.
//
/**
 * 思路：
 * 这里只需要大小为10的数组来存放第一次输入，第二次输入不用存，为了输出方便，结果数组用2001的大小，虽然空间复杂度高了，但是省去了结果排序的时间
*/
struct Poly {
    double conf;
    int exp;
};


#include <cstdio>
int main(){
    Poly a[10];
    double result[2001] = {0.0};

    int count1, count2;  
    //多项式1
    scanf("%d",&count1);
    for (int i = 0; i < count1; i++) {
        scanf("%d%lf", &a[i].exp, &a[i].conf);
    }
    //多项式2
    scanf("%d",&count2);
    for (int i = 0; i < count2; i++) {
        int exp;
        double conf;
        scanf("%d%lf", &exp, &conf);
        for(int j = 0; j < count1; j++) {
            result[a[j].exp + exp] += a[j].conf * conf;
        }
    }
    int count = 0;
    for(int i = 0; i < 2001; i++) {
        if(result[i] != 0.0) count++;
    }
    printf("%d",count);
    for (int i = 2000; i >= 0; i--)
    {
        if(result[i] != 0.0) printf(" %d %.1lf", i, result[i]);
    }
    printf("\n");
    
    return 0;
}