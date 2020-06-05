//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1138-Postorder_Traversal
//
//Created by Ezreal on 2020-06-01.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <map>

using namespace std;
vector<int> v1, v2;
map<int, int> m1, m2;
void post_order(int root, int l_index, int r_index) {
    if (l_index < root) post_order(m2[v1[m1[v2[root]] + 1]], l_index, root - 1);
    else if (r_index > root) post_order(m2[v1[m1[v2[root]] + root - l_index + 1]], root + 1, r_index);
    else printf("%d\n", v2[root]);
}
int main() {
    int N;
    scanf("%d", &N);
    v1.resize(N);
    v2.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &v1[i]);
        m1[v1[i]] = i;
    }   
    for(int i = 0; i < N; i++) {
        scanf("%d", &v2[i]);
        m2[v2[i]] = i;
    }
    post_order(m2[v1[0]], 0 , N - 1);
    return 0;
}