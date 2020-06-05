//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1145-Hashing-Average_Search_Time
//
//Created by Ezreal on 2020-05-30.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>

using namespace std;
int getPrime(int n) {
    bool isPrime = true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime) return n;
    else return getPrime(n + 1);
}
int main() {
    int MSize, N, M, number;
    scanf("%d%d%d", &MSize, &N, &M);
    int TSize = getPrime(MSize);
    vector<int> v(TSize, -1);
    for (int i = 0; i < N; i++) {
        scanf("%d", &number);
        bool flag = false;
        for (int j = 0; j < TSize; j++) {
            if (v[(number + j * j) % TSize] == -1) {
                v[(number + j * j) % TSize] = number;
                flag = true;
                break;
            }
        }
        if (!flag) printf("%d cannot be inserted.\n", number);
    }
    double count = 0.0;
    for (int i = 0; i < M; i++) {
        scanf("%d", &number);
        for (int j = 0; j <= TSize; j++) {
            count++;
            if (v[(number + j * j) % TSize] == number || v[(number + j * j) % TSize] == -1) break;
        }
    }
    printf("%.1f\n", count/M);
    return 0;
}