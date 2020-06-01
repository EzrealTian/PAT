//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1143-Lowest_Common _Ancestor
//
//Created by Ezreal on 2020-05-31.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <map>
#include <vector>

using namespace std;
int main() {
    int M, N, node;
    map<int, int> m;
    int n1, n2;
    scanf("%d%d", &M, &N);
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        m[v[i]] = 1;
    }
    while (M--) {
        scanf("%d%d", &n1, &n2);
        if (m[n1] == 0 && m[n2] == 0) printf("ERROR: %d and %d are not found.\n", n1, n2);
        else if (m[n1] == 0 || m[n2] == 0) printf("ERROR: %d is not found.\n", m[n1] == 0 ? n1 : n2);
        else {
            for (int i = 0; i < N; i++) {
                node = v[i];
                if((node >= n1 && node <= n2) || (node <= n1 && node >= n2)) break;
            }
            if (node == n1 || node == n2) printf("%d is an ancestor of %d.\n", node, node == n1 ? n2 : n1);
            else printf("LCA of %d and %d is %d.\n", n1, n2, node);
        }
    }
    return 0;
}