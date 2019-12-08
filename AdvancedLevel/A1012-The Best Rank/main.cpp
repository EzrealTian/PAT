//
//main.cpp
//A1012-The Best Rank
//
//Created by Ezreal on 2019/09/13.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Student {
    char ID[7];
    int C_Score;
    int M_Score;
    int E_Score;
    int A_Score;
    int tempRank;
    int finalRank;
    char lesson;
};
bool compare1 (Student stu1, Student stu2) {
    return stu1.C_Score > stu2.C_Score;
}
bool compare2 (Student stu1, Student stu2) {
    return stu1.M_Score > stu2.M_Score;
}
bool compare3 (Student stu1, Student stu2) {
    return stu1.E_Score > stu2.E_Score;
}
bool compare4 (Student stu1, Student stu2) {
    return stu1.A_Score > stu2.A_Score;
}

int main(){
    int inputNumber;
    int outputNumber;
    scanf("%d%d", &inputNumber, &outputNumber);
    Student *students = new Student[inputNumber];
    for (int i = 0; i < inputNumber; i++) {
        scanf("%s%d%d%d", students[i].ID, &students[i].C_Score, &students[i].M_Score, &students[i].E_Score);
        students[i].A_Score = (students[i].C_Score + students[i].M_Score + students[i].E_Score) / 3;
    }

    sort(students, students + inputNumber, compare3);
    students[0].finalRank = 1;
    students[0].lesson = 'E';
    for (int i = 1; i < inputNumber; i++) {
        if (students[i].E_Score == students[i - 1].E_Score) students[i].finalRank = students[i - 1].finalRank;
        else students[i].finalRank = i + 1;
        students[i].lesson = 'E';
    }

    sort(students, students + inputNumber, compare2);
    students[0].tempRank = 1;
    if (students[0].tempRank <= students[0].finalRank) {
        students[0].finalRank = students[0].tempRank;
        students[0].lesson = 'M';
    }
    for (int i = 1; i < inputNumber; i++) {
        if (students[i].M_Score == students[i - 1].M_Score) students[i].tempRank = students[i - 1].tempRank;
        else students[i].tempRank = i + 1;
        if (students[i].tempRank <= students[i].finalRank) {
            students[i].finalRank = students[i].tempRank;
            students[i].lesson = 'M';
        }
    }

    sort(students, students + inputNumber, compare1);
    students[0].tempRank = 1;
    if (students[0].tempRank <= students[0].finalRank) {
        students[0].finalRank = students[0].tempRank;
        students[0].lesson = 'C';
    }
    for (int i = 1; i < inputNumber; i++) {
        if (students[i].C_Score == students[i - 1].C_Score) students[i].tempRank = students[i - 1].tempRank;
        else students[i].tempRank = i + 1;
        if (students[i].tempRank <= students[i].finalRank) {
            students[i].finalRank = students[i].tempRank;
            students[i].lesson = 'C';
        }
    }

    sort(students, students + inputNumber, compare4);
    students[0].tempRank = 1;
    if (students[0].tempRank <= students[0].finalRank) {
        students[0].finalRank = students[0].tempRank;
        students[0].lesson = 'A';
    }
    for (int i = 1; i < inputNumber; i++) {
        if (students[i].A_Score == students[i - 1].A_Score) students[i].tempRank = students[i - 1].tempRank;
        else students[i].tempRank = i + 1;
        if (students[i].tempRank <= students[i].finalRank) {
            students[i].finalRank = students[i].tempRank;
            students[i].lesson = 'A';
        }
    }
    char ID[7];
    for (int i = 0; i < outputNumber; i++) {
        scanf("%s", ID);
        bool hasFound = false;
        for (int j = 0; j < inputNumber; j++) {
            if (strcmp(ID, students[j].ID) == 0) {
                hasFound = true;
                printf("%d %c\n",students[j].finalRank, students[j].lesson);
                break;
            }
        }
        if (!hasFound) printf("N/A\n");
    }
    return 0;
}