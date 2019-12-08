//
//main.cpp
//B1027-打印沙漏
//
//Created by Ezreal on 2019/09/04.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    int number;
    char C;
    scanf("%d %c", &number, &C);
    int lineCount;
    for (lineCount = 1; 2 * lineCount * lineCount - 1 <= number; lineCount++);
    lineCount--;
    int totalCount = 2 * lineCount * lineCount - 1;
    for (int i = lineCount; i >= 1; i--) {
        for(int k = 0; k < lineCount - i; k++) printf(" ");
        for (int j = 0; j < i * 2 - 1; j++) printf("%c", C);
        printf("\n");
    }
    for (int i = 2; i <= lineCount; i++) {
        for(int k = 0; k < lineCount - i; k++) printf(" ");
        for (int j = 0; j < i * 2 - 1; j++) printf("%c", C);
        printf("\n");
    }
    printf("%d\n",number - totalCount);
    return 0;
}