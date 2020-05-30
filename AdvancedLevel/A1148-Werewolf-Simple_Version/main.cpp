//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1148-Werewolf-Simple_Version
//
//Created by Ezreal on 2020-05-29.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) cin >> v[i];
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            vector<int> wolf(N + 1, 1);
            wolf[i] = wolf[j] = -1;
            vector<int> lie;
            for (int k = 1; k <= N; k++) {
                if (v[k] * wolf[abs(v[k])] < 0) lie.push_back(k);
            } 
            if (lie.size() == 2 && wolf[lie[0]] + wolf[lie[1]] == 0) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "No Solution\n";
    return 0;
}