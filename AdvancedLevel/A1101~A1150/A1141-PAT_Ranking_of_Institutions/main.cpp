//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1141-PAT_Ranking_of_Institutions
//
//Created by Ezreal on 2020-05-31.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
struct insitution {
    string name;
    double score;
    int count;
};
bool cmp(insitution i1, insitution i2) {
    if (i1.score != i2.score) return i1.score > i2.score;
    else if (i1.count != i2.count) return i1.count < i2.count;
    else return i1.name < i2.name;
}
int main() {
    int n;
    double score;
    string ID, ins;
    map<string, insitution> m;
    cin >> n;
    while (n--) {
        cin >> ID >> score >> ins;
        for (auto &it : ins) it = tolower(it);
        if (ID[0] == 'T') m[ins].score += (score*1.5);
        else ID[0] == 'A' ? m[ins].score += score : m[ins].score += (score/1.5);
        m[ins].count++;
    }
    vector<insitution> v;
    for (auto &it : m) {
        it.second.name = it.first;
        it.second.score = int(it.second.score);
        v.push_back(it.second);
    }
    sort(v.begin(), v.end(), cmp);
    cout << v.size() << endl;
    int rank, t_rank;
    for (int i = 0; i < v.size(); i++) {
        if (i != 0 && v[i].score == v[i - 1].score) rank = t_rank;
        else rank = i + 1;
        cout << rank << " " << v[i].name << " " << int(v[i].score) << " " << v[i].count << endl;
        t_rank = rank;
    }
    return 0;
}