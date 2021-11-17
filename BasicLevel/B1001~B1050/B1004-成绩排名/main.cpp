//
//main.cpp
//~/Desktop/PAT/BasicLevel/B1001~B1050/B1004-成绩排名
//
//Created by Ezreal on 2021-02-08.
//Copyright © 2021年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int main() {
    int n;
    string name, ID;
    int grade;
    scanf("%d", &n);
    string l_name, h_name, l_ID, h_ID;
    int l_grade = 100;  // 当前最低分
    int h_grade = -1;   // 当前最高分
    for (int i = 0; i < n; i++) {
        cin >> name >> ID >> grade;
        if (grade < l_grade) {
            l_name = name;
            l_ID = ID;
            l_grade = grade;
        }
        if (grade > h_grade) {
            h_name = name;
            h_ID = ID;
            h_grade = grade;
        }
    }
    cout << h_name << " " << h_ID << "\n";
    cout << l_name << " " << l_ID << "\n";
    return 0;
}