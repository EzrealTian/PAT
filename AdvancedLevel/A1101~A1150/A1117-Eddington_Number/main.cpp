//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1101~A1150/A1117-Eddington_Number
//
//Created by Ezreal on 2020-06-06.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for (int i = 0; i < N; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end(), cmp);
    bool flag = false;
    for (int i = N - 1; i >= 0; i--) {
        if (v[i] > i + 1) {
            printf("%d\n", i + 1);
            flag = true;
            break;
        }
    }
    if (!flag) printf("0\n");
    return 0;
}