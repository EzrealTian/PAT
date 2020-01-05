#include <stdio.h>
#include <cstring>
int main(){
    bool charSet[128] = {false};
    char string1[68], string2[100001];
    gets(string1);
    scanf("%s", string2);
    for(int i = 0; i < strlen(string1); i++) {
        if (string1[i] >= 'A' && string1[i] <= 'Z') charSet[string1[i] - 'A' + 'a'] = true;
        charSet[string1[i]] = true;
    }
    int length = strlen(string2);
    for (int i = 0; i < length; i++) {
        if (!charSet[string2[i]]) {
            if (string2[i] >= 'A' && string2[i] <= 'Z' && charSet['+']) printf("");
            else printf("%c", string2[i]);
        }
    }
    printf("\n");
    return 0;
}