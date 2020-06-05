//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1132-Cut_Integer
//
//Created by Ezreal on 2020-06-02.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>

using namespace std;
int main() {
    int N, number;
    string a, b;
    cin >> N;
    while (N--) {
        cin >> number;
        string t_str = to_string(number);
        a = t_str.substr(0, t_str.length()/2);
        b = t_str.substr(t_str.length()/2);
        int t = stoi(a) * stoi(b);
        if (t == 0) {   // 除数为零
            cout << "No\n";
            continue;
        }
        number % t == 0 ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}