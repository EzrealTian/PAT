//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1136-A_Delayed_Palindrome
//
//Created by Ezreal on 2020-06-01.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <string>

using namespace std;
int main() {
    string s, t_s;
    cin >> s;
    for (int i = 0; i < 10; i++) {
        bool is_palin = true;
        t_s = s;
        for (int j = 0; j < t_s.size()/2; j++) {
            if (t_s[j] != t_s[t_s.size() - j - 1]) is_palin = false;
            swap(t_s[j], t_s[t_s.size() - j - 1]);
        }
        if (is_palin) {
            cout << s << " is a palindromic number.\n";
            return 0;
        }
        bool up = false;
        string s_sum = s;
        for (int j = s.size() - 1; j >= 0; j--) {
            int a = s[j] - '0';
            int b = t_s[j] - '0';
            int sum = up ? a + b + 1 : a + b;
            if (sum > 9) {
                up = true;
                s_sum[j] = sum + '0' - 10;
            } else {
                up = false;
                s_sum[j] = sum + '0';
            }
            if (j == 0 && up) s_sum = "1" + s_sum;
        }
        cout << s << " + " << t_s << " = " << s_sum << endl;
        s = s_sum;
    }
    cout << "Not found in 10 iterations.\n";
    return 0;
}