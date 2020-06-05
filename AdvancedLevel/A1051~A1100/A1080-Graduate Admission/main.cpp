//
//main.cpp
//A1080-Graduate Admission
//
//Created by Ezreal on 2019/09/17.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <algorithm>

struct Student
{
    int EGrade; //exam成绩
    int IGrade; //interview成绩
    int aveGrade;   //平均成绩
    int index;  //序号
    int rank;   //排名
    int application[5];  //志愿
};

bool compare(Student stu1, Student stu2) {
    if (stu1.aveGrade != stu2.aveGrade) return stu1.aveGrade > stu2.aveGrade;
    return stu1.EGrade > stu2.EGrade;
}

bool compare2(int num1, int num2) {
    return num1 < num2;
}

using namespace std;
int main(){
    //输入志愿数量， 学校数量， 每位学生志愿数量
    int stuCount, schoolCount, applicationCount;
    scanf("%d%d%d", &stuCount, &schoolCount, &applicationCount);
    //输入每个学校招生限制
    int *numConfine = new int[schoolCount];
    for (int i = 0; i < schoolCount; i++) scanf("%d", &numConfine[i]);
    //输入志愿
    Student *stuList = new Student[stuCount];
    for (int i = 0; i < stuCount; i++) {
        scanf("%d%d", &stuList[i].EGrade, &stuList[i].IGrade);
        stuList[i].aveGrade = (stuList[i].EGrade + stuList[i].IGrade) / 2;
        stuList[i].index = i; 
        for (int j = 0; j < applicationCount; j++) scanf("%d", &stuList[i].application[j]);
    }
    sort(stuList, stuList + stuCount, compare);
    stuList[0].rank = 0;

    for (int i = 1; i < stuCount; i++) {
        if (stuList[i].aveGrade == stuList[i - 1].aveGrade && stuList[i].EGrade == stuList[i - 1].EGrade) stuList[i].rank = stuList[i - 1].rank;
        else stuList[i].rank = i;
    }
    int school[5][40000] = {0};
    int *index = new int[schoolCount];
    int *lastRank = new int[schoolCount];
    for (int i = 0; i < stuCount; i++) {
        for (int j = 0; j < applicationCount; j++) {
            int choice = stuList[i].application[j];
            if (numConfine[choice] > 0 || stuList[i].rank == lastRank[choice]) {
                school[choice][index[choice]] = stuList[i].index;
                //index[choice]++;
                numConfine[choice]--;
                //lastRank[choice] = stuList[i].rank;
                break;
            }
        }
    }
    for (int i = 0; i < schoolCount; i++) sort(school[i], school[i] + index[i], compare2);
    for (int i = 0; i < schoolCount; i++) {
        if (index[i] == 0) printf("\n");
        else {
            for (int j = 0; j < index[i]; j++) {
                printf("%d", school[i][j]);
                if (j != index[i] - 1) printf(" ");
            }
            printf("\n");
        }
    }
    //for (int i = 0; i < stuCount; i++) printf("%d %d %d %d\n", stuList[i].index, stuList[i].aveGrade, stuList[i].EGrade, stuList[i].rank);
    return 0;
}