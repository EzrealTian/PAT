//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1139-First_Contact
//
//Created by Ezreal on 2020-06-01.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
struct node {
    int start;
    int end;
};
bool cmp(node n1, node n2) {
    return n1.start == n2.start ? n1.end < n2.end : n1.start < n2.start;
}
int main() {
    int N, M, K;
    string start, end;
    scanf("%d%d", &N, &M);
    map<int, bool> m;
    vector<int> a[10000];
    while (M--) {
        cin >> start >> end;
        if (start.length() == end.length()) {
            a[abs(stoi(start))].push_back(abs(stoi(end)));
            a[abs(stoi(end))].push_back(abs(stoi(start)));
        }
        m[abs(stoi(start)) * 10000 + abs(stoi(end))] = m[abs(stoi(end)) * 10000 + abs(stoi(start))] = true;
    }
    scanf("%d", &K);
    while (K--) {
        int A, B;
        cin >> A >> B;
        vector<node> v;
        for (int i = 0; i < a[abs(A)].size(); i++) {
            for (int j = 0; j < a[abs(B)].size(); j++) {
                if (a[abs(A)][i] == abs(B) || a[abs(B)][j] == abs(A)) continue;
                if (m[a[abs(A)][i] * 10000 + a[abs(B)][j]] == true) v.push_back(node{abs(a[abs(A)][i]), abs(a[abs(B)][j])}); 
            }
        }
        sort(v.begin(), v.end(), cmp);
        printf("%d\n", int(v.size()));
        for (auto it : v) printf("%04d %04d\n", it.start, it.end);
    }
    return 0;
}