//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1127-ZigZagging_on_a_Tree
//
//Created by Ezreal on 2020-06-04.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <map>
#include <queue>

using namespace std;
map<int, int> m1, m2;
vector<int> v1, v2;
int max_level = -1;
struct node {
    int value;
    int level;
    node *left, *right;
};
node* build_tree (int root_index, int left, int right, int level) {
    if (left > right) return NULL;
    node* n = new node;
    n->value = v1[root_index];
    n->level = level;
    max_level = max(max_level, level);
    n->left = build_tree(m1[v2[m2[v1[root_index]] - right + root_index - 1]], left, root_index - 1, level + 1);
    n->right = build_tree(m1[v2[m2[v1[root_index]] - 1]], root_index + 1, right, level + 1);
    return n;
}
int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    v1.resize(N);
    v2.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v1[i]);
        m1[v1[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &v2[i]);
        m2[v2[i]] = i;
    }
    node* root = build_tree(m1[v2[N - 1]], 0, N - 1, 1);
    queue<node*> q;
    q.push(root);
    vector<vector<int> > t_v(max_level + 1);
    while (!q.empty()) {
        node *temp = q.front();
        t_v[temp->level].push_back(q.front()->value);
        q.pop();
        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
    for (int i = 1; i <= max_level; i++) {
        if (i % 2 == 1) for (int j = int(t_v[i].size() - 1); j >= 0; j--) printf("%s%d", (i == 1 && j == 0) ? "" : " ", t_v[i][j]);
        else for (int j = 0; j < t_v[i].size(); j++) printf(" %d", t_v[i][j]);
    }
    printf("\n");
    return 0;
}