//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1152-Google_Recruitment
//
//Created by Ezreal on 2020-05-27.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <string>

using namespace std;
bool isPrime(int number) {
    if (number == 0 || number == 1) return false;
    for (int i  = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}
int main() {
    int length, K;
    string s;
    cin >> length >> K >> s;
    for (int i = 0; i + K - 1 < length; i++) {
        string tempStr = s.substr(i, K);
        int number = stoi(tempStr);
        if (isPrime(number)) {
            cout << tempStr << endl;
            return 0;
        }
    }
    cout << 404 << endl;
    return 0;
}