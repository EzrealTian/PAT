//
//main.cpp
//B1029-旧键盘
//
//Created by Ezreal on 2019/12/09.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <stdio.h>
#include <cstring>
int main(){
    bool charSet[128] = {false};    //位示图
    char string1[81], string2[81];  

    scanf("%s", string1);   //正确输入
    scanf("%s", string2);   //错误输入
    for (int i = 0; i < strlen(string2); i++) { //标记错误输入的字符串中的字符
        if (string2[i] >= 'a' && string2[i] <= 'z') charSet[string2[i] + 'A' - 'a'] = true;
        else charSet[string2[i]] = true;
    }
    for (int i = 0; i < strlen(string1); i++) { //输出没有被标记的字符，也就是坏键
        int temp = string1[i] >= 'a' && string1[i] <= 'z' ? string1[i] + 'A' - 'a' : string1[i];
        if (!charSet[temp]) {
            printf("%c", temp);
            charSet[temp] = true;
        }
    }
    printf("\n");
    return 0;
}