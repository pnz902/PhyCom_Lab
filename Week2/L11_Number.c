#include <stdio.h>

int main(){
    char num[5];
    scanf("%s", &num);
    printf("%c%c%c%.2s", num[2], num[3], num[4], num);

    return 0;
}