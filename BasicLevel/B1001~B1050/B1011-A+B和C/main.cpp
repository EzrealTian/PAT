//
//main.cpp
//B1011-A+B和C
//
//Created by Ezreal on 2019/07/28.
//Copyright © 2019年 Ezreal. All rights reserved.
//


//易错点：虽然自己机子上int是64位，但是int默认应该是32位
#include <cstdio>
int main(){
    long long A,B,C;
    int count;
    scanf("%d",&count);
    for (int i = 0; i < count; i++)
    {
        scanf("%lld%lld%lld",&A,&B,&C);
        if (A + B > C)  
        {
            printf("Case #%d: true\n",i + 1);
        }
        else
        {
            printf("Case #%d: false\n",i + 1);
        }
    }
    return 0;
}