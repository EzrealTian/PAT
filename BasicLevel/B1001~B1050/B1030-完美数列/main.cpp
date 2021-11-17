//
//main.cpp
//B1030-完美数列
//
//Created by Ezreal on 2019/12/09.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <stdio.h>
#include <algorithm>

bool compare(long long n1, long long n2) {return n1 < n2;}
using namespace std;
int main(){
    long long arr1[100000];
    int count, p;
    scanf("%d%d", &count, &p);
    for(int i = 0; i < count; i++) scanf("%lld", &arr1[i]);
    sort(arr1, arr1 + count, compare);

    int length = 0;
    for (int i = 0; i + length - 1 < count; i++) {
        for (int j = i + length; j < count; j++) {
            if (arr1[i] * p >= arr1[j]) {
                if (j - i + 1 > length) length = j - i + 1;
            } else {
                break;
            }
        }
    }
    printf("%d\n", length);
    return 0;
}