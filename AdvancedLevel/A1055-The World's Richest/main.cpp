//
//main.cpp
//A1055-The World's Richest
//
//Created by Ezreal on 2019/09/16.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>
#include <algorithm>

struct Person {
    char name[9];
    int age;
    int worth;
};

bool compare(Person p1, Person p2) {
    if (p1.worth != p2.worth) return p1.worth > p2.worth;
    if (p1.age != p2.age) return p1.age < p2.age;
    return strcmp(p1.name, p2.name) < 0;
}

using namespace std;
int main(){
    int count, number;
    scanf("%d%d", &count, &number);
    Person *persons = new Person[count];
    Person *newPer = new Person[count];
    int age[201] = {0};
    int validNum = 0;
    for (int i = 0; i < count; i++) scanf("%s%d%d", persons[i].name, &persons[i].age, &persons[i].worth);
    sort(persons, persons + count, compare);
    for (int i = 0; i < count; i++) {
        if (age[persons[i].age] < 100) {
            age[persons[i].age]++;
            newPer[validNum] = persons[i];
            validNum++;
        }
    }
    int Min, Max, outNum;
    for (int i = 0; i < number; i++) {
        scanf("%d%d%d", &outNum, &Min, &Max);
        printf("Case #%d:\n", i + 1);
        int printNum = 0;
        for (int j = 0; j < validNum && printNum < outNum; j++) {
            if (newPer[j].age >= Min && newPer[j].age <= Max) {
                printf("%s %d %d\n", newPer[j].name, newPer[j].age, newPer[j].worth);
                printNum++;
            }
        }
        if (printNum == 0) printf("None\n");
    }
    return 0;
}