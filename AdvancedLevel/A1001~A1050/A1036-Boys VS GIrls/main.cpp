//
//main.cpp
//A1036-Boys VS Girls
//
//Created by Ezreal on 2019/09/04.
//Copyright © 2019年 Ezreal. All rights reserved.
//

struct Student {
    char name[11];
    char sex[2];
    char stuNum[11];
    int grade;
};

#include <cstdio>
#include <cstring>
int main(){
    int count;
    scanf("%d", &count);
    Student student;
    Student min,max;
    int minGrade = 101;
    int maxGrade = -1;
    for (int i = 0; i < count; i++) {
        scanf("%s%s%s%d", student.name, student.sex, student.stuNum, &student.grade);
        if (!strcmp(student.sex, "M")) {
            if (student.grade < minGrade) {
                minGrade = student.grade;
                min = student;
            }
        } else {
            if (student.grade > maxGrade) {
                maxGrade = student.grade;
                max = student;
            }
        }
    }
    maxGrade == -1 ? printf("Absent\n") : printf("%s %s\n", max.name, max.stuNum);
    minGrade == 101 ? printf("Absent\n") : printf("%s %s\n", min.name, min.stuNum);
    minGrade == 101 || maxGrade == -1 ? printf("NA\n") : printf("%d\n", maxGrade - minGrade);
    return 0;
}