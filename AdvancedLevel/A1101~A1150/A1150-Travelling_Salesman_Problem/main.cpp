//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1150-Travelling_Salesman_Problem
//
//Created by Ezreal on 2020-05-29.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <set>
#include <limits.h>

using namespace std;
int main() {
    int dis[201][201] = {{0}};
    int N, M, K;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int start, end, distance;
        scanf("%d%d%d", &start, &end, &distance);
        dis[start][end] = dis[end][start] = distance;
    }
    scanf("%d", &K);
    int count;
    int m_index, min = INT_MAX;
    for (int j = 1; j <= K; j++) {
        scanf("%d", &count);
        vector<int> v(count);
        set<int> s;
        for (int i = 0; i < count; i++) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        int distance = 0;
        for (int i = 0; i < count - 1; i++) {
            if (dis[v[i]][v[i+1]] == 0) {
                distance = -1;
                break;
            }
            distance += dis[v[i]][v[i+1]];
        }
        printf("Path %d: ", j);
        if (distance == -1) printf("NA (Not a TS cycle)\n");
        else {
            printf("%d", distance);
            if (s.size() == N && v.front() == v.back()) {
                if (v.size() == N + 1) printf(" (TS simple cycle)\n");
                else printf(" (TS cycle)\n");
                if (distance < min) {
                    min = distance;
                    m_index = j;
                }
            } else {
                printf(" (Not a TS cycle)\n");
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", m_index, min);
    return 0;
}