//
//main.cpp
//A1028-List Sorting
//
//Created by Ezreal on 2019/09/15.
//Copyright © 2019年 Ezreal. All rights reserved.
//



# include <cstdio>
# include <cstring>
# include <algorithm>

struct Student {
    char ID[7];
    char name[9];
    int grade;
};
bool compare1(Student stu1, Student stu2) {
    return strcmp(stu1.ID, stu2.ID) < 0;
}
bool compare2(Student stu1, Student stu2) {
    if (strcmp(stu1.name, stu2.name) == 0) return strcmp(stu1.ID, stu2.ID) < 0;
    return strcmp(stu1.name, stu2.name) < 0;
}
bool compare3(Student stu1, Student stu2) {
    if (stu1.grade == stu2.grade) return strcmp(stu1.ID, stu2.ID) < 0;
    return stu1.grade < stu2.grade;
}
using namespace std;
int main() {
    int number;
    int index;
    scanf("%d%d", &number, &index);
    Student *students = new Student[number];
    for (int i = 0; i < number; i++) {
        scanf("%s%s%d", students[i].ID, students[i].name, &students[i].grade);
    }
    if (index == 1) sort(students, students + number, compare1);
    else if (index == 2) sort(students, students + number, compare2);
    else sort(students, students + number, compare3);
    for (int i = 0; i < number; i++) printf("%s %s %d\n", students[i].ID, students[i].name, students[i].grade);
    return 0;
}