//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1131-Subway_Map
//
//Created by Ezreal on 2020-06-03.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;
vector<vector<int> > v(10000);
vector<int> path, t_path;
unordered_map<int, int> line;
int visit[10000];
int start, end1, min_transfer, min_count;
int cal_transfer(vector<int> t_v) {
    int count = -1;
    int pre = 0;
    for (int i = 1; i < t_v.size(); i++) {
        if (line[t_v[i - 1] * 10000 + t_v[i]] != pre) {
            count++;
            pre = line[t_v[i - 1] * 10000 + t_v[i]];
        }
    }
    return count;
}
void dfs(int node, int count) {
    if (node == end1 && (count < min_count || (count == min_count && cal_transfer(t_path) < min_transfer))) {
        min_transfer = cal_transfer(t_path);
        min_count = count;
        path = t_path;
        return;
    }
    if (node == end1) return;
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            t_path.push_back(v[node][i]);
            dfs(v[node][i], count + 1);
            visit[v[node][i]] = 0;
            t_path.pop_back();
        }
    }
}
int main(int argc, const char * argv[]) {
    int N, M, K;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &M, &start);
        for (int j = 1; j < M; j++) {
            scanf("%d", &end1);
            v[start].push_back(end1);
            v[end1].push_back(start);
            line[start*10000 + end1] = line[end1*10000 + start] = i + 1;
            start = end1;
        }
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d%d", &start, &end1);
        min_count = 99999;
        min_transfer = 99999;
        t_path.clear();
        t_path.push_back(start);
        visit[start] = 1;
        dfs(start, 0);
        visit[start] = 0;
        printf("%d\n", min_count);
        int pre = 0, pre_trans = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j - 1] * 10000 + path[j]] != pre) {
                if (pre != 0) printf("Take Line#%d from %04d to %04d.\n", pre, pre_trans, path[j - 1]);
                pre = line[path[j - 1] * 10000 + path[j]];
                pre_trans = path[j - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", pre, pre_trans, end1);
    }
    return 0;
}
