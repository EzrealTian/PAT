//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1133-Splitting_A_Linked_List
//
//Created by Ezreal on 2020-06-02.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>

using namespace std;
struct node {
    int address;
    int value;
    int next;
};
int main() {
    node a[100000];
    int first, N, K, address, value, next;
    vector<node> v1, v2, v3;
    scanf("%d%d%d", &first, &N, &K);
    while (N--) {
        scanf("%d%d%d", &address, &value, &next);
        a[address].address = address;
        a[address].value = value;
        a[address].next = next; 
    }
    node t_node = a[first];
    while (true) {
        if (t_node.value < 0) v1.push_back(t_node);
        else if (t_node.value <= K) v2.push_back(t_node);
        else v3.push_back(t_node);
        if (t_node.next == -1) break;
        t_node = a[t_node.next];
    }
    for (auto it : v2) v1.push_back(it);
    for (auto it : v3) v1.push_back(it);
    for (int i = 0; i < v1.size(); i++) {
        printf("%05d %d ", v1[i].address, v1[i].value);
        i == v1.size() - 1 ? printf("-1\n") : printf("%05d\n", v1[i + 1].address);
    }
    return 0;
}