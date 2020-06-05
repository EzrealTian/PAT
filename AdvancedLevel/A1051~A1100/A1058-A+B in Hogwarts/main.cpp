//
//main.cpp
//A1058-A+B in Hogwarts
//
//Created by Ezreal on 2019/09/07.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>

int main(){
    int AGalleon, ASickle, AKnut;     //付的钱
    int BGalleon, BSickle, BKnut;    //价格
    int resultGalleon, resultSickle, resultKnut;    //找的钱
    scanf("%d.%d.%d %d.%d.%d", &BGalleon, &BSickle, &BKnut, &AGalleon, &ASickle, &AKnut);
    if (AKnut + BKnut >= 29) {
        resultKnut = AKnut + BKnut - 29;
        ASickle++;
    } else {
        resultKnut = AKnut + BKnut;
    }

    if (ASickle + BSickle >= 17) {
        resultSickle = ASickle + BSickle - 17;
        AGalleon++;
    } else {
        resultSickle = ASickle + BSickle;
    }

    resultGalleon = AGalleon + BGalleon;
    
    printf("%d.%d.%d\n", resultGalleon, resultSickle, resultKnut);
    return 0;
}