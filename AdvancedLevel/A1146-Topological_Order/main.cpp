//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1146-Topological_Order
//
//Created by Ezreal on 2020-05-30.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>

using namespace std;
int main() {
    int N, M, K, start, end;
    scanf("%d%d", &N, &M);
    vector<vector<int> > v(N+1);
    vector<int> inDegree(N+1, 0);
    while (M--) {
        scanf("%d%d", &start, &end);
        v[start].push_back(end);
        inDegree[end]++;
    }
    scanf("%d", &K);
    vector<int> result;
    for (int i = 0; i < K; i++) {
        int number;
        bool flag = true;
        vector<int> temp(inDegree.begin(), inDegree.end());
        for (int j = 0; j < N; j++) {
            scanf("%d", &number);
            if (temp[number] != 0) flag = false;
            for (int it : v[number]) temp[it]--; 
        }
        if (!flag) result.push_back(i);
    }
    for (int i = 0; i < result.size(); i++) i == 0 ? printf("%d", result[i]) : printf(" %d", result[i]);
    return 0;
}