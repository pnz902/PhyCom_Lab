#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char* str = (char*) malloc(sizeof(char) * 101);
    int upper = 0, lower = 0, digit = 0;
    scanf("%[^\n]s", str);

    char *p = str;
    while(*p != '\0'){
        if (islower(*p)) lower++;
        if (isupper(*p)) upper++;
        if (isdigit(*p)) digit++;
        p++;
    }

    printf("Lowercase letters: %d\n", lower);
    printf("Uppercase letters: %d\n", upper);
    printf("Digits: %d", digit);

    free(str);

    return 0;
}