//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1125-Chain_the_Ropes
//
//Created by Ezreal on 2020-06-04.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<double> v(N);
    for (int i = 0; i < N; i++) scanf("%lf", &v[i]);
    sort(v.begin(), v.end());
    double result = v[0];
    for (int i = 1; i < N; i++) result = (v[i] + result) / 2;
    printf("%d\n", int(result));
    return 0;
}