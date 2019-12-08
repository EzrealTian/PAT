//
//main.cpp
//B1003-我要通过！
//
//Created by Ezreal on 2019/12/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <stdio.h>
#include <cstring>
int main(){
    int count;
    char input[101];
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        bool flag = true;
        int P_index, T_index;
        scanf("%s", input);
        int length = strlen(input);
        for (int j = 0; j < length; j++){
            if (input[j] != 'P' && input[j] != 'A' && input[j] != 'T') {
                flag = false;
                continue;
            }
            if (input[j] == 'P') P_index = j;
            if (input[j] == 'T') T_index = j;
        }
        if (P_index * (T_index - P_index - 1) == length - T_index - 1 && flag && T_index - P_index > 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}