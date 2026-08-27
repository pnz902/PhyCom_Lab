#include <stdio.h>
#include <stdlib.h>

int main(){
    char* str = (char*) malloc(sizeof(char) * 101);
    scanf("%[^\n]", str);

    char *p = str;
    while(*p != '\0'){
        p++;
    }

    while(p > str){
        printf("%c", *--p);
    }

    free(str);

    return 0;
}