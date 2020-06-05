//
//main.cpp
//A1025-PAT Ranking
//
//Created by Ezreal on 2019/09/12.
//Copyright © 2019年 Ezreal. All rights reserved.
//
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Student {
    char ID[14];
    int score;
    int locationNum;
    int locationRank;
    int totalRank;
};

bool compare(Student stu1, Student stu2) {
    if (stu1.score != stu2.score) return stu1.score > stu2.score;
    else return strcmp(stu1.ID, stu2.ID) < 0;
}
int main(){
    Student students[30000];
    int count = 0;
    int locationCount;
    int number;
    scanf("%d", &locationCount);
    for (int i = 1; i <= locationCount; i++) {
        scanf("%d", &number);
        for (int j = 0; j < number; j++) {
            scanf("%s%d", students[count].ID, &students[count].score);
            students[count].locationNum = i;
            count++;
        }
        sort(students + count - number, students + count, compare);
        students[count - number].locationRank = 1;
        for (int j = count - number + 1; j < count; j++) {
            if (students[j].score == students[j - 1].score) students[j].locationRank = students[j - 1].locationRank;
            else students[j].locationRank = j - count + number + 1;
        }
    }
    sort(students, students + count, compare);
    students[0].totalRank = 1;
    for (int i = 1; i < count; i++) {
        if (students[i].score == students[i - 1].score) students[i].totalRank = students[i - 1].totalRank;
        else students[i].totalRank = i + 1;
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s %d %d %d\n",students[i].ID, students[i].totalRank, students[i].locationNum, students[i].locationRank);
    }
    return 0;
}