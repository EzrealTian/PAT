//
//main.cpp
//A1016-Phone Bills
//
//Created by Ezreal on 2019/09/13.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>
#include <algorithm>

struct User {
    char name[21];
    int month;
    int day;
    int hour;
    int minute;
    char state[9];
};

bool compare(User user1, User user2) {
    if (strcmp(user1.name, user2.name) == 0) {
        return user1.day * 24 * 60 + user1.hour * 60 + user1.minute < user2.day * 24 * 60 + user2.hour * 60 + user2.minute;
    }
    return strcmp(user1.name, user2.name) < 0;
}

using namespace std;
int main(){
    int rate[24];
    for (int i = 0; i < 24; i++) scanf("%d", &rate[i]);
    int count;
    scanf("%d", &count);
    User *user = new User[count];
    for (int i = 0; i < count; i++) scanf("%s%d:%d:%d:%d%s", user[i].name, &user[i].month, &user[i].day, &user[i].hour, &user[i].minute, user[i].state);
    sort(user, user + count, compare);
    //for (int i = 0; i < count; i++) printf("%s %02d:%02d:%02d:%02d %s\n", user[i].name, user[i].month, user[i].day, user[i].hour, user[i].minute, user[i].state);
    double perDayPrice = 0;
    for (int k = 0; k < 24; k++) perDayPrice += 60 * rate[k];   //24小时话费
    char tempName[21];  //当前用户名
    strcpy(tempName, user[0].name);
    double totalPrice = 0;  //当前用户总花费
    bool hasPrint = false;  //当前用户是否print过名字
    for (int i = 0; i < count - 1; i++) {
        double price = 0;
        int minute = 0;
        if (strcmp(user[i].name, tempName) != 0) { 
            strcpy(tempName, user[i].name);
            if (totalPrice > 0) printf("Total amount: $%.2lf\n", totalPrice);
            hasPrint = false;
            totalPrice = 0;
        }
        if (strcmp("on-line", user[i].state) == 0 && strcmp("off-line", user[i + 1].state) == 0 && strcmp(user[i].name, user[i + 1].name) == 0) {
            if (!hasPrint) {
                printf("%s %02d\n", tempName, user[i].month);
                hasPrint = true;
            }
            if (user[i].day < user[i + 1].day) {
                price += (user[i + 1].day - user[i].day - 1) * perDayPrice;
                minute += (user[i + 1].day - user[i].day - 1) * 60 * 24;
                for (int k = user[i].hour; k < 24; k++) {
                    price += rate[k] * 60;
                    minute += 60;
                }
                for (int k = 0; k < user[i + 1].hour; k++) {
                    price += rate[k] * 60;
                    minute += 60;
                }
            } else {
                for (int k = user[i].hour; k < user[i + 1].hour; k++) {
                    price += rate[k] * 60;
                    minute += 60;
                }
            }
            price  = price - rate[user[i].hour] * user[i].minute + rate[user[i + 1].hour] * user[i + 1].minute;
            minute = minute - user[i].minute + user[i + 1].minute;
            price /= 100;
            totalPrice += price;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",user[i].day, user[i].hour, user[i].minute, user[i + 1].day, user[i + 1].hour, user[i + 1].minute, minute, price);
        }
    }
    if (totalPrice > 0) printf("Total amount: $%.2lf\n", totalPrice);
    return 0;
}