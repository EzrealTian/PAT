//
//main.cpp
//B1031-查验身份证
//
//Created by Ezreal on 2019/09/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//


#include <cstdio>
int main(){
    char ID[19];
    int count;
    char M[11]  = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    scanf("%d", &count);
    bool isAllPassed = true;
    for (int i = 0; i < count; i++) {
        scanf("%s", ID);
        bool hasLetter = false;
        for (int i = 0; i < 17; i++){
            if (ID[i] < '0' || ID[i] > '9') {
                printf("%s\n", ID);
                hasLetter = true;
                isAllPassed = false;
                break;
            }
        }
        if (hasLetter) {
            continue;
        } else {
            int Z = (ID[0] - '0') * 7 + (ID[1] - '0') * 9 + (ID[2] - '0') * 10 + (ID[3] - '0') * 5 + (ID[4] - '0') * 8 + (ID[5] - '0') * 4 + (ID[6] - '0') * 2 + (ID[7] - '0') * 1 + (ID[8] - '0') * 6 + (ID[9] - '0') * 3 + (ID[10] - '0') * 7 + (ID[11] - '0') * 9 + (ID[12] - '0') * 10 + (ID[13] - '0') * 5 + (ID[14] - '0') * 8 + (ID[15] - '0') * 4 + (ID[16] - '0') * 2; 
            Z %= 11;
            if (M[Z] != ID[17]) {
                printf("%s\n", ID);
                isAllPassed = false;
            }
        }
    }
    if (isAllPassed) printf("All passed\n");
    return 0;
}