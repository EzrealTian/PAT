#include <stdio.h>

int main(){
    unsigned int number;
    int count = 0;
    scanf("%d",&number);
    while (number != 1)
    {
        number = number % 2 == 0 ? number / 2 : (3 * number + 1) / 2;
        count++;
    }
    printf("%d\n",count);
    
    return 0;
}