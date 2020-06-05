//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1154-Vertex_Coloring
//
//Created by Ezreal on 2020-05-28.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;
struct edge {
    int start;
    int end;
};
int main() {
    int N, M, K;
    scanf("%d%d", &N, &M);
    vector<edge> v(M);
    for (int i = 0; i < M; i++) scanf("%d%d", &v[i].start, &v[i].end);
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int* colors = new int[N];
        unordered_set<int> s;
        for (int j = 0; j < N; j++) {
            scanf("%d", &colors[j]);
            s.insert(colors[j]);
        }
        bool flag = true;
        for (int j = 0; j < v.size(); j++) {
            if (colors[v[j].start] == colors[v[j].end]) {
                flag = false;
                break;
            }
        }
        if (flag) printf("%d-coloring\n", int(s.size()));
        else printf("No\n");
    }
    return 0;
}