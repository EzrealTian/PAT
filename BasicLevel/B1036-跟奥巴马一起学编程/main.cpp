//
//main.cpp
//B1036-跟奥巴马一起学编程
//
//Created by Ezreal on 2019/09/04.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    int count;
    char input[2];
    scanf("%d%s", &count, input);
    int temp = count % 2 == 0 ? count - 1 : count;
    for (int i = 0; i < temp; i++){
        if (i == 0 || i == temp - 1) {
            for (int j = 0; j < count; j++) {
                printf("%s",input);
            }
            printf("\n");
        } else {
            if (i % 2 == 1) printf("");
            else {
                for(int k = 0; k < count; k++) {
                    if(k == 0 || k == count - 1) printf("%s", input);
                    else printf(" ");
                }
                printf("\n");
            }
        }
    }
    
    return 0;
}