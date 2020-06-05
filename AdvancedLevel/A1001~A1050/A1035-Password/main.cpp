//
//main.cpp
//A1035-Password
//
//Created by Ezreal on 2019/09/11.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cstring>

struct User {
    char name[11];
    char password[11];
};

int main(){
    int number;
    scanf("%d", &number);
    User *user = new User[number];
    User *result = new User[number];
    int count = 0;
    for (int i = 0; i < number; i++) {
        bool isModified = false;
        scanf("%s %s", user[i].name, user[i].password);
        int length = strlen(user[i].password);
        for (int j = 0; j < length; j++) {
            if (user[i].password[j] == '1' || user[i].password[j] == '0' || user[i].password[j] == 'l' || user[i].password[j] == 'O') isModified = true;
            if (user[i].password[j] == '1') user[i].password[j] = '@';
            if (user[i].password[j] == '0') user[i].password[j] = '%';
            if (user[i].password[j] == 'l') user[i].password[j] = 'L';
            if (user[i].password[j] == 'O') user[i].password[j] = 'o';
        }
        if (isModified) {
            result[count] = user[i];
            count++;
        }
    }
    if (count == 0 && number == 1) printf("There is 1 account and no account is modified\n");
    else if (count == 0) printf("There are %d accounts and no account is modified", number);
    else {
        printf("%d\n", count);
        for (int i = 0; i < count; i++) printf("%s %s\n", result[i].name, result[i].password);
    }
    return 0;
}