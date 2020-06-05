//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1101~A1150/A1123-Is_It_a_Complete_AVL_Tree
//
//Created by Ezreal on 2020-06-05.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
struct node {
    int value;
    node *left, *right;
};
int has_after = 1;
int is_complete = 1;
node* left_rotate(node* tree) {
    node* temp = tree->right;
    tree->right = temp->left;
    temp->left = tree;
    return temp;
}
node* right_rotate(node* tree) {
    node* temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    return temp;
}
node* left_right_rotate(node* tree) {
    tree->left = left_rotate(tree->left);
    return right_rotate(tree);
}
node* right_left_rotate(node* tree) {
    tree->right = right_rotate(tree->right);
    return left_rotate(tree);
}
int get_height(node* tree) {
    if (tree == NULL) return 0;
    int left = get_height(tree->left) + 1;
    int right = get_height(tree->right) + 1;
    return max(left, right);
}
node* insert_node(node* tree, int value) {
    if (tree == NULL) {
        tree = new node();
        tree->value = value;
    } else if (value < tree->value) {
        tree->left = insert_node(tree->left, value);
        int left = get_height(tree->left);
        int right = get_height(tree->right);
        if (left - right >= 2) {
            if (value < tree->left->value) tree = right_rotate(tree);
            else tree = left_right_rotate(tree);
        }
    } else {
        tree->right = insert_node(tree->right, value);
        int left = get_height(tree->left);
        int right = get_height(tree->right);
        if (right - left >= 2) {
            if (value < tree->right->value) tree = right_left_rotate(tree);
            else tree = left_rotate(tree);
        }
    }
    return tree;
}
vector<int> level_traverse (node* tree) {
    queue<node*> q;
    q.push(tree);
    vector<int> v;
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        v.push_back(temp->value);
        if (temp->left != NULL) {
            q.push(temp->left);
            if (!has_after) is_complete = 0;
        } else {
            has_after = 0;
        }
        if (temp->right != NULL) {
            q.push(temp->right);
            if (!has_after) is_complete = 0;
        } else {
            has_after = 0;
        }
    }
    return v;
}
int main() {
    int N, value;
    scanf("%d", &N);
    node* tree = NULL;
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        tree = insert_node(tree, value);
    }
    vector<int> result = level_traverse(tree);
    for (int i = 0; i < N; i++) printf("%d%s", result[i], i == N - 1 ? "\n" : " ");
    printf("%s\n", is_complete ? "YES" : "NO");
    return 0;
}