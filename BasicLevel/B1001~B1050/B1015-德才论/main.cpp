//
//main.cpp
//B1015-德才论
//
//Created by Ezreal on 2019/09/12.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <algorithm>
#include <cstring>

struct Student {
    char ID[9];
    int Score_1;
    int Score_2;
};
bool compare(Student stu1, Student stu2) {
    if (stu1.Score_1 + stu1.Score_2 == stu2.Score_1 + stu2.Score_2) {
        if (stu1.Score_1 == stu2.Score_1) return strcmp(stu1.ID, stu2.ID) < 0;
        return stu1.Score_1 > stu2.Score_1;
    }
    return stu1.Score_1 + stu1.Score_2 > stu2.Score_1 + stu2.Score_2;
}
using namespace std;
int main(){
    int count_1 = 0;
    int count_2 = 0;
    int count_3 = 0;
    int count_4 = 0;
    int number, lowScore, highScore;
    scanf("%d%d%d", &number, &lowScore, &highScore);
    Student students[4][100000];
    for (int i = 0; i < number; i++) {
        Student student;
        scanf("%s%d%d", student.ID, &student.Score_1, &student.Score_2);
        if (student.Score_1 >= lowScore && student.Score_2 >= lowScore) {
            if (student.Score_1 >= highScore && student.Score_2 >= highScore) {
                students[0][count_1] = student;
                count_1 ++;
            } else if (student.Score_1 >= highScore && student.Score_2 >= lowScore) {
                students[1][count_2] = student;
                count_2++;
            } else if (student.Score_1 < highScore && student.Score_2 < highScore && student.Score_1 >= student.Score_2) {
                students[2][count_3] = student;
                count_3++;
            } else {
                students[3][count_4] = student;
                count_4++;
            }
        }
    }
    sort(students[0], students[0] + count_1, compare);
    sort(students[1], students[1] + count_2, compare);
    sort(students[2], students[2] + count_3, compare);
    sort(students[3], students[3] + count_4, compare);
    printf("%d\n", count_1 + count_2 + count_3 + count_4);
    for (int i = 0; i < count_1; i++) printf("%s %d %d\n", students[0][i].ID, students[0][i].Score_1, students[0][i].Score_2);
    for (int i = 0; i < count_2; i++) printf("%s %d %d\n", students[1][i].ID, students[1][i].Score_1, students[1][i].Score_2);
    for (int i = 0; i < count_3; i++) printf("%s %d %d\n", students[2][i].ID, students[2][i].Score_1, students[2][i].Score_2);
    for (int i = 0; i < count_4; i++) printf("%s %d %d\n", students[3][i].ID, students[3][i].Score_1, students[3][i].Score_2);
    return 0;
}