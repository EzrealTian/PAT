//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1151-LCA_in_a_Binary_Tree
//
//Created by Ezreal on 2020-05-29.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;
vector<int> in, pre;
unordered_map<int, int> m;
int n1, n2, index1, index2;
void LCA(int root, int left, int right) {
    if (left > right) return;
    int r_index ;
    for (int i = left; i <= right; i++) if (in[i] == pre[root]) r_index = i;
    if ((index1 < r_index && index2 > r_index) || (index1 > r_index && index2 < r_index)) printf("LCA of %d and %d is %d.\n", n1, n2, in[r_index]);
    else if (index1 == r_index) printf("%d is an ancestor of %d.\n", n1, n2);
    else if (index2 == r_index) printf("%d is an ancestor of %d.\n", n2, n1);
    else if (index1 < r_index && index2 < r_index) LCA(root + 1, left, r_index - 1);
    else if (index1 > r_index && index2 > r_index) LCA(root + r_index - left + 1, r_index + 1, right);
}
int main() {
    int M, N;
    scanf("%d%d", &M, &N);
    in.resize(N);
    pre.resize(N);
    for (int i = 0; i < N; i++) scanf("%d", &in[i]);
    for (int i = 0; i < N; i++) {
        scanf("%d", &pre[i]);
        m[in[i]] = i;
    }
    while (M--) {
        scanf("%d%d", &n1, &n2);
        if(m[n1] == 0 && m[n2] == 0) printf("ERROR: %d and %d are not found.\n", n1, n2);
        else if (m[n1] == 0 || m[n2] == 0) printf("ERROR: %d is not found.\n", m[n1] == 0 ? n1 : n2);
        else {
            for (int i = 0; i < N; i++) {
                if (in[i] == n1) index1 = i;
                if (in[i] == n2) index2 = i;
            }
            LCA(0, 0, N - 1);
        }
    }
    return 0;
}