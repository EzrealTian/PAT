//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1101~A1150/A1122-Hamiltonian_Cycle
//
//Created by Ezreal on 2020-06-05.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <set>

using namespace std;
int main() {
    int N, M, K, start, end, count, node;
    int a[201][201];
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &start, &end);
        a[start][end] = a[end][start] = 1;
    }
    scanf("%d", &K);
    while (K--) {
        scanf ("%d", &count);
        vector<int> v;
        set<int> s;
        for (int i = 0; i < count; i++) {
            scanf("%d", &node);
            v.push_back(node);
            s.insert(node);
        }
        bool flag = true;
        if (v.front() == v.back() && s.size() == N && v.size() == N + 1) {
            for (int i = 1; i < N + 1; i++) if (a[v[i - 1]][v[i]] == 0) flag = false;
        } else {
            flag = false;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}