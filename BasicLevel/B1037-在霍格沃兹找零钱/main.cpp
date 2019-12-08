//
//main.cpp
//B1037-在霍格沃兹找零钱
//
//Created by Ezreal on 2019/09/05.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>
#include <cmath>
int main(){
    int payGalleon, paySickle, payKnut;     //付的钱
    int priceGalleon, priceSickle, priceKnut;    //价格
    int changeGalleon, changeSickle, changeKnut;    //找的钱
    scanf("%d.%d.%d %d.%d.%d", &priceGalleon, &priceSickle, &priceKnut, &payGalleon, &paySickle, &payKnut);
    int price = priceGalleon * 17 * 29 + priceSickle * 29 + priceKnut;
    int pay = payGalleon * 17 * 29 + paySickle * 29 + payKnut;
    int result = fabs(price - pay);

    changeGalleon = result / (17 * 29);
    result %= (17 * 29);
    changeSickle = result / 29;
    changeKnut = result % 29;
    if (price > pay) changeGalleon = -changeGalleon;
    printf("%d.%d.%d\n", changeGalleon, changeSickle, changeKnut);
    return 0;
}