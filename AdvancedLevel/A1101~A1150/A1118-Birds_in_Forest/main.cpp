//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1101~A1150/A1118-Birds_in_Forest
//
//Created by Ezreal on 2020-06-06.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>

using namespace std;
const int capacity = 10010;
int pre[capacity];
int flag[capacity] = {0};
int cnt[capacity] = {0};
int union_search(int root) {
    int son = root;
    while (root != pre[root]) root = pre[root];
    int temp;
    while (son != pre[son]) {
        temp = pre[son];
        pre[son] = root;
        son = temp;
    }
    return root;
}
void join(int a, int b) {
    int f1 = union_search(a);
    int f2 = union_search(b);
    if (f1 != f2) pre[f1] = f2;
}
int main() {
    for (int i = 1; i < capacity; i++) pre[i] = i;
    int N, K, Q, id, temp;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &K, &id);
        flag[id] = 1;
        for (int j = 0; j < K - 1; j++) {
            scanf("%d", &temp);
            flag[temp] = 1;
            join(id, temp);
        }
    }
    for (int i = 1; i < capacity; i++) {
        if (flag[i] == 1) cnt[union_search(i)]++;
    }
    int bird_count = 0;
    int tree_count = 0;
    for (int i = 1; i < capacity; i++) {
        if (cnt[i] != 0) {
            bird_count += cnt[i];
            tree_count++;
        }
    }
    printf("%d %d\n", tree_count, bird_count);
    scanf("%d", &Q);
    while (Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%s\n", union_search(a) == union_search(b) ? "Yes" : "No");
    }
    return 0;
}