//
//main.cpp
//A1073-Scientific Notation
//
//Created by Ezreal on 2019/09/10.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>

int main(){
    char str[10010];
    scanf("%s", str);
    if (str[0] == '-') printf("-");

    int length = strlen(str);
    int ECount;
    for (int i = 0; i < length; i++) {
        if (str[i] == 'E') {
            ECount = i;
            break;
        }
    }
    int exp = 0;
    for (int i = ECount + 2; i < length; i++) {
        exp = (str[i] - '0') + exp * 10;
    }
    if (str[ECount + 1] == '+') {
        if (ECount - 3 <= exp) {
            printf("%c", str[1]);
            for(int i = 3;i < ECount; i++) printf("%c", str[i]);
            for (int i = 0; i < exp - ECount + 3; i++) printf("0");
        } else {
            printf("%c", str[1]);
            for(int i = 3;i < ECount; i++) {
                printf("%c", str[i]);
                if (i - 2 == exp) printf(".");
            }
        }
    } else {
        printf("0.");
        for (int i = 0; i < exp - 1; i++) printf("0");
        for (int i = 1; i < ECount; i++) if (str[i] != '.') printf("%c", str[i]);
    }
    return 0;
}
