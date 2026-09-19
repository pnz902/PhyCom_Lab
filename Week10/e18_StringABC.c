#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

int main(){
    char text[201];
    scanf("%[^\n]", text);
    qsort(text, strlen(text), sizeof(text[0]), compare);
    
    int index = 0;
    while(text[index] != '\0'){
        if(text[index] != ' '){
            printf("%c", text[index]);
        }
        index++;
    }

    return 0;
}