//
//main.cpp
//B1028-人口普查
//
//Created by Ezreal on 2019/09/03.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <string>
using namespace std;
int main(){
    int count;
    scanf("%d", &count);
    string name;
    name.resize(6);
    int year, month, day;
    int standardMax = 2014 * 365 + 9 * 30 + 6;
    int standardMin = 1814 * 365 + 9 * 30 + 6;
    int minNumber = 1814 * 365 + 9 * 30 + 6;
    int maxNumber = 2014 * 365 + 9 * 30 + 6;
    string oldName = "";
    string youngName = "";
    int result = 0;
    for (int i = 0; i < count; i++) {
        scanf("%s %d/%d/%d", &name[0], &year, &month, &day);
        //printf("%s", name.c_str());
        int temp = year * 365 + month * 30 + day;
        if(temp <= standardMax && temp >= standardMin) {
            result++;
            if (temp < maxNumber)
            {
                oldName = name;
                //printf("%s %d", name.c_str(),int(name.length()));
                //printf("%s\n", oldName.c_str());
                maxNumber = temp;
            }
            if (temp > minNumber)
            {
                youngName.assign(name);
                //printf("young%s\n", youngName.c_str());
                minNumber = temp;
            }
        } else {
            continue;
        }
    }
    if(result == 0) printf("0\n");
    else printf("%d %s %s\n",result, oldName.c_str(), youngName.c_str());

    return 0;
}