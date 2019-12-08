//
//main.cpp
//B1018-锤子剪刀布
//
//Created by Ezreal on 2019/07/28.
//Copyright © 2019年 Ezreal. All rights reserved.
//



#include <cstdio>

int printGesture(int *gesture);

int main(){
    int count;
    scanf("%d",&count);
    char player1, player2;
    int player1Score[3] = {0};
    int player1Gesture[3] = {0};
    int player2Gesture[3] = {0};
    getchar();  //注意要吃掉回车
    for(int i = 0; i < count; i++)
    {
        scanf("%c %c",&player1,&player2);
        getchar();  //注意要吃掉回车
        if (player1 == player2) {
            player1Score[1]++;
            continue;
        }
        if (player1 == 'C') {
            if (player2 == 'J') {
                player1Score[0]++;
                player1Gesture[1]++;
            } else if (player2 == 'B') {
                player1Score[2]++;
                player2Gesture[0]++;
            }
        } else if (player1 == 'J') {
            if (player2 == 'B') {
                player1Score[0]++;
                player1Gesture[2]++;
            } else if (player2 == 'C') {
                player1Score[2]++;
                player2Gesture[1]++;
            }
        } else {
            if (player2 == 'C') {
                player1Score[0]++;
                player1Gesture[0]++;
            } else if (player2 == 'J') {
                player1Score[2]++;
                player2Gesture[2]++;
            }
        }
    }
    printf("%d %d %d\n",player1Score[0],player1Score[1],player1Score[2]);
    printf("%d %d %d\n",player1Score[2],player1Score[1],player1Score[0]);
    if (printGesture(player1Gesture) == 1) printf("B ");
    if (printGesture(player1Gesture) == 2) printf("C ");
    if (printGesture(player1Gesture) == 3) printf("J ");
    if (printGesture(player2Gesture) == 1) printf("B");
    if (printGesture(player2Gesture) == 2) printf("C");
    if (printGesture(player2Gesture) == 3) printf("J");
    printf("\n");
    return 0;
}

int printGesture(int *gesture) {
   if (gesture[0] > gesture[1]) {
      if (gesture[0] >= gesture[2]) return 1;
      else if (gesture[0] < gesture[2]) return 3;
   } 
   if (gesture[0] < gesture[1]) {
      if (gesture[1] >= gesture[2]) return 2;
      else if (gesture[1] < gesture[2]) return 3;
   }
   if (gesture[0] == gesture[1]) {
      if (gesture[0] >= gesture[2]) return 1;
      else if (gesture[0] < gesture[2]) return 3;  
   }
   return 0;   
}

