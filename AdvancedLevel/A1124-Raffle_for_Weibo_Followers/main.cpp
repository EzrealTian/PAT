//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1124-Raffle_for_Weibo_Followers
//
//Created by Ezreal on 2020-06-04.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <unordered_map>

using namespace std;
int main(int argc, const char * argv[]) {
    int M, N, S;
    unordered_map<string, int> m;
    string name;
    cin >> M >> N >> S;
    int count = N - 1;
    if (S > M) {
        cout << "Keep going..." << endl;
        return 0;
    }
    for (int i = 1; i < S; i++) cin >> name;
    for (int i = S; i <= M; i++) {
        cin >> name;
        if (m[name] == 1) continue;
        count++;
        if (count == N) {
            m[name] = 1;
            count = 0;
            cout << name << endl;
        }
    }
    return 0;
}
