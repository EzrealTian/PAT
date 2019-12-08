//
//main.cpp
//B1004-成绩排名
//
//Created by Ezreal on 2019/09/03.
//Copyright © 2019年 Ezreal. All rights reserved.
//

struct Student {
    char name[11];
    char number[11];
    int grade;
};

#include <cstdio>
int main(){
    int count;
    scanf("%d",&count);
    int maxIndex;
    int maxGrade = 0;
    int minIndex;
    int minGrade = 100;
    Student *list = new Student[count];
    for(int i = 0; i < count; i++) {
        scanf("%s%s%d",list[i].name, list[i].number, &list[i].grade);
        if(list[i].grade > maxGrade) {
            maxIndex = i;
            maxGrade = list[i].grade;
        }
        if(list[i].grade < minGrade) {
            minIndex = i;
            minGrade = list[i].grade;
        }
    }
    printf("%s %s\n", list[maxIndex].name, list[maxIndex].number);
    printf("%s %s\n", list[minIndex].name, list[minIndex].number);
    return 0;
}