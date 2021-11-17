//
//main.cpp
//~/Desktop/PAT/BasicLevel/B1001~B1050/B1003-我要通过！
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
    scanf("%d", &n);
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        bool flag = true;
        int length = str.length();
        int P_index = -1, T_index = -1;
        for (int j = 0; j < length; j++) {
            // 判断除了PAT之外的非法输入
            if (str[j] != 'P' && str[j] != 'A' && str[j] != 'T') {
                flag = false;
                break;
            }
            // 确定P的位置以及是否有重复的P
            if (str[j] == 'P') {
                if (P_index == -1)
                    P_index = j;
                else {
                    flag = false;
                    break;
                } 
            }
            // 确定T的位置以及是否有重复的T
            if (str[j] == 'T') {
                if (T_index == -1)
                    T_index = j;
                else {
                    flag = false;
                    break;
                }
            }
        }
        // 确定A的个数是否合法
        if (flag && P_index * (T_index - P_index - 1) == length - T_index - 1 && T_index > P_index + 1)
            printf("YES\n");
        else 
            printf("NO\n"); 
    }    
    return 0;
}