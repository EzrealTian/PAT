//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1147-Heaps
//
//Created by Ezreal on 2020-05-30.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>

using namespace std;
int m, n;
vector<int> v;
void postOrder(int root) {
    if (root >= n) return;
    if (root * 2 + 1 < n) postOrder(root * 2 + 1);
    if (root * 2 + 2 < n) postOrder(root * 2 + 2);
    printf("%d%s", v[root], root == 0 ? "\n" : " ");
}
int main() {
    scanf("%d%d", &m, &n);
    v.resize(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &v[j]);
        bool isMax = true, isMin = true;
        for (int j = 1; j < n; j++) {
            if (v[(j - 1)/2] > v[j]) isMin = false;
            if (v[(j - 1)/2] < v[j]) isMax = false;
        }
        if (isMax) printf("Max Heap\n");
        else isMin ? printf("Min Heap\n") : printf("Not Heap\n");
        postOrder(0);
    }
    return 0;
}