//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1137-Final_Grading
//
//Created by Ezreal on 2020-06-01.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
struct student {
    string ID;
    int p_score;
    int m_score;
    int f_score;
    int score;
    student() : ID(""), p_score(-1), m_score(-1), f_score(-1), score(-1) {}
};
bool cmp (student s1, student s2) {
    if (s1.score != s2.score) return s1.score > s2.score;
    return s1.ID < s2.ID;
}
int main() {
    unordered_map<string, student> m;
    int P, M, N, score;
    string name;
    cin >> P >> M >> N;
    while (P--) {
        cin >> name >> score;
        if (score >= 200) m[name].p_score = score;
    }
    while (M--) {
        cin >> name >> score;
        if (m[name].p_score >= 200) m[name].m_score = score;
    }
    while (N--) {
        cin >> name >> score;
        if (m[name].p_score >= 200) m[name].f_score = score;
    }
    vector<student> v;
    for (auto &it : m) {
        it.second.ID = it.first;
        if (it.second.f_score >= it.second.m_score) it.second.score = it.second.f_score;
        else it.second.score = int(it.second.m_score * 0.4 + it.second.f_score * 0.6 + 0.5);
        if(it.second.score >= 60) v.push_back(it.second);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v) cout << it.ID << " " << it.p_score << " " << it.m_score << " " << it.f_score << " " << it.score << endl;
    return 0;
}