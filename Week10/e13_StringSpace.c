#include <stdio.h>

int main(){
    char text[151];

    scanf("%[^\n]", text);

    int index = 0;
    while(text[index] != '\0'){
        if (text[index] != ' '){
            printf("%c", text[index]);
        }
        index++;
    }

    return 0;
}