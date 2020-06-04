//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1135-Is_It_A_Red-Black_Tree
//
//Created by Ezreal on 2020-06-02.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
struct node {
    int value;
    node* left;
    node* right;
};
node* build_tree(node *root, int value) {
    if (root == NULL) {
        root = new node;
        root->value = value;
        root->left = root->right = NULL;
    } else if (abs(value) < abs(root->value)) root->left = build_tree(root->left, value);
    else if (abs(value) > abs(root->value)) root->right = build_tree(root->right, value);
    return root;
}
int getNum(node *root) {
    if (root == NULL) return 0;
    int left = getNum(root->left);
    int right = getNum(root->right);
    return root->value > 0 ? max(left, right) + 1 : max(left, right);
}
bool judge1(node *root) {
    if (root == NULL) return true;
    if (root->value < 0) {
        if (root->left != NULL && root->left->value < 0) return false;
        if (root->right != NULL && root->right->value < 0) return false;
    }
    return judge1(root->left) && judge1(root->right);
}
bool judge2(node* root) {
    if (root == NULL) return true;
    int left = getNum(root->left);
    int right = getNum(root->right);
    if (left != right) return false;
    return judge2(root->left) && judge2(root->right);
}
int main() {
    int N, value, count;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &count);
        node *root = NULL;
        for (int i = 0; i < count; i++) {
            scanf("%d", &value);
            root = build_tree(root, value);
        }
        if (root->value < 0 || !judge1(root) || !judge2(root)) 
            printf("No\n");
        else 
            printf("Yes\n");
    }
    return 0;
}