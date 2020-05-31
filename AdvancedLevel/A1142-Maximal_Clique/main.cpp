//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1142-Maximal_Clique
//
//Created by Ezreal on 2020-05-31.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <map>

using namespace std;
int main() {
    int e[201][201];
    int nv, ne, M, K;
    scanf("%d%d", &nv, &ne);
    int temp = nv;
    while (ne--) {
        int start, end;
        scanf("%d%d", &start, &end);
        e[start][end] = e[end][start] = 1;
    }
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &K);
        vector<int> v(K);
        map<int, int> m;
        for (int i = 0; i < K; i++) {
            scanf("%d", &v[i]);
            m[v[i]] = 1;
        }
        bool isCli = true;
        for (int i = 0; i < K; i++) {
            for (int j = i + 1; j < K; j++) {
                if (e[v[i]][v[j]] == 0) {
                    isCli = false;
                    break;
                }
            }
        }
        if (!isCli) printf("Not a Clique\n");
        else {
            bool isMax = true;
            for (int i = 1; i <= nv; i++) {
                int count = 0;
                if (m[i] == 0) {
                    for (int j = 0; j < K; j++) if (e[i][v[j]] == 1) count++;
                    if (count == K) {
                        isMax = false;
                        break;
                    }
                } 
            }
            printf("%s", isMax ? "Yes\n" : "Not Maximal\n");
        }
    }
    return 0;
}