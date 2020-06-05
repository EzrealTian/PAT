//
//main.cpp
//A1077-Kuchiguse
//
//Created by Ezreal on 2019/09/11.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    int number;
    scanf("%d", &number);
    getchar();
    char words[100][257];

    int minLength = 256;
    for (int i = 0; i < number; i++) {
        cin.getline(words[i], 257);
        if (strlen(words[i]) < minLength) minLength = strlen(words[i]);
    }
    int count = 0;
    char result[257];
    printf("%d\n", minLength);
    for (int i = 0; i < minLength; i++) {
        char temp = words[0][strlen(words[0]) - 1 - i];
        bool isCommon = true;
        for (int j = 0; j < number; j++) {
            if (temp != words[j][strlen(words[j]) - 1 - i]) {
                isCommon = false;
                break;
            } 
        }
        if (isCommon) {
            result[count] = temp;
            count++;
        } else break;
    }
    for (int i = count - 1; i >= 0; i--) printf("%c", result[i]);
    if (count == 0) printf("nai");
    printf("\n");
    return 0;
}