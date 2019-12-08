//
//main.cpp
//A1027-Colors in Mars
//
//Created by Ezreal on 2019/09/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//

char numberToDigit(int number);

#include <cstdio>
int main(){
    char Red[2] = {'0'};
    char Green[2] = {'0'};
    char Blue[2] = {'0'};
    int red, green, blue;
    scanf("%d%d%d", &red, &green, &blue);
    Red[1] = numberToDigit(red % 13);
    Red[0] = numberToDigit(red / 13);
    Green[1] = numberToDigit(green % 13);
    Green[0] = numberToDigit(green / 13);
    Blue[1] = numberToDigit(blue % 13);
    Blue[0] = numberToDigit(blue / 13);
    printf("#%c%c%c%c%c%c\n", Red[0], Red[1], Green[0], Green[1], Blue[0], Blue[1]);
    return 0;
}

char numberToDigit(int number) {
    if (number >= 0 && number <= 9) {
        return '0' + number;
    } else {
        return 'A' + number - 10;
    }
}