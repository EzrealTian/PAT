//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1134-Vertex Cover
//
//Created by Ezreal on 2020-06-02.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;
int main() {
    int N, M, K;
    scanf("%d%d", &N, &M);
    vector<int> v1(M), v2(M);
    for (int i = 0; i < M; i++) scanf("%d%d", &v1[i], &v2[i]);
    scanf("%d", &K);
    while (K--) {
        int count, node;
        unordered_map<int, int> m;
        scanf("%d", &count);
        while (count--) {
            scanf("%d", &node);
            m[node] = 1;
        }
        bool flag = true;
        for (int i = 0; i < M; i++) {
            if (m[v1[i]] == 0 && m[v2[i]] == 0) {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}