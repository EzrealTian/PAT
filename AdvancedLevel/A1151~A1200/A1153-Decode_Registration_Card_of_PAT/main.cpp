//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1153-Decode_Registration_Card_of_PAT
//
//Created by Ezreal on 2020-05-27.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
struct Node {
    string str;
    int value;
};
struct Site {
    int count;
    int score;
};
bool cmp(const Node &n1, const Node &n2) {
    if (n1.str[0] == n2.str[0]) return n1.value == n2.value ? n1.str < n2.str : n1.value > n2.value; 
    else return n1.str[0] < n2.str[0]; 
}
bool cmp2(const Node &n1, const Node &n2) { return n1.value == n2.value ? n1.str < n2.str : n1.value > n2.value; }
int main() {
    int M, N, num;
    string s;
    cin >> N >> M;
    vector<Node> list(N);
    unordered_map<string, Site> m;
    for (int i = 0; i < N; i++) {
        cin >> list[i].str >> list[i].value;
        m[list[i].str.substr(1, 3)].count++;
        m[list[i].str.substr(1, 3)].score += list[i].value;
    }
    sort(list.begin(), list.end(), cmp);

    for (int i = 1; i <= M; i++) {
        cin >> num >> s;
        printf("Case %d: %d %s\n", i, num, s.c_str());
        if (num == 1) {
            int count = 0;
            for (auto stu : list) if (stu.str[0] == s[0]) {
                count++;
                printf("%s %d\n", stu.str.c_str(), stu.value);
            }
            if (count == 0) printf("NA\n");
        } else if (num == 2) {
            if (m[s].count == 0) printf("NA\n");
            else printf("%d %d\n", m[s].count, m[s].score);
        } else {
            unordered_map<string, int> tm;
            for (int i = 0; i < list.size(); i++) {
                if (s == list[i].str.substr(4, 6)) tm[list[i].str.substr(1, 3)]++;
            }
            vector<Node> temp;
            for (auto it : tm) temp.push_back({it.first, it.second});
            sort(temp.begin(), temp.end(), cmp2);
            if (temp.size() == 0) printf("NA\n");
            else for (auto i : temp) printf("%s %d\n", i.str.c_str(), i.value);
        }
    }
    return 0;
}