//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1130-Infix_Expression
//
//Created by Ezreal on 2020-06-03.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <map>
#include <string>

using namespace std;
struct node {
    string value;
    int left, right;
};
node n[21];
string in_order(int root) {
    if (root == -1) return "";
    if (n[root].left == -1 && n[root].right == -1) return n[root].value;
    else return "(" + in_order(n[root].left) + n[root].value + in_order(n[root].right) + ")";
}
int main() {
    int N;
    cin >> N;
    map<int, int> m;
    for (int i = 1; i <= N; i++) {
        cin >> n[i].value >> n[i].left >> n[i].right;
        m[n[i].left] = m[n[i].right] = 1;
    }
    int root;
    for (int i = 1; i <= N; i++) if (m[i] == 0) root = i;
    string result = in_order(root);
    if (result[0] == '(') {
        int count = 0;
        bool flag = true;
        for (int i = 0; i < result.length(); i++) {
            if (result[i] == '(') count++;
            if (result[i] == ')') count--;
            if (count == 0 && i != result.length() - 1) {
                flag = false;
                break;
            }
        }
        if (flag) result = result.substr(1, result.length() - 2);
    }
    cout << result << endl;
    return 0;
}