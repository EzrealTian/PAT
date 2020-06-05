//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1101~A1150/A1121-Damn_Single
//
//Created by Ezreal on 2020-06-05.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <set>

using namespace std;
int main() {
    int N, M, person1, person2;
    vector<int> v(100000, -1), t_v;
    set<int> s1, s2;
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &person1, &person2);
        v[person1] = person2;
        v[person2] = person1;
    }
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &person1);
        s1.insert(person1);
    }
    for (auto it : s1) {
        if (v[it] == -1) s2.insert(it);
        else if (s1.find(v[it]) == s1.end()) s2.insert(it);
    }
    printf("%d\n", int(s2.size()));
    for (auto it : s2) printf("%s%05d", it == *s2.begin() ? "" : " ", it);
    return 0;
}