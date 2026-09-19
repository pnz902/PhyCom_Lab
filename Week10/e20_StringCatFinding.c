#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char text[2001];
    scanf("%[^\n]", text);

    int index = 0;
    while(text[index] != '\0'){
        text[index] = tolower(text[index]);
        index++;
    }

    char *p = strstr(text, "cat");
    printf("%d", p - text);

    p += 3;
    while((p = strstr(p, "cat")) != NULL){
        printf(", %d", p - text);
        p += 3;
    }

    return 0;
}