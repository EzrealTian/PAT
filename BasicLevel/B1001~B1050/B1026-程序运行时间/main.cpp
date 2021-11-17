//
//main.cpp
//B1026-程序运行时间
//
//Created by Ezreal on 2019/07/28.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
int main(){
    int start, end;
    scanf("%d%d",&start,&end);
    int time = (end - start) % 100 > 49 ? (end - start)/100 + 1 : (end - start)/100;    //要四舍五入
    int hour, minute, second;
    hour = time / 3600;
    time %= 3600;
    minute = time / 60;
    second = time % 60;
    printf("%02d:%02d:%02d\n",hour,minute,second);  //格式化输出
    return 0;
}