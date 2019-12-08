//
//main.cpp
//B1010-一元多项式求导
//
//Created by Ezreal on 2019/07/31.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    int coefficient, index;
    bool first = true;
    while (scanf("%d%d",&coefficient,&index) == 2) {
        if (first && index == 0) {
            printf("0 0\n");
            break;
        } else if (index == 0) {
            break;
        } else {
            if (first) {
                printf("%d %d",coefficient * index,index - 1);
                first = false;
            } else {
                printf(" %d %d",coefficient * index,index - 1);
            }
        }
    }
    return 0;
}