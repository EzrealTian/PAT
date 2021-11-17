//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1101~A1150/A1116-Come_on_Lets_C
//
//Created by Ezreal on 2020-06-06.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>
#include <string>

using namespace std;
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main() {
    int N, K, index;
    vector<string> v(10000, "Are you kidding?");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &index);
        if (i == 1) v[index] = "Mystery Award";
        else if (is_prime(i)) v[index] = "Minion";
        else v[index] = "Chocolate";
    }
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &index);
        printf("%04d: %s\n", index, v[index].c_str());
        if (v[index] != "Are you kidding?") v[index] = "Checked";
    }
    return 0;
}