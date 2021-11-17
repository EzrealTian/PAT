//
//main.cpp
//B1041-考试座位号
//
//Created by Ezreal on 2019/09/01.
//Copyright © 2019年 Ezreal. All rights reserved.
//
/**
 * 节省空间的思路，在输入座位信息的时候直接将测试机位当做数组下标，这样在查询的时候不需要循环遍历，直接下标取出信息即可，节省了时间
*/
struct SeatInfo {
    char id[17];
    int testSeat;
    int examSeat;
};

#include <cstdio>
int main(){
    int count;
    scanf("%d",&count);
    SeatInfo *seatInfo = new SeatInfo[count];
    for (int i = 0; i < count; i++) {
        scanf("%s%d%d",seatInfo[i].id, &seatInfo[i].testSeat, &seatInfo[i].examSeat);
    }
    int querySeat;
    int count2;
    scanf("%d", &count2);
    for(int i = 0; i < count2; i++) {
        scanf("%d", &querySeat);
        for (int j = 0; j < count; j++) {
            if(seatInfo[j].testSeat == querySeat) {
                printf("%s %d\n", seatInfo[j].id, seatInfo[j].examSeat);
                break;
            }
        }
    }
    return 0;
}