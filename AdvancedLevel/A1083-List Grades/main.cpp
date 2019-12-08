//
//main.cpp
//A1083-List Grades
//
//Created by Ezreal on 2019/09/17.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <algorithm>

struct Student {
    char name[11];
    char ID[11];
    int grade;
};

bool compare(Student stu1, Student stu2) {
    return stu1.grade > stu2.grade;
}

using namespace std;
int main(){
    int count;
    scanf("%d", &count);
    Student *students = new Student[count];
    for (int i = 0; i < count; i++) scanf("%s%s%d", students[i].name, students[i].ID, &students[i].grade);
    sort(students, students + count, compare);
    int min, max;
    scanf("%d%d", &min, &max);

    bool hasPrint = false;
    for (int i = 0; i < count; i++) {
        if (students[i].grade >= min && students[i].grade <= max) {
            printf("%s %s\n", students[i].name, students[i].ID);
            hasPrint = true;
        }
    }
    if (!hasPrint) printf("NONE\n");
    return 0;
}