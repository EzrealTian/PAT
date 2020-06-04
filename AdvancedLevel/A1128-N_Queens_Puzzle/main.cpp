//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1128-N_Queens_Puzzle
//
//Created by Ezreal on 2020-06-02.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <map>

using namespace std;
int main() {
    int N, count, number;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &count);
        vector<int> v1(count * 2), v2(count * 2);
        map<int, int> m;
        int flag = true;
        for (int i = 1; i <= count; i++) {
            scanf("%d", &number);
            if (m[number] == 1) flag = false;
            m[number] = 1;
            v1[i + number - 1]++;
            v2[count - i + number]++;
        }
        for (int i = 1; i < count * 2 - 1; i++) {
            if (v1[i] > 1 || v2[i] > 1) {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}