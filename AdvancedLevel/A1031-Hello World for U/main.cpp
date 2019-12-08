//
//main.cpp
//A1031-Hello World for U
//
//Created by Ezreal on 2019/09/04.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>
int main(){
    char input[101];
    scanf("%s", input);
    int length = strlen(input);
    int lineCount = (length + 2) / 3;     //行数
    int width;
    if ((length + 2) % 3 == 0) {
        width = (length + 2) / 3;
    } else if ((length + 2) % 3 == 1) {
        width = (length + 2) / 3 + 1;
    } else {
        width = (length + 2) / 3 + 2;
    }
    //int width = (length + 2) % 3 == 0 ? (length + 2) / 3 : (length + 2) / 3 + 1;  //每行字符数
    //printf("%d\n",width);
    for (int i = 0; i < lineCount - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) printf("%c", input[i]);
            else if (j == width - 1) printf("%c" ,input[length - 1 - i]);
            else printf(" ");
        }
        printf("\n");
    }
    for (int i = lineCount - 1; i < lineCount + width - 1; i++) printf("%c", input[i]);
    printf("\n");
    return 0;
}