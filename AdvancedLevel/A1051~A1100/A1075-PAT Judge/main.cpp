//
//main.cpp
//A1075-PAT Judge
//
//Created by Ezreal on 2019/09/16.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <algorithm>

struct Student {
    int ID;
    int grade[6];
    int perfectCount;
    int totalGrade;
    int solutionCount;
    bool shouldPrint;
    int rank;
};

bool compare(Student stu1, Student stu2) {
    if (stu1.totalGrade != stu2.totalGrade) return stu1.totalGrade > stu2.totalGrade;
    if (stu1.solutionCount != stu2.solutionCount) return stu1.solutionCount > stu2.solutionCount;
    return stu1.ID < stu2.ID;
}

using namespace std;
int main(){
    int stuCount, questionCount, submissionCount;
    scanf("%d%d%d", &stuCount, &questionCount, &submissionCount);
    Student *students = new Student[stuCount + 1];
    for (int i = 1; i < stuCount + 1; i++) for (int j = 1; j < questionCount + 1; j++) students[i].grade[j] = -2;   //初始化成绩
    
    //输入每一题的满分值
    int *perfectGrade = new int[questionCount + 1];
    for (int i = 1; i < questionCount + 1; i++) scanf("%d", &perfectGrade[i]);  //每一题满分值

    int tempID, tempIndex, tempGrade;
    for (int i = 1; i < submissionCount + 1; i++) {
        scanf("%d%d%d", &tempID, &tempIndex, &tempGrade);
        if (students[tempID].grade[tempIndex] < tempGrade) students[tempID].grade[tempIndex] = tempGrade;
    }

    Student *result = new Student[stuCount + 1];
    int count = 0;
    for (int i = 1; i < stuCount + 1; i++) {
        students[i].totalGrade = 0;
        students[i].solutionCount = 0;
        students[i].shouldPrint = false;
        for (int j = 1; j < questionCount + 1; j++) {
            if (students[i].grade[j] > -1) {
                students[i].totalGrade += students[i].grade[j];
                students[i].shouldPrint = true;
            }
            if (students[i].grade[j] == perfectGrade[j]) students[i].solutionCount++;
        }
        if (students[i].shouldPrint) {
            result[count] = students[i];
            result[count].ID = i;
            count++;
        }
    }
    sort(result, result + count, compare);
    //for (int i = 1; i < count + 1; i++) printf("%05d\n", )
    result[0].rank = 1;
    for (int i = 1; i < count; i++) {
        if (result[i].totalGrade == result[i - 1].totalGrade) result[i].rank = result[i - 1].rank;
        else result[i].rank = i + 1;
    }
    for (int i = 0; i < count; i++) {
        printf("%d %05d %d", result[i].rank, result[i].ID, result[i].totalGrade);
        for (int j = 1; j < questionCount + 1; j++) {
            if (result[i].grade[j] == -2) printf(" -");
            else if (result[i].grade[j] == -1) printf(" 0");
            else printf(" %d", result[i].grade[j]);
        }
        printf("\n");
    }
    return 0;
}