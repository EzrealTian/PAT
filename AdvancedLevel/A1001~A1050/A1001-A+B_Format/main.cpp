//
//main.cpp
//A1001-A+B Format
//
//Created by Ezreal on 2019-09-11.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <string>

using namespace std;
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    int sum = a + b;
    if (sum < 0) {
        printf("-");
        sum = -sum;
    }
    string str = to_string(sum);
    int length = str.length();
    int head = length % 3;
    for (int i = 0; i < head; i++) printf("%c", str[i]);
    for (int i = head; i < length; i++) {
        if ((i - head) % 3 == 0 && i > 0) printf(",");
        printf("%c", str[i]);
    }
    return 0;
}