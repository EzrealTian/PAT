//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1126-Eulerian_Path
//
//Created by Ezreal on 2020-06-04.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>

using namespace std;
int visit[501];
int a[501][501];
int N, M, start, end1, cnt;
void dfs(int node) {
    visit[node] = 1;
    cnt++;
    for (int i = 1; i <= N; i++) {
        if (a[node][i] == 1 && visit[i] == 0) dfs(i);
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d%d", &N, &M);
    vector<int> v(N + 1);
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &start, &end1);
        a[start][end1] = a[end1][start] = 1;
        v[start]++;
        v[end1]++;
    }
    int count = 0;
    for (int i = 1; i <= N; i++) {
        printf("%d%s", v[i], i == N ? "\n" : " ");
        if (v[i] % 2 == 1) count++;
    }
    dfs(1);
    if (count == 0 && cnt == N) printf("Eulerian\n");
    else if (count == 2 && cnt == N) printf("Semi-Eulerian\n");
    else printf("Non-Eulerian\n");
    return 0;
}