//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1149-Dangerous_Goods_Packaging
//
//Created by Ezreal on 2020-05-29.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main() {
    int N, M, K;
    cin >> N >> M;
    map<int, vector<int> > m;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    for (int i = 0; i < M; i++) {
        cin >> K;
        int a[1000000] = {0};
        vector<int> v(K);
        for (int j = 0; j < K; j++) {
            cin >> v[j];
            a[v[j]] = 1;
        }
        bool flag = false;
        for (int j = 0; j < K; j++) {
            for (int p = 0; p < m[v[j]].size(); p++) {
                if (a[m[v[j]][p]] == 1) {
                    flag = true;
                    break; 
                }
            }
            if (flag) break;
        }
        flag ? cout << "No\n" : cout << "Yes\n"; 
    }
    return 0;
}