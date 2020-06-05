//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1101~A1150/A1120-Friend_Numbers
//
//Created by Ezreal on 2020-06-05.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <set>

using namespace std;
int main() {
    int N;
    string number;
    cin >> N;
    set<int> result;
    while (N--) {
        cin >> number;
        int sum = 0;
        for (int i = 0; i < number.length(); i++) sum += (number[i] - '0');
        result.insert(sum);
    }
    cout << result.size() << endl;
    for (auto it : result) it == *result.begin() ? cout << it : cout << " " << it;
    cout << endl;
    return 0;
}