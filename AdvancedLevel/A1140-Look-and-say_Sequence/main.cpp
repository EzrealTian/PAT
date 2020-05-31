//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1140-Look-and-say_Sequence
//
//Created by Ezreal on 2020-05-31.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>

using namespace std;
int main() {
    int d, n;
    scanf("%d%d", &d, &n);
    vector<int> v1, v2;
    v1.push_back(d);
    for (int i = 1; i < n; i++) {
        int start = 0, end = 0;
        v2.push_back(v1[0]);
        v2.push_back(0);
        while (end < v1.size()) {
            if (v1[start] == v1[end]) {
                v2.back()++;
                end++;
            } else {
                start = end;
                v2.push_back(v1[start]);
                v2.push_back(0);
            }
        }
        v1.assign(v2.begin(), v2.end());
        v2.clear();
    }
    for (auto it : v1) printf("%d", it);
    return 0;
}