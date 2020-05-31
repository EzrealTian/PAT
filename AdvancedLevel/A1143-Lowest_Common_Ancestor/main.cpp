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
vector<int> v;
map<int, int> m;
int n1, n2;
void LCA(int root_index) {
    if (root_index >= v.size()) return;
    int root = v[root_index];
    if ((root > n1 && root < n2) || (root < n1 && root > n2)) printf("LCA of %d and %d is %d.\n", n1, n2, root);
    else if (n1 == root) printf("%d is an ancestor of %d.\n", n1, n2);
    else if (n2 == root) printf("%d is an ancestor of %d.\n", n2, n1);
    else if (root > n1 && root > n2) LCA(root_index + 1);
    else {
        int r_index;
        for (int i = root_index; i < v.size(); i++) if (v[i] > root) {
            r_index = i;
            break;
        } 
        LCA(r_index);
    }
}
int main() {
    int M, N;
    scanf("%d%d", &M, &N);
    v.resize(N+1);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &v[i]);
        m[v[i]] = i;
    }
    while (M--) {
        scanf("%d%d", &n1, &n2);
        if (m[n1] == 0) {
            if (m[n2] == 0) printf("ERROR: %d and %d are not found.\n", n1, n2);
            else printf("ERROR: %d is not found.\n", n1);
        } else if (m[n2] == 0) {
            printf("ERROR: %d is not found.\n", n2);
        } else {
            LCA(0);
        }
    }
    return 0;
}