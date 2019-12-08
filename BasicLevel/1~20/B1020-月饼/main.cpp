//
//main.cpp
//B1020-月饼
//
//Created by Ezreal on 2019/12/08.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <stdio.h>
#include <algorithm>

struct Mood {   //月饼结构体
    double count;
    double price;
};

bool compare(Mood mood1, Mood mood2) {  //比较函数
    return mood1.price > mood2.price;
}
using namespace std;
int main(){
    int typeCount;  //月饼种类
    double needs;   //需求量
    double temp;    
    scanf("%d%lf", &typeCount, &needs);
    Mood *moods = new Mood[typeCount];  //月饼数组
    for (int i = 0; i < typeCount; i++) scanf("%lf", &moods[i].count); 
    for (int i = 0; i < typeCount; i++) {
        scanf("%lf", &temp);
        moods[i].price = temp / moods[i].count; //存每种月饼的单价
    }   

    sort(moods, moods + typeCount, compare);    //递减排序
    double price = 0;

    for (int i = 0; i < typeCount; i++) {
        if (needs >= moods[i].count) {  //需求大于当前种类库存，卖出全部库存
            price += moods[i].count * moods[i].price;
            needs -= moods[i].count;
        } else {
            price += needs * moods[i].price;
            break;
        }
    }
    printf("%.2lf\n", price);

    return 0;
}