//
//main.cpp
//B1048-数字加密
//
//Created by Ezreal on 2019/09/10.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>

int main(){
    char A[101];
    char B[101];
    char set[14] = {'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
    scanf("%s", A);
    scanf("%s", B);
    int lengthA = strlen(A) - 1;
    int lengthB = strlen(B) - 1;
    for (int i = 0; i < lengthA/2 + 1; i++) {
        char temp;
        temp = A[i];
        A[i] = A[lengthA - i];
        A[lengthA - i] = temp;
    }
    for (int i = 0; i < lengthB/2 + 1; i++) {
        char temp;
        temp = B[i];
        B[i] = B[lengthB - i];
        B[lengthB - i] = temp;
    }
    if (lengthA > lengthB) for (int i = lengthB + 1; i <= lengthA; i++) B[i] = '0'; //补0
    else for (int i = lengthA + 1; i <= lengthB; i++) A[i] = '0';
    int length = lengthA > lengthB ? lengthA : lengthB;

    for (int i = 0; i <= length; i++) {
        int a = A[i] - '0';
        int b = B[i] - '0';
        if (i % 2 == 0) B[i] = set[(a + b)%13];
        else B[i] = b - a < 0 ? b - a + 10 + '0' : b - a + '0';
        printf("%d %c\n",i + 1, B[i]);
    }
    for (int i = length; i >= 0; i--) printf("%c", B[i]);
    printf("\n");
    return 0;
}