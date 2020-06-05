//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1144-The_Missing_Number
//
//Created by Ezreal on 2020-05-30.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <map>

using namespace std;
int main() {
    int N, t;
    cin >> N;
    map<int, int> m;
    while (N--) {
        cin >> t;
        m[t] = 1;
    }
    for (int i = 1; ; i++) {
        if (m[i] == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}