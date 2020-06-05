//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1129-Recommendation_System
//
//Created by Ezreal on 2020-06-03.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <set>
#include <map>

using namespace std;
struct node {
    int value;
    int count;
    bool operator < (const node &a) const {
        return (count != a.count) ? count > a.count : value < a.value;
    }
};
int main() {
    int N, K, value;
    scanf("%d%d", &N, &K);
    set<node> s;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        if (i != 0) {
            printf("%d:", value);
            int t_count = 0;
            for (auto it = s.begin(); it != s.end() && t_count < K; it++) {
                printf(" %d", it->value);
                t_count++;
            }
            printf("\n");
        }
        auto it = s.find({value, m[value]});
        if (it != s.end()) s.erase(it);
        m[value]++;
        s.insert({value, m[value]});
    }
    return 0;
}